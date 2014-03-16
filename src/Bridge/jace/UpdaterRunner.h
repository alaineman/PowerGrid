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

#ifndef UPDATER_RUNNER_H
#define UPDATER_RUNNER_H

#include <jni.h>
#include "jace/JNIException.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief native method void net.pgrid.loader.UpdaterRunner.signalUpdaterReady()
 *
 * JNI information:
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Class:     net.pgrid.loader.bridge.UpdaterRunner
 * Method:    signalUpdaterReady
 * Signature: ()V
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
JNIEXPORT void JNICALL Java_net_pgrid_loader_bridge_UpdaterRunner_signalUpdaterReady
  (JNIEnv *, jobject, jstring, jbyteArray);

/**
 * \brief representative namespace for \c net.pgrid.loader.bridge
 */
namespace bridge {

/**
 * \brief representative namespace for \c net.pgrid.loader.bridge.updater
 */
namespace updater {

/**
 * @brief Registers natives for the UpdaterRunner class
 * @param env the JNIEnv*
 */
void UpdaterRunner_registerNatives(JNIEnv* env) throw(jace::JNIException);

} // namespace updater
} // namespace bridge

#ifdef __cplusplus
}
#endif

#endif
