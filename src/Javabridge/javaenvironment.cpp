#include "javaenvironment.h"

#include <QString>
#include <QByteArray>
#include <QStringList>
#include <QProcess>

#include <jace/JNIHelper.h>
#include <jace/OptionList.h>

#ifdef Q_OS_WIN32
# include <jace/Win32VmLoader.h>
#else // we assume any Unix OS.
# include <jace/UnixVmLoader.h>
#endif

using namespace jace;

JavaEnvironment::JavaEnvironment() {
  jreLocated = false;
}

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
# ifndef JAVA_LIB_PATH
#  error JAVA_LIB_PATH needs to be defined when compiling on unix.
# endif
    javaLibraryPath.setFileName(JAVA_LIB_PATH);
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
