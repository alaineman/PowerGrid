
#ifndef JACE_PROXY_JAVA_SECURITY_CODESOURCE_H
#include "jace/proxy/java/security/CodeSource.h"
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
#ifndef JACE_PROXY_JAVA_NET_URL_H
#include "jace/proxy/java/net/URL.h"
#endif
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, security )

/**
 * The Jace C++ proxy class source for java/security/CodeSource.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define CodeSource_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define CodeSource_INITIALIZER
#endif

CodeSource::CodeSource( ::jace::proxy::java::net::URL p0, ::jace::JArray< ::jace::proxy::java::security::cert::Certificate > p1 ) CodeSource_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

CodeSource::CodeSource( ::jace::proxy::java::net::URL p0, ::jace::JArray< ::jace::proxy::java::security::CodeSigner > p1 ) CodeSource_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::types::JInt CodeSource::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean CodeSource::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::java::net::URL CodeSource::getLocation() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::net::URL >( "getLocation" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::security::cert::Certificate > CodeSource::getCertificates() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::security::cert::Certificate > >( "getCertificates" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::security::CodeSigner > CodeSource::getCodeSigners() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::security::CodeSigner > >( "getCodeSigners" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean CodeSource::implies( ::jace::proxy::java::security::CodeSource p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "implies" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String CodeSource::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
CodeSource::CodeSource( jvalue value ) CodeSource_INITIALIZER {
  setJavaJniValue( value );
}

CodeSource::CodeSource( jobject object ) CodeSource_INITIALIZER {
  setJavaJniObject( object );
}

CodeSource::CodeSource( const CodeSource& object ) CodeSource_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

CodeSource::CodeSource( const NoOp& noOp ) CodeSource_INITIALIZER {
}

const JClass* CodeSource::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/security/CodeSource" );
  return &javaClass;
}

const JClass* CodeSource::getJavaJniClass() const throw ( JNIException ) {
  return CodeSource::staticGetJavaJniClass();
}

JEnlister< CodeSource> CodeSource::enlister;

END_NAMESPACE_4( jace, proxy, java, security )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::security::CodeSource>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::security::CodeSource( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::security::CodeSource>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::security::CodeSource>& proxy ) : 
    ::jace::proxy::java::security::CodeSource( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::security::CodeSource>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::security::CodeSource( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::CodeSource>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::security::CodeSource( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::CodeSource>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::security::CodeSource>& object ) : 
    ::jace::proxy::java::security::CodeSource( object.getJavaJniValue() ), Object( NO_OP ) {

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

