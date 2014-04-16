#ifndef JACE_UNIX_VM_LOADER
#define JACE_UNIX_VM_LOADER

#include <QtGlobal>

// Only use this class for generic Unix.
// (do not use for Mac OS X, see MacVmLoader class).
#if defined(Q_OS_UNIX) && !defined(Q_OS_MACX)
#include "jni.h"
#include "jace/VmLoader.h"
#include "jace/JNIException.h"

namespace jace {

/**
 * A generic Virtual Machine loader for Unix based operating systems.
 * This simple loader should work fine on most Unices.
 *
 * @author Toby Reyelts   (original)
 * @author Patrick Kramer (use of Qt and JAVE_HOME environment variable)
 */
class UnixVmLoader : public VmLoader {
private:
    jint ver;
    QString path;
    typedef jint (*CreateJavaVMFunc)(JavaVM**,void**,void*);
    typedef jint (*GetCreatedJavaVMsFunc)(JavaVM**,jsize,jsize*);
    QLibrary jvmLib;
    CreateJavaVMFunc fn_createJavaVM;
    GetCreatedJavaVMsFunc fn_getCreatedJavaVMs;
public:    
    /**
     * Creates a new VM loader for the specified VM.
     * The VM to be loaded is specified by the path to the shared library.
     *
     * @param path The path to the shared library implementing the VM.
     *
     * @param jniVersion The version of JNI to use. Default is \c JNI_VERSION_1_6.
     *
     */
    UnixVmLoader( QString path_ = QString(), jint jniVersion = JNI_VERSION_1_6);

    /**
     * @brief Finds the path to the JVM library.
     * @return the detected jvm library path
     * @throws JNIException if the path cannot be found
     */
    QString getJVMPath() throw(JNIException);

    void loadVm() throw(JNIException);
    void unloadVm();
    jint createJavaVM( JavaVM **pvm, void **env, void *args );
    jint getCreatedJavaVMs( JavaVM **vmBuf, jsize bufLen, jsize *nVMs );
    VmLoader* clone() const;
    jint version();
};

}

#endif // Q_OS_UNIX && !Q_OS_MACX

#endif // JACE_UNIX_VM_LOADER

