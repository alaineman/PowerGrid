
#ifndef JACE_PROXY_JAVA_UTIL_ENUMERATION_H
#include "jace/proxy/java/util/Enumeration.h"
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
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, util )

/**
 * The Jace C++ proxy class source for java/util/Enumeration.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Enumeration_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Enumeration_INITIALIZER
#endif

::jace::proxy::types::JBoolean Enumeration::hasMoreElements() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "hasMoreElements" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object Enumeration::nextElement() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "nextElement" ).invoke( *this, arguments );
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
Enumeration::Enumeration() : Object( NO_OP ) { 
}

Enumeration::Enumeration( jvalue value ) Enumeration_INITIALIZER {
  setJavaJniValue( value );
}

Enumeration::Enumeration( jobject object ) Enumeration_INITIALIZER {
  setJavaJniObject( object );
}

Enumeration::Enumeration( const Enumeration& object ) Enumeration_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Enumeration::Enumeration( const NoOp& noOp ) Enumeration_INITIALIZER {
}

const JClass* Enumeration::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/util/Enumeration" );
  return &javaClass;
}

const JClass* Enumeration::getJavaJniClass() const throw ( JNIException ) {
  return Enumeration::staticGetJavaJniClass();
}

JEnlister< Enumeration> Enumeration::enlister;

END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::util::Enumeration>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::Enumeration( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::Enumeration>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::Enumeration>& proxy ) : 
    ::jace::proxy::java::util::Enumeration( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::util::Enumeration>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::Enumeration( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Enumeration>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::Enumeration( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Enumeration>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::Enumeration>& object ) : 
    ::jace::proxy::java::util::Enumeration( object.getJavaJniValue() ), Object( NO_OP ) {

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

