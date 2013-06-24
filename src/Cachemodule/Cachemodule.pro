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
