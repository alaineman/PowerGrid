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
# Include project file for the Java bridge.
#
# Include this file into other .pro files that
# depend on the Javabridge project.
#
#------------------------------------------------

LIBS           += $$OUT_PWD/../JNIModule/build/libJNIModule.a
PRE_TARGETDEPS += $$OUT_PWD/../JNIModule/build/libJNIModule.a

# We also need to explicitly link the JNI headers / libraries
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

INCLUDEPATH += $$JNI_HEADERS $$PWD/../JNIModule
DEPENDPATH  += $$JNI_HEADERS $$PWD/../JNIModule
