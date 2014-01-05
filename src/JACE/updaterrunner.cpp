#include <jni.h>
#include "updaterrunner.h"
#include "rsclassmapper.h"
#include <QtCore>

/**
 * This method parses the updater data downloaded by the Java client.
 * It is normally invoked from the JVM by the
 * net.pgrid.loader.bridge.UpdaterRunner class once it's ready.
 */
JNIEXPORT void JNICALL Java_net_pgrid_loader_bridge_UpdaterRunner_signalUpdaterReady
  (JNIEnv *, jobject) {
    RSClassMapper* mapper = RSClassMapper::DefaultInstance();
    if (mapper) {
        mapper->parseData();
    } else {
        qWarning() << "Cannot parse Updater data: mapper does not exist";
    }
}
