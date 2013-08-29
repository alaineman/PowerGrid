
#ifndef JACE_PROXY_JAVA_NET_URISYNTAXEXCEPTION_H
#include "jace/proxy/java/net/URISyntaxException.h"
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

BEGIN_NAMESPACE_4( jace, proxy, java, net )

/**
 * The Jace C++ proxy class source for java/net/URISyntaxException.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define URISyntaxException_INITIALIZER : ::jace::proxy::java::lang::Exception( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define URISyntaxException_INITIALIZER : ::jace::proxy::java::lang::Exception( NO_OP )
#endif

URISyntaxException::URISyntaxException( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::types::JInt p2 ) URISyntaxException_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

URISyntaxException::URISyntaxException( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 ) URISyntaxException_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::java::lang::String URISyntaxException::getInput() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getInput" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URISyntaxException::getReason() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getReason" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt URISyntaxException::getIndex() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "getIndex" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String URISyntaxException::getMessage() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getMessage" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
URISyntaxException::URISyntaxException( jvalue value ) URISyntaxException_INITIALIZER {
  setJavaJniValue( value );
}

URISyntaxException::URISyntaxException( jobject object ) URISyntaxException_INITIALIZER {
  setJavaJniObject( object );
}

URISyntaxException::URISyntaxException( const URISyntaxException& object ) URISyntaxException_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

URISyntaxException::URISyntaxException( const NoOp& noOp ) URISyntaxException_INITIALIZER {
}

const JClass* URISyntaxException::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/net/URISyntaxException" );
  return &javaClass;
}

const JClass* URISyntaxException::getJavaJniClass() const throw ( JNIException ) {
  return URISyntaxException::staticGetJavaJniClass();
}

JEnlister< URISyntaxException> URISyntaxException::enlister;

END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::net::URISyntaxException>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::net::URISyntaxException( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::net::URISyntaxException>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::net::URISyntaxException>& proxy ) : 
    ::jace::proxy::java::net::URISyntaxException( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::net::URISyntaxException>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::net::URISyntaxException( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::URISyntaxException>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::net::URISyntaxException( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::URISyntaxException>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::net::URISyntaxException>& object ) : 
    ::jace::proxy::java::net::URISyntaxException( object.getJavaJniValue() ), Object( NO_OP ) {

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

