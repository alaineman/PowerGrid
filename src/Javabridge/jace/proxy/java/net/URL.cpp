
#ifndef JACE_PROXY_JAVA_NET_URL_H
#include "jace/proxy/java/net/URL.h"
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
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_MALFORMEDURLEXCEPTION_H
#include "jace/proxy/java/net/MalformedURLException.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_URLSTREAMHANDLER_H
#include "jace/proxy/java/net/URLStreamHandler.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_URI_H
#include "jace/proxy/java/net/URI.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_URISYNTAXEXCEPTION_H
#include "jace/proxy/java/net/URISyntaxException.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_URLCONNECTION_H
#include "jace/proxy/java/net/URLConnection.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_PROXY_H
#include "jace/proxy/java/net/Proxy.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_INPUTSTREAM_H
#include "jace/proxy/java/io/InputStream.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_URLSTREAMHANDLERFACTORY_H
#include "jace/proxy/java/net/URLStreamHandlerFactory.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, net )

/**
 * The Jace C++ proxy class source for java/net/URL.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define URL_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define URL_INITIALIZER
#endif

URL::URL( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::types::JInt p2, ::jace::proxy::java::lang::String p3 ) URL_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

URL::URL( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::java::lang::String p2 ) URL_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

URL::URL( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::types::JInt p2, ::jace::proxy::java::lang::String p3, ::jace::proxy::java::net::URLStreamHandler p4 ) URL_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3 << p4;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

URL::URL( ::jace::proxy::java::lang::String p0 ) URL_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

URL::URL( ::jace::proxy::java::net::URL p0, ::jace::proxy::java::lang::String p1 ) URL_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

URL::URL( ::jace::proxy::java::net::URL p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::java::net::URLStreamHandler p2 ) URL_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::java::lang::String URL::getQuery() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getQuery" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URL::getPath() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getPath" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URL::getUserInfo() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getUserInfo" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URL::getAuthority() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getAuthority" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt URL::getPort() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "getPort" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt URL::getDefaultPort() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "getDefaultPort" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URL::getProtocol() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getProtocol" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URL::getHost() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getHost" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URL::getFile() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getFile" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URL::getRef() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getRef" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean URL::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt URL::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean URL::sameFile( ::jace::proxy::java::net::URL p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "sameFile" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URL::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URL::toExternalForm() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toExternalForm" ).invoke( *this, arguments );
}

::jace::proxy::java::net::URI URL::toURI() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::net::URI >( "toURI" ).invoke( *this, arguments );
}

::jace::proxy::java::net::URLConnection URL::openConnection() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::net::URLConnection >( "openConnection" ).invoke( *this, arguments );
}

::jace::proxy::java::net::URLConnection URL::openConnection( ::jace::proxy::java::net::Proxy p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::net::URLConnection >( "openConnection" ).invoke( *this, arguments );
}

::jace::proxy::java::io::InputStream URL::openStream() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::io::InputStream >( "openStream" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object URL::getContent() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "getContent" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object URL::getContent( ::jace::JArray< ::jace::proxy::java::lang::Class > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "getContent" ).invoke( *this, arguments );
}

void URL::setURLStreamHandlerFactory( ::jace::proxy::java::net::URLStreamHandlerFactory p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setURLStreamHandlerFactory" ).invoke( staticGetJavaJniClass(), arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
URL::URL( jvalue value ) URL_INITIALIZER {
  setJavaJniValue( value );
}

URL::URL( jobject object ) URL_INITIALIZER {
  setJavaJniObject( object );
}

URL::URL( const URL& object ) URL_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

URL::URL( const NoOp& noOp ) URL_INITIALIZER {
}

const JClass* URL::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/net/URL" );
  return &javaClass;
}

const JClass* URL::getJavaJniClass() const throw ( JNIException ) {
  return URL::staticGetJavaJniClass();
}

JEnlister< URL> URL::enlister;

END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::net::URL>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::net::URL( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::net::URL>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::net::URL>& proxy ) : 
    ::jace::proxy::java::net::URL( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::net::URL>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::net::URL( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::URL>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::net::URL( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::URL>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::net::URL>& object ) : 
    ::jace::proxy::java::net::URL( object.getJavaJniValue() ), Object( NO_OP ) {

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

