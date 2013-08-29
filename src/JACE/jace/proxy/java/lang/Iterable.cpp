
#ifndef JACE_PROXY_JAVA_LANG_ITERABLE_H
#include "jace/proxy/java/lang/Iterable.h"
#endif

/**
 * Standard Jace headers needed to implement this class.
 *
 */
#ifndef JACE_JARGUMENTS_H
#include "jace/JArguments.h"
#endif
using jace::JArguments;

#ifndef JACE_JMETHOD_H
#include "jace/JMethod.h"
#endif
using jace::JMethod;

#ifndef JACE_JFIELD_H
#include "jace/JField.h"
#endif
using jace::JField;

#ifndef JACE_JCLASS_IMPL_H
#include "jace/JClassImpl.h"
#endif
using jace::JClassImpl;


/**
 * Headers for the classes that this class uses.
 *
 */
#ifndef JACE_PROXY_JAVA_UTIL_ITERATOR_H
#include "jace/proxy/java/util/Iterator.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, lang )

/**
 * The Jace C++ proxy class source for java/lang/Iterable.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Iterable_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Iterable_INITIALIZER
#endif

::jace::proxy::java::util::Iterator Iterable::iterator() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Iterator >( "iterator" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
/**
 * Special no arg constructor for interface virtual inheritance
 *
 */
Iterable::Iterable() : Object( NO_OP ) { 
}

Iterable::Iterable( jvalue value ) Iterable_INITIALIZER {
  setJavaJniValue( value );
}

Iterable::Iterable( jobject object ) Iterable_INITIALIZER {
  setJavaJniObject( object );
}

Iterable::Iterable( const Iterable& object ) Iterable_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Iterable::Iterable( const NoOp& noOp ) Iterable_INITIALIZER {
}

const JClass* Iterable::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/lang/Iterable" );
  return &javaClass;
}

const JClass* Iterable::getJavaJniClass() const throw ( JNIException ) {
  return Iterable::staticGetJavaJniClass();
}

JEnlister< Iterable> Iterable::enlister;

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::lang::Iterable>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::Iterable( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::Iterable>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::Iterable>& proxy ) : 
    ::jace::proxy::java::lang::Iterable( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Iterable>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::Iterable( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Iterable>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::Iterable( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Iterable>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::Iterable>& object ) : 
    ::jace::proxy::java::lang::Iterable( object.getJavaJniValue() ), Object( NO_OP ) {

    fieldID = object.fieldID; 

    if ( object.parent ) {
      JNIEnv* env = ::jace::helper::attach();
      parent = ::jace::helper::newGlobalRef( env, object.parent );
    }
    else {
      parent = 0;
    }

    if ( object.parentClass ) {
      JNIEnv* env = ::jace::helper::attach();
      parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, object.parentClass ) );
    }
    else {
      parentClass = 0;
    }
  }
#endif

END_NAMESPACE( jace )

