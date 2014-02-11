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

#ifdef PG_BUILD_JNILIB

#include <jni.h>
#include "jace/WrapperVmLoader.h"
#include <QApplication>
#include "mainwindow.h"
#include "versionInfo.h"
#include <QtConcurrent>

using namespace jace;

VmLoader* globalVmLoader;

// These two functions allow a JVM to load this application
// as a library
jint JNI_OnLoad(JavaVM* vm, void*) {
    globalVmLoader = new WrapperVmLoader(vm);
    // FIXME This should go into a Java class that makes a native method call.
    // Now the JVM may be waiting forever until the library is loaded.
    // Additionally, QApplication may only be launched from a QThread, so we need to
    // start a new Thread from there.
    int argc = 0;
    QApplication app (argc, NULL);
    app.setApplicationName(PG_NAME_STR);
    MainWindow window;
    window.show();
    int result = app.exec();
    if (result == 0) {
        return JNI_OK;
    } else {
        return JNI_ERR;
    }
}

void JNI_OnUnload(JavaVM*, void*) {
    if (globalVmLoader) {
        // Our VmLoader is no longer valid
        globalVmLoader->unloadVm();
        delete (globalVmLoader);
    }

    // Terminate the running Qt Application
    QApplication::exit();
}

#else
#warning libmain.cpp is included in the build even though the target is an application! Use main.cpp instead.
#endif
