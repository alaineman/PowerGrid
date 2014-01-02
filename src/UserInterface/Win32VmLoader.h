#ifndef JACE_WIN32_VM_LOADER
#define JACE_WIN32_VM_LOADER

#include "jace/os_dep.h"
#ifdef _WIN32

#include "jace/namespace.h"
#include "jace/JNIException.h"
#include "jace/VmLoader.h"

#include <jni.h>

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#endif

#include <windows.h>

#include <string>

BEGIN_NAMESPACE( jace )

/**
 * A generic Virtual Machine loader for Windows.
 *
 * This loader makes use of keys in the Windows registry to find and
 * load a JVM dynamically.
 *
 * Note that this loader currently only supports the Oracle JVM
 * (previously Sun).
 *
 * @author Toby Reyelts; modified by Patrick Kramer
 *
 */
class Win32VmLoader : public ::jace::VmLoader {

  public:

  /**
   * Creates a new VM loader for the specified VM.
   * The VM to be loaded is selected by vendor, type and version parameters. 
   *
   * @param version - Version of the VM as String (e.g. "1.3.1", "1.4")
   *        The default value is the version of the lastest Sun VM installed.
   *
   * @param version - The version of JNI to use. For example,
   * JNI_VERSION_1_2 or JNI_VERSION_1_4. The default is JNI_VERSION_1_6.
   *
   * @throws JNIException if an error occurs while trying to look up the VM.
   */
  Win32VmLoader(std::string version = "", jint jniVersion = JNI_VERSION_1_6 );
  Win32VmLoader(jint jniVersion, std::string path);
  virtual ~Win32VmLoader() {}

  void loadVm() throw ( ::jace::JNIException );
  void unloadVm();
  ::jace::VmLoader* clone() const;
  virtual jint version();
  jint getCreatedJavaVMs( JavaVM **vmBuf, jsize bufLen, jsize *nVMs );
  jint createJavaVM( JavaVM **pvm, void **env, void *args );

  private:

  jint jniVersion;
  std::string jvmVersion;

  typedef jint (JNICALL *GetCreatedJavaVMs_t)(JavaVM **vmBuf, jsize bufLen, jsize *nVMs);
  typedef jint (JNICALL *CreateJavaVM_t)(JavaVM **pvm, void **env, void *args);

  GetCreatedJavaVMs_t getCreatedJavaVMsPtr;
  CreateJavaVM_t createJavaVMPtr;

  std::string path;
  HINSTANCE handle;

  /**
   * Method to specify a VM and initialize the VM entry points.
   * The VM to be loaded could be selected by vendor, type and version parameters
   *
   * @param version - Version of the VM as String (e.g. "1.3.1", "1.4")
   *        The default value is the version of the lastest Sun VM installed.
   *
   * @throws JNIException if an error occurs while trying to look up the VM.
   */
  void specifyVm() throw (JNIException);

  /**
   * Loads the VM at the specified path.
   *
   * @throws JNIException if an error occurs while trying to load the VM.
   */
  void loadVm( const std::string& path ) throw ( JNIException );

  std::string getJVMVersion() const { return jvmVersion; }
};

END_NAMESPACE( jace )

#endif // JACE_WIN32_VM_LOADER

#endif // _WIN32


