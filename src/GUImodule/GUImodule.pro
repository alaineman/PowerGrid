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
QT          = core gui widgets

TARGET      = PowerGrid
TEMPLATE    = app

DESTDIR     = build/
OBJECTS_DIR = build/

win32:     RC_FILE = powergrid.rc
else:macx {
  ICON    = images/PowerGrid.icns
  QMAKE_INFO_PLIST = PowerGrid.plists
}

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
