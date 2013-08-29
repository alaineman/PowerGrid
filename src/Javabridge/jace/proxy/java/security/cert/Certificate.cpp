
#ifndef JACE_PROXY_JAVA_SECURITY_CERT_CERTIFICATE_H
#include "jace/proxy/java/security/cert/Certificate.h"
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
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_PROXY_JAVA_SECURITY_CERT_CERTIFICATEENCODINGEXCEPTION_H
#include "jace/proxy/java/security/cert/CertificateEncodingException.h"
#endif
#ifndef JACE_TYPES_JVOID_H
#include "jace/proxy/types/JVoid.h"
#endif
#ifndef JACE_PROXY_JAVA_SECURITY_PUBLICKEY_H
#include "jace/proxy/java/security/PublicKey.h"
#endif
#ifndef JACE_PROXY_JAVA_SECURITY_CERT_CERTIFICATEEXCEPTION_H
#include "jace/proxy/java/security/cert/CertificateException.h"
#endif
#ifndef JACE_PROXY_JAVA_SECURITY_NOSUCHALGORITHMEXCEPTION_H
#include "jace/proxy/java/security/NoSuchAlgorithmException.h"
#endif
#ifndef JACE_PROXY_JAVA_SECURITY_INVALIDKEYEXCEPTION_H
#include "jace/proxy/java/security/InvalidKeyException.h"
#endif
#ifndef JACE_PROXY_JAVA_SECURITY_NOSUCHPROVIDEREXCEPTION_H
#include "jace/proxy/java/security/NoSuchProviderException.h"
#endif
#ifndef JACE_PROXY_JAVA_SECURITY_SIGNATUREEXCEPTION_H
#include "jace/proxy/java/security/SignatureException.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, security, cert )

/**
 * The Jace C++ proxy class source for java/security/cert/Certificate.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Certificate_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Certificate_INITIALIZER
#endif

::jace::proxy::java::lang::String Certificate::getType() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getType" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Certificate::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt Certificate::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::types::JByte > Certificate::getEncoded() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::types::JByte > >( "getEncoded" ).invoke( *this, arguments );
}

void Certificate::verify( ::jace::proxy::java::security::PublicKey p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "verify" ).invoke( *this, arguments );
}

void Certificate::verify( ::jace::proxy::java::security::PublicKey p0, ::jace::proxy::java::lang::String p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "verify" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Certificate::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

::jace::proxy::java::security::PublicKey Certificate::getPublicKey() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::security::PublicKey >( "getPublicKey" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Certificate::Certificate( jvalue value ) Certificate_INITIALIZER {
  setJavaJniValue( value );
}

Certificate::Certificate( jobject object ) Certificate_INITIALIZER {
  setJavaJniObject( object );
}

Certificate::Certificate( const Certificate& object ) Certificate_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Certificate::Certificate( const NoOp& noOp ) Certificate_INITIALIZER {
}

const JClass* Certificate::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/security/cert/Certificate" );
  return &javaClass;
}

const JClass* Certificate::getJavaJniClass() const throw ( JNIException ) {
  return Certificate::staticGetJavaJniClass();
}

JEnlister< Certificate> Certificate::enlister;

END_NAMESPACE_5( jace, proxy, java, security, cert )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::security::cert::Certificate>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::security::cert::Certificate( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::security::cert::Certificate>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::security::cert::Certificate>& proxy ) : 
    ::jace::proxy::java::security::cert::Certificate( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::security::cert::Certificate>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::security::cert::Certificate( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::cert::Certificate>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::security::cert::Certificate( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::cert::Certificate>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::security::cert::Certificate>& object ) : 
    ::jace::proxy::java::security::cert::Certificate( object.getJavaJniValue() ), Object( NO_OP ) {

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

