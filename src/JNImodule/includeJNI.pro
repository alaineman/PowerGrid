#------------------------------------------------
#
# Include project file for the JNI module.
#
# Include this file into other .pro files that
# depend on the JNImodule project.
#
#------------------------------------------------

INCLUDEPATH    += $$PWD/../JNIModule
DEPENDPATH     += $$PWD/../JNIModule

LIBS           += $$OUT_PWD/../JNIModule/build/libJNIModule.a
PRE_TARGETDEPS += $$OUT_PWD/../JNIModule/build/libJNIModule.a

include (../JavaNI/JavaNI.pro)
