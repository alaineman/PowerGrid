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

using namespace jace;

VmLoader* globalVmLoader;

/**
 * @brief executes the PowerGrid application
 * @param argc the amount of arguments
 * @param argv the actual arguments
 * @return the result
 */
int execute(int argc, char** argv) {
    QApplication app (argc, argv);
    app.setApplicationName("PowerGrid");
    MainWindow window;
    window.show();
    return app.exec();
}

// These two functions allow a JVM to load this application
// as a library
void JNI_OnLoad(JavaVM* vm, void*) {
    globalVmLoader = new WrapperVmLoader(vm);
    // Start the Qt Event Loop on another Thread
    QtConcurrent::run(execute, argc, argv);
}

void JNI_OnUnload(JavaVM*, void*) {
    // Terminate the running Qt Application
    QApplication.exit(0);

    if (globalVmLoader) {
        globalVmLoader->unloadVm();
        delete (globalVmLoader);
    }
}

#endif
