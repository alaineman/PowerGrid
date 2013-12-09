#include "rsclass.h"
#include "jace/JNIHelper.h"

/**
 * Creates a new RSClass with the given name and type name.
 *
 * @param name - The name of this class, suitable for use in
 *               a call to JNIEnv::FindClass.
 * @param simpleName the simple (semantic) name of the RSClass
 */
RSClass::RSClass(const std::string name, const std::string simpleName) :
  JClass(name),
  simpleName (simpleName) {
}

const std::string& RSClass::getSimpleName() const {
  return simpleName;
}
