
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_ASYNCHRONOUSFILECHANNEL_H
#include "jace/proxy/java/nio/channels/AsynchronousFileChannel.h"
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
#ifndef JACE_PROXY_JAVA_NIO_FILE_PATH_H
#include "jace/proxy/java/nio/file/Path.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_SET_H
#include "jace/proxy/java/util/Set.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_CONCURRENT_EXECUTORSERVICE_H
#include "jace/proxy/java/util/concurrent/ExecutorService.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif
#ifndef JACE_TYPES_JLONG_H
#include "jace/proxy/types/JLong.h"
#endif
#ifndef JACE_TYPES_JVOID_H
#include "jace/proxy/types/JVoid.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_COMPLETIONHANDLER_H
#include "jace/proxy/java/nio/channels/CompletionHandler.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_CONCURRENT_FUTURE_H
#include "jace/proxy/java/util/concurrent/Future.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_FILELOCK_H
#include "jace/proxy/java/nio/channels/FileLock.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_BYTEBUFFER_H
#include "jace/proxy/java/nio/ByteBuffer.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )

/**
 * The Jace C++ proxy class source for java/nio/channels/AsynchronousFileChannel.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define AsynchronousFileChannel_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define AsynchronousFileChannel_INITIALIZER
#endif

::jace::proxy::java::nio::channels::AsynchronousFileChannel AsynchronousFileChannel::open( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::util::Set p1, ::jace::proxy::java::util::concurrent::ExecutorService p2, ::jace::JArray< ::jace::proxy::java::nio::file::attribute::FileAttribute > p3 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3;
  return ::jace::JMethod< ::jace::proxy::java::nio::channels::AsynchronousFileChannel >( "open" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::channels::AsynchronousFileChannel AsynchronousFileChannel::open( ::jace::proxy::java::nio::file::Path p0, ::jace::JArray< ::jace::proxy::java::nio::file::OpenOption > p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::nio::channels::AsynchronousFileChannel >( "open" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::types::JLong AsynchronousFileChannel::size() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "size" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::channels::AsynchronousFileChannel AsynchronousFileChannel::truncate( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::channels::AsynchronousFileChannel >( "truncate" ).invoke( *this, arguments );
}

void AsynchronousFileChannel::force( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "force" ).invoke( *this, arguments );
}

void AsynchronousFileChannel::lock( ::jace::proxy::types::JLong p0, ::jace::proxy::types::JLong p1, ::jace::proxy::types::JBoolean p2, ::jace::proxy::java::lang::Object p3, ::jace::proxy::java::nio::channels::CompletionHandler p4 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3 << p4;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "lock" ).invoke( *this, arguments );
}

void AsynchronousFileChannel::lock( ::jace::proxy::java::lang::Object p0, ::jace::proxy::java::nio::channels::CompletionHandler p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "lock" ).invoke( *this, arguments );
}

::jace::proxy::java::util::concurrent::Future AsynchronousFileChannel::lock( ::jace::proxy::types::JLong p0, ::jace::proxy::types::JLong p1, ::jace::proxy::types::JBoolean p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::util::concurrent::Future >( "lock" ).invoke( *this, arguments );
}

::jace::proxy::java::util::concurrent::Future AsynchronousFileChannel::lock() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::concurrent::Future >( "lock" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::channels::FileLock AsynchronousFileChannel::tryLock( ::jace::proxy::types::JLong p0, ::jace::proxy::types::JLong p1, ::jace::proxy::types::JBoolean p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::channels::FileLock >( "tryLock" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::channels::FileLock AsynchronousFileChannel::tryLock() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::channels::FileLock >( "tryLock" ).invoke( *this, arguments );
}

void AsynchronousFileChannel::read( ::jace::proxy::java::nio::ByteBuffer p0, ::jace::proxy::types::JLong p1, ::jace::proxy::java::lang::Object p2, ::jace::proxy::java::nio::channels::CompletionHandler p3 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "read" ).invoke( *this, arguments );
}

::jace::proxy::java::util::concurrent::Future AsynchronousFileChannel::read( ::jace::proxy::java::nio::ByteBuffer p0, ::jace::proxy::types::JLong p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::util::concurrent::Future >( "read" ).invoke( *this, arguments );
}

void AsynchronousFileChannel::write( ::jace::proxy::java::nio::ByteBuffer p0, ::jace::proxy::types::JLong p1, ::jace::proxy::java::lang::Object p2, ::jace::proxy::java::nio::channels::CompletionHandler p3 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "write" ).invoke( *this, arguments );
}

::jace::proxy::java::util::concurrent::Future AsynchronousFileChannel::write( ::jace::proxy::java::nio::ByteBuffer p0, ::jace::proxy::types::JLong p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::util::concurrent::Future >( "write" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
AsynchronousFileChannel::AsynchronousFileChannel( jvalue value ) AsynchronousFileChannel_INITIALIZER {
  setJavaJniValue( value );
}

AsynchronousFileChannel::AsynchronousFileChannel( jobject object ) AsynchronousFileChannel_INITIALIZER {
  setJavaJniObject( object );
}

AsynchronousFileChannel::AsynchronousFileChannel( const AsynchronousFileChannel& object ) AsynchronousFileChannel_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

AsynchronousFileChannel::AsynchronousFileChannel( const NoOp& noOp ) AsynchronousFileChannel_INITIALIZER {
}

const JClass* AsynchronousFileChannel::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/channels/AsynchronousFileChannel" );
  return &javaClass;
}

const JClass* AsynchronousFileChannel::getJavaJniClass() const throw ( JNIException ) {
  return AsynchronousFileChannel::staticGetJavaJniClass();
}

JEnlister< AsynchronousFileChannel> AsynchronousFileChannel::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::AsynchronousFileChannel>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::channels::AsynchronousFileChannel( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::AsynchronousFileChannel>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::channels::AsynchronousFileChannel>& proxy ) : 
    ::jace::proxy::java::nio::channels::AsynchronousFileChannel( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::AsynchronousFileChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::channels::AsynchronousFileChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::AsynchronousFileChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::channels::AsynchronousFileChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::AsynchronousFileChannel>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::channels::AsynchronousFileChannel>& object ) : 
    ::jace::proxy::java::nio::channels::AsynchronousFileChannel( object.getJavaJniValue() ), Object( NO_OP ) {

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

