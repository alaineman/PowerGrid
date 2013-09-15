#include "javaenvironment.h"

#include <stdexcept>

#include <QString>
#include <QByteArray>
#include <QStringList>
#include <QProcess>
#include <QFile>
#include <QDebug>

#include <jace/JNIHelper.h>
#include <jace/OptionList.h>

#ifdef Q_OS_WIN32
# include <jace/Win32VmLoader.h>
#else // Unix OS.
# include <jace/UnixVmLoader.h>
#endif

using namespace jace;
using namespace std;

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

  If the java.conf file mentioned above contains a "options" key, its value is used as additonal arguments
  to the jvm being created. Examples of this are "-Xmx256M", for setting the max heap size, and "-X
 */


/*!
 *
 * \brief JavaEnvironment Constructor
 *
 * Creates a new JavaEnvironment object that is ready to locate a JRE
 * and start a Java VM.
 */
JavaEnvironment::JavaEnvironment(QObject* parent) : QObject(parent) {}

/*!
 * \brief Explicitly sets the path to the Java library
 * \param path the path to the jvm library
 *
 * If a JRE has already been found, calling this function
 * will still override the found path. Additionally, if
 * the path provided is an empty String, the JavaEnvironment
 * will
 */
void JavaEnvironment::setLibPath(QString path) {
  javaLibraryPath = path;
}

/*!
 * \brief Parses the given config file.
 * \param file the file to parse.
 *
 * The file should contain a key-value pair on each line in
 * the format <key>=<value>.
 */
void JavaEnvironment::parseConfigFile(QString fileName) {
  QFile file (fileName);
  if (file.exists()) {
    while (file.canReadLine()) {
      QByteArray arr = file.readLine();
      QString line = QString::fromLatin1(arr); // Note: might cause encoding issues.

      if (!line.isEmpty()) {
        int index = line.indexOf('=');
        if (index < 0) {
          qWarning() << "Invalid line found in config file:" << line;
        } else {
          QString key (line);
          key.remove(index, key.size() - index);
          QString value (line);
          value.remove(0,index+1);

          if (!key.isEmpty()) {
            configuration.insert(key.toLower(), value);
          }
        }
      }
    }
  }
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
  if (!isJRELocated()) {
    // We first take the value in the configuration, if it was specified
    if (configuration.isEmpty()) {
      // if configuration is empty we first try to load it.
      parseConfigFile(QStringLiteral("java.conf"));
    }

    if (configuration.contains(QStringLiteral("jvm_path"))) {
      javaLibraryPath = configuration.value(QStringLiteral("jvm_path"));
      return;
    }
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
          javaLibraryPath = line.replace('\\','/'); // in Qt, '/' should be used even for Win32
          qDebug() << "Java library located at\n" << qPrintable(javaLibraryPath);
          break;
        }
      }
    }
    if (javaLibraryPath.isEmpty()) {
      throw runtime_error( "[Windows] failed to locate JRE" );
    }
#elif defined(Q_OS_MACX)
    // On Mac OS X, we can find the jvm library in the JavaVM framework.
    // This executable exports all public JNI symbols, similar to the jvm library on
    // other platforms. This file is actually an alias pointing to the newest JavaVM
    // version, so it is always correct regardless of the installed Java version.
    javaLibraryPath = QStringLiteral("/System/Library/Frameworks/JavaVM.framework/JavaVM");
#else // assuming any Unix OS
    // Unix has many peculiarities which differ per distribution.
    // Because we cannot go over all possibilities, we require
    // other Unix builds to manually define the library path for the java runtime.
    parseConfigFile();
    if (configuration.contains(QStringLiteral("jvm_path"))) {
      javaLibraryPath = configuration.value(QStringLiteral("jvm_path"));
    } else {
      throw runtime_error("[Unix] failed to locate JRE. Please add the path to the config file");
    }
#endif
  }
}


bool JavaEnvironment::validate(QString) {
  return true;
}

bool JavaEnvironment::validate() {
  return validate(javaLibraryPath);
}

/*!
 * \brief Starts the Java Virtual Machine.
 *
 * This function throws a runtime_error when the path to the
 */
void JavaEnvironment::start() {
  // we need to ensure the library path has been found.
  locateJRE();

  // if the path is invalid we throw a runtime error
  if (!validate()) {
    throw runtime_error("Failed to find jvm library, which is required to start");
  }
  // Now we create the correct loader based on the operating system
#ifdef Q_OS_WIN32
  Win32VmLoader loader (javaLibraryPath.toStdString(), static_cast<jint>(JNI_VERSION_1_6));
#else // any Unix OS, including Mac OS
  UnixVmLoader  loader (javaLibraryPath.toStdString(), (long) JNI_VERSION_1_6);
#endif

  QStringList optionList = configuration.value(QStringLiteral("options")).split(' ');

  OptionList options;

  options.push_back( ClassPath("PowerGridLoader.jar") );

  for (QStringList::Iterator it = optionList.begin(); it != optionList.end(); it++) {
    // we push_back each option as a CustomOption
    options.push_back( CustomOption(it->toStdString()) );
  }

  jace::helper::createVm( loader, options );

  qDebug() << "Successfully loaded Java Virtual Machine";
}
