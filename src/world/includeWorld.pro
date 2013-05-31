#------------------------------------------------
#
# Include project file for the world subproject.
#
# Include this file into other .pro files that
# depend on the world project.
#
#------------------------------------------------

INCLUDEPATH    += $$PWD/../world
DEPENDPATH     += $$PWD/../world

LIBS           += $$OUT_PWD/../world/build/libworld.a
PRE_TARGETDEPS += $$OUT_PWD/../world/build/libworld.a
