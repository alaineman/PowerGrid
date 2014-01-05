#include "rsclass.h"
using std::string;

/**
 * Creates a new RSClass with the given name and type name.
 *
 * @param name - The name of this class, suitable for use in
 *               a call to JNIEnv::FindClass.
 * @param simpleName the simple (semantic) name of the RSClass
 */
RSClass::RSClass(const string name, const string simpleName) :
  JClassImpl(name),
  simpleName (simpleName) {
}

const string& RSClass::getSimpleName() const {
  return simpleName;
}
