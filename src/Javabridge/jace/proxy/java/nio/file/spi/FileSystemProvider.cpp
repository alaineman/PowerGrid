
#ifndef JACE_PROXY_JAVA_NIO_FILE_SPI_FILESYSTEMPROVIDER_H
#include "jace/proxy/java/nio/file/spi/FileSystemProvider.h"
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
#ifndef JACE_PROXY_JAVA_UTIL_LIST_H
#include "jace/proxy/java/util/List.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_FILESYSTEM_H
#include "jace/proxy/java/nio/file/FileSystem.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_URI_H
#include "jace/proxy/java/net/URI.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_MAP_H
#include "jace/proxy/java/util/Map.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_PATH_H
#include "jace/proxy/java/nio/file/Path.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_INPUTSTREAM_H
#include "jace/proxy/java/io/InputStream.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_OUTPUTSTREAM_H
#include "jace/proxy/java/io/OutputStream.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_FILECHANNEL_H
#include "jace/proxy/java/nio/channels/FileChannel.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_SET_H
#include "jace/proxy/java/util/Set.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_ASYNCHRONOUSFILECHANNEL_H
#include "jace/proxy/java/nio/channels/AsynchronousFileChannel.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_CONCURRENT_EXECUTORSERVICE_H
#include "jace/proxy/java/util/concurrent/ExecutorService.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_SEEKABLEBYTECHANNEL_H
#include "jace/proxy/java/nio/channels/SeekableByteChannel.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_DIRECTORYSTREAM_H
#include "jace/proxy/java/nio/file/DirectoryStream.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_DIRECTORYSTREAM_FILTER_H
#include "jace/proxy/java/nio/file/DirectoryStream.Filter.h"
#endif
#ifndef JACE_TYPES_JVOID_H
#include "jace/proxy/types/JVoid.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_FILESTORE_H
#include "jace/proxy/java/nio/file/FileStore.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_ATTRIBUTE_FILEATTRIBUTEVIEW_H
#include "jace/proxy/java/nio/file/attribute/FileAttributeView.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_CLASS_H
#include "jace/proxy/java/lang/Class.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_ATTRIBUTE_BASICFILEATTRIBUTES_H
#include "jace/proxy/java/nio/file/attribute/BasicFileAttributes.h"
#endif

BEGIN_NAMESPACE_6( jace, proxy, java, nio, file, spi )

