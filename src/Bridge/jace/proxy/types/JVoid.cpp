#include "jace/proxy/types/JVoid.h"
#include "jace/JClassImpl.h"
using jace::JClassImpl;

namespace jace {
namespace proxy {
namespace types {

/**
 * Returns the JClass for this class.
 *
 */
const JClass* JVoid::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "void", "V" );
  return &javaClass;
}


/**
 * Returns the JClass for this class.
 *
 */
const JClass* JVoid::getJavaJniClass() const throw ( JNIException ) {
  return JVoid::staticGetJavaJniClass();
}

}
}
}
