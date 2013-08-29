
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_GATHERINGBYTECHANNEL_H
#include "jace/proxy/java/nio/channels/GatheringByteChannel.h"
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
 * The Jace C++ proxy class source for java/nio/channels/GatheringByteChannel.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define GatheringByteChannel_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define GatheringByteChannel_INITIALIZER
#endif

::jace::proxy::types::JLong GatheringByteChannel::write( ::jace::JArray< ::jace::proxy::java::nio::ByteBuffer > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "write" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong GatheringByteChannel::write( ::jace::JArray< ::jace::proxy::java::nio::ByteBuffer > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "write" ).invoke( *this, arguments );
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
GatheringByteChannel::GatheringByteChannel() : Object( NO_OP ) { 
}

GatheringByteChannel::GatheringByteChannel( jvalue value ) GatheringByteChannel_INITIALIZER {
  setJavaJniValue( value );
}

GatheringByteChannel::GatheringByteChannel( jobject object ) GatheringByteChannel_INITIALIZER {
  setJavaJniObject( object );
}

GatheringByteChannel::GatheringByteChannel( const GatheringByteChannel& object ) GatheringByteChannel_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

GatheringByteChannel::GatheringByteChannel( const NoOp& noOp ) GatheringByteChannel_INITIALIZER {
}

const JClass* GatheringByteChannel::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/channels/GatheringByteChannel" );
  return &javaClass;
}

const JClass* GatheringByteChannel::getJavaJniClass() const throw ( JNIException ) {
  return GatheringByteChannel::staticGetJavaJniClass();
}

JEnlister< GatheringByteChannel> GatheringByteChannel::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::GatheringByteChannel>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::channels::GatheringByteChannel( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::GatheringByteChannel>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::channels::GatheringByteChannel>& proxy ) : 
    ::jace::proxy::java::nio::channels::GatheringByteChannel( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::GatheringByteChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::channels::GatheringByteChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::GatheringByteChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::channels::GatheringByteChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::GatheringByteChannel>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::channels::GatheringByteChannel>& object ) : 
    ::jace::proxy::java::nio::channels::GatheringByteChannel( object.getJavaJniValue() ), Object( NO_OP ) {

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

