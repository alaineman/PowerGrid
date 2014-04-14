#include "macvmloader.h"
#include <QtGlobal>

#ifdef Q_OS_MACX

namespace jace {

MacVmLoader::MacVmLoader(QString path) :
    version(0), path(path) {
}


QString MacVmLoader::getJVMPath() throw (JNIException) {
    if (path.isEmpty()) {
        // TODO: Call /usr/libexec/java_home
        //       Add "jre/lib/server/libjvm.dylib"
        //       store in "path" variable.
        //       throw JNIException upon failure.
    }
    return path;
}

void MacVmLoader::loadVm() throw (JNIException) {
    QString p = getJVMPath();
    // TODO load library at "p"
    //      throw JNIException upon failure
}

void MacVmLoader::unloadVm() {
    // TODO unload library at "path" if loaded
}

VmLoader* MacVmLoader::clone() const {
    return new MacVmLoader(path);
}

jint MacVmLoader::createJavaVM(JavaVM **pvm, void **env, void *args) {
    // TODO Call JNI_CreateJavaVM in the loaded library
}

jint MacVmLoader::getCreatedJavaVMs(JavaVM **vmBuf, jsize bufLen, jsize *nVms) {
    // TODO Call JNI_GetCreatedJavaVMs in the loaded library.
}

} // namespace jace

#endif // Q_OS_MACX
