
#ifdef _WIN32

#include "Win32VmLoader.h"
using ::jace::VmLoader;
using ::jace::Win32VmLoader;
using ::jace::JNIException;

#include <windows.h>

#include <string>
using std::string;

#include <QtCore>
#include <string>

namespace {
using std::to_string;
/**
   * Windows helper for querying the registry values related to the various JVM installations
   */
std::string getRegistryValue(const std::string& regPath, const std::string& regValue, LPDWORD dataSize) {
    LONG result;
    LPDWORD dataType = NULL;
    PHKEY regKeyHnd = NULL;
    result = RegOpenKeyExA(HKEY_LOCAL_MACHINE, regPath.c_str(), 0, KEY_QUERY_VALUE, regKeyHnd);
    if (result != ERROR_SUCCESS) {
        throw JNIException(std::string("Registry Open Error: ") + to_string(result));
    }
    PVOID buf = NULL;
    result = RegGetValueA(*regKeyHnd, "", regValue.c_str(),
                 RRF_RT_REG_SZ, dataType, buf, dataSize);
    RegCloseKey(*regKeyHnd);
    if (result == ERROR_SUCCESS) {
        std::string retValue (reinterpret_cast<char*>(buf), *dataSize);
        return retValue;
    }
    throw JNIException(std::string("Registry Query Error: ") + to_string(result));
}

}

namespace jace {

Win32VmLoader::Win32VmLoader(std::string version, jint jniVer) :
    jniVersion( jniVer ), jvmVersion(version), path(), handle( 0 )   {

    getCreatedJavaVMsPtr = 0;
    createJavaVMPtr = 0;

    specifyVm();
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
    if (jvmVersion.length() == 0) {
        try {
            DWORD size = 16;
            jvmVersion = getRegistryValue("SOFTWARE\\JavaSoft\\Java Runtime Environment", "CurrentVersion", &size);
        } catch (JNIException& e) {
            throw JNIException(std::string("Missing default JVM version: ") + e.what());
        }
    }
    try {
        DWORD size = 256;
        path = getRegistryValue("SOFTWARE\\JavaSoft\\Java Runtime Environment\\" + jvmVersion, "RuntimeLib", &size);
    } catch (JNIException& e) {
        throw JNIException(std::string("Missing RuntimeLib key for JVM version ") + jvmVersion + ": " + e.what());
    }
}

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

    createJavaVMPtr = (CreateJavaVM_t)GetProcAddress(handle, "JNI_CreateJavaVM");
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
    return new Win32VmLoader( jvmVersion, jniVersion );
}

}
#endif // _WIN32

