#include "javaenvironment.h"

#include <QString>
#include <QByteArray>
#include <QStringList>
#include <QProcess>
#include <QFile>

#include <jace/JNIHelper.h>
#include <jace/OptionList.h>

#ifdef Q_OS_WIN32
# include <jace/Win32VmLoader.h>
#else // we assume any Unix OS.
# include <jace/UnixVmLoader.h>
#endif

using namespace jace;

/*!

  \class JavaEnvironment

  \brief Loader class for the Java Runtime Environment

  This class locates a Java Runtime Environment (JRE) and then uses the
  appropriate JACE dynamic VM loader to load and start the Java Virtual Machine.

  This class can locate an already installed JRE, or one can be provided explicitly using the
  setLibPath(QString) member function.

  Alternatively, if a file called "java.conf" is found in the same directory as the executable,
  this class takes the value of the "jvm_path" key and uses that path as jvm path. Note that
  this class will still try to find another jvm library if the one provided explicitly is invalid.

 */

/*!
 * \brief JavaEnvironment Constructor
 *
 * Creates a new JavaEnvironment object that is ready to locate a JRE and start a Java VM.
 */
JavaEnvironment::JavaEnvironment() {
  jreLocated = false;
}

/*!
 * \brief Tries to find a valid Java Runtime Environment on the system.
 *
 * This function tries to locate an installed JRE using a method suitable
 * for the OS it is running on. On Unix (except Mac OS), you will have to
 * specify the path to the Java library explicitly in the file called
 * "java.conf" in order for this class to locate it.
 *
 * On Mac OS, the jvm library is taken from the JavaVM framework.
 *
 * On Windows, the PATH environment variable is searched for a valid java
 * installation. As such, under some circumstances, it may be possible that
 * this class does not correctly detect the jvm library in some cases.
 * If this is the case, the path to the jvm.dll file must be explicitly
 * defined in the "java.conf" file, or the PATH environment variable must be
 * altered to correctly include the java executable.
 */
void JavaEnvironment::locateJRE() {
  if (!jreLocated) {
#ifdef Q_OS_WIN32
    // On Windows, we can use the 'where' command to locate the Java executable.
    QProcess whereJava, whereJVM;
    whereJava.start("where", QStringList() << "java");
    whereJava.waitForFinished();
    while (whereJava.canReadLine()) {
      QByteArray bytes = whereJava.readLine();
      QString line = QString::fromLocal8Bit(bytes);

      if (!line.isEmpty()) {
        line.chop( line.size()-line.lastIndexOf('\\') );
        whereJVM.start("where", QStringList() << "/R" << line << "jvm.dll");
        whereJVM.waitForFinished();

        if (whereJVM.exitCode() == 0) {
          // the where command returned at least 1 result when the exit code is 0.
          bytes = whereJVM.readLine();
          line = QString::fromLocal8Bit(bytes);

          line.chop(1); // this removes the additional '\n' char at the end
          javaLibraryPath.setFileName(line.replace('\\','/')); // in Qt, '/' should be used even for Win32
          break;
        }
      }
    }
    if (javaLibraryPath.fileName().isEmpty()) {
      throw runtime_exception( "[Windows] failed to locate JRE" );
    }
#elif defined(Q_OS_MACX)
    // On Mac OS X, we can find the jvm library in the JavaVM framework.
    // This executable exports all public JNI symbols, similar to the jvm library on
    // other platforms. This file is actually an alias pointing to the newest JavaVM
    // version, so it is always correct regardless of the installed Java version.
    javaLibraryPath.setFileName("/System/Library/Frameworks/JavaVM.framework/JavaVM");
#else // assuming any Unix OS
    // Unix has many peculiarities which differ per distribution.
    // Because we cannot go over all possibilities, we require
    // other Unix builds to manually define the library path for the java runtime.
    // Note that this also means most Unix users will have to manually compile as well.

#endif
    jreLocated = true;
  }
}

void JavaEnvironment::start() {
  // we need to ensure the lib and RT paths have been found.
  locateJRE();

  // Now we create the correct loader based on the operating system
#ifdef Q_OS_WIN32
  Win32VmLoader loader (javaLibraryPath.fileName().toStdString().c_str(), JNI_VERSION_1_6);
#else // assuming any Unix OS
  UnixVmLoader  loader (javaLibraryPath.fileName().toStdString().c_str(), JNI_VERSION_1_6);
#endif

  OptionList options;

  options.push_back( ClassPath("PowerGridLoader.jar") );
  options.push_back( CustomOption("-Xmx256M") );
  options.push_back( CustomOption("-Xss2M"));

  jace::helper::createVm( loader, options );

  qDebug() << "Successfully loaded Java Virtual Machine";
}
