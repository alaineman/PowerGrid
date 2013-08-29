
#ifndef JACE_PROXY_JAVA_NIO_FLOATBUFFER_H
#include "jace/proxy/java/nio/FloatBuffer.h"
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
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_TYPES_JFLOAT_H
#include "jace/proxy/types/JFloat.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_OBJECT_H
#include "jace/proxy/java/lang/Object.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_BYTEORDER_H
#include "jace/proxy/java/nio/ByteOrder.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, nio )

/**
 * The Jace C++ proxy class source for java/nio/FloatBuffer.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define FloatBuffer_INITIALIZER : ::jace::proxy::java::nio::Buffer( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define FloatBuffer_INITIALIZER : ::jace::proxy::java::nio::Buffer( NO_OP )
#endif

::jace::proxy::java::nio::FloatBuffer FloatBuffer::allocate( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::FloatBuffer >( "allocate" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::FloatBuffer FloatBuffer::wrap( ::jace::JArray< ::jace::proxy::types::JFloat > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::FloatBuffer >( "wrap" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::FloatBuffer FloatBuffer::wrap( ::jace::JArray< ::jace::proxy::types::JFloat > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::FloatBuffer >( "wrap" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::FloatBuffer FloatBuffer::slice() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::FloatBuffer >( "slice" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::FloatBuffer FloatBuffer::duplicate() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::FloatBuffer >( "duplicate" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::FloatBuffer FloatBuffer::asReadOnlyBuffer() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::FloatBuffer >( "asReadOnlyBuffer" ).invoke( *this, arguments );
}

::jace::proxy::types::JFloat FloatBuffer::get() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JFloat >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::FloatBuffer FloatBuffer::put( ::jace::proxy::types::JFloat p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::FloatBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::types::JFloat FloatBuffer::get( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JFloat >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::FloatBuffer FloatBuffer::put( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JFloat p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::nio::FloatBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::FloatBuffer FloatBuffer::get( ::jace::JArray< ::jace::proxy::types::JFloat > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::FloatBuffer >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::FloatBuffer FloatBuffer::get( ::jace::JArray< ::jace::proxy::types::JFloat > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::FloatBuffer >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::FloatBuffer FloatBuffer::put( ::jace::proxy::java::nio::FloatBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::FloatBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::FloatBuffer FloatBuffer::put( ::jace::JArray< ::jace::proxy::types::JFloat > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::FloatBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::FloatBuffer FloatBuffer::put( ::jace::JArray< ::jace::proxy::types::JFloat > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::FloatBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean FloatBuffer::hasArray() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "hasArray" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::types::JFloat > FloatBuffer::array() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::types::JFloat > >( "array" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt FloatBuffer::arrayOffset() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "arrayOffset" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::FloatBuffer FloatBuffer::compact() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::FloatBuffer >( "compact" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean FloatBuffer::isDirect() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isDirect" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String FloatBuffer::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt FloatBuffer::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean FloatBuffer::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt FloatBuffer::compareTo( ::jace::proxy::java::nio::FloatBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "compareTo" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteOrder FloatBuffer::order() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteOrder >( "order" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
FloatBuffer::FloatBuffer( jvalue value ) FloatBuffer_INITIALIZER {
  setJavaJniValue( value );
}

FloatBuffer::FloatBuffer( jobject object ) FloatBuffer_INITIALIZER {
  setJavaJniObject( object );
}

FloatBuffer::FloatBuffer( const FloatBuffer& object ) FloatBuffer_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

FloatBuffer::FloatBuffer( const NoOp& noOp ) FloatBuffer_INITIALIZER {
}

const JClass* FloatBuffer::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/FloatBuffer" );
  return &javaClass;
}

const JClass* FloatBuffer::getJavaJniClass() const throw ( JNIException ) {
  return FloatBuffer::staticGetJavaJniClass();
}

JEnlister< FloatBuffer> FloatBuffer::enlister;

END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::FloatBuffer>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::FloatBuffer( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::FloatBuffer>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::FloatBuffer>& proxy ) : 
    ::jace::proxy::java::nio::FloatBuffer( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::FloatBuffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::FloatBuffer( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::FloatBuffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::FloatBuffer( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::FloatBuffer>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::FloatBuffer>& object ) : 
    ::jace::proxy::java::nio::FloatBuffer( object.getJavaJniValue() ), Object( NO_OP ) {

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

