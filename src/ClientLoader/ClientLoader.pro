#-------------------------------------------------
#
# Project created by QtCreator 2015-02-24T18:35:10
#
#-------------------------------------------------

QT       -= gui

TARGET = ClientLoader
TEMPLATE = lib
CONFIG += staticlib

SOURCES += ClientLoader.cpp \
    JVMLoader.cpp

HEADERS += ClientLoader.h \
    JVMLoader.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

# Include the Bridge subproject
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Bridge/release/ -lBridge
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Bridge/debug/ -lBridge
else:unix: LIBS += -L$$OUT_PWD/../Bridge/ -lBridge

INCLUDEPATH += $$PWD/../Bridge
DEPENDPATH += $$PWD/../Bridge

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Bridge/release/libBridge.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Bridge/debug/libBridge.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Bridge/release/Bridge.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Bridge/debug/Bridge.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Bridge/libBridge.a
