
#ifndef JACE_PROXY_JAVA_NIO_SHORTBUFFER_H
#include "jace/proxy/java/nio/ShortBuffer.h"
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
#ifndef JACE_TYPES_JSHORT_H
#include "jace/proxy/types/JShort.h"
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
 * The Jace C++ proxy class source for java/nio/ShortBuffer.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define ShortBuffer_INITIALIZER : ::jace::proxy::java::nio::Buffer( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define ShortBuffer_INITIALIZER : ::jace::proxy::java::nio::Buffer( NO_OP )
#endif

::jace::proxy::java::nio::ShortBuffer ShortBuffer::allocate( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ShortBuffer >( "allocate" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::ShortBuffer ShortBuffer::wrap( ::jace::JArray< ::jace::proxy::types::JShort > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::ShortBuffer >( "wrap" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::ShortBuffer ShortBuffer::wrap( ::jace::JArray< ::jace::proxy::types::JShort > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ShortBuffer >( "wrap" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::ShortBuffer ShortBuffer::slice() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::ShortBuffer >( "slice" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ShortBuffer ShortBuffer::duplicate() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::ShortBuffer >( "duplicate" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ShortBuffer ShortBuffer::asReadOnlyBuffer() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::ShortBuffer >( "asReadOnlyBuffer" ).invoke( *this, arguments );
}

::jace::proxy::types::JShort ShortBuffer::get() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JShort >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ShortBuffer ShortBuffer::put( ::jace::proxy::types::JShort p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ShortBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::types::JShort ShortBuffer::get( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JShort >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ShortBuffer ShortBuffer::put( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JShort p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::nio::ShortBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ShortBuffer ShortBuffer::get( ::jace::JArray< ::jace::proxy::types::JShort > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::ShortBuffer >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ShortBuffer ShortBuffer::get( ::jace::JArray< ::jace::proxy::types::JShort > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ShortBuffer >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ShortBuffer ShortBuffer::put( ::jace::proxy::java::nio::ShortBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ShortBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ShortBuffer ShortBuffer::put( ::jace::JArray< ::jace::proxy::types::JShort > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::ShortBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ShortBuffer ShortBuffer::put( ::jace::JArray< ::jace::proxy::types::JShort > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ShortBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean ShortBuffer::hasArray() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "hasArray" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::types::JShort > ShortBuffer::array() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::types::JShort > >( "array" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt ShortBuffer::arrayOffset() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "arrayOffset" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ShortBuffer ShortBuffer::compact() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::ShortBuffer >( "compact" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean ShortBuffer::isDirect() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isDirect" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String ShortBuffer::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt ShortBuffer::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean ShortBuffer::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt ShortBuffer::compareTo( ::jace::proxy::java::nio::ShortBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "compareTo" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteOrder ShortBuffer::order() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteOrder >( "order" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
ShortBuffer::ShortBuffer( jvalue value ) ShortBuffer_INITIALIZER {
  setJavaJniValue( value );
}

ShortBuffer::ShortBuffer( jobject object ) ShortBuffer_INITIALIZER {
  setJavaJniObject( object );
}

ShortBuffer::ShortBuffer( const ShortBuffer& object ) ShortBuffer_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

ShortBuffer::ShortBuffer( const NoOp& noOp ) ShortBuffer_INITIALIZER {
}

const JClass* ShortBuffer::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/ShortBuffer" );
  return &javaClass;
}

const JClass* ShortBuffer::getJavaJniClass() const throw ( JNIException ) {
  return ShortBuffer::staticGetJavaJniClass();
}

JEnlister< ShortBuffer> ShortBuffer::enlister;

END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::ShortBuffer>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::ShortBuffer( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::ShortBuffer>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::ShortBuffer>& proxy ) : 
    ::jace::proxy::java::nio::ShortBuffer( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::ShortBuffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::ShortBuffer( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::ShortBuffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::ShortBuffer( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::ShortBuffer>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::ShortBuffer>& object ) : 
    ::jace::proxy::java::nio::ShortBuffer( object.getJavaJniValue() ), Object( NO_OP ) {

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

