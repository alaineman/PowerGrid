#include <QtGlobal>

#ifdef Q_OS_WIN32

#include "Win32VmLoader.h"
using jace::VmLoader;
using jace::Win32VmLoader;
using jace::JNIException;

#include <QString>

using std::string;
using std::to_string;

namespace {

/**
 * Windows helper for querying the registry values related to the various JVM installations.
 *
 * @param regPath  - The path of the registry value to retrieve.
 * @param regValue - The name of the registry value to retrieve.
 * @param dataSize - An indication of the size of the registry contents.
 *
 * @throws jace::JNIException if an error occurs while reading from registry.
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

Win32VmLoader::Win32VmLoader(std::string version, jint jniVer) :
    jniVersion( jniVer ), jvmVersion(version), path(), handle( 0 )   {

    getCreatedJavaVMsPtr = 0;
    createJavaVMPtr = 0;

    specifyVm();
}

Win32VmLoader::Win32VmLoader(jint version, std::string path) :
    jniVersion( version ), jvmVersion("unknown"), path( path ), handle (0) {

    getCreatedJavaVMsPtr = 0;
    createJavaVMPtr = 0;

}

void Win32VmLoader::loadVm() throw ( JNIException ) {
    loadVm( path );
}

void Win32VmLoader::unloadVm() {
    if ( handle ) {
        FreeLibrary( handle );
        handle = 0;
    }
}

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
        qCDebug(logLauncher) << "Using JVM version" << jvmVersion.c_str() << "at" << path.c_str();
    } catch (JNIException& e) {
        throw JNIException(std::string("Missing RuntimeLib key for JVM version ") + jvmVersion + ": " + e.what());
    }
}

void Win32VmLoader::loadVm( const std::string &jvmPath ) throw ( JNIException ) {

    /* Load the Java VM DLL */
    if ( ( handle = LoadLibraryA( jvmPath.c_str() ) ) == 0 ) {
        throw JNIException( QString("Can't load JVM from ") % jvmPath.c_str() );
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

jint Win32VmLoader::version() {
    return jniVersion;
}

jint Win32VmLoader::createJavaVM( JavaVM **pvm, void **env, void *args ) {
    return createJavaVMPtr( pvm, env, args );
}

jint Win32VmLoader::getCreatedJavaVMs( JavaVM **vmBuf, jsize bufLen, jsize *nVMs ) {
    return getCreatedJavaVMsPtr( vmBuf, bufLen, nVMs );
}

VmLoader* Win32VmLoader::clone() const {
    return new Win32VmLoader( jniVersion, path );
}

}
#endif // _WIN32

