
#ifndef JACE_PROXY_JAVA_NIO_CHARBUFFER_H
#include "jace/proxy/java/nio/CharBuffer.h"
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
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif
#ifndef JACE_TYPES_JCHAR_H
#include "jace/proxy/types/JChar.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_OBJECT_H
#include "jace/proxy/java/lang/Object.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_BYTEORDER_H
#include "jace/proxy/java/nio/ByteOrder.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, nio )

/**
 * The Jace C++ proxy class source for java/nio/CharBuffer.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define CharBuffer_INITIALIZER : ::jace::proxy::java::nio::Buffer( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define CharBuffer_INITIALIZER : ::jace::proxy::java::nio::Buffer( NO_OP )
#endif

::jace::proxy::java::nio::CharBuffer CharBuffer::allocate( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "allocate" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::CharBuffer CharBuffer::wrap( ::jace::JArray< ::jace::proxy::types::JChar > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "wrap" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::CharBuffer CharBuffer::wrap( ::jace::JArray< ::jace::proxy::types::JChar > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "wrap" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::types::JInt CharBuffer::read( ::jace::proxy::java::nio::CharBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "read" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::CharBuffer CharBuffer::wrap( ::jace::proxy::java::lang::CharSequence p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "wrap" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::CharBuffer CharBuffer::wrap( ::jace::proxy::java::lang::CharSequence p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "wrap" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::CharBuffer CharBuffer::slice() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "slice" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::CharBuffer CharBuffer::duplicate() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "duplicate" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::CharBuffer CharBuffer::asReadOnlyBuffer() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "asReadOnlyBuffer" ).invoke( *this, arguments );
}

::jace::proxy::types::JChar CharBuffer::get() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JChar >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::CharBuffer CharBuffer::put( ::jace::proxy::types::JChar p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::types::JChar CharBuffer::get( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JChar >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::CharBuffer CharBuffer::put( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JChar p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::CharBuffer CharBuffer::get( ::jace::JArray< ::jace::proxy::types::JChar > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::CharBuffer CharBuffer::get( ::jace::JArray< ::jace::proxy::types::JChar > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::CharBuffer CharBuffer::put( ::jace::proxy::java::nio::CharBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::CharBuffer CharBuffer::put( ::jace::JArray< ::jace::proxy::types::JChar > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::CharBuffer CharBuffer::put( ::jace::JArray< ::jace::proxy::types::JChar > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::CharBuffer CharBuffer::put( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::CharBuffer CharBuffer::put( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean CharBuffer::hasArray() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "hasArray" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::types::JChar > CharBuffer::array() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::types::JChar > >( "array" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt CharBuffer::arrayOffset() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "arrayOffset" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::CharBuffer CharBuffer::compact() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "compact" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean CharBuffer::isDirect() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isDirect" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt CharBuffer::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean CharBuffer::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt CharBuffer::compareTo( ::jace::proxy::java::nio::CharBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "compareTo" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String CharBuffer::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt CharBuffer::length() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "length" ).invoke( *this, arguments );
}

::jace::proxy::types::JChar CharBuffer::charAt( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JChar >( "charAt" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::CharBuffer CharBuffer::subSequence( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "subSequence" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::CharBuffer CharBuffer::append( ::jace::proxy::java::lang::CharSequence p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::CharBuffer CharBuffer::append( ::jace::proxy::java::lang::CharSequence p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::CharBuffer CharBuffer::append( ::jace::proxy::types::JChar p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteOrder CharBuffer::order() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteOrder >( "order" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
CharBuffer::CharBuffer( jvalue value ) CharBuffer_INITIALIZER {
  setJavaJniValue( value );
}

CharBuffer::CharBuffer( jobject object ) CharBuffer_INITIALIZER {
  setJavaJniObject( object );
}

CharBuffer::CharBuffer( const CharBuffer& object ) CharBuffer_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

CharBuffer::CharBuffer( const NoOp& noOp ) CharBuffer_INITIALIZER {
}

const JClass* CharBuffer::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/CharBuffer" );
  return &javaClass;
}

const JClass* CharBuffer::getJavaJniClass() const throw ( JNIException ) {
  return CharBuffer::staticGetJavaJniClass();
}

JEnlister< CharBuffer> CharBuffer::enlister;

END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::CharBuffer>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::CharBuffer( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::CharBuffer>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::CharBuffer>& proxy ) : 
    ::jace::proxy::java::nio::CharBuffer( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::CharBuffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::CharBuffer( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::CharBuffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::CharBuffer( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::CharBuffer>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::CharBuffer>& object ) : 
    ::jace::proxy::java::nio::CharBuffer( object.getJavaJniValue() ), Object( NO_OP ) {

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

