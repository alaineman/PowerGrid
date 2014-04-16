#include "macvmloader.h"
#ifdef Q_OS_MACX

namespace jace {

MacVmLoader::MacVmLoader(QString path, jint version) :
    ver(version), path(path) {
}

QString MacVmLoader::getJVMPath() throw (JNIException) {
    if (path.isEmpty()) {
        QProcess proc;
        proc.start("/usr/libexec/java_home",QIODevice::ReadOnly);
        if (proc.waitForReadyRead()) {
            QByteArray pathBytes = proc.readAll();
            QString line = QString::fromLocal8Bit(pathBytes.constData());
            line.chop(1); // chop removes the '\n' at the end of the output.
            path = line + "/jre/lib/server/libjvm.dylib";
            proc.waitForFinished();
            if (! QFile::exists(path) ) {
                throw JNIException("libjvm.dylib not found at expected location: " + path);
            }
        } else {
            throw JNIException("java_home tool did not output path");
        }
    }
    return path;
}

void MacVmLoader::loadVm() throw (JNIException) {
    if (jvmLib.isLoaded()) {
        return;
    }
    QString p = getJVMPath();
    jvmLib.setFileName(p);
    if (!jvmLib.load()) {
        throw JNIException("Cannot load JVM library: " + jvmLib.errorString());
    } else {
        fn_createJavaVM      = (CreateJavaVMFunc) jvmLib.resolve("JNI_CreateJavaVM");
        if (!fn_createJavaVM) {
            throw JNIException("Could not find JNI_CreateJavaVM function");
        }
        fn_getCreatedJavaVMs = (GetCreatedJavaVMsFunc) jvmLib.resolve("JNI_GetCreatedJavaVMs");
        if (!fn_getCreatedJavaVMs) {
            throw JNIException("Could not find JNI_GetCreatedJavaVMs function");
        }
    }
}

void MacVmLoader::unloadVm() {
    if (jvmLib.isLoaded()) {
        fn_createJavaVM = NULL;
        fn_getCreatedJavaVMs = NULL;
        jvmLib.unload();
    }
}

jint MacVmLoader::version() {
    return ver;
}

VmLoader* MacVmLoader::clone() const {
    return new MacVmLoader(path, ver);
}

jint MacVmLoader::createJavaVM(JavaVM **pvm, void **env, void *args) {
    loadVm();
    if (fn_createJavaVM) {
        return fn_createJavaVM(pvm, env, args);
    }
    return JNI_ERR;
}

jint MacVmLoader::getCreatedJavaVMs(JavaVM **vmBuf, jsize bufLen, jsize *nVms) {
    loadVm();
    if (fn_getCreatedJavaVMs) {
        return fn_getCreatedJavaVMs(vmBuf, bufLen, nVms);
    }
    return JNI_ERR;
}

} // namespace jace

#endif // Q_OS_MACX
