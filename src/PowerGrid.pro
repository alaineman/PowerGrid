#-------------------------------------------------
#
# Project created by QtCreator 2013-05-14T10:55:56
#
#-------------------------------------------------

QT       += core gui widgets

win32: QMAKE_CXXFLAGS += -std=c++11
# Apple's Clang compiler does not recognize the -std=c++11 flag, but instead uses -std=c++0x
macx {
  QMAKE_CXXFLAGS += -stdlib=libc++ -std=c++0x
}
TARGET   = PowerGrid
TEMPLATE = app

SOURCES  += main.cpp\
            mainwindow.cpp \
        jni/javaenv.cpp \
    jni/jnimethod.cpp \
    jni/jnielement.cpp \
    jni/jnivalue.cpp \
    jni/ongoinginvocation.cpp \
    cache/worlddata.cpp \
    cache/sector.cpp \
    cache/collisionmap.cpp \
    cache/stringmap.cpp \
    world/point.cpp

HEADERS  += mainwindow.h \
        jni/javaenv.h \
            stdafx.h \
    jni/jnimethod.h \
    jni/jnielement.h \
    JNIConnection \
    jni/ongoinginvocation.h \
    jni/jnivalue.h \
    cache/worlddata.h \
    cache/sector.h \
    cache/collisionmap.h \
    cache/stringmap.h \
    world/point.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc


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

    LIBS += -framework JavaVM
}


