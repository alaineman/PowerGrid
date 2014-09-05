
#ifndef JACE_VM_LOADER
#define JACE_VM_LOADER

#include "jace/os_dep.h"
#include "jace/JNIException.h"

#include <jni.h>

namespace jace {

/**
 * The base interface for virtual machine loaders.
 * 
 * To create a virtual machine using jace::helper::createVm(),
 * you need to specify a VmLoader.
 *
 * For Windows, you can use Win32VmLoader. It is capable of querying the registry
 * to discover different flavors of installed virtual machines.
 *
 * For Mac OS X, you can use MacVmLoader. It calls the java_home tool shipped with
 * Mac OS X to find the location of the latest Java VM installed on the system.
 *
 * For generic flavors of Unix, you can use UnixVmLoader. It uses the standard
 * dlsym function to load a virtual machine.
 *
 * @author Toby Reyelts
 */
class VmLoader {

  public:

  /**
   * Loads the virtual machine into memory.
   *
   */
  JACE_API virtual void loadVm() throw ( ::jace::JNIException ) = 0;

  /**
   * Unloads the virtual machine from memory.
   *
   */
  JACE_API virtual void unloadVm() = 0;

  /**
   * Returns the version of the virtual machine to be loaded.
   * The implementation should cache this value because it is used on JVM shutdown
   * and might lead to deadlocks if jace::helper::attach() is called at that point.
   */
  JACE_API virtual jint version() = 0;

  /**
   * Creates a new dynamically allocated clone of this VmLoader.
   *
   */
  JACE_API virtual VmLoader* clone() const = 0;

  /**
   * Calls into JNI_CreateJavaVM.
   *
   */
  JACE_API virtual jint createJavaVM( JavaVM **pvm, void **env, void *args ) = 0;

  /**
   * Calls into JNI_GetCreatedJavaVMs.
   *
   */
  JACE_API virtual jint getCreatedJavaVMs( JavaVM **vmBuf, jsize bufLen, jsize *nVMs ) = 0;

  JACE_API virtual ~VmLoader() {
  }

};

}

#endif // JACE_VM_LOADER

