
#ifndef JACE_PROXY_JAVA_NIO_BUFFER_H
#include "jace/proxy/java/nio/Buffer.h"
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

BEGIN_NAMESPACE_4( jace, proxy, java, nio )

/**
 * The Jace C++ proxy class source for java/nio/Buffer.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Buffer_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Buffer_INITIALIZER
#endif

::jace::proxy::types::JInt Buffer::capacity() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "capacity" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt Buffer::position() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "position" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::Buffer Buffer::position( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::Buffer >( "position" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt Buffer::limit() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "limit" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::Buffer Buffer::limit( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::Buffer >( "limit" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::Buffer Buffer::mark() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::Buffer >( "mark" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::Buffer Buffer::reset() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::Buffer >( "reset" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::Buffer Buffer::clear() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::Buffer >( "clear" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::Buffer Buffer::flip() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::Buffer >( "flip" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::Buffer Buffer::rewind() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::Buffer >( "rewind" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt Buffer::remaining() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "remaining" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Buffer::hasRemaining() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "hasRemaining" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Buffer::isReadOnly() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isReadOnly" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Buffer::hasArray() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "hasArray" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object Buffer::array() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "array" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt Buffer::arrayOffset() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "arrayOffset" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Buffer::isDirect() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isDirect" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Buffer::Buffer( jvalue value ) Buffer_INITIALIZER {
  setJavaJniValue( value );
}

Buffer::Buffer( jobject object ) Buffer_INITIALIZER {
  setJavaJniObject( object );
}

Buffer::Buffer( const Buffer& object ) Buffer_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Buffer::Buffer( const NoOp& noOp ) Buffer_INITIALIZER {
}

const JClass* Buffer::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/Buffer" );
  return &javaClass;
}

const JClass* Buffer::getJavaJniClass() const throw ( JNIException ) {
  return Buffer::staticGetJavaJniClass();
}

JEnlister< Buffer> Buffer::enlister;

END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::Buffer>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::Buffer( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::Buffer>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::Buffer>& proxy ) : 
    ::jace::proxy::java::nio::Buffer( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::Buffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::Buffer( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::Buffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::Buffer( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::Buffer>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::Buffer>& object ) : 
    ::jace::proxy::java::nio::Buffer( object.getJavaJniValue() ), Object( NO_OP ) {

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

