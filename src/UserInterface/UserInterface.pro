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
QT          = core gui widgets network
CONFIG     += thread c++11
TEMPLATE    = app

win32: RC_FILE = powergrid.rc

# Make sure the executable/library is named PowerGrid and is in
# an easy to find location
# See also doc/autoBuildInstructions.md
TARGET = PowerGrid
DESTDIR = $$PWD/../../dist

# Add instruction to copy dependant Qt libraries to DESTDIR
# and set the project to call Ant to build the Java loader.
CONFIG(release, debug|release) {
    win32: QMAKE_POST_LINK += windeployqt $$shell_quote($$shell_path($${DESTDIR}/$${TARGET}.exe)) &
}
win32 {
    QMAKE_POST_LINK += cd $$PWD/../../loader & ant.bat jar &
}
else {
    QMAKE_POST_LINK += cd $$PWD/../../loader; ant jar;
}

#------------------------------------------------
# The files in this project
#------------------------------------------------
SOURCES += \
    main.cpp \
    mainwindow.cpp \
    monitorwindow.cpp
HEADERS += \
    mainwindow.h \
    versionInfo.h \
    powergrid.rc \
    monitorwindow.h
FORMS += \
    mainwindow.ui \
    monitorwindow.ui
RESOURCES += \
    resources.qrc

# helper defines to detect build mode.
CONFIG(debug, debug|release) {
    DEFINES += PG_DEBUG
}
CONFIG(release, debug|release) {
    DEFINES += PG_RELEASE
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

# Depends for API
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../API/release/ -lAPI
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../API/debug/ -lAPI
else:unix: LIBS += -L$$OUT_PWD/../API/ -lAPI

INCLUDEPATH += $$PWD/../API
DEPENDPATH += $$PWD/../API

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../API/release/libAPI.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../API/debug/libAPI.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../API/release/API.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../API/debug/API.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../API/libAPI.a
