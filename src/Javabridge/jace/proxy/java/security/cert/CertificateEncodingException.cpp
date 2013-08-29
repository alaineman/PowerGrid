
#ifndef JACE_PROXY_JAVA_SECURITY_CERT_CERTIFICATEENCODINGEXCEPTION_H
#include "jace/proxy/java/security/cert/CertificateEncodingException.h"
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
#ifndef JACE_PROXY_JAVA_LANG_THROWABLE_H
#include "jace/proxy/java/lang/Throwable.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, security, cert )

/**
 * The Jace C++ proxy class source for java/security/cert/CertificateEncodingException.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define CertificateEncodingException_INITIALIZER : ::jace::proxy::java::security::cert::CertificateException( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define CertificateEncodingException_INITIALIZER : ::jace::proxy::java::security::cert::CertificateException( NO_OP )
#endif

CertificateEncodingException::CertificateEncodingException() CertificateEncodingException_INITIALIZER {
  ::jace::JArguments arguments;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

CertificateEncodingException::CertificateEncodingException( ::jace::proxy::java::lang::String p0 ) CertificateEncodingException_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

CertificateEncodingException::CertificateEncodingException( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::Throwable p1 ) CertificateEncodingException_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

CertificateEncodingException::CertificateEncodingException( ::jace::proxy::java::lang::Throwable p0 ) CertificateEncodingException_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
CertificateEncodingException::CertificateEncodingException( jvalue value ) CertificateEncodingException_INITIALIZER {
  setJavaJniValue( value );
}

CertificateEncodingException::CertificateEncodingException( jobject object ) CertificateEncodingException_INITIALIZER {
  setJavaJniObject( object );
}

CertificateEncodingException::CertificateEncodingException( const CertificateEncodingException& object ) CertificateEncodingException_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

CertificateEncodingException::CertificateEncodingException( const NoOp& noOp ) CertificateEncodingException_INITIALIZER {
}

const JClass* CertificateEncodingException::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/security/cert/CertificateEncodingException" );
  return &javaClass;
}

const JClass* CertificateEncodingException::getJavaJniClass() const throw ( JNIException ) {
  return CertificateEncodingException::staticGetJavaJniClass();
}

JEnlister< CertificateEncodingException> CertificateEncodingException::enlister;

END_NAMESPACE_5( jace, proxy, java, security, cert )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::security::cert::CertificateEncodingException>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::security::cert::CertificateEncodingException( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::security::cert::CertificateEncodingException>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::security::cert::CertificateEncodingException>& proxy ) : 
    ::jace::proxy::java::security::cert::CertificateEncodingException( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::security::cert::CertificateEncodingException>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::security::cert::CertificateEncodingException( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::cert::CertificateEncodingException>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::security::cert::CertificateEncodingException( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::cert::CertificateEncodingException>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::security::cert::CertificateEncodingException>& object ) : 
    ::jace::proxy::java::security::cert::CertificateEncodingException( object.getJavaJniValue() ), Object( NO_OP ) {

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

