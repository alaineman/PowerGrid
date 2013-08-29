
#ifndef JACE_PROXY_JAVA_NET_URLSTREAMHANDLERFACTORY_H
#include "jace/proxy/java/net/URLStreamHandlerFactory.h"
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
#ifndef JACE_PROXY_JAVA_NET_URLSTREAMHANDLER_H
#include "jace/proxy/java/net/URLStreamHandler.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, net )

/**
 * The Jace C++ proxy class source for java/net/URLStreamHandlerFactory.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define URLStreamHandlerFactory_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define URLStreamHandlerFactory_INITIALIZER
#endif

::jace::proxy::java::net::URLStreamHandler URLStreamHandlerFactory::createURLStreamHandler( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::net::URLStreamHandler >( "createURLStreamHandler" ).invoke( *this, arguments );
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
URLStreamHandlerFactory::URLStreamHandlerFactory() : Object( NO_OP ) { 
}

URLStreamHandlerFactory::URLStreamHandlerFactory( jvalue value ) URLStreamHandlerFactory_INITIALIZER {
  setJavaJniValue( value );
}

URLStreamHandlerFactory::URLStreamHandlerFactory( jobject object ) URLStreamHandlerFactory_INITIALIZER {
  setJavaJniObject( object );
}

URLStreamHandlerFactory::URLStreamHandlerFactory( const URLStreamHandlerFactory& object ) URLStreamHandlerFactory_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

URLStreamHandlerFactory::URLStreamHandlerFactory( const NoOp& noOp ) URLStreamHandlerFactory_INITIALIZER {
}

const JClass* URLStreamHandlerFactory::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/net/URLStreamHandlerFactory" );
  return &javaClass;
}

const JClass* URLStreamHandlerFactory::getJavaJniClass() const throw ( JNIException ) {
  return URLStreamHandlerFactory::staticGetJavaJniClass();
}

JEnlister< URLStreamHandlerFactory> URLStreamHandlerFactory::enlister;

END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::net::URLStreamHandlerFactory>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::net::URLStreamHandlerFactory( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::net::URLStreamHandlerFactory>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::net::URLStreamHandlerFactory>& proxy ) : 
    ::jace::proxy::java::net::URLStreamHandlerFactory( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::net::URLStreamHandlerFactory>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::net::URLStreamHandlerFactory( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::URLStreamHandlerFactory>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::net::URLStreamHandlerFactory( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::URLStreamHandlerFactory>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::net::URLStreamHandlerFactory>& object ) : 
    ::jace::proxy::java::net::URLStreamHandlerFactory( object.getJavaJniValue() ), Object( NO_OP ) {

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

