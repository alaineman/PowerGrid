#-------------------------------------------------
#
# Project created by QtCreator 2014-04-30T21:00:47
#
#-------------------------------------------------

QT       -= gui

TARGET = TestPlugin
TEMPLATE = lib
CONFIG  += plugin shared c++11

DEFINES += TESTPLUGIN_LIBRARY

SOURCES += testplugin.cpp \
    dummytaskdescriptor.cpp \
    dummyclassifier.cpp

HEADERS += testplugin.h\
        testplugin_global.h \
    dummytaskdescriptor.h \
    dummyclassifier.h

OTHER_FILES += testplugin.json

DESTDIR = $PWD/../../dist/plugins

unix {
    target.path = /usr/lib
    INSTALLS += target
}

# Link against the Plugin Framework
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../PluginFramework/release/ -lPluginFramework
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../PluginFramework/debug/ -lPluginFramework
else:unix: LIBS += -L$$OUT_PWD/../PluginFramework/ -lPluginFramework

INCLUDEPATH += $$PWD/../PluginFramework
DEPENDPATH  += $$PWD/../PluginFramework

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../PluginFramework/release/libPluginFramework.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../PluginFramework/debug/libPluginFramework.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../PluginFramework/release/PluginFramework.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../PluginFramework/debug/PluginFramework.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../PluginFramework/libPluginFramework.a

# Link against the Bridge
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
