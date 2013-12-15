#-------------------------------------------------
#
# Project created by QtCreator 2013-12-14T23:40:33
#
#-------------------------------------------------

QT       -= gui
CONFIG   += plugin
TARGET    = $$qtLibraryTarget(DefaultPlugin)
TEMPLATE  = lib
DESTDIR   = ../plugins

INCLUDEPATH += ../PluginFramework

DEFINES += DEFAULTPLUGIN_LIBRARY

SOURCES += defaultplugin.cpp

HEADERS += defaultplugin.h\
        defaultplugin_global.h
