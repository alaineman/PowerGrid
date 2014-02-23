#include <QtGlobal>

#ifdef Q_OS_WIN32

#include "Win32VmLoader.h"
using ::jace::VmLoader;
using ::jace::Win32VmLoader;
using ::jace::JNIException;

#include <windows.h>

#include <string>
using std::string;
using std::to_string;

#include <iostream>
using std::cout;
using std::endl;

namespace {

/**
   * Windows helper for querying the registry values related to the various JVM installations
   */
std::string getRegistryValue(const std::string& regPath, const std::string& regValue, LPDWORD dataSize) {
    LONG result;
    HKEY regKeyHnd;
    result = RegOpenKeyExA(
                HKEY_LOCAL_MACHINE,
                regPath.c_str(),
                0,
                KEY_READ,
                &regKeyHnd
    );
    if (result != ERROR_SUCCESS) {
        throw JNIException(std::string("Registry Open Error (") + regPath + "): " + to_string(result));
    }
    char buf [*dataSize];
    DWORD valueType = REG_SZ;
    result = RegQueryValueExA(
                regKeyHnd,
                regValue.c_str(),
                NULL,
                (LPDWORD)&valueType,
                (LPBYTE)buf,
                dataSize
    );
    if (result != ERROR_SUCCESS) {
        std::string msg ("Registry Query Error (");
        msg = msg + regPath + "\\" + regValue + "): ";
        switch (result) {
            case ERROR_MORE_DATA:
                throw JNIException(msg + "Buffer not large enough");
            case ERROR_FILE_NOT_FOUND:
                throw JNIException(msg + "Registry value not found");
            default:
                throw JNIException(msg + to_string(result));
        }
    }

    result = RegCloseKey(regKeyHnd);
    if (result == ERROR_SUCCESS) {
        std::string retValue (reinterpret_cast<char*>(buf), *dataSize);
        return retValue;
    }
    throw JNIException(std::string("Registry Close Error (") + regPath + "\\" + regValue + "): " + to_string(result));
}

}

