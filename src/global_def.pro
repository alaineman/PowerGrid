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

#------------------------------------------------------------------------
# This project file adds specific configuration settings to the QMake
# parameters, so that each subproject of PowerGrid is built the same way.
#
# Platform and compiler specific flags are added to enable
# C++11 support. Also, a couple of variables are set to values relevant
# specifically to the PowerGrid project.
#------------------------------------------------------------------------

#------------------------------------------------------------------------
# Environment flags
#------------------------------------------------------------------------

# root of the PowerGrid repository.
# It can be used to easily define paths relative to the repository
PROJECT_ROOT = $$PWD/..

# Important directories are stored in variables here to allow easy moving
# without needing to edit all .pro files to fix paths.
BUILD_DIR  = $$PROJECT_ROOT/build
SOURCE_DIR = $$PROJECT_ROOT/src
DIST_DIR   = $$PROJECT_ROOT/dist
DOC_DIR    = $$PROJECT_ROOT/doc
LOADER_DIR = $$PROJECT_ROOT/loader
LIB_DIR    = $$PROJECT_ROOT/lib

# All intermediate build targets should go into build/[Debug|Release]/
# The subproject root build path is $$TARGET_DIR/<project_name>
debug: TARGET_DIR = $$BUILD_DIR/Debug
else:  TARGET_DIR = $$BUILD_DIR/Release

# Configure the project settings using previously set QMAKE variables
# The TARGET variable should be set before this file is included
target.path = $$TARGET_DIR/$$TARGET
INSTALLS += target

DESTDIR = $$TARGET_DIR

OBJECTS_DIR = $$TARGET_DIR/$$TARGET/
MOC_DIR     = $$OBJECTS_DIR


# Compiler/Platform specific flags and settings

# These settings should set the best flags for the used platform / compiler.
# They should enable the C++11 standard and possibly any compiler-specific enhancements
macx {
    macx-clang {
        # pthreads are required for JACE, but clang has trouble supporting them
        QMAKE_CXXFLAGS += -stdlib=libc++ -std=c++11
    } else {
        warning ( Unknown compiler. Add Compiler flags as needed to global_def.pro )
    }
}
else:win32 {
    win32-g++ {
        QMAKE_CXXFLAGS += -std=gnu++0x
    } else {
        warning ( Unknown compiler. Add Compiler flags as needed to global_def.pro )
    }
}
else {
    warning ( Unsupported platform )
}

