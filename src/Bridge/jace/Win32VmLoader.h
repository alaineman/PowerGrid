#ifndef JACE_WIN32_VM_LOADER
#define JACE_WIN32_VM_LOADER

#include <QtGlobal>
#include "jace/os_dep.h"

#ifdef Q_OS_WIN32

#include "jace/JNIException.h"
#include "jace/VmLoader.h"

#include <jni.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
#endif

#include <windows.h>

#include <string>

Q_DECLARE_LOGGING_CATEGORY(logLauncher)

namespace jace {

/**
 * @brief Java Virtual Machine loader for Windows.
 *
 * This VmLoader makes use of keys in the Windows registry to find and load a
 * JVM dynamically. Note that this VmLoader only supports the Oracle JVM
 * (previously known as the Sun JVM).
 *
 * \author Toby Reyelts (original); Patrick Kramer (modifications)
 */
class Win32VmLoader : public VmLoader {
public:
    /**
     * @brief Creates a new Win32VmLoader.
     * @param version    - The version of the JVM to load. Default is the newest version.
     * @param jniVersion - The JNI version to use. Default is JNI_VERSION_1_6
     *
     * @throws JNIException when looking up the JVM failed, or if no JVM with the provided
     *         version is installed on the system.
     */
    Win32VmLoader(std::string version = "", jint jniVersion = JNI_VERSION_1_6 );

    /**
     * @brief Creates a new Win32VmLoader.
     * @param jniVersion - the JNI version to use. Version 1.6 is recommended.
     * @param path       - the path to the jvm.dll library.
     */
    Win32VmLoader(jint jniVersion, std::string path);
    virtual ~Win32VmLoader() {}

    /**
     * @brief Loads the Java VM.
     * @throws JNIException if loading the JVM failed.
     */
    void loadVm() throw ( ::jace::JNIException );
    /**
     * @brief Unloads the Java VM.
     * After the JVM is unloaded, it should no longer be used. Depending on the JVM
     * implementation, it may or may not shut down immediately after this call.
     */
    void unloadVm();
    /**
     * @brief Creates and returns a copy of this VmLoader instance
     * @return a copy of this VmLoader instance
     */
    jace::VmLoader* clone() const;
    /**
     * @brief Returns the JNI version used for this VmLoader.
     */
    virtual jint version();

    // These functions delegate to the JVM library functions with the same name
    // and signature.
    jint getCreatedJavaVMs( JavaVM **vmBuf, jsize bufLen, jsize *nVMs );
    jint createJavaVM( JavaVM **pvm, void **env, void *args );
private:
    jint jniVersion;
    std::string jvmVersion;

    typedef jint (JNICALL *GetCreatedJavaVMs_t)(JavaVM **vmBuf, jsize bufLen, jsize *nVMs);
    typedef jint (JNICALL *CreateJavaVM_t)(JavaVM **pvm, void **env, void *args);

    GetCreatedJavaVMs_t getCreatedJavaVMsPtr;
    CreateJavaVM_t createJavaVMPtr;

    std::string path;
    HINSTANCE handle;

    /**
     * @brief Tries to find a JVM based on a previously set version string.
     * @throws JNIException if no JVM could be found.
     */
    void specifyVm() throw (JNIException);
    /**
     * @brief Loads the JVM at the provided path.
     * @param path - the path to load the JVM from
     * @throws JNIException if the JVM could not be loaded
     */
    void loadVm( const std::string& path ) throw ( JNIException );
    /**
     * @brief Returns the version of the Java Runtime, as a std::string.
     */
    std::string getJVMVersion() const { return jvmVersion; }
};

}

#endif // JACE_WIN32_VM_LOADER

#endif // _WIN32


