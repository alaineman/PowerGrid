#include <jni.h>
#include "updaterrunner.h"
#include "rsclassmapper.h"
#include <QtCore>
#include "jace/namespace.h"
#include <string>

using jace::JNIException;

/**
 * This method parses the updater data downloaded by the Java client.
 * It is normally invoked from the JVM by the
 * net.pgrid.loader.bridge.UpdaterRunner class once it's ready.
 */
JNIEXPORT void JNICALL Java_net_pgrid_loader_bridge_UpdaterRunner_signalUpdaterReady
  (JNIEnv *, jobject, jstring) {
    RSClassMapper* mapper = RSClassMapper::DefaultInstance();
    if (mapper) {
        mapper->parseData();
    } else {
        qWarning() << "Cannot parse Updater data: mapper does not exist";
    }
}

BEGIN_NAMESPACE_2( bridge, updater )

/**
 * @brief Registers native methods for the net.pgrid.loader.bridge.UpdaterRunner class
 *
 * Note that calling this function more than once will result in undefined behavior in
 * the JNI.
 * @param env the JNIEnv* to register with
 */
void UpdaterRunner_registerNatives(JNIEnv* env)
        throw (JNIException) {
    // Find the Java class "net.pgrid.loader.bridge.UpdaterRunner
    jclass updaterRunner = env->FindClass("net/pgrid/loader/bridge/UpdaterRunner");
    if (! updaterRunner) {
        throw JNIException("Cannot find net.pgrid.loader.bridge.UpdaterRunner class");
    }
    // The JNINativeMethod struct we need to register
    JNINativeMethod nativeMethod;
    nativeMethod.name = const_cast<char*> ("signalUpdaterReady");
    nativeMethod.signature = const_cast<char*> ("(Ljava/lang/String;)V");
    nativeMethod.fnPtr = reinterpret_cast<void*>(&Java_net_pgrid_loader_bridge_UpdaterRunner_signalUpdaterReady);

    jint result = env->RegisterNatives(updaterRunner, &nativeMethod, 1);
    env->DeleteLocalRef(updaterRunner);
    if (result != JNI_OK) {
        throw JNIException("RegisterNatives failed for UpdaterRunner: "
                           + jace::JNIError_toString(result));
    }
}

END_NAMESPACE_2( bridge, updater )
