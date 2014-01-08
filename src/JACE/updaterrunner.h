#ifndef UPDATER_RUNNER_H
#define UPDATER_RUNNER_H

#include <jni.h>
#include "jace/JNIException.h"
#include "jace/namespace.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Class:     net_pgrid_loader_bridge_UpdaterRunner
 * Method:    signalUpdaterReady
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_net_pgrid_loader_bridge_UpdaterRunner_signalUpdaterReady
  (JNIEnv *, jobject);

BEGIN_NAMESPACE_2( bridge, updater )
void UpdaterRunner_registerNatives(JNIEnv* env) throw(jace::JNIException);
END_NAMESPACE_2( bridge, updater )

#ifdef __cplusplus
}
#endif

#endif
