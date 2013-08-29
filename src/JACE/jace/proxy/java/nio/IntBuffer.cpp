
#ifndef JACE_PROXY_JAVA_NIO_INTBUFFER_H
#include "jace/proxy/java/nio/IntBuffer.h"
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
 * The Jace C++ proxy class source for java/nio/IntBuffer.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define IntBuffer_INITIALIZER : ::jace::proxy::java::nio::Buffer( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define IntBuffer_INITIALIZER : ::jace::proxy::java::nio::Buffer( NO_OP )
#endif

::jace::proxy::java::nio::IntBuffer IntBuffer::allocate( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::IntBuffer >( "allocate" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::IntBuffer IntBuffer::wrap( ::jace::JArray< ::jace::proxy::types::JInt > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::IntBuffer >( "wrap" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::IntBuffer IntBuffer::wrap( ::jace::JArray< ::jace::proxy::types::JInt > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::IntBuffer >( "wrap" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::IntBuffer IntBuffer::slice() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::IntBuffer >( "slice" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::IntBuffer IntBuffer::duplicate() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::IntBuffer >( "duplicate" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::IntBuffer IntBuffer::asReadOnlyBuffer() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::IntBuffer >( "asReadOnlyBuffer" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt IntBuffer::get() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::IntBuffer IntBuffer::put( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::IntBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt IntBuffer::get( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::IntBuffer IntBuffer::put( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::nio::IntBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::IntBuffer IntBuffer::get( ::jace::JArray< ::jace::proxy::types::JInt > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::IntBuffer >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::IntBuffer IntBuffer::get( ::jace::JArray< ::jace::proxy::types::JInt > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::IntBuffer >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::IntBuffer IntBuffer::put( ::jace::proxy::java::nio::IntBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::IntBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::IntBuffer IntBuffer::put( ::jace::JArray< ::jace::proxy::types::JInt > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::IntBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::IntBuffer IntBuffer::put( ::jace::JArray< ::jace::proxy::types::JInt > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::IntBuffer >( "put" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean IntBuffer::hasArray() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "hasArray" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::types::JInt > IntBuffer::array() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::types::JInt > >( "array" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt IntBuffer::arrayOffset() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "arrayOffset" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::IntBuffer IntBuffer::compact() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::IntBuffer >( "compact" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean IntBuffer::isDirect() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isDirect" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String IntBuffer::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt IntBuffer::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean IntBuffer::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt IntBuffer::compareTo( ::jace::proxy::java::nio::IntBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "compareTo" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteOrder IntBuffer::order() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteOrder >( "order" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
IntBuffer::IntBuffer( jvalue value ) IntBuffer_INITIALIZER {
  setJavaJniValue( value );
}

IntBuffer::IntBuffer( jobject object ) IntBuffer_INITIALIZER {
  setJavaJniObject( object );
}

IntBuffer::IntBuffer( const IntBuffer& object ) IntBuffer_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

IntBuffer::IntBuffer( const NoOp& noOp ) IntBuffer_INITIALIZER {
}

const JClass* IntBuffer::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/IntBuffer" );
  return &javaClass;
}

const JClass* IntBuffer::getJavaJniClass() const throw ( JNIException ) {
  return IntBuffer::staticGetJavaJniClass();
}

JEnlister< IntBuffer> IntBuffer::enlister;

END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::IntBuffer>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::IntBuffer( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::IntBuffer>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::IntBuffer>& proxy ) : 
    ::jace::proxy::java::nio::IntBuffer( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::IntBuffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::IntBuffer( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::IntBuffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::IntBuffer( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::IntBuffer>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::IntBuffer>& object ) : 
    ::jace::proxy::java::nio::IntBuffer( object.getJavaJniValue() ), Object( NO_OP ) {

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

