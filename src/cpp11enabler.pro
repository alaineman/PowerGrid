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
# This project file adds platform and compiler specific flags to enable
# C++11 support. If your compiler is not listed, please add the
# appropriate flags for your compiler to enable C++11 features.
#------------------------------------------------------------------------

# The platform-compiler name is the filename (without path) that the
# message below reports. It can be used for identification
message(QMake Spec: $$QMAKESPEC)

macx-clang {
    # Clang has its own c++ library optimized for the Clang compiler (libc++).
    # We prefer using that library over the standard one (libstdc++)
    QMAKE_CXXFLAGS += -stdlib=libc++ -std=c++11

    message(Compiling using clang compiler on Mac OS X)
}
else:win32-g++ {
    # GCC compiler version 4.3 and above use the C++11 standard when the standard is
    # declared as c++0x. In contrast, c++11 only works on GCC version 4.7 and higher.
    # We use gnu++0x to enable GNU specific extensions in addition to the C++11 standard.
    QMAKE_CXXFLAGS += -std=gnu++0x

    message(Compiling using g++ compiler on Windows)
}
# Add additional compiler definitions here as needed
else {
    # We have no specific information. We assume -std=c++0x works (like for GCC).
    # However, we also provide a warning that specific compiler flags are not
    # available, so that they can be added when required.
    QMAKE_CXXFLAGS += -std=c++0x
    warning(No specific compiler flags available. Please add compiler flags specific to your compiler.)
}


