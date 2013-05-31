#------------------------------------------------
#
# This project contains the GUI, and statically
# links to the other subprojects.
#
#------------------------------------------------

#------------------------------------------------
# Basic properties of the project itself
#------------------------------------------------
QT          = core gui widgets

TARGET      = PowerGrid
TEMPLATE    = app

DESTDIR     = build/
OBJECTS_DIR = build/

#------------------------------------------------
# The files in this project
#------------------------------------------------
SOURCES     = main.cpp \
              mainwindow.cpp
HEADERS     = mainwindow.h
FORMS       = mainwindow.ui
RESOURCES   = resources.qrc
OTHER_FILES = powergrid.rc

#------------------------------------------------
# The subprojects this project depends on
#------------------------------------------------
include (../JNIModule/includeJNI.pro)
