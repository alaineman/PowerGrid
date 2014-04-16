#------------------------------------------------------------------------
# Copyright 2014 Patrick Kramer, Vincent Wassenaar
#
# This file is part of PowerGrid.
#
# PowerGrid is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# PowerGrid is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
#------------------------------------------------------------------------

#------------------------------------------------
#
# This project contains the GUI, and statically
# links to the other subprojects. This is the
# entry point for PowerGrid, and as such this
# project file also contains the icon and
# metadata such as productname and version.
#
#------------------------------------------------

#------------------------------------------------
# Basic properties of the project itself
#------------------------------------------------
QT          = core gui widgets
CONFIG     += thread c++11
TEMPLATE    = app


win32: RC_FILE = powergrid.rc

# Make sure the executable/library is named PowerGrid and is in
# an easy to find location
# See also doc/autoBuildInstructions.md
TARGET = PowerGrid
DESTDIR = $$PWD/../../dist

# Add instruction to copy dependant Qt libraries to DESTDIR
win32 {
    # On Windows, Qt libraries are in the 'bin' folder
    QTDIR = $$[QT_INSTALL_PREFIX]/bin
    qtlibs.path = $$DESTDIR
    qtlibs.CONFIG = no_check_exist
    CONFIG(debug, debug|release) {
        qtlibs.files += $$QTDIR/Qt5Cored.dll
        qtlibs.files += $$QTDIR/Qt5Guid.dll
        qtlibs.files += $$QTDIR/Qt5Widgetsd.dll
    }
    CONFIG(release, debug|release) {
        qtlibs.files += $$QTDIR/Qt5Core.dll
        qtlibs.files += $$QTDIR/Qt5Gui.dll
        qtlibs.files += $$QTDIR/Qt5Widgets.dll
    }
    qtlibs.files += $$QTDIR/icudt51.dll
    qtlibs.files += $$QTDIR/icuin51.dll
    qtlibs.files += $$QTDIR/icuuc51.dll
    win32-g++ {
        qtlibs.files += $$QTDIR/libgcc_s_dw2-1.dll
        qtlibs.files += $$QTDIR/libstd~1.dll
        qtlibs.files += $$QTDIR/libwinpthread-1.dll
    }
    # We may need to add specific files for other compilers
    else: warning(possibly missing compiler dependant libraries)
    INSTALLS += qtlibs
}
else {
    warning(missing dependency specs; Qt libraries are not copied)
}

#------------------------------------------------
# The files in this project
#------------------------------------------------
SOURCES       += main.cpp mainwindow.cpp
HEADERS        = mainwindow.h versionInfo.h powergrid.rc
FORMS          = mainwindow.ui
RESOURCES      = resources.qrc

# helper defines to detect build mode.
CONFIG(debug, debug|release) {
    DEFINES += PG_DEBUG
}
CONFIG(release, debug|release) {
    DEFINES += PG_RELEASE # QT_NO_DEBUG_OUTPUT
}
DEFINES += JACE_STATIC

# Depends for Bridge
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Bridge/release/ -lBridge
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Bridge/debug/ -lBridge
else:unix: LIBS += -L$$OUT_PWD/../Bridge/ -lBridge

INCLUDEPATH += $$PWD/../Bridge
DEPENDPATH += $$PWD/../Bridge

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Bridge/release/libBridge.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Bridge/debug/libBridge.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Bridge/release/Bridge.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Bridge/debug/Bridge.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Bridge/libBridge.a
