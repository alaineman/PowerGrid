
#ifndef JACE_PROXY_JAVA_NET_INETADDRESS_H
#include "jace/proxy/java/net/InetAddress.h"
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
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_NETWORKINTERFACE_H
#include "jace/proxy/java/net/NetworkInterface.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_UNKNOWNHOSTEXCEPTION_H
#include "jace/proxy/java/net/UnknownHostException.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, net )

/**
 * The Jace C++ proxy class source for java/net/InetAddress.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define InetAddress_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define InetAddress_INITIALIZER
#endif

::jace::proxy::types::JBoolean InetAddress::isMulticastAddress() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isMulticastAddress" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean InetAddress::isAnyLocalAddress() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isAnyLocalAddress" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean InetAddress::isLoopbackAddress() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isLoopbackAddress" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean InetAddress::isLinkLocalAddress() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isLinkLocalAddress" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean InetAddress::isSiteLocalAddress() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isSiteLocalAddress" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean InetAddress::isMCGlobal() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isMCGlobal" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean InetAddress::isMCNodeLocal() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isMCNodeLocal" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean InetAddress::isMCLinkLocal() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isMCLinkLocal" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean InetAddress::isMCSiteLocal() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isMCSiteLocal" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean InetAddress::isMCOrgLocal() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isMCOrgLocal" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean InetAddress::isReachable( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isReachable" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean InetAddress::isReachable( ::jace::proxy::java::net::NetworkInterface p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isReachable" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String InetAddress::getHostName() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getHostName" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String InetAddress::getCanonicalHostName() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getCanonicalHostName" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::types::JByte > InetAddress::getAddress() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::types::JByte > >( "getAddress" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String InetAddress::getHostAddress() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getHostAddress" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt InetAddress::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean InetAddress::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String InetAddress::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

::jace::proxy::java::net::InetAddress InetAddress::getByAddress( ::jace::proxy::java::lang::String p0, ::jace::JArray< ::jace::proxy::types::JByte > p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::net::InetAddress >( "getByAddress" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::net::InetAddress InetAddress::getByName( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::net::InetAddress >( "getByName" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::JArray< ::jace::proxy::java::net::InetAddress > InetAddress::getAllByName( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::net::InetAddress > >( "getAllByName" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::net::InetAddress InetAddress::getLoopbackAddress() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::net::InetAddress >( "getLoopbackAddress" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::net::InetAddress InetAddress::getByAddress( ::jace::JArray< ::jace::proxy::types::JByte > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::net::InetAddress >( "getByAddress" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::net::InetAddress InetAddress::getLocalHost() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::net::InetAddress >( "getLocalHost" ).invoke( staticGetJavaJniClass(), arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
InetAddress::InetAddress( jvalue value ) InetAddress_INITIALIZER {
  setJavaJniValue( value );
}

InetAddress::InetAddress( jobject object ) InetAddress_INITIALIZER {
  setJavaJniObject( object );
}

InetAddress::InetAddress( const InetAddress& object ) InetAddress_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

InetAddress::InetAddress( const NoOp& noOp ) InetAddress_INITIALIZER {
}

const JClass* InetAddress::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/net/InetAddress" );
  return &javaClass;
}

const JClass* InetAddress::getJavaJniClass() const throw ( JNIException ) {
  return InetAddress::staticGetJavaJniClass();
}

JEnlister< InetAddress> InetAddress::enlister;

END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::net::InetAddress>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::net::InetAddress( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::net::InetAddress>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::net::InetAddress>& proxy ) : 
    ::jace::proxy::java::net::InetAddress( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::net::InetAddress>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::net::InetAddress( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::InetAddress>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::net::InetAddress( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::InetAddress>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::net::InetAddress>& object ) : 
    ::jace::proxy::java::net::InetAddress( object.getJavaJniValue() ), Object( NO_OP ) {

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

