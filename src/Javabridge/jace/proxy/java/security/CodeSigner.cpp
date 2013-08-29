
#ifndef JACE_PROXY_JAVA_SECURITY_CODESIGNER_H
#include "jace/proxy/java/security/CodeSigner.h"
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
#ifndef JACE_PROXY_JAVA_SECURITY_CERT_CERTPATH_H
#include "jace/proxy/java/security/cert/CertPath.h"
#endif
#ifndef JACE_PROXY_JAVA_SECURITY_TIMESTAMP_H
#include "jace/proxy/java/security/Timestamp.h"
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
 * The Jace C++ proxy class source for java/security/CodeSigner.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define CodeSigner_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define CodeSigner_INITIALIZER
#endif

CodeSigner::CodeSigner( ::jace::proxy::java::security::cert::CertPath p0, ::jace::proxy::java::security::Timestamp p1 ) CodeSigner_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::java::security::cert::CertPath CodeSigner::getSignerCertPath() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::security::cert::CertPath >( "getSignerCertPath" ).invoke( *this, arguments );
}

::jace::proxy::java::security::Timestamp CodeSigner::getTimestamp() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::security::Timestamp >( "getTimestamp" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt CodeSigner::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean CodeSigner::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String CodeSigner::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
CodeSigner::CodeSigner( jvalue value ) CodeSigner_INITIALIZER {
  setJavaJniValue( value );
}

CodeSigner::CodeSigner( jobject object ) CodeSigner_INITIALIZER {
  setJavaJniObject( object );
}

CodeSigner::CodeSigner( const CodeSigner& object ) CodeSigner_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

CodeSigner::CodeSigner( const NoOp& noOp ) CodeSigner_INITIALIZER {
}

const JClass* CodeSigner::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/security/CodeSigner" );
  return &javaClass;
}

const JClass* CodeSigner::getJavaJniClass() const throw ( JNIException ) {
  return CodeSigner::staticGetJavaJniClass();
}

JEnlister< CodeSigner> CodeSigner::enlister;

END_NAMESPACE_4( jace, proxy, java, security )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::security::CodeSigner>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::security::CodeSigner( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::security::CodeSigner>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::security::CodeSigner>& proxy ) : 
    ::jace::proxy::java::security::CodeSigner( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::security::CodeSigner>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::security::CodeSigner( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::CodeSigner>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::security::CodeSigner( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::CodeSigner>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::security::CodeSigner>& object ) : 
    ::jace::proxy::java::security::CodeSigner( object.getJavaJniValue() ), Object( NO_OP ) {

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

