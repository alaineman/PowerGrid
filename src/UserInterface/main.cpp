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

#include <QtCore>
#include <QProcess>
#include <stdexcept>
#include <string>

#include "jace/JNIHelper.h"
#ifdef Q_OS_UNIX
#  include "JACE/UnixVmLoader.h"
#else
#  include "jace/Win32VmLoader.h"
#endif
using namespace jace;
using namespace std;

#ifdef Q_OS_MAC
/**
 * @brief Detects the Java Virtual Machine library path
 *
 * @return a string containing the detected JVM path
 * @throws runtime_error when the path cannot be found.
 */
string detectJVMPath() {
    // We use the "java_home" tool to track the path to the java home
    QProcess javaHomeProcess;
    javaHomeProcess.start("/usr/libexec/java_home");
    javaHomeProcess.waitForFinished();

    if (javaHomeProcess.canReadLine()) {
        QByteArray data = javaHomeProcess.readLine();
        QString dataString = QString::fromLocal8Bit(data);

        string dataStdString = dataString.toStdString();
        return dataStdString;
    } else {
        throw runtime_error("Failed to execute /usr/libexec/java_home");
    }
}
#elif defined(Q_OS_UNIX)
// not Mac, but generic Unix
// Not yet supported since there may not be a standard way to get the
// path to the JVM library
#error Unix is not supported, missing OS-specific JVM library path

#endif

int main(int, char*[]) {

  qDebug() << "Attempting to load JVM...";

  // Create the loader instance with the appropriate configuration options.
#ifdef Q_OS_UNIX
  // Unix OS has no common way of detecting jvm path, so for
  // Unix, a detectJVMPath function is used.
  string jvmPath;
  try {
    jvmPath = detectJVMPath();
    qDebug() << "Found JVM path:" << jvmPath.c_str();
  } catch (runtime_error& err) {
    qWarning() << "Error during JVM path detection:" << err.what();
    return EXIT_FAILURE;
  }
  UnixVmLoader loader (jvmPath, JNI_VERSION_1_6);
#else
  // Windows installations have a key in registry indicating the Java installation.
  // The special Win32VmLoader makes use of this key to find a JVM.
  Win32VmLoader loader ( Win32VmLoader::JVMV_SUN, Win32VmLoader::JVMT_DEFAULT, "", JNI_VERSION_1_6 );
#endif

  OptionList options;

  // Add the PowerGrid jar file to the classpath
  options.push_back( ClassPath( "../../loader/dist/PowerGridLoader.jar" ) );

  // create the JVM
  try {
    helper::createVm( loader, options );
    qDebug() << "JVM created";
  } catch (JNIException& e) {
    qWarning() << "[FAILURE] Creating VM failed:" << e.what();
    return EXIT_FAILURE;
  }

  // JVM created, start the client.


  return EXIT_SUCCESS;
}
