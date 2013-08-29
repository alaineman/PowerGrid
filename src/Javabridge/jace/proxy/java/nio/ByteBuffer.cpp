
#ifndef JACE_PROXY_JAVA_NIO_BYTEBUFFER_H
#include "jace/proxy/java/nio/ByteBuffer.h"
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
#ifndef JACE_TYPES_JBYTE_H
#include "jace/proxy/types/JByte.h"
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
#ifndef JACE_TYPES_JCHAR_H
#include "jace/proxy/types/JChar.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHARBUFFER_H
#include "jace/proxy/java/nio/CharBuffer.h"
#endif
#ifndef JACE_TYPES_JSHORT_H
#include "jace/proxy/types/JShort.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_SHORTBUFFER_H
#include "jace/proxy/java/nio/ShortBuffer.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_INTBUFFER_H
#include "jace/proxy/java/nio/IntBuffer.h"
#endif
#ifndef JACE_TYPES_JLONG_H
#include "jace/proxy/types/JLong.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_LONGBUFFER_H
#include "jace/proxy/java/nio/LongBuffer.h"
#endif
#ifndef JACE_TYPES_JFLOAT_H
#include "jace/proxy/types/JFloat.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FLOATBUFFER_H
#include "jace/proxy/java/nio/FloatBuffer.h"
#endif
#ifndef JACE_TYPES_JDOUBLE_H
#include "jace/proxy/types/JDouble.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_DOUBLEBUFFER_H
#include "jace/proxy/java/nio/DoubleBuffer.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, nio )

/**
 * The Jace C++ proxy class source for java/nio/ByteBuffer.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define ByteBuffer_INITIALIZER : ::jace::proxy::java::nio::Buffer( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define ByteBuffer_INITIALIZER : ::jace::proxy::java::nio::Buffer( NO_OP )
#endif

::jace::proxy::java::nio::ByteBuffer ByteBuffer::allocateDirect( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "allocateDirect" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::allocate( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "allocate" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::wrap( ::jace::JArray< ::jace::proxy::types::JByte > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "wrap" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::wrap( ::jace::JArray< ::jace::proxy::types::JByte > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "wrap" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::slice() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "slice" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::duplicate() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "duplicate" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::asReadOnlyBuffer() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "asReadOnlyBuffer" ).invoke( *this, arguments );
}

::jace::proxy::types::JByte ByteBuffer::get() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JByte >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::put( ::jace::proxy::types::JByte p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::types::JByte ByteBuffer::get( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JByte >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::put( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JByte p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::get( ::jace::JArray< ::jace::proxy::types::JByte > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::get( ::jace::JArray< ::jace::proxy::types::JByte > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::put( ::jace::proxy::java::nio::ByteBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::put( ::jace::JArray< ::jace::proxy::types::JByte > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::put( ::jace::JArray< ::jace::proxy::types::JByte > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean ByteBuffer::hasArray() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "hasArray" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::types::JByte > ByteBuffer::array() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::types::JByte > >( "array" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt ByteBuffer::arrayOffset() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "arrayOffset" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::compact() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "compact" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean ByteBuffer::isDirect() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isDirect" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String ByteBuffer::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt ByteBuffer::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean ByteBuffer::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt ByteBuffer::compareTo( ::jace::proxy::java::nio::ByteBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "compareTo" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteOrder ByteBuffer::order() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteOrder >( "order" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::order( ::jace::proxy::java::nio::ByteOrder p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "order" ).invoke( *this, arguments );
}

::jace::proxy::types::JChar ByteBuffer::getChar() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JChar >( "getChar" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::putChar( ::jace::proxy::types::JChar p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "putChar" ).invoke( *this, arguments );
}

::jace::proxy::types::JChar ByteBuffer::getChar( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JChar >( "getChar" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::putChar( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JChar p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "putChar" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::CharBuffer ByteBuffer::asCharBuffer() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "asCharBuffer" ).invoke( *this, arguments );
}

::jace::proxy::types::JShort ByteBuffer::getShort() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JShort >( "getShort" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::putShort( ::jace::proxy::types::JShort p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "putShort" ).invoke( *this, arguments );
}

::jace::proxy::types::JShort ByteBuffer::getShort( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JShort >( "getShort" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::putShort( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JShort p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "putShort" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ShortBuffer ByteBuffer::asShortBuffer() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::ShortBuffer >( "asShortBuffer" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt ByteBuffer::getInt() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "getInt" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::putInt( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "putInt" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt ByteBuffer::getInt( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "getInt" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::putInt( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "putInt" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::IntBuffer ByteBuffer::asIntBuffer() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::IntBuffer >( "asIntBuffer" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong ByteBuffer::getLong() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "getLong" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::putLong( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "putLong" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong ByteBuffer::getLong( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "getLong" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::putLong( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JLong p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "putLong" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::LongBuffer ByteBuffer::asLongBuffer() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::LongBuffer >( "asLongBuffer" ).invoke( *this, arguments );
}

::jace::proxy::types::JFloat ByteBuffer::getFloat() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JFloat >( "getFloat" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::putFloat( ::jace::proxy::types::JFloat p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "putFloat" ).invoke( *this, arguments );
}

::jace::proxy::types::JFloat ByteBuffer::getFloat( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JFloat >( "getFloat" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::putFloat( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JFloat p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "putFloat" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::FloatBuffer ByteBuffer::asFloatBuffer() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::FloatBuffer >( "asFloatBuffer" ).invoke( *this, arguments );
}

::jace::proxy::types::JDouble ByteBuffer::getDouble() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JDouble >( "getDouble" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::putDouble( ::jace::proxy::types::JDouble p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "putDouble" ).invoke( *this, arguments );
}

::jace::proxy::types::JDouble ByteBuffer::getDouble( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JDouble >( "getDouble" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer ByteBuffer::putDouble( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JDouble p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "putDouble" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::DoubleBuffer ByteBuffer::asDoubleBuffer() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::DoubleBuffer >( "asDoubleBuffer" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
ByteBuffer::ByteBuffer( jvalue value ) ByteBuffer_INITIALIZER {
  setJavaJniValue( value );
}

ByteBuffer::ByteBuffer( jobject object ) ByteBuffer_INITIALIZER {
  setJavaJniObject( object );
}

ByteBuffer::ByteBuffer( const ByteBuffer& object ) ByteBuffer_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

ByteBuffer::ByteBuffer( const NoOp& noOp ) ByteBuffer_INITIALIZER {
}

const JClass* ByteBuffer::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/ByteBuffer" );
  return &javaClass;
}

const JClass* ByteBuffer::getJavaJniClass() const throw ( JNIException ) {
  return ByteBuffer::staticGetJavaJniClass();
}

JEnlister< ByteBuffer> ByteBuffer::enlister;

END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::ByteBuffer>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::ByteBuffer( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::ByteBuffer>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::ByteBuffer>& proxy ) : 
    ::jace::proxy::java::nio::ByteBuffer( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::ByteBuffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::ByteBuffer( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::ByteBuffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::ByteBuffer( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::ByteBuffer>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::ByteBuffer>& object ) : 
    ::jace::proxy::java::nio::ByteBuffer( object.getJavaJniValue() ), Object( NO_OP ) {

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

