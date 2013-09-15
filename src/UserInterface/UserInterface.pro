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

debug: TARGET = PowerGrid-Debug
else : TARGET = PowerGrid-Release

include (../global_def.pro)

win32 {
    QMAKE_POST_LINK = copy $$PROJECT_ROOT/loader/dist/*.jar $$INSTALL_DIR
}

# Temporary files are placed in the "tmp" folder
OBJECTS_DIR = tmp
MOC_DIR     = tmp

win32:     RC_FILE = powergrid.rc
else:macx: ICON    = powergrid.icns

#------------------------------------------------
# The files in this project
#------------------------------------------------
SOURCES     = main.cpp
HEADERS     =
FORMS       =
RESOURCES   = resources.qrc
OTHER_FILES = powergrid.rc powergrid.icns

# Depends for Javabridge
LIBS += -lJavabridge -lJACE

INCLUDEPATH += $$PWD/../Javabridge
DEPENDPATH += $$PWD/../Javabridge

INCLUDEPATH += $$PWD/../JACE
DEPENDPATH  += $$PWD/../JACE
