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
# This project contains the caches that are used
# to store data from the Runescape environment.
#
#-------------------------------------------------

#------------------------------------------------
# Basic properties of the project itself
#------------------------------------------------
QT          = core

TARGET      = Cachemodule
TEMPLATE    = lib
CONFIG     += staticlib

DESTDIR     = build/
OBJECTS_DIR = build/

#------------------------------------------------
# The files in this project
#------------------------------------------------
SOURCES     = worlddata.cpp sector.cpp basecomponent.cpp
HEADERS     = worlddata.h   sector.h   basecomponent.h

#------------------------------------------------
# The subprojects this project depends on
#------------------------------------------------
include (../JNIModule/includeJNI.pro)
include (../world/includeWorld.pro)
