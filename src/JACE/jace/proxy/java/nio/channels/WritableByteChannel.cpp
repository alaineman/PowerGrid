
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_WRITABLEBYTECHANNEL_H
#include "jace/proxy/java/nio/channels/WritableByteChannel.h"
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

BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )

/**
 * The Jace C++ proxy class source for java/nio/channels/WritableByteChannel.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define WritableByteChannel_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define WritableByteChannel_INITIALIZER
#endif

::jace::proxy::types::JInt WritableByteChannel::write( ::jace::proxy::java::nio::ByteBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "write" ).invoke( *this, arguments );
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
WritableByteChannel::WritableByteChannel() : Object( NO_OP ) { 
}

WritableByteChannel::WritableByteChannel( jvalue value ) WritableByteChannel_INITIALIZER {
  setJavaJniValue( value );
}

WritableByteChannel::WritableByteChannel( jobject object ) WritableByteChannel_INITIALIZER {
  setJavaJniObject( object );
}

WritableByteChannel::WritableByteChannel( const WritableByteChannel& object ) WritableByteChannel_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

WritableByteChannel::WritableByteChannel( const NoOp& noOp ) WritableByteChannel_INITIALIZER {
}

const JClass* WritableByteChannel::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/channels/WritableByteChannel" );
  return &javaClass;
}

const JClass* WritableByteChannel::getJavaJniClass() const throw ( JNIException ) {
  return WritableByteChannel::staticGetJavaJniClass();
}

JEnlister< WritableByteChannel> WritableByteChannel::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::WritableByteChannel>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::channels::WritableByteChannel( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::WritableByteChannel>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::channels::WritableByteChannel>& proxy ) : 
    ::jace::proxy::java::nio::channels::WritableByteChannel( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::WritableByteChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::channels::WritableByteChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::WritableByteChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::channels::WritableByteChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::WritableByteChannel>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::channels::WritableByteChannel>& object ) : 
    ::jace::proxy::java::nio::channels::WritableByteChannel( object.getJavaJniValue() ), Object( NO_OP ) {

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

