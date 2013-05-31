#-------------------------------------------------
#
# This project contains the Injection code that
# injects event objects into the Runescape
# environment
#
#-------------------------------------------------

#------------------------------------------------
# Basic properties of the project itself
#------------------------------------------------
QT          = core

TARGET      = Injectionmodule
TEMPLATE    = lib
CONFIG     += staticlib

DESTDIR     = build/
OBJECTS_DIR = build/

#------------------------------------------------
# The files in this project
#------------------------------------------------
SOURCES     =
HEADERS     =

#------------------------------------------------
# The subprojects this project depends on
#------------------------------------------------
include (../JNIModule/includeJNI.pro)
