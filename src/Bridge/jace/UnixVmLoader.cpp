
#include "jace/UnixVmLoader.h"

#if defined(Q_OS_UNIX) && !defined(Q_OS_MACX)

namespace jace {

UnixVmLoader::UnixVmLoader( QString path_, jint jniVersion ) :
  ver(jniVersion), path( path_ ) {
}

QString UnixVmLoader::getJVMPath() throw(JNIException) {
    if (path.isEmpty()) {
        QByteArray javaHomeBytes = qgetenv("JAVA_HOME");
        QString javaHome = QString::fromLocal8Bit(javaHomeBytes.constData());
        QDir dir (javaHome);
        QDirIterator it (dir, QDir::NoSymLinks | QDir::Files,
                         QDirIterator::Subdirectories);
        while (it.hasNext()) {
            QString entry = it.next();
            if (entry.endsWith("libjvm.so")) {
                path = entry;
                return path;
            }
        }
        // Still not found, so we throw an exception
        throw JNIException("Cannot find libjvm.so in JAVA_HOME path");
    } else {
        return path;
    }
}

jint UnixVmLoader::createJavaVM( JavaVM **pvm, void **env, void *args ) {
    loadVm();
    if (!fn_createJavaVM) {
        return JNI_ERR;
    } else {
        return fn_createJavaVM( pvm, env, args );
    }
}

jint UnixVmLoader::getCreatedJavaVMs( JavaVM **vmBuf, jsize bufLen, jsize *nVMs ) {
    loadVm();
    if (!fn_getCreatedJavaVMs) {
        return JNI_ERR;
    } else {
        return fn_getCreatedJavaVMs(vmBuf, bufLen, nVMs);
    }
}

void UnixVmLoader::loadVm() throw(JNIException) {
    if (jvmLib.isLoaded()) {
        return;
    }
    QString p = getJVMPath();
    jvmLib.setFileName(p);
    if (jvmLib.load()) {
        fn_createJavaVM = (CreateJavaVMFunc) jvmLib.resolve("JNI_CreateJavaVM");
        if (!fn_createJavaVM) {
            throw JNIException("Cannot resolve \"JNI_CreateJavaVM\" function");
        }
        fn_getCreatedJavaVMs = (GetCreatedJavaVMsFunc) jvmLib.resolve("JNI_GetCreatedJavaVMs");
        if (!fn_getCreatedJavaVMs) {
            throw JNIException("Cannot resolve \"JNI_GetCreatedJavaVMs\" function");
        }
    } else {
        throw JNIException("Cannot load JVM library: " + jvmLib.errorString());
    }
}


void UnixVmLoader::unloadVm() {
  if (jvmLib.isLoaded()) {
      fn_createJavaVM = NULL;
      fn_getCreatedJavaVMs = NULL;
      jvmLib.unload();
  }
}

VmLoader* UnixVmLoader::clone() const {
    return new UnixVmLoader(path, ver);
}

jint UnixVmLoader::version() {
  return ver;
}

}

#endif // JACE_GENERIC_UNIX

