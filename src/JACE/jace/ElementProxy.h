#ifndef JACE_ELEMENT_PROXY_H
#define JACE_ELEMENT_PROXY_H

#include "jace/os_dep.h"
#include "jace/namespace.h"

#include "jace/JNIHelper.h"
#include "jace/ElementProxyHelper.h"

#include "jace/proxy/JObject.h"
#include "jace/JClass.h"

#include "jace/proxy/types/JBoolean.h"
#include "jace/proxy/types/JByte.h"
#include "jace/proxy/types/JChar.h"
#include "jace/proxy/types/JDouble.h"
#include "jace/proxy/types/JFloat.h"
#include "jace/proxy/types/JInt.h"
#include "jace/proxy/types/JLong.h"
#include "jace/proxy/types/JShort.h"

BEGIN_NAMESPACE( jace )

/**
 * An ElementProxy is a wrapper around a JArray element.
 *
 * An ElementProxy is responsible for pinning and depinning
 * its element as required.
 *
 * @author Toby Reyelts
 *
 */
template <class ElementType> class ElementProxy : public ElementType, public virtual ::jace::proxy::JObject {


public:


/**
 * Creates a new ElementProxy that belongs to the given array.
 *
 * This constructor shouldn't be called anymore, as it should be specialized
 * by every proxy type. Every ElementProxy instance should allocate
 * a new global ref to its parent array.
 *
 *
 */
ElementProxy( jarray array, jvalue element, int index ) :
  ElementType( element ), ::jace::proxy::JObject( NO_OP ),
  parent( array ), mIndex( index ) {

  // #error "ElementProxy was not properly specialized."

  std::cout << "ElementProxy was not properly specialized for " <<
           ElementType::staticGetJavaJniClass()->getName() << std::endl;
}


/**
 * Copy constructor. This constructor should also never be called. It should be specialized away.
 *
 */
ElementProxy( const ElementProxy& proxy ) : ::jace::proxy::JObject( NO_OP ), ElementType( 0 ), parent( proxy.parent ), mIndex( proxy.mIndex ) {
  std::cout << "ElementProxy was not properly specialized for " <<
           ElementType::staticGetJavaJniClass()->getName() << std::endl;
}


/**
 * If someone assigns to this array element, they're really assigning
 * to an array, so we need to call SetObjectArrayElement.
 *
 */
ElementType& operator=( const ElementType& element ) {
  ::jace::ElementProxyHelper::assign( element, mIndex, parent );
  return *this;
}


/**
 * If someone assigns to this array element, they're really assigning
 * to an array, so we need to call SetObjectArrayElement.
 *
 */
const ElementType& operator=( const ElementType& element ) const {
  ::jace::ElementProxyHelper::assign( element, mIndex, parent );
  return *this;
}


~ElementProxy() throw() {
  try {
    JNIEnv* env = ::jace::helper::attach();
    ::jace::helper::deleteGlobalRef( env, parent );
  }
  catch ( std::exception& e ) {
    #ifdef JACE_UNUSED_LOCAL_VAR
      e; // shut up the compiler warning
      // It's possible that we're trying to attach when
      // the JVM has already been destroyed
    #endif
  }
}


private:

jarray parent;
int mIndex;

};

END_NAMESPACE( jace )

/**
 * For those (oddball) compilers that need the template specialization
 * definitions in the header.
 */
#ifdef PUT_TSDS_IN_HEADER
  #include "jace/ElementProxy.tsd"
#else
  #include "jace/ElementProxy.tsp"
#endif

#endif

