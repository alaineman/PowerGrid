#ifndef JACE_MACVMLOADER_H
#define JACE_MACVMLOADER_H

#include <QtCore>

// This header only makes sense to use on Mac OS X, so we disable the entire class
// on other platforms to prevent problems.
#ifdef Q_OS_MACX

#include "VmLoader.h"
#include "JNIException.h"

namespace jace {

/**
 * \brief JVM Loader class for Mac OS X.
 *
 * This locates the JVM using the \c java_home tool (located at
 * /usr/libexec/java_home) and then loads the dynamic library at
 * jre/lib/server/libjvm.dylib
 */
class MacVmLoader : public VmLoader {
private:
    typedef jint (*CreateJavaVMFunc)(JavaVM**,void**,void*);
    typedef jint (*GetCreatedJavaVMsFunc)(JavaVM**,jsize,jsize*);

    jint ver;      ///< The JNI version used for loading the VM.
    QString path;  ///< The path to the libJVM dynamic library
    QLibrary jvmLib; ///< The QLibrary object representing the (loaded) library
    CreateJavaVMFunc fn_createJavaVM; ///< The pointer to the JNI_CreateJavaVM function
    GetCreatedJavaVMsFunc fn_getCreatedJavaVMs; ///< The pointer to the JNI_GetCreatedJavaVMs function
public:
    /**
     * \brief Creates a new MacVmLoader instance.
     * \param path the path to libJVM. If empty, the path is detected from the OS.
     * \param version the JNI version to use. Default (and recommended) is \c JNI_VERSION_1_6.
     */
    MacVmLoader(QString path = QString(), jint version=JNI_VERSION_1_6);
    ~MacVmLoader() {}

    /**
     * \brief Returns the path to the JVM library.
     *
     * If the path is not currently known, it is first retrieved using
     * Apple's java_home tool.
     *
     * \throws JNIException when the path cannot be retrieved.
     */
    JACE_API QString getJVMPath() throw (JNIException);

    /**
     * \brief Loads the Virtual Machine library.
     *
     * The JVM library is located using \c getJVMPath(), and then
     * the library at the resulting path is loaded.
     */
    JACE_API void loadVm() throw (JNIException);

    /**
     * \brief Unloads the Virtual Machine library.
     */
    JACE_API void unloadVm();

    /**
     * \brief Returns the JNI version used by this loader's VM.
     */
    JACE_API jint version();

    /**
     * \brief Creates and returns a clone of this VmLoader.
     */
    JACE_API VmLoader* clone() const;

    /**
     * \brief Creates a Java VM with the specified arguments.
     *
     * This redirects to a call to JNI_CreateJavaVM in the loaded library.
     */
    JACE_API jint createJavaVM(JavaVM **pvm, void **env, void *args);

    /**
     * \brief Retrieves all created Java VMs.
     *
     * This redirects to a call to JNI_GetCreatedJavaVMs.
     */
    JACE_API jint getCreatedJavaVMs(JavaVM **vmBuf, jsize bufLen, jsize *nVms);
};

} // namespace jace

#endif // Q_OS_MACX

#endif // JACE_MACVMLOADER_H
