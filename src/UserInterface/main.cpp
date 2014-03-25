/*
 * Copyright 2014 Patrick Kramer, Vincent Wassenaar
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

// Required Qt headers
#include <QtCore>
#include <QApplication>

#ifdef Q_OS_MACX
// There is a bug in Oracle's VM on Mac OS X, and as such we may not be able to load it
// from here.
#warning PowerGrid does not officially support Mac OS (yet) due to a bug in Oracle`s JVM.
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

// OS-dependant headers
#ifdef Q_OS_UNIX
#  include "jace/UnixVmLoader.h"
#  include <QList>
#  include <QDir>
#elif defined(Q_OS_WIN32)
#  include "Win32VmLoader.h"
#endif

// Native methods that need to be registered
#include "jace/updaterrunner.h"

// Our own additional headers
#include "mainwindow.h"
#include "versionInfo.h"

using namespace jace;
using namespace std;

int main(int argc, char** argv) {

    qDebug() << "Attempting to load JVM...";

    // Create the loader instance with the appropriate configuration options.
    try {

#if defined(Q_OS_UNIX)
        QString jvmPath;
        // get the JAVA_HOME environment variable.
        QByteArray java_home_bytes = qgetenv("JAVA_HOME");
        QString java_home(java_home_bytes);
        if (java_home.isEmpty()) {
            throw JNIException("JAVA_HOME is not set; cannot find installed jre");
        }
        // Now we have to look for libjvm.so in this directory
        // and subdirectories. We do this iteratively using a
        // queue of directories (implemented as a QList).
        QList<QDir> directories;
        directories.append(java_home);

        while (!directories.empty()) {
            QDir current = directories.takeFirst();
            QFileInfoList entries = current.entryInfoList();
            QFileInfoList::iterator it = entries.begin();
            for (;it != entries.end(); it++) {
                QFileInfo info = *it;
                if (info.fileName() == QStringLiteral("libjvm.so")) {
                    // We found it
                    jvmPath = info.canonicalFilePath();
                    break;
                }
                if (info.isDir()) {
                    // Add the directories to the list of directories
                    // to search.
                    directories.prepend(info.absoluteDir());
                }
            }
            if (!jvmPath.isEmpty()) {
                break;
            }
        }

        if (jvmPath.isEmpty()) {
            throw JNIException("Cannot find libjvm.so in JAVA_HOME directory");
        }

        UnixVmLoader loader (jvmPath.toStdString(), JNI_VERSION_1_6);
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
        bridge::updater::UpdaterRunner_registerNatives(env);

        // Start the PowerGridLoader
        // Actual command (in java): net.pgrid.loader.PGLoader.main(new String[]{"-c"});

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

        qDebug() << "Calling PGLoader.main(String[] args)";
        env->CallStaticVoidMethod(pgLoaderClass, mainMethod, NULL);

        if (env->ExceptionCheck()) {
            throw JNIException("Exception in main method invocation");
        }

        // Clean up JNI references
        env->DeleteLocalRef(stringClass);
        env->DeleteLocalRef(pgLoaderClass);

    } catch (JNIException& e) {
        qWarning() << "Error creating JVM loader: " << e.what();
        return EXIT_FAILURE;
    }



    qDebug() << "JVM started, creating control panel";
    QApplication app (argc, argv);
    app.setApplicationName(PG_NAME_STR);
    app.setApplicationVersion(PG_VERSION_STR);
    // The JVM is started and is running, now create our
    // PowerGrid Qt Application and frame.
    MainWindow window;
    window.show();
    window.setJVMVersion(jace::helper::getJavaProperty("java.version"));
    qDebug() << "Done.";
    return app.exec();
}
