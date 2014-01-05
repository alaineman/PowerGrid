#------------------------------------------------------------------------
# Copyright 2012-2013 Patrick Kramer, Vincent Wassenaar
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
TEMPLATE    = app
CONFIG     += c++11

win32:     RC_FILE = powergrid.rc
else:macx: ICON    = powergrid.icns

# Make sure the executable is named PowerGrid and is in
# an easy to find location
# See also doc/autoBuildInstructions.md
TARGET = PowerGrid
DESTDIR = $$PWD/../../dist

QMAKE_CXXFLAGS += -std=gnu++11

#------------------------------------------------
# The files in this project
#------------------------------------------------
SOURCES     = main.cpp \
              mainwindow.cpp
HEADERS     = mainwindow.h
FORMS       = mainwindow.ui
RESOURCES   = resources.qrc
OTHER_FILES = powergrid.rc \
              powergrid.icns

win32 {
    # Windows has this specific VmLoader
    SOURCES += Win32VmLoader.cpp
    HEADERS += Win32VmLoader.h
}

# helper defines to detect build mode.
debug:   DEFINES += PG_DEBUG
release: DEFINES += PG_RELEASE

# Depends for JACE
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../JACE/release/ -lJACE
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../JACE/debug/ -lJACE
else:unix: LIBS += -L$$OUT_PWD/../JACE/ -lJACE

INCLUDEPATH += $$PWD/../JACE
DEPENDPATH += $$PWD/../JACE

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../JACE/release/libJACE.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../JACE/debug/libJACE.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../JACE/release/JACE.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../JACE/debug/JACE.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../JACE/libJACE.a
