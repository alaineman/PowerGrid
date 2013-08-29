
#ifndef JACE_PROXY_JAVA_NET_CONTENTHANDLER_H
#include "jace/proxy/java/net/ContentHandler.h"
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
#ifndef JACE_PROXY_JAVA_NET_URLCONNECTION_H
#include "jace/proxy/java/net/URLConnection.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, net )

/**
 * The Jace C++ proxy class source for java/net/ContentHandler.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define ContentHandler_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define ContentHandler_INITIALIZER
#endif

ContentHandler::ContentHandler() ContentHandler_INITIALIZER {
  ::jace::JArguments arguments;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::java::lang::Object ContentHandler::getContent( ::jace::proxy::java::net::URLConnection p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "getContent" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object ContentHandler::getContent( ::jace::proxy::java::net::URLConnection p0, ::jace::JArray< ::jace::proxy::java::lang::Class > p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "getContent" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
ContentHandler::ContentHandler( jvalue value ) ContentHandler_INITIALIZER {
  setJavaJniValue( value );
}

ContentHandler::ContentHandler( jobject object ) ContentHandler_INITIALIZER {
  setJavaJniObject( object );
}

ContentHandler::ContentHandler( const ContentHandler& object ) ContentHandler_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

ContentHandler::ContentHandler( const NoOp& noOp ) ContentHandler_INITIALIZER {
}

const JClass* ContentHandler::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/net/ContentHandler" );
  return &javaClass;
}

const JClass* ContentHandler::getJavaJniClass() const throw ( JNIException ) {
  return ContentHandler::staticGetJavaJniClass();
}

JEnlister< ContentHandler> ContentHandler::enlister;

END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::net::ContentHandler>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::net::ContentHandler( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::net::ContentHandler>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::net::ContentHandler>& proxy ) : 
    ::jace::proxy::java::net::ContentHandler( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::net::ContentHandler>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::net::ContentHandler( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::ContentHandler>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::net::ContentHandler( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::ContentHandler>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::net::ContentHandler>& object ) : 
    ::jace::proxy::java::net::ContentHandler( object.getJavaJniValue() ), Object( NO_OP ) {

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

