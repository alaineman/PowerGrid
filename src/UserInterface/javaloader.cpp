#include "javaloader.h"

#include "jace/JNIHelper.h"

Q_DECLARE_LOGGING_CATEGORY(logLauncher)

JavaLoader::JavaLoader(QObject *parent) :
    QObject(parent) {
}

void JavaLoader::addOption(const Option &opt) {
    options.push_back(opt);
}

void JavaLoader::setLibraryPath(const QString path) {
#ifdef Q_OS_WIN32
    // On Windows, take the value of the USERPROFILE environment variable.
    // We don't care about forward or backward slashes, since any Windows
    // nowadays supports both.
    QByteArray userprofileBytes = qgetenv("USERPROFILE");
    QByteArray libBytes = qgetenv("PATH");
    const char* libPath = std::string(libBytes.constData())
                                .append(";")
                                .append(userprofileBytes.constData())
                                .append("/")
                                .append(qPrintable(path)).c_str();
#else
    QByteArray libBytes = qgetenv("LD_LIBRARY_PATH");
    // Unixes have a standard way of getting the home directory (~)
    const char* libPath = std::string(libBytes.constData()).append(":~/").append(qPrintable(path)).c_str();
#endif
    addOption( LibraryPath(libPath) );
}

void JavaLoader::startJVM() throw(JNIException) {
    jace::helper::createVm(loader, options, false);

    // The PowerGrid loader requires Java 8, so we print an error if the version does not match.
    // Afterwards we exit, because the loader won't run anyway.
    QString javaVersion = helper::getJavaProperty("java.version");
    int secondPeriod = javaVersion.indexOf('.', javaVersion.indexOf('.') + 1);
    double version = javaVersion.left(secondPeriod).toDouble();
    if (version < 1.8) {
        qCWarning(logLauncher) << "[FAILURE] PowerGrid requires at least Java 8 to run. Please update your Java version";
        qCWarning(logLauncher) << "          Found java version" << version << "instead";

        throw JNIException("Version mismatch: required at least 1.8 but found version: " % QString::number(version));
    }
    qCDebug(logLauncher) << "Started JVM with version" << version;
}
