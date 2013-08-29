
#ifndef JACE_PROXY_JAVA_NET_PROXY_H
#include "jace/proxy/java/net/Proxy.h"
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
#ifndef JACE_TYPES_JVOID_H
#include "jace/proxy/types/JVoid.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_PROXY_TYPE_H
#include "jace/proxy/java/net/Proxy.Type.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_SOCKETADDRESS_H
#include "jace/proxy/java/net/SocketAddress.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, net )

/**
 * The Jace C++ proxy class source for java/net/Proxy.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Proxy_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Proxy_INITIALIZER
#endif

Proxy::Proxy( ::jace::proxy::java::net::Proxy_Type p0, ::jace::proxy::java::net::SocketAddress p1 ) Proxy_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::java::net::Proxy_Type Proxy::type() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::net::Proxy_Type >( "type" ).invoke( *this, arguments );
}

::jace::proxy::java::net::SocketAddress Proxy::address() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::net::SocketAddress >( "address" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Proxy::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Proxy::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt Proxy::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

/**
 * public static final NO_PROXY
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::net::Proxy > Proxy::NO_PROXY() {
  return ::jace::JField< ::jace::proxy::java::net::Proxy >( "NO_PROXY" ).get( staticGetJavaJniClass() );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Proxy::Proxy( jvalue value ) Proxy_INITIALIZER {
  setJavaJniValue( value );
}

Proxy::Proxy( jobject object ) Proxy_INITIALIZER {
  setJavaJniObject( object );
}

Proxy::Proxy( const Proxy& object ) Proxy_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Proxy::Proxy( const NoOp& noOp ) Proxy_INITIALIZER {
}

const JClass* Proxy::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/net/Proxy" );
  return &javaClass;
}

const JClass* Proxy::getJavaJniClass() const throw ( JNIException ) {
  return Proxy::staticGetJavaJniClass();
}

JEnlister< Proxy> Proxy::enlister;

END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::net::Proxy>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::net::Proxy( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::net::Proxy>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::net::Proxy>& proxy ) : 
    ::jace::proxy::java::net::Proxy( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::net::Proxy>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::net::Proxy( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::Proxy>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::net::Proxy( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::Proxy>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::net::Proxy>& object ) : 
    ::jace::proxy::java::net::Proxy( object.getJavaJniValue() ), Object( NO_OP ) {

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

