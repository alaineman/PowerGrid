#ifndef JACE_WIN32_VM_LOADER
#define JACE_WIN32_VM_LOADER

#include <QtGlobal>
#include "jace/os_dep.h"

#ifdef Q_OS_WIN32

#include "jace/JNIException.h"
#include "jace/VmLoader.h"

#include <jni.h>

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#endif

#include <windows.h>

#include <string>

Q_DECLARE_LOGGING_CATEGORY(logLauncher)

namespace jace {

class Win32VmLoader : public VmLoader {
public:
  Win32VmLoader(std::string version = "", jint jniVersion = JNI_VERSION_1_6 );
  Win32VmLoader(jint jniVersion, std::string path);
  virtual ~Win32VmLoader() {}

  void loadVm() throw ( ::jace::JNIException );
  void unloadVm();
  jace::VmLoader* clone() const;
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

  void specifyVm() throw (JNIException);
  void loadVm( const std::string& path ) throw ( JNIException );
  std::string getJVMVersion() const { return jvmVersion; }
};

}

#endif // JACE_WIN32_VM_LOADER

#endif // _WIN32


