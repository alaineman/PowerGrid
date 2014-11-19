#ifndef JAVALOADER_H
#define JAVALOADER_H

#include <QObject>

#include "jace/VmLoader.h"
#include "jace/OptionList.h"
#include "jace/JNIException.h"

// Each platform-dependant header checks the platform before defining anything,
// So we can just include all of them here without issues.
#include "jace/Win32VmLoader.h"
#include "jace/macvmloader.h"
#include "jace/UnixVmLoader.h"

using namespace jace;

/**
 * @brief Loader class for the JVM.
 *
 * This class is responsible for finding a suitable JVM and load it.
 *
 * This class also eliminates any platform-dependant code by wrapping
 * the required VmLoader for each platform, and bundles the OptionList
 * in the class itself.
 */
class JavaLoader : public QObject {
    Q_OBJECT
private:

#ifdef Q_OS_WIN
    typedef jace::Win32VmLoader JavaPlatformLoader;
#elif defined(Q_OS_MACX)
    typedef jace::MacVmLoader JavaPlatformLoader;
#else // Q_OS_UNIX (but not Mac OS)
    typedef jace::UnixVmLoader JavaPlatformLoader;
#endif

    JavaPlatformLoader loader;
    OptionList options;
public:
    /**
     * @brief Creates a new JavaLoader instance.
     * @param parent - The parent of this QObject subclass.
     */
    explicit JavaLoader(QObject *parent = 0);

    /**
     * @brief Adds the provided Option as a JVM Option.
     * @param opt - The Option to add.
     */
    void addOption(const Option& opt);

    /**
     * @brief Sets the path for native libraries to be used by the JVM.
     *
     * The existing library path (which is platform-dependant) is preserved.
     * The path is taken relative to the user's home directory (which is '~' on
     * Unix and '%USERPROFILE%' on Windows).
     *
     * @param path - The path for native libraries
     */
    void setLibraryPath(const QString path);

    /**
     * @brief Starts the JVM using the VmLoader and provided Options.
     *
     * This function also checks if the loaded version is supported by PowerGrid.
     * PowerGrid requires at least Java 8 to run. This function throws a JNIException
     * if the version is not supported.
     *
     * @throws JNIException - When starting the JVM failed for any reason.
     */
    void startJVM() throw(JNIException);

signals:
    /**
     * @brief Signal emitted when the JavaLoader has started a JVM.
     */
    void finished();

    /**
     * @brief Signal emitted when the JavaLoader failed to start a JVM.
     * @param message - A message indicating the problem.
     */
    void error(QString message);
};

#endif // JAVALOADER_H
