
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_SCATTERINGBYTECHANNEL_H
#include "jace/proxy/java/nio/channels/ScatteringByteChannel.h"
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
#ifndef JACE_TYPES_JLONG_H
#include "jace/proxy/types/JLong.h"
#endif
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )

/**
 * The Jace C++ proxy class source for java/nio/channels/ScatteringByteChannel.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define ScatteringByteChannel_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define ScatteringByteChannel_INITIALIZER
#endif

::jace::proxy::types::JLong ScatteringByteChannel::read( ::jace::JArray< ::jace::proxy::java::nio::ByteBuffer > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "read" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong ScatteringByteChannel::read( ::jace::JArray< ::jace::proxy::java::nio::ByteBuffer > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "read" ).invoke( *this, arguments );
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
ScatteringByteChannel::ScatteringByteChannel() : Object( NO_OP ) { 
}

ScatteringByteChannel::ScatteringByteChannel( jvalue value ) ScatteringByteChannel_INITIALIZER {
  setJavaJniValue( value );
}

ScatteringByteChannel::ScatteringByteChannel( jobject object ) ScatteringByteChannel_INITIALIZER {
  setJavaJniObject( object );
}

ScatteringByteChannel::ScatteringByteChannel( const ScatteringByteChannel& object ) ScatteringByteChannel_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

ScatteringByteChannel::ScatteringByteChannel( const NoOp& noOp ) ScatteringByteChannel_INITIALIZER {
}

const JClass* ScatteringByteChannel::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/channels/ScatteringByteChannel" );
  return &javaClass;
}

const JClass* ScatteringByteChannel::getJavaJniClass() const throw ( JNIException ) {
  return ScatteringByteChannel::staticGetJavaJniClass();
}

JEnlister< ScatteringByteChannel> ScatteringByteChannel::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::ScatteringByteChannel>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::channels::ScatteringByteChannel( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::ScatteringByteChannel>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::channels::ScatteringByteChannel>& proxy ) : 
    ::jace::proxy::java::nio::channels::ScatteringByteChannel( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::ScatteringByteChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::channels::ScatteringByteChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::ScatteringByteChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::channels::ScatteringByteChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::ScatteringByteChannel>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::channels::ScatteringByteChannel>& object ) : 
    ::jace::proxy::java::nio::channels::ScatteringByteChannel( object.getJavaJniValue() ), Object( NO_OP ) {

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

