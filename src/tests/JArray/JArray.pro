#------------------------------------------------------------------------
# Copyright 2012-2014 Patrick Kramer, Vincent Wassenaar
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
#
# Note that the files contained in this project do NOT fall under the
# terms of the GNU General Public License, but instead fall under a
# different license as mentioned below. This .pro file does fall under the
# GNU General Public License.
#------------------------------------------------------------------------

#------------------------------------------------------------------------
# .pro file for the JACE library tests.
#
# This test suite tests the functionality added to JACE specifically
# for PowerGrid.
#------------------------------------------------------------------------
TARGET = tst_jace
include (../common.pri)

SOURCES += tst_jarraytest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

# Dependency for JACE
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../JACE/release/ -lJACE
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../JACE/debug/ -lJACE
else:unix: LIBS += -L$$OUT_PWD/../../JACE/ -lJACE

INCLUDEPATH += $$PWD/../../JACE
DEPENDPATH += $$PWD/../../JACE

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../JACE/release/libJACE.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../JACE/debug/libJACE.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../JACE/release/JACE.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../JACE/debug/JACE.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../JACE/libJACE.a
