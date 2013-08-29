
#ifndef JACE_PROXY_JAVA_NET_URI_H
#include "jace/proxy/java/net/URI.h"
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
#ifndef JACE_PROXY_JAVA_NET_URISYNTAXEXCEPTION_H
#include "jace/proxy/java/net/URISyntaxException.h"
#endif
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_URL_H
#include "jace/proxy/java/net/URL.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_MALFORMEDURLEXCEPTION_H
#include "jace/proxy/java/net/MalformedURLException.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, net )

/**
 * The Jace C++ proxy class source for java/net/URI.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define URI_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define URI_INITIALIZER
#endif

URI::URI( ::jace::proxy::java::lang::String p0 ) URI_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

URI::URI( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::java::lang::String p2, ::jace::proxy::types::JInt p3, ::jace::proxy::java::lang::String p4, ::jace::proxy::java::lang::String p5, ::jace::proxy::java::lang::String p6 ) URI_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3 << p4 << p5 << p6;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

URI::URI( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::java::lang::String p2, ::jace::proxy::java::lang::String p3, ::jace::proxy::java::lang::String p4 ) URI_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3 << p4;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

URI::URI( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::java::lang::String p2, ::jace::proxy::java::lang::String p3 ) URI_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

URI::URI( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::java::lang::String p2 ) URI_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::java::net::URI URI::create( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::net::URI >( "create" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::net::URI URI::parseServerAuthority() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::net::URI >( "parseServerAuthority" ).invoke( *this, arguments );
}

::jace::proxy::java::net::URI URI::normalize() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::net::URI >( "normalize" ).invoke( *this, arguments );
}

::jace::proxy::java::net::URI URI::resolve( ::jace::proxy::java::net::URI p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::net::URI >( "resolve" ).invoke( *this, arguments );
}

::jace::proxy::java::net::URI URI::resolve( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::net::URI >( "resolve" ).invoke( *this, arguments );
}

::jace::proxy::java::net::URI URI::relativize( ::jace::proxy::java::net::URI p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::net::URI >( "relativize" ).invoke( *this, arguments );
}

::jace::proxy::java::net::URL URI::toURL() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::net::URL >( "toURL" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URI::getScheme() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getScheme" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean URI::isAbsolute() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isAbsolute" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean URI::isOpaque() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isOpaque" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URI::getRawSchemeSpecificPart() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getRawSchemeSpecificPart" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URI::getSchemeSpecificPart() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getSchemeSpecificPart" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URI::getRawAuthority() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getRawAuthority" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URI::getAuthority() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getAuthority" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URI::getRawUserInfo() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getRawUserInfo" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URI::getUserInfo() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getUserInfo" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URI::getHost() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getHost" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt URI::getPort() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "getPort" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URI::getRawPath() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getRawPath" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URI::getPath() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getPath" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URI::getRawQuery() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getRawQuery" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URI::getQuery() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getQuery" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URI::getRawFragment() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getRawFragment" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URI::getFragment() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getFragment" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean URI::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt URI::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt URI::compareTo( ::jace::proxy::java::net::URI p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "compareTo" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URI::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URI::toASCIIString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toASCIIString" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
URI::URI( jvalue value ) URI_INITIALIZER {
  setJavaJniValue( value );
}

URI::URI( jobject object ) URI_INITIALIZER {
  setJavaJniObject( object );
}

URI::URI( const URI& object ) URI_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

URI::URI( const NoOp& noOp ) URI_INITIALIZER {
}

const JClass* URI::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/net/URI" );
  return &javaClass;
}

const JClass* URI::getJavaJniClass() const throw ( JNIException ) {
  return URI::staticGetJavaJniClass();
}

JEnlister< URI> URI::enlister;

END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::net::URI>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::net::URI( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::net::URI>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::net::URI>& proxy ) : 
    ::jace::proxy::java::net::URI( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::net::URI>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::net::URI( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::URI>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::net::URI( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::URI>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::net::URI>& object ) : 
    ::jace::proxy::java::net::URI( object.getJavaJniValue() ), Object( NO_OP ) {

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

