
#ifndef JACE_PROXY_JAVA_SECURITY_CERT_CERTPATH_H
#include "jace/proxy/java/security/cert/CertPath.h"
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
#ifndef JACE_PROXY_JAVA_UTIL_ITERATOR_H
#include "jace/proxy/java/util/Iterator.h"
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
#ifndef JACE_PROXY_JAVA_UTIL_LIST_H
#include "jace/proxy/java/util/List.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, security, cert )

/**
 * The Jace C++ proxy class source for java/security/cert/CertPath.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define CertPath_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define CertPath_INITIALIZER
#endif

::jace::proxy::java::lang::String CertPath::getType() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getType" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Iterator CertPath::getEncodings() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Iterator >( "getEncodings" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean CertPath::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt CertPath::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String CertPath::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::types::JByte > CertPath::getEncoded() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::types::JByte > >( "getEncoded" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::types::JByte > CertPath::getEncoded( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::types::JByte > >( "getEncoded" ).invoke( *this, arguments );
}

::jace::proxy::java::util::List CertPath::getCertificates() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::List >( "getCertificates" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
CertPath::CertPath( jvalue value ) CertPath_INITIALIZER {
  setJavaJniValue( value );
}

CertPath::CertPath( jobject object ) CertPath_INITIALIZER {
  setJavaJniObject( object );
}

CertPath::CertPath( const CertPath& object ) CertPath_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

CertPath::CertPath( const NoOp& noOp ) CertPath_INITIALIZER {
}

const JClass* CertPath::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/security/cert/CertPath" );
  return &javaClass;
}

const JClass* CertPath::getJavaJniClass() const throw ( JNIException ) {
  return CertPath::staticGetJavaJniClass();
}

JEnlister< CertPath> CertPath::enlister;

END_NAMESPACE_5( jace, proxy, java, security, cert )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::security::cert::CertPath>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::security::cert::CertPath( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::security::cert::CertPath>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::security::cert::CertPath>& proxy ) : 
    ::jace::proxy::java::security::cert::CertPath( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::security::cert::CertPath>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::security::cert::CertPath( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::cert::CertPath>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::security::cert::CertPath( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::cert::CertPath>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::security::cert::CertPath>& object ) : 
    ::jace::proxy::java::security::cert::CertPath( object.getJavaJniValue() ), Object( NO_OP ) {

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

