/*
 * Copyright 2012-2013 Patrick Kramer, Vincent Wassenaar
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

#include <cstdlib>
#include <iostream>

/* We require dynamic JVM loading instead of statically binding to the JVM library
 * This prevents the StaticVMLoader class from trying to statically bind to jvm.lib
 */
#define JACE_WANT_DYNAMIC_LOAD

#include "jace/JNIHelper.h"
#include "jace/Win32VmLoader.h"

using namespace jace;

int main(int, char*[]) {

  // Create the loader instance with the appropriate configuration options.
  Win32VmLoader loader ( Win32VmLoader::JVMV_SUN, Win32VmLoader::JVMT_DEFAULT, "", JNI_VERSION_1_6 );

  OptionList options;

  // Add the jar file to the classpath
  options.push_back( ClassPath( "PowerGridLoader.jar" ) );

  // create the JVM
  try {
    helper::createVm( loader, options );
  } catch (JNIException& e) {
    qWarning() << "Creating VM failed:" << e.what();
    return EXIT_FAILURE;
  }

  // Test whether JACE delivers a valid JNIEnv pointer.
  JNIEnv* jniEnv = NULL;
  try {
    jniEnv = helper::attach();
  } catch (JNIException& e) {
    qWarning() << "JNIException occurred:" << e.what();
    return EXIT_FAILURE;
  }
  if ( jniEnv ) {
    qDebug() << "Acquired non-NULL JNIEnv* from JACE";
  } else {
    qWarning() << "Failed to get valid JNIEnv* from JACE";
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
