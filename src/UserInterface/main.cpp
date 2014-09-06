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
#ifdef Q_OS_MACX
#  include "jace/macvmloader.h"
#elif defined(Q_OS_UNIX)
#  include "jace/UnixVmLoader.h"
#else //Q_OS_WIN32
#  include "jace/Win32VmLoader.h"
#endif

// Native methods that need to be registered
#include "jace/UpdaterRunner.h"

// Our own additional headers
#include "mainwindow.h"
#include "versionInfo.h"
#include "net/pgrid/loader/pgloader.h"
using net::pgrid::loader::PGLoader;

Q_DECLARE_LOGGING_CATEGORY(logLauncher)
Q_LOGGING_CATEGORY(logLauncher, "LAUNCHER")

using namespace jace;
using namespace std;

// We use our own custom message handler for qDebug, qWarning, etc... messages to match the format
// used by the Java client.
void PGMessageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg) {
    Q_UNUSED(type)

    // We prefer to label the message with its category. However, if no category is defined,
    // we use a prefix based on the message type (debug, warning, critical, or fatal).
    const char* prefix = context.category;
    int len = strlen(prefix);
    if (len == 0) {
        switch (type) {
        case QtDebugMsg:
            cout << "INFORMATION  | ";
            break;
        case QtWarningMsg:
            cout << "WARNING      | ";
            break;
        case QtCriticalMsg:
            cout << "CRITICAL     | ";
            break;
        case QtFatalMsg:
            cout << "FATAL ERROR  | ";
        }
    } else {
        // Print the prefix and pad it to a length of (at least) 13.
        cout << prefix;
        while (len < 13) {
            cout << ' ';
            len++;
        }
        cout << "| ";
    }
    // After the label we print the message.
    cout << qPrintable(msg) << endl;
#if defined(PG_DEBUG) && !defined(PG_DEBUG_NO_TRACE)
    // We print the origin of the message in debug builds
    // (unless this was specifically disabled with PG_DEBUG_NO_TRACE)
    cout << "             | at " << context.file << ": " << context.line << endl;
#else
    Q_UNUSED(context)
#endif
}

int main(int argc, char** argv) {
    // Enable debug output for all categories by default
    QLoggingCategory::setFilterRules(QStringLiteral("*.debug=true"));
    qInstallMessageHandler(PGMessageHandler);
    qCDebug(logLauncher) << "Attempting to load JVM...";

    // Create the loader instance with the appropriate configuration options.
    try {
        OptionList options;
#if defined(Q_OS_WIN32)
        // Windows installations have a key in registry indicating the Java installation.
        // The special Win32VmLoader makes use of this key to find a JVM.
        Win32VmLoader loader;
#elif defined(Q_OS_MACX)
        // Mac OS X has a tool named java_home that indicates the path to the Java
        // installation. We use the MacVmLoader to dynamically load the JVM library in this way.
        MacVmLoader loader;
#else
        // Not Mac OS X, but generic Unix. We use the UnixVmLoader to load the JVM.
        // We expect the JAVA_HOME environment variable to be set for this.
        UnixVmLoader loader;
#endif

        // Add the PowerGrid jar file to the classpath
#ifdef Q_OS_MACX
        // Temporary fix for issue caused by Mac OS X application bundle layout.
        options.push_back( CustomOption("-Djava.class.path=../../../PowerGridLoader.jar") );
        options.push_back( CustomOption("-javaagent:../../../PowerGridLoader.jar") );
#else
        options.push_back( CustomOption("-Djava.class.path=PowerGridLoader.jar") );
        options.push_back( CustomOption("-javaagent:PowerGridLoader.jar") );
#endif

#ifdef PG_DEBUG
        options.push_back( CustomOption("-Xcheck:jni") ); // check JNI calls when in debug mode
#endif

        options.push_back( CustomOption("-Xss2M") );

        // create the JVM
        try {
            helper::createVm(loader, options);
            qCDebug(logLauncher) << "JVM created";
        } catch (JNIException& e) {
            qCWarning(logLauncher) << "[FAILURE] Creating VM failed:" << e.what();
            return EXIT_FAILURE;
        }

        JNIEnv* env = helper::attach();

        // Register all natives
        bridge::updater::UpdaterRunner_registerNatives(env);

        // Start the PowerGridLoader
        // Actual command (in java): net.pgrid.loader.PGLoader.main(null);

        qCDebug(logLauncher) << "Calling PGLoader.main";
        //FIXME It appears that on Mac OS X, a bug in the JVM causes problems with
        //      loading the PGLoader class, when the JVM is started from native
        //      code. No known workaround exists as of now.

        jclass pgLoaderClass = env->FindClass("net/pgrid/loader/PGLoader");
        if (!pgLoaderClass) {
            throw JNIException("PGLoader class not found");
        }
        jmethodID mainMethod = env->GetStaticMethodID(pgLoaderClass, "main", "([Ljava/lang/String;)V");
        if (!mainMethod) {
            throw JNIException("PGLoader.main method not found");
        }
        env->CallStaticVoidMethod(pgLoaderClass, mainMethod, NULL);

        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            throw JNIException("Exception in main method invocation");
        }

        // Clean up JNI references
        env->DeleteLocalRef(pgLoaderClass);

    } catch (JNIException& e) {
        qCWarning(logLauncher) << "Error creating JVM loader: " << e.what();
        return EXIT_FAILURE;
    }


    // The JVM is started and is running, now create our
    // PowerGrid Qt Application and frame.
    qCDebug(logLauncher) << "JVM started, creating control panel";
    QApplication app (argc, argv);
    app.setApplicationName(PG_NAME_STR);
    app.setApplicationVersion(PG_VERSION_STR);

    MainWindow window;
    window.show();
    window.setJVMVersion(jace::helper::getJavaProperty("java.version"));
    qCDebug(logLauncher) << "Done.";
    return app.exec();
}
