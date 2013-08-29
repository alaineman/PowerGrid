
#ifndef JACE_PROXY_JAVA_NET_PROXY_TYPE_H
#include "jace/proxy/java/net/Proxy.Type.h"
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
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, net )

/**
 * The Jace C++ proxy class source for java/net/Proxy$Type.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Proxy_Type_INITIALIZER : ::jace::proxy::java::lang::Enum( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Proxy_Type_INITIALIZER : ::jace::proxy::java::lang::Enum( NO_OP )
#endif

::jace::JArray< ::jace::proxy::java::net::Proxy_Type > Proxy_Type::values() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::net::Proxy_Type > >( "values" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::net::Proxy_Type Proxy_Type::valueOf( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::net::Proxy_Type >( "valueOf" ).invoke( staticGetJavaJniClass(), arguments );
}

/**
 * public static final enum DIRECT
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::net::Proxy_Type > Proxy_Type::DIRECT() {
  return ::jace::JField< ::jace::proxy::java::net::Proxy_Type >( "DIRECT" ).get( staticGetJavaJniClass() );
}

/**
 * public static final enum HTTP
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::net::Proxy_Type > Proxy_Type::HTTP() {
  return ::jace::JField< ::jace::proxy::java::net::Proxy_Type >( "HTTP" ).get( staticGetJavaJniClass() );
}

/**
 * public static final enum SOCKS
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::net::Proxy_Type > Proxy_Type::SOCKS() {
  return ::jace::JField< ::jace::proxy::java::net::Proxy_Type >( "SOCKS" ).get( staticGetJavaJniClass() );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Proxy_Type::Proxy_Type( jvalue value ) Proxy_Type_INITIALIZER {
  setJavaJniValue( value );
}

Proxy_Type::Proxy_Type( jobject object ) Proxy_Type_INITIALIZER {
  setJavaJniObject( object );
}

Proxy_Type::Proxy_Type( const Proxy_Type& object ) Proxy_Type_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Proxy_Type::Proxy_Type( const NoOp& noOp ) Proxy_Type_INITIALIZER {
}

const JClass* Proxy_Type::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/net/Proxy$Type" );
  return &javaClass;
}

const JClass* Proxy_Type::getJavaJniClass() const throw ( JNIException ) {
  return Proxy_Type::staticGetJavaJniClass();
}

JEnlister< Proxy_Type> Proxy_Type::enlister;

END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::net::Proxy_Type>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::net::Proxy_Type( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::net::Proxy_Type>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::net::Proxy_Type>& proxy ) : 
    ::jace::proxy::java::net::Proxy_Type( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::net::Proxy_Type>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::net::Proxy_Type( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::Proxy_Type>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::net::Proxy_Type( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::Proxy_Type>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::net::Proxy_Type>& object ) : 
    ::jace::proxy::java::net::Proxy_Type( object.getJavaJniValue() ), Object( NO_OP ) {

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

