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
QT          = core gui
TEMPLATE    = app

win32:     RC_FILE = powergrid.rc
else:macx: ICON    = powergrid.icns

QMAKE_CXXFLAGS += -std=gnu++11

#------------------------------------------------
# The files in this project
#------------------------------------------------
SOURCES     = main.cpp
HEADERS     =
FORMS       =
RESOURCES   = resources.qrc
OTHER_FILES = powergrid.rc powergrid.icns

# Depends for JACE
LIBS += -L$$PWD/../../build/release/JACE/release -lJACE

INCLUDEPATH += $$PWD/../JACE
DEPENDPATH  += $$PWD/../JACE
