#include <jni.h>
#include "updaterrunner.h"

/**
 * This method starts the RSClassMapper on a new Thread and returns directly.
 * It is normally invoked from the JVM by the
 * net.pgrid.loader.bridge.UpdaterRunner class once it's ready.
 */
JNIEXPORT void JNICALL Java_net_pgrid_loader_bridge_UpdaterRunner_signalUpdaterReady
  (JNIEnv *, jobject) {
  //TODO start a new C++ thread on which the UpdaterParser will run.

}
