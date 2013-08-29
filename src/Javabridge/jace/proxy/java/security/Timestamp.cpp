
#ifndef JACE_PROXY_JAVA_SECURITY_TIMESTAMP_H
#include "jace/proxy/java/security/Timestamp.h"
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
#ifndef JACE_PROXY_JAVA_UTIL_DATE_H
#include "jace/proxy/java/util/Date.h"
#endif
#ifndef JACE_PROXY_JAVA_SECURITY_CERT_CERTPATH_H
#include "jace/proxy/java/security/cert/CertPath.h"
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
 * The Jace C++ proxy class source for java/security/Timestamp.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Timestamp_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Timestamp_INITIALIZER
#endif

Timestamp::Timestamp( ::jace::proxy::java::util::Date p0, ::jace::proxy::java::security::cert::CertPath p1 ) Timestamp_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::java::util::Date Timestamp::getTimestamp() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Date >( "getTimestamp" ).invoke( *this, arguments );
}

::jace::proxy::java::security::cert::CertPath Timestamp::getSignerCertPath() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::security::cert::CertPath >( "getSignerCertPath" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt Timestamp::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Timestamp::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Timestamp::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Timestamp::Timestamp( jvalue value ) Timestamp_INITIALIZER {
  setJavaJniValue( value );
}

Timestamp::Timestamp( jobject object ) Timestamp_INITIALIZER {
  setJavaJniObject( object );
}

Timestamp::Timestamp( const Timestamp& object ) Timestamp_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Timestamp::Timestamp( const NoOp& noOp ) Timestamp_INITIALIZER {
}

const JClass* Timestamp::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/security/Timestamp" );
  return &javaClass;
}

const JClass* Timestamp::getJavaJniClass() const throw ( JNIException ) {
  return Timestamp::staticGetJavaJniClass();
}

JEnlister< Timestamp> Timestamp::enlister;

END_NAMESPACE_4( jace, proxy, java, security )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::security::Timestamp>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::security::Timestamp( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::security::Timestamp>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::security::Timestamp>& proxy ) : 
    ::jace::proxy::java::security::Timestamp( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::security::Timestamp>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::security::Timestamp( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::Timestamp>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::security::Timestamp( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::Timestamp>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::security::Timestamp>& object ) : 
    ::jace::proxy::java::security::Timestamp( object.getJavaJniValue() ), Object( NO_OP ) {

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

