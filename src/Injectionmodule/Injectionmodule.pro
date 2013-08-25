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

#-------------------------------------------------
#
# This project contains the Injection code that
# injects event objects into the Runescape
# environment
#
#-------------------------------------------------

#------------------------------------------------
# Basic properties of the project itself
#------------------------------------------------
QT          = core

TARGET      = Injectionmodule
TEMPLATE    = lib
CONFIG     += staticlib

DESTDIR     = build/
OBJECTS_DIR = build/

#------------------------------------------------
# The files in this project
#------------------------------------------------
SOURCES     = \
    mouse.cpp \
    keyboard.cpp
HEADERS     = \
    mouse.h \
    keyboard.h

#------------------------------------------------
# The subprojects this project depends on
#------------------------------------------------
include (../Javabridge/include.pro)

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../world/release/ -lworld
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../world/debug/ -lworld
else:unix: LIBS += -L$$OUT_PWD/../world/ -lworld

INCLUDEPATH += $$PWD/../world
DEPENDPATH += $$PWD/../world
