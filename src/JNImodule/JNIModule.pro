#------------------------------------------------
#
# .pro file for the JNI module.
#
# This module manages the connection with the
# running Java Virtual Machine and is therefore
# essential for starting Runescape. The JNI
# module then acts as a gateway between the rest
# of PowerGrid and Runescape.
#
#------------------------------------------------

#------------------------------------------------
# The JNI only needs the QtCore, not the QtGUI.
# Furthermore, The JNI module should be built as
# a static library with multi-threading support.
#------------------------------------------------

QT = core

TARGET = JNIModule
TEMPLATE = lib
CONFIG += staticlib

DESTDIR = build/
OBJECTS_DIR = build/


#------------------------------------------------
# All headers and source files to include
#------------------------------------------------

HEADERS += \
    jnivalue.h \
    jnistring.h \
    jniobject.h \
    jnimethod.h \
    jniexception.h \
    jniclass.h \
    javaenv.h \
    jnimodule.h \
    classmodelbuilder.h

SOURCES += \
    jnivalue.cpp \
    jnistring.cpp \
    jniobject.cpp \
    jnimethod.cpp \
    jniclass.cpp \
    javaenv.cpp \
    classmodelbuilder.cpp

OTHER_FILES = includeJNI.pro

#------------------------------------------------
# Add the dependency for jni
#------------------------------------------------
include (../JavaNI/JavaNI.pro)

