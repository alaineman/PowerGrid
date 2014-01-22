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

#ifndef PG_BUILD_JNILIB


/* We require dynamic JVM loading instead of statically binding to the JVM library
 * This prevents the StaticVMLoader class from trying to statically bind to the jvm library
 */
#define JACE_WANT_DYNAMIC_LOAD

// Required Qt headers
#include <QtCore>
#include <QApplication>

#ifdef Q_OS_MACX
// There is a bug in Oracle's VM on Mac OS X, and as such we may not be able to load it
// from here. We build PowerGrid to be loaded as a jni library from a running JVM instead.
#warning This file does not officially support Mac OS, consider using "libmain.cpp" instead.
#endif

// Required standard headers
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <iostream>

// Required JACE headers
#include "jni.h"
#include "jace/JNIHelper.h"
#include "jace/OptionList.h"

#ifdef Q_OS_UNIX
#  include "jace/UnixVmLoader.h"
#else
#  include "Win32VmLoader.h"
#endif

// Native methods that need to be registered
#include "updaterrunner.h"

// Our own additional headers
#include "mainwindow.h"

using namespace jace;
using namespace std;

int main(int argc, char** argv) {

    qDebug() << "Attempting to load JVM...";

    // Create the loader instance with the appropriate configuration options.
    try {

#if defined(Q_OS_UNIX) && !defined(Q_OS_MACX)
        // As for now, Unix is not supported. We need to be find out
        // how to find a JVM installation on Unix platforms first.
#error Unix based systems are not supported yet.

        string jvmPath;
        UnixVmLoader loader (jvmPath, JNI_VERSION_1_6);
#else
        // Windows installations have a key in registry indicating the Java installation.
        // The special Win32VmLoader makes use of this key to find a JVM.
        Win32VmLoader loader;
#endif

        OptionList options;
        // Add the PowerGrid jar file to the classpath
        options.push_back( CustomOption("-Djava.class.path=./PowerGridLoader.jar") );
#ifdef PG_DEBUG
        options.push_back( CustomOption("-Xcheck:jni") ); // check JNI calls when in debug mode
#endif

        // create the JVM
        try {
            helper::createVm(loader, options);
            qDebug() << "JVM created";
        } catch (JNIException& e) {
            qWarning() << "[FAILURE] Creating VM failed:" << e.what();
            return EXIT_FAILURE;
        }

        JNIEnv* env = helper::attach();

        // Register all natives
        bridge::updater::UpdaterRunner_registerNatives(env); // net.pgrid.loader.bridge.UpdaterRunner

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

        // Clean up JNI references
        env->DeleteLocalRef(arg1);
        env->DeleteLocalRef(args);
        env->DeleteLocalRef(stringClass);
        env->DeleteLocalRef(pgLoaderClass);

        helper::detach();

    } catch (JNIException& e) {
        qWarning() << "Error creating JVM loader: " << e.what();
        return EXIT_FAILURE;
    }

    // The JVM is started and is running, now create our
    // PowerGrid Qt Application and frame.
    QApplication app (argc, argv);
    app.setApplicationName(QStringLiteral("PowerGrid"));
    MainWindow window;
    window.show();
    return app.exec();
}

#endif
