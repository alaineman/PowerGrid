#------------------------------------------------
#
# Global qmake project file for PowerGrid.
#
# This project file includes and builds each
# subproject and links all modules together.
#
#------------------------------------------------

TEMPLATE = subdirs


#------------------------------------------------
# We need the projects to be ordered to prevent
# dependancy loops.
#------------------------------------------------

CONFIG += ordered

SUBDIRS += \
    JNIModule \
    world \
    Cachemodule \
    Injectionmodule \
    GUImodule \
#    Monitormodule \
#    AImodule \