/**
 * The Jace C++ proxy class source for java/nio/file/spi/FileSystemProvider.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define FileSystemProvider_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define FileSystemProvider_INITIALIZER
#endif

::jace::proxy::java::util::List FileSystemProvider::installedProviders() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::List >( "installedProviders" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String FileSystemProvider::getScheme() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getScheme" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::FileSystem FileSystemProvider::newFileSystem( ::jace::proxy::java::net::URI p0, ::jace::proxy::java::util::Map p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::FileSystem >( "newFileSystem" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::FileSystem FileSystemProvider::getFileSystem( ::jace::proxy::java::net::URI p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::FileSystem >( "getFileSystem" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::Path FileSystemProvider::getPath( ::jace::proxy::java::net::URI p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::Path >( "getPath" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::FileSystem FileSystemProvider::newFileSystem( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::util::Map p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::FileSystem >( "newFileSystem" ).invoke( *this, arguments );
}

::jace::proxy::java::io::InputStream FileSystemProvider::newInputStream( ::jace::proxy::java::nio::file::Path p0, ::jace::JArray< ::jace::proxy::java::nio::file::OpenOption > p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::io::InputStream >( "newInputStream" ).invoke( *this, arguments );
}

::jace::proxy::java::io::OutputStream FileSystemProvider::newOutputStream( ::jace::proxy::java::nio::file::Path p0, ::jace::JArray< ::jace::proxy::java::nio::file::OpenOption > p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::io::OutputStream >( "newOutputStream" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::channels::FileChannel FileSystemProvider::newFileChannel( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::util::Set p1, ::jace::JArray< ::jace::proxy::java::nio::file::attribute::FileAttribute > p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::channels::FileChannel >( "newFileChannel" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::channels::AsynchronousFileChannel FileSystemProvider::newAsynchronousFileChannel( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::util::Set p1, ::jace::proxy::java::util::concurrent::ExecutorService p2, ::jace::JArray< ::jace::proxy::java::nio::file::attribute::FileAttribute > p3 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3;
  return ::jace::JMethod< ::jace::proxy::java::nio::channels::AsynchronousFileChannel >( "newAsynchronousFileChannel" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::channels::SeekableByteChannel FileSystemProvider::newByteChannel( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::util::Set p1, ::jace::JArray< ::jace::proxy::java::nio::file::attribute::FileAttribute > p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::channels::SeekableByteChannel >( "newByteChannel" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::DirectoryStream FileSystemProvider::newDirectoryStream( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::nio::file::DirectoryStream_Filter p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::DirectoryStream >( "newDirectoryStream" ).invoke( *this, arguments );
}

void FileSystemProvider::createDirectory( ::jace::proxy::java::nio::file::Path p0, ::jace::JArray< ::jace::proxy::java::nio::file::attribute::FileAttribute > p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "createDirectory" ).invoke( *this, arguments );
}

void FileSystemProvider::createSymbolicLink( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::nio::file::Path p1, ::jace::JArray< ::jace::proxy::java::nio::file::attribute::FileAttribute > p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "createSymbolicLink" ).invoke( *this, arguments );
}

void FileSystemProvider::createLink( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::nio::file::Path p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "createLink" ).invoke( *this, arguments );
}

void FileSystemProvider::delete_( ::jace::proxy::java::nio::file::Path p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "delete_" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean FileSystemProvider::deleteIfExists( ::jace::proxy::java::nio::file::Path p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "deleteIfExists" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::Path FileSystemProvider::readSymbolicLink( ::jace::proxy::java::nio::file::Path p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::Path >( "readSymbolicLink" ).invoke( *this, arguments );
}

void FileSystemProvider::copy( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::nio::file::Path p1, ::jace::JArray< ::jace::proxy::java::nio::file::CopyOption > p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "copy" ).invoke( *this, arguments );
}

void FileSystemProvider::move( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::nio::file::Path p1, ::jace::JArray< ::jace::proxy::java::nio::file::CopyOption > p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "move" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean FileSystemProvider::isSameFile( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::nio::file::Path p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isSameFile" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean FileSystemProvider::isHidden( ::jace::proxy::java::nio::file::Path p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isHidden" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::FileStore FileSystemProvider::getFileStore( ::jace::proxy::java::nio::file::Path p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::FileStore >( "getFileStore" ).invoke( *this, arguments );
}

void FileSystemProvider::checkAccess( ::jace::proxy::java::nio::file::Path p0, ::jace::JArray< ::jace::proxy::java::nio::file::AccessMode > p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkAccess" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::attribute::FileAttributeView FileSystemProvider::getFileAttributeView( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::lang::Class p1, ::jace::JArray< ::jace::proxy::java::nio::file::LinkOption > p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::attribute::FileAttributeView >( "getFileAttributeView" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::attribute::BasicFileAttributes FileSystemProvider::readAttributes( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::lang::Class p1, ::jace::JArray< ::jace::proxy::java::nio::file::LinkOption > p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::attribute::BasicFileAttributes >( "readAttributes" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Map FileSystemProvider::readAttributes( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::lang::String p1, ::jace::JArray< ::jace::proxy::java::nio::file::LinkOption > p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::util::Map >( "readAttributes" ).invoke( *this, arguments );
}

void FileSystemProvider::setAttribute( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::java::lang::Object p2, ::jace::JArray< ::jace::proxy::java::nio::file::LinkOption > p3 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setAttribute" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
FileSystemProvider::FileSystemProvider( jvalue value ) FileSystemProvider_INITIALIZER {
  setJavaJniValue( value );
}

FileSystemProvider::FileSystemProvider( jobject object ) FileSystemProvider_INITIALIZER {
  setJavaJniObject( object );
}

FileSystemProvider::FileSystemProvider( const FileSystemProvider& object ) FileSystemProvider_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

FileSystemProvider::FileSystemProvider( const NoOp& noOp ) FileSystemProvider_INITIALIZER {
}

const JClass* FileSystemProvider::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/file/spi/FileSystemProvider" );
  return &javaClass;
}

const JClass* FileSystemProvider::getJavaJniClass() const throw ( JNIException ) {
  return FileSystemProvider::staticGetJavaJniClass();
}

JEnlister< FileSystemProvider> FileSystemProvider::enlister;

END_NAMESPACE_6( jace, proxy, java, nio, file, spi )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::spi::FileSystemProvider>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::file::spi::FileSystemProvider( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::spi::FileSystemProvider>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::file::spi::FileSystemProvider>& proxy ) : 
    ::jace::proxy::java::nio::file::spi::FileSystemProvider( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::spi::FileSystemProvider>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::file::spi::FileSystemProvider( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::spi::FileSystemProvider>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::file::spi::FileSystemProvider( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::spi::FileSystemProvider>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::file::spi::FileSystemProvider>& object ) : 
    ::jace::proxy::java::nio::file::spi::FileSystemProvider( object.getJavaJniValue() ), Object( NO_OP ) {

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

