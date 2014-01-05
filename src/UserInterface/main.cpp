/*
 * Copyright 2012-2013 Patrick Kramer, Vincent Wassenaar
 *
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <cstdlib>
#include <iostream>

/* We require dynamic JVM loading instead of statically binding to the JVM library
 * This prevents the StaticVMLoader class from trying to statically bind to jvm.lib
 */
#define JACE_WANT_DYNAMIC_LOAD

#include <QtCore>
#include <QProcess>
#include <QApplication>
#include <stdexcept>
#include <string>

#include "jace/JNIHelper.h"
#include "jni.h"
#ifdef Q_OS_UNIX
#  include "jace/UnixVmLoader.h"
#else
#  include "Win32VmLoader.h"
#endif
#include "jace/OptionList.h"

#include "jace/JArray.h"
using jace::JArray;

#include "mainwindow.h"

using namespace jace;
using namespace std;

#ifdef Q_OS_MAC
/**
 * @brief Detects the Java Virtual Machine library path
 *
 * This function executes the java_home tool to find the home directory,
 * and then assumes the
 * @return a string containing the detected JVM path
 * @throws runtime_error when the path cannot be found.
 */
string detectJVMPath() {
    // We use the "java_home" tool to track the path to the java home
    // The JVM library can be found in <java_home>/jre/lib/server/libjvm.dylib
    QProcess javaHomeProcess;
    javaHomeProcess.start("/usr/libexec/java_home");
    javaHomeProcess.waitForFinished();

    if (javaHomeProcess.canReadLine()) {
        QByteArray data = javaHomeProcess.readLine();
        QString dataString = QString::fromLocal8Bit(data);
        dataString.chop(1); // Remove the '\n' from the result string.
        dataString.append("/jre/lib/server/libjvm.dylib");
        string dataStdString = dataString.toStdString();
        return dataStdString;
    } else {
        throw runtime_error("Failed to execute /usr/libexec/java_home");
    }
}
#elif defined(Q_OS_UNIX)
// not Mac, but generic Unix
// Not yet supported since there may not be a standard way to get the
// path to the JVM library
#error Unix is not supported at this moment

#endif

int main(int argc, char** argv) {

    qDebug() << "Attempting to load JVM...";

    // Create the loader instance with the appropriate configuration options.
    try {

#ifdef Q_OS_UNIX
        // Unix OS has no common way of detecting jvm path, so for
        // Unix, a detectJVMPath function is used.
        string jvmPath;
        try {
            jvmPath = detectJVMPath();
            qDebug() << "Found JVM path:" << jvmPath.c_str();
        } catch (runtime_error& err) {
            qWarning() << "Error during JVM path detection:" << err.what();
            return EXIT_FAILURE;
        }
        UnixVmLoader loader (jvmPath, JNI_VERSION_1_6);
#else
        // Windows installations have a key in registry indicating the Java installation.
        // The special Win32VmLoader makes use of this key to find a JVM.
        jace::Win32VmLoader loader;
#endif

        OptionList options;

        // Add the PowerGrid jar file to the classpath
        options.push_back( CustomOption("-Djava.class.path=./PowerGridLoader.jar") );
#ifdef PG_DEBUG
        options.push_back( CustomOption("-Xcheck:jni") ); // check JNI calls when in debug mode
#endif

#ifdef Q_OS_MACX
        /* MacX has issues when starting a JVM through JNI. This is adressed
         * in this issue: https://bugs.openjdk.java.net/browse/JDK-7131356
         *
         * This issue may be fixed later by allowing PowerGrid to start from
         * Java, effectively circumventing the issue, but this currently has
         * no priority.
         */
        qWarning() << "Please make sure Apple's JVM is installed and being used.";
#endif
        // create the JVM
        try {
            helper::createVm( loader, options, false);
            qDebug() << "JVM created";
        } catch (JNIException& e) {

            qWarning() << "[FAILURE] Creating VM failed:" << e.what();

            return EXIT_FAILURE;
        }

        JNIEnv* env = helper::attach();
        jclass pgLoaderClass = env->FindClass("net/pgrid/loader/PGLoader");
        if (!pgLoaderClass) {
            throw JNIException("PGLoader class not found");
        }
        jmethodID mainMethod = env->GetStaticMethodID(pgLoaderClass, "main", "([Ljava/lang/String;)V");
        if (!mainMethod) {
            throw JNIException("PGLoader.main method not found");
        }
        jclass stringClass = env->FindClass("java/lang/String");
        if (!stringClass) {
            throw JNIException("String class not found");
        }

        jstring arg1 = env->NewStringUTF("-u");
        if (!arg1) {
            throw JNIException("Failed to create UTF String \"-u\"");
        }

        jarray args = env->NewObjectArray(1, stringClass, arg1);
        if (!args) {
            throw JNIException("Failed to allocate String[] object");
        }

        qDebug() << "Calling PGLoader.main(String[] args)";
        env->CallStaticVoidMethod(pgLoaderClass, mainMethod, args);

        if (env->ExceptionCheck()) {
            throw JNIException("Exception in main method invocation");
        }

        // Clean up all JNI resources
        env->DeleteLocalRef(arg1);
        env->DeleteLocalRef(args);
        env->DeleteLocalRef(stringClass);
        env->DeleteLocalRef(pgLoaderClass);

        helper::detach();

    } catch (JNIException& e) {
        qWarning() << "Error creating JVM loader: " << e.what();
        return EXIT_FAILURE;
    }

    // The JVM is started and is running, now create our control frame.
    QApplication app (argc, argv);
    app.setApplicationName("PowerGrid");
    MainWindow window;
    window.show();
    return app.exec();
}
