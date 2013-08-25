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
# .pro file for the Java bridge
#
# This module manages the connection with the
# running Java Virtual Machine and is therefore
# essential for starting Runescape. The Java bridge
# then acts as a gateway between the rest
# of PowerGrid and Runescape.
#
#------------------------------------------------

#------------------------------------------------
# The bridge only needs the QtCore, not the QtGUI.
#------------------------------------------------

QT = core

TARGET = Javabridge
TEMPLATE = lib
CONFIG += staticlib

DESTDIR = build/
OBJECTS_DIR = build/


#------------------------------------------------
# All headers and source files to include
#------------------------------------------------

HEADERS += \
    jnivalue.h \
    jnistring.h \
    jniobject.h \
    jnimethod.h \
    jniexception.h \
    jniclass.h \
    javaenv.h \
    rsclass.h

SOURCES += \
    jnivalue.cpp \
    jnistring.cpp \
    jniobject.cpp \
    jnimethod.cpp \
    jniclass.cpp \
    javaenv.cpp \

OTHER_FILES = \
    include.pro

#------------------------------------------------
# Add the dependency for jni
#------------------------------------------------

# Set the base directory for the Java Native Interface libraries
JNI_BASE = $$PWD/../../External/JNI

# Find the appropriate OS name for the platform-dependent include.
win32:      OS_NAME     = win32
else:macx:  OS_NAME     = darwin
else:unix:  OS_NAME     = unix
else:       error ("Unsupported OS")

JNI_HEADERS = $$JNI_BASE/include \
              $$JNI_BASE/include/$$OS_NAME

# On Mac OS, Java should be linked as a framework instead of a library.
# else (on windows and unix), the jvm is a normal (dynamic) library

macx:  LIBS += -framework JavaVM
else:  LIBS += -L$$JNI_BASE/lib -ljvm

INCLUDEPATH += $$JNI_HEADERS
DEPENDPATH  += $$JNI_HEADERS