namespace jace {

/*!
 * \class jace::Win32VmLoader
 * \brief A Virtual Machine loader for Windows.
 *
 * This loader makes use of keys in the Windows registry to find and
 * load a JVM dynamically.
 *
 * Note that this loader currently only supports the Oracle JVM
 * (previously the Sun JVM).
 *
 * \author Toby Reyelts; modified by Patrick Kramer
 */

/*!
 * \brief Creates a new VM loader for the specified VM.
 *
 * The VM to be loaded is selected by vendor, type and version parameters.
 *
 * \param version Version of the VM as String (e.g. "1.3.1", "1.4")
 *        The default value is the version of the lastest Sun VM installed.
 *
 * \param jniVersion The version of JNI to use. For example,
 * JNI_VERSION_1_2 or JNI_VERSION_1_4. The default is JNI_VERSION_1_6.
 *
 * \throws JNIException if an error occurs while trying to look up the VM.
 */
Win32VmLoader::Win32VmLoader(std::string version, jint jniVer) :
    jniVersion( jniVer ), jvmVersion(version), path(), handle( 0 )   {

    getCreatedJavaVMsPtr = 0;
    createJavaVMPtr = 0;

    specifyVm();
}
/*!
 * \brief Creates a new VM loader that uses the VM located at the given path.
 * \param jniVersion the JNI version of the provided VM
 * \param path the path to the JVM library
 */
Win32VmLoader::Win32VmLoader(jint version, std::string path) :
    jniVersion( version ), jvmVersion("unknown"), path( path ), handle (0) {

    getCreatedJavaVMsPtr = 0;
    createJavaVMPtr = 0;

}
/*!
 * \brief Loads the Java VM
 * \throws jace::JNIException if loading the JVM failed.
 */
void Win32VmLoader::loadVm() throw ( JNIException ) {
    loadVm( path );
}
/*!
 * \brief Unloads the JVM
 * After the JVM is unloaded, it is no longer safe to use.
 * Depending on the state and version of the Java VM, it may or may not
 * shut down immediately after this call.
 */
void Win32VmLoader::unloadVm() {
    if ( handle ) {
        FreeLibrary( handle );
        handle = 0;
    }
}
/*!
 * Method to specify a VM and initialize the VM entry points.
 * The VM to be loaded could be selected by vendor, type and version parameters
 *
 * \throws JNIException if an error occurs while trying to look up the VM.
 */
void Win32VmLoader::specifyVm() throw (JNIException) {
    DWORD size;
    if (jvmVersion.length() == 0) {
        try {
            size = 16;
            jvmVersion = getRegistryValue("SOFTWARE\\JavaSoft\\Java Runtime Environment", "CurrentVersion", &size);
        } catch (JNIException& e) {
            throw JNIException(std::string("Missing default JVM version: ") + e.what());
        }
    }
    try {
        size = 256;
        path = getRegistryValue("SOFTWARE\\JavaSoft\\Java Runtime Environment\\" + jvmVersion, "RuntimeLib", &size);
        std::cout << "Using JVM v" << jvmVersion.c_str() << " at " << path.c_str() << endl;
    } catch (JNIException& e) {
        throw JNIException(std::string("Missing RuntimeLib key for JVM version ") + jvmVersion + ": " + e.what());
    }
}
/*!
 * Loads the VM at the specified path.
 *
 * \throws JNIException if an error occurs while trying to load the VM.
 */
void Win32VmLoader::loadVm( const std::string &jvmPath ) throw ( JNIException ) {

    /* Load the Java VM DLL */
    if ( ( handle = LoadLibraryA( jvmPath.c_str() ) ) == 0 ) {
        throw JNIException( std::string( "Can't load JVM from " ) + jvmPath );
    }

    /* Now get the function addresses */
    getCreatedJavaVMsPtr = ( GetCreatedJavaVMs_t )GetProcAddress(handle, "JNI_GetCreatedJavaVMs");
    if ( ! getCreatedJavaVMsPtr ) {
        throw JNIException(std::string("Can't find JNI_GetCreatedJavaVMs in ") + jvmPath);
    }

    createJavaVMPtr = (CreateJavaVM_t) GetProcAddress(handle, "JNI_CreateJavaVM");
    if ( ! createJavaVMPtr ) {
        throw JNIException(std::string("Can't find JNI_CreateJavaVM in ") + jvmPath);
    }
}
/*!
 * \brief returns the JNI version used by this \c VmLoader
 * \return the JNI version, which is one of:
 *         JNI_VERSION_1_1, JNI_VERSION_1_2, JNI_VERSION_1_4, JNI_VERSION_1_6.
 */
jint Win32VmLoader::version() {
    return jniVersion;
}
/*!
 * \brief Creates a new JavaVM
 *
 * \param pvm a pointer to store the \c JavaVM in
 * \param env a pointer to store the accompanying \c JNIEnv
 * \param args a pointer to a JavaVMInitArgs struct with options.
 * \return JNI_OK if the operation succeeded, or a JNI error code otherwise.
 */
jint Win32VmLoader::createJavaVM( JavaVM **pvm, void **env, void *args ) {
    return createJavaVMPtr( pvm, env, args );
}
/*!
 * \brief provides access to all JavaVMs created by this loader.
 *
 * \param vmBuf a buffer to store the JavaVM pointers in
 * \param bufLen the length of the provided buffer
 * \param nVMs the number of JavaVMs stored in \c vmBuf
 * \return JNI_OK if the operation succeeded, or a JNI error code otherwise.
 */
jint Win32VmLoader::getCreatedJavaVMs( JavaVM **vmBuf, jsize bufLen, jsize *nVMs ) {
    return getCreatedJavaVMsPtr( vmBuf, bufLen, nVMs );
}
/*!
 * \brief Returns a copy of this \c VmLoader
 */
VmLoader* Win32VmLoader::clone() const {
    return new Win32VmLoader( jniVersion, path );
}

}
#endif // _WIN32

