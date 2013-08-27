#ifndef JAVAENVIRONMENT_H
#define JAVAENVIRONMENT_H

#include <QString>

/**
 * This class loads and sets up the Java Virtual Machine using JACE.
 * It tries to find an installed JRE and then create the VM using
 * the appropriate functionality provided by JACE.
 */
class JavaEnvironment {
  private:
    bool jreLocated;
    QString javaLibraryPath;

  public:
    JavaEnvironment();

    /// Returns true if and only if a jre is located.
    bool isJRELocated() const { return jreLocated; }
    /** Returns the library path found by locateJRE(),
     *  or an empty QString when locateJRE has not (yet) found a JRE.
     */
    QString getLibPath()  const { return QString(javaLibraryPath); }

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
