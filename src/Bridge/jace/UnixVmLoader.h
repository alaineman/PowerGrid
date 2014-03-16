#ifndef JACE_UNIX_VM_LOADER
#define JACE_UNIX_VM_LOADER

#include "jace/os_dep.h"

#ifdef JACE_GENERIC_UNIX
#include "jace/VmLoader.h"
#include "jace/JNIException.h"

#include <jni.h>

#include <string>

namespace jace {

/**
 * A generic Virtual Machine loader for Unix based operating systems.
 * This simple loader should work fine on most Unices.
 *
 * @author Toby Reyelts
 *
 */
class UnixVmLoader : public ::jace::VmLoader {

  public:

  /**
   * Creates a new VM loader for the specified VM.
   * The VM to be loaded is specified by the path to the shared library.
   *
   * @param path - The path to the shared library implementing the VM.
   *
   * @param jniVersion - The version of JNI to use. For example, JNI_VERSION_1_2 or
   * JNI_VERSION_1_4.
   *
   */
  UnixVmLoader( std::string path_, jint jniVersion );

  void loadVm() throw ( ::jace::JNIException );
  void unloadVm();
  jint createJavaVM( JavaVM **pvm, void **env, void *args );
  jint getCreatedJavaVMs( JavaVM **vmBuf, jsize bufLen, jsize *nVMs );
  ::jace::VmLoader* clone() const;
  jint version();

  private:

  jint jniVersion;

  typedef jint ( JNICALL *CreateJavaVM_t )( JavaVM **pvm, void **env, void *args );
  typedef jint ( JNICALL *GetCreatedJavaVMs_t )( JavaVM **vmBuf, jsize bufLen, jsize *nVMs );

  CreateJavaVM_t createJavaVMPtr;
  GetCreatedJavaVMs_t getCreatedJavaVMsPtr;

  std::string path;
  void* lib;
};

}

#endif // JACE_GENERIC_UNIX

#endif // JACE_UNIX_VM_LOADER

