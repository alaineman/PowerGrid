#-------------------------------------------------
#
# Project created by QtCreator 2013-05-14T10:55:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET   = PowerGrid
TEMPLATE = app

SOURCES  += main.cpp\
            mainwindow.cpp \
        jni/javaenv.cpp \
    jni/jnimethod.cpp \
    jni/jnielement.cpp

HEADERS  += mainwindow.h \
        jni/javaenv.h \
            stdafx.h \
    jni/jnimethod.h \
    jni/jnielement.h \
    JNIConnection

FORMS    += mainwindow.ui

# Add the JVM library as a dependancy

INCLUDEPATH += $$PWD/../External/JNI/include
DEPENDPATH += $$PWD/../External/JNI/include

# Win32 specific headers for JNI
win32 {
    INCLUDEPATH += $$PWD/../External/JNI/include/win32
    DEPENDPATH += $$PWD/../External/JNI/include/win32

    LIBS += -L$$PWD/../External/JNI/lib -ljvm
}

# Mac  specific headers for JNI
macx {
    INCLUDEPATH += $$PWD/../External/JNI/include/darwin
    DEPENDPATH += $$PWD/../External/JNI/include/darwin

    LIBS += -F$$PWD/../External/JNI/lib -framework jvm
}

RESOURCES += \
    resources.qrc
