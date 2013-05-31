#------------------------------------------------
#
# .pro file for the world representation.
#
# The classes in this subproject all represent
# objects from the Runescape environment.
#
#------------------------------------------------

QT       -= gui

TARGET = world
TEMPLATE = lib
CONFIG += staticlib

DESTDIR = build/
OBJECTS_DIR = build/

SOURCES +=

HEADERS += \
    widget.h \
    point.h

OTHER_FILES += \
    includeWorld.pro
