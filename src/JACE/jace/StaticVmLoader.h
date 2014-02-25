
#ifndef JACE_STATIC_VM_LOADER
#define JACE_STATIC_VM_LOADER

#include "jace/os_dep.h"
#include "jace/JNIException.h"
#include "jace/VmLoader.h"

#include <jni.h>

namespace jace {

/**
 * The default VmLoader which works by statically linking to the JVM.
 * To turn off the StaticVmLoader, you must #define JACE_WANT_DYNAMIC_LOAD
 *
 * StaticVmLoader is totally inlined so that the Jace library can be built
 * orthogonally in reference to dynamic or static VM linking. If StaticVmLoader
 * wasn't defined within the header file, two different binaries of the Jace library
 * would be required.
 *
 * @author Toby Reyelts
 *
 */
class StaticVmLoader : public VmLoader {

public:

  StaticVmLoader( jint version ) : jniVersion( version ) {
  }

  virtual void loadVm() throw ( JNIException ) {
    // The operating system automatically loads the JVM
  }

  virtual void unloadVm() {
    // The operating system automatically unloads the JVM
  }

#ifndef JACE_WANT_DYNAMIC_LOAD
  virtual jint getCreatedJavaVMs( JavaVM **vmBuf, jsize bufLen, jsize *nVMs ) {
      return JNI_GetCreatedJavaVMs( vmBuf, bufLen, nVMs );
  }
  virtual jint createJavaVM( JavaVM **pvm, void **env, void *args ) {
      return JNI_CreateJavaVM( pvm, env, args );
  }
#else
  // Prevent operations on the JVM if JACE_WANT_DYNAMIC_LOAD is specified
  virtual jint getCreatedJavaVMs(JavaVM**,jsize, jsize*) { return -1; }
  virtual jint createJavaVM(JavaVM**, void**, void*) { return -1; }
#endif

  virtual VmLoader* clone() const {
    return new StaticVmLoader( jniVersion );
  }

  virtual jint version() {
    return jniVersion;
  }

  private:

  jint jniVersion;
};

}

#endif // JACE_STATIC_VM_LOADER

