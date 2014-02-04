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
# common .pri file for Qt Unit Tests.
#------------------------------------------------------------------------
QT       = core testlib  # Adds support for QTest library
TEMPLATE = app           # Tests are executable
CONFIG  += testcase      # Adds unit test to "make check" target
CONFIG  += console       # Behaves as a console application on Windows
CONFIG  -= app_bundle    # Should not build an app bundle on Mac OS
