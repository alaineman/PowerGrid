
#ifndef JACE_PROXY_JAVA_NIO_CHARSET_CODERRESULT_H
#include "jace/proxy/java/nio/charset/CoderResult.h"
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
#ifndef JACE_TYPES_JVOID_H
#include "jace/proxy/types/JVoid.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHARSET_CHARACTERCODINGEXCEPTION_H
#include "jace/proxy/java/nio/charset/CharacterCodingException.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, nio, charset )

/**
 * The Jace C++ proxy class source for java/nio/charset/CoderResult.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define CoderResult_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define CoderResult_INITIALIZER
#endif

::jace::proxy::java::lang::String CoderResult::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean CoderResult::isUnderflow() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isUnderflow" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean CoderResult::isOverflow() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isOverflow" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean CoderResult::isError() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isError" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean CoderResult::isMalformed() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isMalformed" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean CoderResult::isUnmappable() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isUnmappable" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt CoderResult::length() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "length" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::charset::CoderResult CoderResult::malformedForLength( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::CoderResult >( "malformedForLength" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::charset::CoderResult CoderResult::unmappableForLength( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::CoderResult >( "unmappableForLength" ).invoke( staticGetJavaJniClass(), arguments );
}

void CoderResult::throwException() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "throwException" ).invoke( *this, arguments );
}

/**
 * public static final UNDERFLOW_Jace
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::nio::charset::CoderResult > CoderResult::UNDERFLOW_Jace() {
  return ::jace::JField< ::jace::proxy::java::nio::charset::CoderResult >( "UNDERFLOW_Jace" ).get( staticGetJavaJniClass() );
}

/**
 * public static final OVERFLOW_Jace
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::nio::charset::CoderResult > CoderResult::OVERFLOW_Jace() {
  return ::jace::JField< ::jace::proxy::java::nio::charset::CoderResult >( "OVERFLOW_Jace" ).get( staticGetJavaJniClass() );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
CoderResult::CoderResult( jvalue value ) CoderResult_INITIALIZER {
  setJavaJniValue( value );
}

CoderResult::CoderResult( jobject object ) CoderResult_INITIALIZER {
  setJavaJniObject( object );
}

CoderResult::CoderResult( const CoderResult& object ) CoderResult_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

CoderResult::CoderResult( const NoOp& noOp ) CoderResult_INITIALIZER {
}

const JClass* CoderResult::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/charset/CoderResult" );
  return &javaClass;
}

const JClass* CoderResult::getJavaJniClass() const throw ( JNIException ) {
  return CoderResult::staticGetJavaJniClass();
}

JEnlister< CoderResult> CoderResult::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, charset )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::charset::CoderResult>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::charset::CoderResult( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::charset::CoderResult>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::charset::CoderResult>& proxy ) : 
    ::jace::proxy::java::nio::charset::CoderResult( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::charset::CoderResult>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::charset::CoderResult( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::charset::CoderResult>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::charset::CoderResult( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::charset::CoderResult>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::charset::CoderResult>& object ) : 
    ::jace::proxy::java::nio::charset::CoderResult( object.getJavaJniValue() ), Object( NO_OP ) {

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

