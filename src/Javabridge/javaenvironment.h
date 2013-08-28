#ifndef JAVAENVIRONMENT_H
#define JAVAENVIRONMENT_H

#include <QString>
#include <QMap>

/**
 * This class loads and sets up the Java Virtual Machine using JACE.
 * It tries to find an installed JRE and then create the VM using
 * the appropriate functionality provided by JACE.
 */
class JavaEnvironment {
  private:
    bool jreLocated;
    QString javaLibraryPath;
    QMap<QString, QString> configuration;

  public:
    JavaEnvironment();

    /// Returns true if and only if a jre is located.
    bool isJRELocated() const { return jreLocated; }
    /** Returns the library path found by locateJRE(),
     *  or an empty QString when locateJRE has not (yet) found a JRE.
     */
    QString getLibPath()  const { return QString(javaLibraryPath); }

    /// Explicitly sets the path to the jvm library.
    void setLibPath(QString path);

    /// parses the configuration file and stores the key-value bindings.
    void parseConfigFile(QString file = QStringLiteral("java.conf"));

    /// validates the given path and returns true iff the path is a valid jvm library
    static bool validate(QString path);

    /// overloaded method, equal to javaEnvironment.validate(getLibPath())
    bool validate();

    /**
     * This function attempts to locate an installed JRE.
     * It then stores the path to the jvm library.
     *
     * When the JRE cannot be found, this function throws an std::runtime_error
     */
    void locateJRE();
    /**
     * This function attempts to create a Java VM.
     * To do so, it first calls locateJRE() if the path is not yet found.
     * Then it creates a Java VM using JACE.
     */
    void start();
};

#endif // JAVAENVIRONMENT_H
