
#ifndef JACE_PROXY_JAVA_SECURITY_SIGNATUREEXCEPTION_H
#include "jace/proxy/java/security/SignatureException.h"
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

BEGIN_NAMESPACE_4( jace, proxy, java, security )

/**
 * The Jace C++ proxy class source for java/security/SignatureException.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define SignatureException_INITIALIZER : ::jace::proxy::java::security::GeneralSecurityException( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define SignatureException_INITIALIZER : ::jace::proxy::java::security::GeneralSecurityException( NO_OP )
#endif

SignatureException::SignatureException() SignatureException_INITIALIZER {
  ::jace::JArguments arguments;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

SignatureException::SignatureException( ::jace::proxy::java::lang::String p0 ) SignatureException_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

SignatureException::SignatureException( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::Throwable p1 ) SignatureException_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

SignatureException::SignatureException( ::jace::proxy::java::lang::Throwable p0 ) SignatureException_INITIALIZER {
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
SignatureException::SignatureException( jvalue value ) SignatureException_INITIALIZER {
  setJavaJniValue( value );
}

SignatureException::SignatureException( jobject object ) SignatureException_INITIALIZER {
  setJavaJniObject( object );
}

SignatureException::SignatureException( const SignatureException& object ) SignatureException_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

SignatureException::SignatureException( const NoOp& noOp ) SignatureException_INITIALIZER {
}

const JClass* SignatureException::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/security/SignatureException" );
  return &javaClass;
}

const JClass* SignatureException::getJavaJniClass() const throw ( JNIException ) {
  return SignatureException::staticGetJavaJniClass();
}

JEnlister< SignatureException> SignatureException::enlister;

END_NAMESPACE_4( jace, proxy, java, security )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::security::SignatureException>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::security::SignatureException( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::security::SignatureException>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::security::SignatureException>& proxy ) : 
    ::jace::proxy::java::security::SignatureException( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::security::SignatureException>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::security::SignatureException( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::SignatureException>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::security::SignatureException( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::SignatureException>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::security::SignatureException>& object ) : 
    ::jace::proxy::java::security::SignatureException( object.getJavaJniValue() ), Object( NO_OP ) {

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

