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
# Include project file for the world subproject.
#
# Include this file into other .pro files that
# depend on the world project.
#
#------------------------------------------------

INCLUDEPATH    += $$PWD/../world
DEPENDPATH     += $$PWD/../world

LIBS           += $$OUT_PWD/../world/build/libworld.a
PRE_TARGETDEPS += $$OUT_PWD/../world/build/libworld.a
