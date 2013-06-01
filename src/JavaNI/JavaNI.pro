#------------------------------------------------
#
# Include .pro file for the JNI headers
#
#------------------------------------------------

# Set the base directory for JNI iff it was not already set (overwritten)
isEmpty(JNI_BASE): JNI_BASE = $$PWD/../../External/JNI

# Find the appropriate OS name for the platform-dependent include.
win32:      OS_NAME     = win32
else:unix:  OS_NAME     = unix
else:macx:  OS_NAME     = darwin
else:       error ("Unsupported OS")

# verify the directories and files exist and give an error when it doesn't
# this prevents vague include or linking errors and instead simply states the cause.
!exists($$JNI_BASE/include):           error("Missing JNI header directory")
!exists($$JNI_BASE/include/$$OS_NAME): error("Target OS has no platform-dependent JNI headers")
!exists($$JNI_BASE/lib):               error("Missing JNI lib directory")
macx {} # Mac OS has the JavaVM framework built-in and as such needs no additional files.
else: win32 {
    # On windows, verify the dll and lib file exist for linking.
    !exists($$JNI_BASE/lib/jvm.dll):   error("(Windows) Missing jvm.dll")
    !exists($$JNI_BASE/lib/jvm.lib):   error("(Windows) Missing jvm.lib")
}
else: unix {
    # On Unix, verify the .so file exists for linking
    !exists($$JNI_BASE/lib/libjvm.so): error("(Unix) Missing libjvm.so")
}

JNI_HEADERS = $$JNI_BASE/include $$JNI_BASE/include/$$OS_NAME

# On Mac OS, Java should be linked as a framework instead of a library.
# else (on windows and unix), the jvm is a normal (dynamic) library

macx:  LIBS += -framework JavaVM
else:  LIBS += -L$$JNI_BASE/lib -ljvm

INCLUDEPATH += $$JNI_HEADERS
DEPENDPATH  += $$JNI_HEADERS
