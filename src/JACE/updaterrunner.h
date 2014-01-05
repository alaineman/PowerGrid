#ifndef UPDATER_RUNNER_H
#define UPDATER_RUNNER_H

#include <jni.h>

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

#ifdef __cplusplus
}
#endif

#endif
