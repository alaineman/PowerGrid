#ifndef JAVAENVIRONMENT_H
#define JAVAENVIRONMENT_H

#include <QString>
#include <QMap>
#include <QObject>
#include <stdexcept>
#include <jace/JNIException.h>

class JavaEnvironment : QObject {
  private:
    Q_DISABLE_COPY( JavaEnvironment )

    QString javaLibraryPath;
    QMap<QString, QString> configuration;

  public:
    JavaEnvironment(QObject* parent = NULL) Q_DECL_NOTHROW;

    bool isJRELocated()   const Q_DECL_NOTHROW { return !javaLibraryPath.isEmpty(); }
    QString getLibPath()  const Q_DECL_NOTHROW { return QString(javaLibraryPath); }

    void setLibPath(QString path) Q_DECL_NOTHROW;
    void parseConfigFile(QString fileName = QStringLiteral("java.conf"));

    static bool validate(QString path);
    bool validate() Q_DECL_NOTHROW;

    void locateJRE() throw(std::runtime_error);
    void start()     throw(std::runtime_error, jace::JNIException);
};

#endif // JAVAENVIRONMENT_H
