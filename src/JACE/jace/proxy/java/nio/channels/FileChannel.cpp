
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_FILECHANNEL_H
#include "jace/proxy/java/nio/channels/FileChannel.h"
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
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_BYTEBUFFER_H
#include "jace/proxy/java/nio/ByteBuffer.h"
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
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_WRITABLEBYTECHANNEL_H
#include "jace/proxy/java/nio/channels/WritableByteChannel.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_READABLEBYTECHANNEL_H
#include "jace/proxy/java/nio/channels/ReadableByteChannel.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_MAPPEDBYTEBUFFER_H
#include "jace/proxy/java/nio/MappedByteBuffer.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_FILECHANNEL_MAPMODE_H
#include "jace/proxy/java/nio/channels/FileChannel.MapMode.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_FILELOCK_H
#include "jace/proxy/java/nio/channels/FileLock.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )

/**
 * The Jace C++ proxy class source for java/nio/channels/FileChannel.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define FileChannel_INITIALIZER : ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define FileChannel_INITIALIZER : ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel( NO_OP )
#endif

::jace::proxy::java::nio::channels::FileChannel FileChannel::open( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::util::Set p1, ::jace::JArray< ::jace::proxy::java::nio::file::attribute::FileAttribute > p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::channels::FileChannel >( "open" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::channels::FileChannel FileChannel::open( ::jace::proxy::java::nio::file::Path p0, ::jace::JArray< ::jace::proxy::java::nio::file::OpenOption > p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::nio::channels::FileChannel >( "open" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::types::JInt FileChannel::read( ::jace::proxy::java::nio::ByteBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "read" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong FileChannel::read( ::jace::JArray< ::jace::proxy::java::nio::ByteBuffer > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "read" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong FileChannel::read( ::jace::JArray< ::jace::proxy::java::nio::ByteBuffer > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "read" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt FileChannel::write( ::jace::proxy::java::nio::ByteBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "write" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong FileChannel::write( ::jace::JArray< ::jace::proxy::java::nio::ByteBuffer > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "write" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong FileChannel::write( ::jace::JArray< ::jace::proxy::java::nio::ByteBuffer > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "write" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong FileChannel::position() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "position" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::channels::FileChannel FileChannel::position( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::channels::FileChannel >( "position" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong FileChannel::size() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "size" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::channels::FileChannel FileChannel::truncate( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::channels::FileChannel >( "truncate" ).invoke( *this, arguments );
}

void FileChannel::force( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "force" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong FileChannel::transferTo( ::jace::proxy::types::JLong p0, ::jace::proxy::types::JLong p1, ::jace::proxy::java::nio::channels::WritableByteChannel p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "transferTo" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong FileChannel::transferFrom( ::jace::proxy::java::nio::channels::ReadableByteChannel p0, ::jace::proxy::types::JLong p1, ::jace::proxy::types::JLong p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "transferFrom" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt FileChannel::read( ::jace::proxy::java::nio::ByteBuffer p0, ::jace::proxy::types::JLong p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "read" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt FileChannel::write( ::jace::proxy::java::nio::ByteBuffer p0, ::jace::proxy::types::JLong p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "write" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::MappedByteBuffer FileChannel::map( ::jace::proxy::java::nio::channels::FileChannel_MapMode p0, ::jace::proxy::types::JLong p1, ::jace::proxy::types::JLong p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::MappedByteBuffer >( "map" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::channels::FileLock FileChannel::lock( ::jace::proxy::types::JLong p0, ::jace::proxy::types::JLong p1, ::jace::proxy::types::JBoolean p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::channels::FileLock >( "lock" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::channels::FileLock FileChannel::lock() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::channels::FileLock >( "lock" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::channels::FileLock FileChannel::tryLock( ::jace::proxy::types::JLong p0, ::jace::proxy::types::JLong p1, ::jace::proxy::types::JBoolean p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::channels::FileLock >( "tryLock" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::channels::FileLock FileChannel::tryLock() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::channels::FileLock >( "tryLock" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
FileChannel::FileChannel( jvalue value ) FileChannel_INITIALIZER {
  setJavaJniValue( value );
}

FileChannel::FileChannel( jobject object ) FileChannel_INITIALIZER {
  setJavaJniObject( object );
}

FileChannel::FileChannel( const FileChannel& object ) FileChannel_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

FileChannel::FileChannel( const NoOp& noOp ) FileChannel_INITIALIZER {
}

const JClass* FileChannel::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/channels/FileChannel" );
  return &javaClass;
}

const JClass* FileChannel::getJavaJniClass() const throw ( JNIException ) {
  return FileChannel::staticGetJavaJniClass();
}

JEnlister< FileChannel> FileChannel::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::FileChannel>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::channels::FileChannel( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::FileChannel>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::channels::FileChannel>& proxy ) : 
    ::jace::proxy::java::nio::channels::FileChannel( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::FileChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::channels::FileChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::FileChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::channels::FileChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::FileChannel>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::channels::FileChannel>& object ) : 
    ::jace::proxy::java::nio::channels::FileChannel( object.getJavaJniValue() ), Object( NO_OP ) {

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

