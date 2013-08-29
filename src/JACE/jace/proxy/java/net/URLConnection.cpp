
#ifndef JACE_PROXY_JAVA_NET_URLCONNECTION_H
#include "jace/proxy/java/net/URLConnection.h"
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
#ifndef JACE_PROXY_JAVA_NET_FILENAMEMAP_H
#include "jace/proxy/java/net/FileNameMap.h"
#endif
#ifndef JACE_TYPES_JVOID_H
#include "jace/proxy/types/JVoid.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_URL_H
#include "jace/proxy/java/net/URL.h"
#endif
#ifndef JACE_TYPES_JLONG_H
#include "jace/proxy/types/JLong.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_MAP_H
#include "jace/proxy/java/util/Map.h"
#endif
#ifndef JACE_PROXY_JAVA_SECURITY_PERMISSION_H
#include "jace/proxy/java/security/Permission.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_INPUTSTREAM_H
#include "jace/proxy/java/io/InputStream.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_OUTPUTSTREAM_H
#include "jace/proxy/java/io/OutputStream.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_CONTENTHANDLERFACTORY_H
#include "jace/proxy/java/net/ContentHandlerFactory.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, net )

/**
 * The Jace C++ proxy class source for java/net/URLConnection.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define URLConnection_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define URLConnection_INITIALIZER
#endif

::jace::proxy::java::net::FileNameMap URLConnection::getFileNameMap() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::net::FileNameMap >( "getFileNameMap" ).invoke( staticGetJavaJniClass(), arguments );
}

void URLConnection::setFileNameMap( ::jace::proxy::java::net::FileNameMap p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setFileNameMap" ).invoke( staticGetJavaJniClass(), arguments );
}

void URLConnection::connect() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "connect" ).invoke( *this, arguments );
}

void URLConnection::setConnectTimeout( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setConnectTimeout" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt URLConnection::getConnectTimeout() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "getConnectTimeout" ).invoke( *this, arguments );
}

void URLConnection::setReadTimeout( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setReadTimeout" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt URLConnection::getReadTimeout() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "getReadTimeout" ).invoke( *this, arguments );
}

::jace::proxy::java::net::URL URLConnection::getURL() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::net::URL >( "getURL" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt URLConnection::getContentLength() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "getContentLength" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong URLConnection::getContentLengthLong() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "getContentLengthLong" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URLConnection::getContentType() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getContentType" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URLConnection::getContentEncoding() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getContentEncoding" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong URLConnection::getExpiration() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "getExpiration" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong URLConnection::getDate() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "getDate" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong URLConnection::getLastModified() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "getLastModified" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URLConnection::getHeaderField( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getHeaderField" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Map URLConnection::getHeaderFields() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Map >( "getHeaderFields" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt URLConnection::getHeaderFieldInt( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "getHeaderFieldInt" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong URLConnection::getHeaderFieldLong( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JLong p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "getHeaderFieldLong" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong URLConnection::getHeaderFieldDate( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JLong p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "getHeaderFieldDate" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URLConnection::getHeaderFieldKey( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getHeaderFieldKey" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URLConnection::getHeaderField( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getHeaderField" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object URLConnection::getContent() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "getContent" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object URLConnection::getContent( ::jace::JArray< ::jace::proxy::java::lang::Class > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "getContent" ).invoke( *this, arguments );
}

::jace::proxy::java::security::Permission URLConnection::getPermission() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::security::Permission >( "getPermission" ).invoke( *this, arguments );
}

::jace::proxy::java::io::InputStream URLConnection::getInputStream() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::io::InputStream >( "getInputStream" ).invoke( *this, arguments );
}

::jace::proxy::java::io::OutputStream URLConnection::getOutputStream() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::io::OutputStream >( "getOutputStream" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URLConnection::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

void URLConnection::setDoInput( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setDoInput" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean URLConnection::getDoInput() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "getDoInput" ).invoke( *this, arguments );
}

void URLConnection::setDoOutput( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setDoOutput" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean URLConnection::getDoOutput() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "getDoOutput" ).invoke( *this, arguments );
}

void URLConnection::setAllowUserInteraction( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setAllowUserInteraction" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean URLConnection::getAllowUserInteraction() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "getAllowUserInteraction" ).invoke( *this, arguments );
}

void URLConnection::setDefaultAllowUserInteraction( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setDefaultAllowUserInteraction" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::types::JBoolean URLConnection::getDefaultAllowUserInteraction() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "getDefaultAllowUserInteraction" ).invoke( staticGetJavaJniClass(), arguments );
}

void URLConnection::setUseCaches( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setUseCaches" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean URLConnection::getUseCaches() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "getUseCaches" ).invoke( *this, arguments );
}

void URLConnection::setIfModifiedSince( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setIfModifiedSince" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong URLConnection::getIfModifiedSince() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "getIfModifiedSince" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean URLConnection::getDefaultUseCaches() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "getDefaultUseCaches" ).invoke( *this, arguments );
}

void URLConnection::setDefaultUseCaches( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setDefaultUseCaches" ).invoke( *this, arguments );
}

void URLConnection::setRequestProperty( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setRequestProperty" ).invoke( *this, arguments );
}

void URLConnection::addRequestProperty( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "addRequestProperty" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URLConnection::getRequestProperty( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getRequestProperty" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Map URLConnection::getRequestProperties() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Map >( "getRequestProperties" ).invoke( *this, arguments );
}

void URLConnection::setDefaultRequestProperty( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setDefaultRequestProperty" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String URLConnection::getDefaultRequestProperty( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getDefaultRequestProperty" ).invoke( staticGetJavaJniClass(), arguments );
}

void URLConnection::setContentHandlerFactory( ::jace::proxy::java::net::ContentHandlerFactory p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setContentHandlerFactory" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String URLConnection::guessContentTypeFromName( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "guessContentTypeFromName" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String URLConnection::guessContentTypeFromStream( ::jace::proxy::java::io::InputStream p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "guessContentTypeFromStream" ).invoke( staticGetJavaJniClass(), arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
URLConnection::URLConnection( jvalue value ) URLConnection_INITIALIZER {
  setJavaJniValue( value );
}

URLConnection::URLConnection( jobject object ) URLConnection_INITIALIZER {
  setJavaJniObject( object );
}

URLConnection::URLConnection( const URLConnection& object ) URLConnection_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

URLConnection::URLConnection( const NoOp& noOp ) URLConnection_INITIALIZER {
}

const JClass* URLConnection::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/net/URLConnection" );
  return &javaClass;
}

const JClass* URLConnection::getJavaJniClass() const throw ( JNIException ) {
  return URLConnection::staticGetJavaJniClass();
}

JEnlister< URLConnection> URLConnection::enlister;

END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::net::URLConnection>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::net::URLConnection( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::net::URLConnection>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::net::URLConnection>& proxy ) : 
    ::jace::proxy::java::net::URLConnection( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::net::URLConnection>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::net::URLConnection( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::URLConnection>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::net::URLConnection( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::URLConnection>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::net::URLConnection>& object ) : 
    ::jace::proxy::java::net::URLConnection( object.getJavaJniValue() ), Object( NO_OP ) {

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

