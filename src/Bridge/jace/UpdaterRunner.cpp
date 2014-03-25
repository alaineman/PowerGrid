/*
 * Copyright 2014 Patrick Kramer, Vincent Wassenaar
 *
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <jni.h>
#include "UpdaterRunner.h"
#include "RSClassMapper.h"
#include <QtCore>
#include <string>

using jace::JNIException;
using jace::RSClassMapper;

/**
 * This method parses the updater data downloaded by the Java client.
 * It is normally invoked from the JVM by the
 * net.pgrid.loader.bridge.UpdaterRunner class once it's ready.
 */
JNIEXPORT void JNICALL Java_net_pgrid_loader_bridge_UpdaterRunner_signalUpdaterReady
  (JNIEnv*, jclass, jbyteArray bytes) {
    RSClassMapper* mapper = RSClassMapper::DefaultInstance();
    if (mapper) {
        try {
            mapper->parseData(bytes);
        } catch (const JNIException& ex) {
            qWarning() << "Cannot parse Updater data:" << ex.what();
        }
    } else {
        qWarning() << "Cannot parse Updater data: mapper does not exist";
    }
}

namespace bridge {
namespace updater {

/**
 * @brief Registers native methods for the net.pgrid.loader.bridge.UpdaterRunner class
 *
 * Note that calling this function more than once will result in undefined behavior in
 * the JNI.
 * @param env the JNIEnv* to register with
 */
void UpdaterRunner_registerNatives(JNIEnv* env)
        throw (JNIException) {
    // Find the Java class "net.pgrid.loader.bridge.UpdaterRunner"
    jclass updaterRunner = env->FindClass("net/pgrid/loader/bridge/UpdaterRunner");
    if (! updaterRunner) {
        throw JNIException("Cannot find net.pgrid.loader.bridge.UpdaterRunner class");
    }
    // The JNINativeMethod struct we need to register
    JNINativeMethod nativeMethod;
    nativeMethod.name = const_cast<char*> ("signalUpdaterReady");
    nativeMethod.signature = const_cast<char*> ("([B)V");
    nativeMethod.fnPtr = reinterpret_cast<void*>(&Java_net_pgrid_loader_bridge_UpdaterRunner_signalUpdaterReady);

    jint result = env->RegisterNatives(updaterRunner, &nativeMethod, 1);
    env->DeleteLocalRef(updaterRunner);
    if (result != JNI_OK) {
        throw JNIException("RegisterNatives failed for UpdaterRunner: "
                           + jace::JNIError_toString(result));
    }
    qDebug() << "Natives registered successfully for UpdaterRunner class";
}

}
}
