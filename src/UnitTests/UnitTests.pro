#-------------------------------------------------
#
# Subproject containing all Unit tests for
# PowerGrid.
#
#-------------------------------------------------

TEMPLATE = app

QT += testlib

TARGET    = UnitTests
CONFIG   += console

SOURCES += main.cpp \
    tests/MyTestSuite.cpp

HEADERS += \
    tests/MyTestSuite.h
