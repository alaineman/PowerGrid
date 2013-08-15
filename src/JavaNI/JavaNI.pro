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
# Include .pro file for the JNI headers
#
#------------------------------------------------

# Set the base directory for JNI iff it was not already set (overwritten)
isEmpty(JNI_BASE): JNI_BASE = $$PWD/../../External/JNI

# Find the appropriate OS name for the platform-dependent include.
win32:      OS_NAME     = win32
else:macx:  OS_NAME     = darwin
else:unix:  OS_NAME     = unix
else:       error ("Unsupported OS")

# verify the directories and files exist and give an error when it doesn't
# this prevents vague include or linking errors and instead simply states the cause.
!exists($$JNI_BASE/include):           error("Missing JNI header directory")
!exists($$JNI_BASE/include/$$OS_NAME): error("Target OS has no platform-dependent JNI headers")
!exists($$JNI_BASE/lib):               error("Missing JNI lib directory")
macx {}
else: win32 {
    # On windows, verify the dll and lib file exist for linking.
    !exists($$JNI_BASE/lib/jvm.dll):   error("(Windows) Missing jvm.dll")
    !exists($$JNI_BASE/lib/jvm.lib):   error("(Windows) Missing jvm.lib")
}
else: unix {
    # On Unix, verify the .so file exists for linking
    !exists($$JNI_BASE/lib/libjvm.so): error("(Unix) Missing libjvm.so")
}

JNI_HEADERS = $$JNI_BASE/include $$JNI_BASE/include/$$OS_NAME

# On Mac OS, Java should be linked as a framework instead of a library.
# else (on windows and unix), the jvm is a normal (dynamic) library

macx:  LIBS += -framework JavaVM
else:  LIBS += -L$$JNI_BASE/lib -ljvm

INCLUDEPATH += $$JNI_HEADERS
DEPENDPATH  += $$JNI_HEADERS
