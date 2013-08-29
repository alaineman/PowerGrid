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
    JavaEnvironment(QObject* parent = NULL);

    bool isJRELocated()   const { return !javaLibraryPath.isEmpty(); }
    QString getLibPath()  const { return QString(javaLibraryPath); }

    void setLibPath(QString path);
    void parseConfigFile(QString fileName = QStringLiteral("java.conf"));

    static bool validate(QString path);
    bool validate();

    void locateJRE();
    void start();
};

#endif // JAVAENVIRONMENT_H
