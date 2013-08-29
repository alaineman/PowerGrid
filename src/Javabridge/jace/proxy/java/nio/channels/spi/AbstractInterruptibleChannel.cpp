
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_SPI_ABSTRACTINTERRUPTIBLECHANNEL_H
#include "jace/proxy/java/nio/channels/spi/AbstractInterruptibleChannel.h"
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
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif

BEGIN_NAMESPACE_6( jace, proxy, java, nio, channels, spi )

/**
 * The Jace C++ proxy class source for java/nio/channels/spi/AbstractInterruptibleChannel.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define AbstractInterruptibleChannel_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define AbstractInterruptibleChannel_INITIALIZER
#endif

void AbstractInterruptibleChannel::close() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "close" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean AbstractInterruptibleChannel::isOpen() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isOpen" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
AbstractInterruptibleChannel::AbstractInterruptibleChannel( jvalue value ) AbstractInterruptibleChannel_INITIALIZER {
  setJavaJniValue( value );
}

AbstractInterruptibleChannel::AbstractInterruptibleChannel( jobject object ) AbstractInterruptibleChannel_INITIALIZER {
  setJavaJniObject( object );
}

AbstractInterruptibleChannel::AbstractInterruptibleChannel( const AbstractInterruptibleChannel& object ) AbstractInterruptibleChannel_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

AbstractInterruptibleChannel::AbstractInterruptibleChannel( const NoOp& noOp ) AbstractInterruptibleChannel_INITIALIZER {
}

const JClass* AbstractInterruptibleChannel::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/channels/spi/AbstractInterruptibleChannel" );
  return &javaClass;
}

const JClass* AbstractInterruptibleChannel::getJavaJniClass() const throw ( JNIException ) {
  return AbstractInterruptibleChannel::staticGetJavaJniClass();
}

JEnlister< AbstractInterruptibleChannel> AbstractInterruptibleChannel::enlister;

END_NAMESPACE_6( jace, proxy, java, nio, channels, spi )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel>& proxy ) : 
    ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel>& object ) : 
    ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel( object.getJavaJniValue() ), Object( NO_OP ) {

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

