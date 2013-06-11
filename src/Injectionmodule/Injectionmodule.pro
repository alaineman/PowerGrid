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
SOURCES     = \
    mouse.cpp \
    keyboard.cpp
HEADERS     = \
    mouse.h \
    keyboard.h

#------------------------------------------------
# The subprojects this project depends on
#------------------------------------------------
include (../JNIModule/includeJNI.pro)

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../world/release/ -lworld
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../world/debug/ -lworld
else:unix: LIBS += -L$$OUT_PWD/../world/ -lworld

INCLUDEPATH += $$PWD/../world
DEPENDPATH += $$PWD/../world
