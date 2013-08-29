
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_SEEKABLEBYTECHANNEL_H
#include "jace/proxy/java/nio/channels/SeekableByteChannel.h"
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
#ifndef JACE_PROXY_JAVA_NIO_BYTEBUFFER_H
#include "jace/proxy/java/nio/ByteBuffer.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif
#ifndef JACE_TYPES_JLONG_H
#include "jace/proxy/types/JLong.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )

/**
 * The Jace C++ proxy class source for java/nio/channels/SeekableByteChannel.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define SeekableByteChannel_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define SeekableByteChannel_INITIALIZER
#endif

::jace::proxy::types::JInt SeekableByteChannel::read( ::jace::proxy::java::nio::ByteBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "read" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt SeekableByteChannel::write( ::jace::proxy::java::nio::ByteBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "write" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong SeekableByteChannel::position() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "position" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::channels::SeekableByteChannel SeekableByteChannel::position( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::channels::SeekableByteChannel >( "position" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong SeekableByteChannel::size() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "size" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::channels::SeekableByteChannel SeekableByteChannel::truncate( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::channels::SeekableByteChannel >( "truncate" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
/**
 * Special no arg constructor for interface virtual inheritance
 *
 */
SeekableByteChannel::SeekableByteChannel() : Object( NO_OP ) { 
}

SeekableByteChannel::SeekableByteChannel( jvalue value ) SeekableByteChannel_INITIALIZER {
  setJavaJniValue( value );
}

SeekableByteChannel::SeekableByteChannel( jobject object ) SeekableByteChannel_INITIALIZER {
  setJavaJniObject( object );
}

SeekableByteChannel::SeekableByteChannel( const SeekableByteChannel& object ) SeekableByteChannel_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

SeekableByteChannel::SeekableByteChannel( const NoOp& noOp ) SeekableByteChannel_INITIALIZER {
}

const JClass* SeekableByteChannel::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/channels/SeekableByteChannel" );
  return &javaClass;
}

const JClass* SeekableByteChannel::getJavaJniClass() const throw ( JNIException ) {
  return SeekableByteChannel::staticGetJavaJniClass();
}

JEnlister< SeekableByteChannel> SeekableByteChannel::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::SeekableByteChannel>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::channels::SeekableByteChannel( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::SeekableByteChannel>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::channels::SeekableByteChannel>& proxy ) : 
    ::jace::proxy::java::nio::channels::SeekableByteChannel( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::SeekableByteChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::channels::SeekableByteChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::SeekableByteChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::channels::SeekableByteChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::SeekableByteChannel>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::channels::SeekableByteChannel>& object ) : 
    ::jace::proxy::java::nio::channels::SeekableByteChannel( object.getJavaJniValue() ), Object( NO_OP ) {

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

