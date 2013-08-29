
#ifndef JACE_PROXY_JAVA_NET_NETWORKINTERFACE_H
#include "jace/proxy/java/net/NetworkInterface.h"
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
#ifndef JACE_PROXY_JAVA_UTIL_ENUMERATION_H
#include "jace/proxy/java/util/Enumeration.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_LIST_H
#include "jace/proxy/java/util/List.h"
#endif
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_SOCKETEXCEPTION_H
#include "jace/proxy/java/net/SocketException.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_INETADDRESS_H
#include "jace/proxy/java/net/InetAddress.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, net )

/**
 * The Jace C++ proxy class source for java/net/NetworkInterface.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define NetworkInterface_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define NetworkInterface_INITIALIZER
#endif

::jace::proxy::java::lang::String NetworkInterface::getName() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getName" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Enumeration NetworkInterface::getInetAddresses() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Enumeration >( "getInetAddresses" ).invoke( *this, arguments );
}

::jace::proxy::java::util::List NetworkInterface::getInterfaceAddresses() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::List >( "getInterfaceAddresses" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Enumeration NetworkInterface::getSubInterfaces() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Enumeration >( "getSubInterfaces" ).invoke( *this, arguments );
}

::jace::proxy::java::net::NetworkInterface NetworkInterface::getParent() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::net::NetworkInterface >( "getParent" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt NetworkInterface::getIndex() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "getIndex" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String NetworkInterface::getDisplayName() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getDisplayName" ).invoke( *this, arguments );
}

::jace::proxy::java::net::NetworkInterface NetworkInterface::getByName( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::net::NetworkInterface >( "getByName" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::net::NetworkInterface NetworkInterface::getByIndex( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::net::NetworkInterface >( "getByIndex" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::net::NetworkInterface NetworkInterface::getByInetAddress( ::jace::proxy::java::net::InetAddress p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::net::NetworkInterface >( "getByInetAddress" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::util::Enumeration NetworkInterface::getNetworkInterfaces() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Enumeration >( "getNetworkInterfaces" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::types::JBoolean NetworkInterface::isUp() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isUp" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean NetworkInterface::isLoopback() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isLoopback" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean NetworkInterface::isPointToPoint() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isPointToPoint" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean NetworkInterface::supportsMulticast() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "supportsMulticast" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::types::JByte > NetworkInterface::getHardwareAddress() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::types::JByte > >( "getHardwareAddress" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt NetworkInterface::getMTU() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "getMTU" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean NetworkInterface::isVirtual() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isVirtual" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean NetworkInterface::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt NetworkInterface::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String NetworkInterface::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
NetworkInterface::NetworkInterface( jvalue value ) NetworkInterface_INITIALIZER {
  setJavaJniValue( value );
}

NetworkInterface::NetworkInterface( jobject object ) NetworkInterface_INITIALIZER {
  setJavaJniObject( object );
}

NetworkInterface::NetworkInterface( const NetworkInterface& object ) NetworkInterface_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

NetworkInterface::NetworkInterface( const NoOp& noOp ) NetworkInterface_INITIALIZER {
}

const JClass* NetworkInterface::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/net/NetworkInterface" );
  return &javaClass;
}

const JClass* NetworkInterface::getJavaJniClass() const throw ( JNIException ) {
  return NetworkInterface::staticGetJavaJniClass();
}

JEnlister< NetworkInterface> NetworkInterface::enlister;

END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::net::NetworkInterface>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::net::NetworkInterface( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::net::NetworkInterface>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::net::NetworkInterface>& proxy ) : 
    ::jace::proxy::java::net::NetworkInterface( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::net::NetworkInterface>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::net::NetworkInterface( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::NetworkInterface>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::net::NetworkInterface( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::NetworkInterface>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::net::NetworkInterface>& object ) : 
    ::jace::proxy::java::net::NetworkInterface( object.getJavaJniValue() ), Object( NO_OP ) {

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

