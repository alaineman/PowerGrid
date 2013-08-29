
#ifndef JACE_PROXY_JAVA_NIO_FILE_SPI_FILESYSTEMPROVIDER_H
#define JACE_PROXY_JAVA_NIO_FILE_SPI_FILESYSTEMPROVIDER_H

#ifndef JACE_OS_DEP_H
#include "jace/os_dep.h"
#endif

#ifndef JACE_NAMESPACE_H
#include "jace/namespace.h"
#endif

#ifndef JACE_JOBJECT_H
#include "jace/proxy/JObject.h"
#endif

#ifndef JACE_JENLISTER_H
#include "jace/JEnlister.h"
#endif

#ifndef JACE_JARRAY_H
#include "jace/JArray.h"
#endif

#ifndef JACE_JFIELD_PROXY_H
#include "jace/JFieldProxy.h"
#endif

/**
 * The super class for this class.
 *
 */
#ifndef JACE_PROXY_JAVA_LANG_OBJECT_H
#include "jace/proxy/java/lang/Object.h"
#endif

/**
 * Classes which this class is fully dependent upon.
 *
 */
#ifndef JACE_PROXY_JAVA_NIO_FILE_OPENOPTION_H
#include "jace/proxy/java/nio/file/OpenOption.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_ATTRIBUTE_FILEATTRIBUTE_H
#include "jace/proxy/java/nio/file/attribute/FileAttribute.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_COPYOPTION_H
#include "jace/proxy/java/nio/file/CopyOption.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_ACCESSMODE_H
#include "jace/proxy/java/nio/file/AccessMode.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_LINKOPTION_H
#include "jace/proxy/java/nio/file/LinkOption.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_4( jace, proxy, java, util )
class List;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )
class FileSystem;
END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE_4( jace, proxy, java, net )
class URI;
END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Map;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class IOException;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )
class Path;
END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class InputStream;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class OutputStream;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )
class FileChannel;
END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Set;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )
class AsynchronousFileChannel;
END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE_5( jace, proxy, java, util, concurrent )
class ExecutorService;
END_NAMESPACE_5( jace, proxy, java, util, concurrent )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )
class SeekableByteChannel;
END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )
class DirectoryStream;
END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )
class DirectoryStream_Filter;
END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )
class FileStore;
END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE_6( jace, proxy, java, nio, file, attribute )
class FileAttributeView;
END_NAMESPACE_6( jace, proxy, java, nio, file, attribute )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class Class;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_6( jace, proxy, java, nio, file, attribute )
class BasicFileAttributes;
END_NAMESPACE_6( jace, proxy, java, nio, file, attribute )

BEGIN_NAMESPACE_6( jace, proxy, java, nio, file, spi )

/**
 * The Jace C++ proxy class for java/nio/file/spi/FileSystemProvider.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class FileSystemProvider : public virtual ::jace::proxy::java::lang::Object {

public: 

/**
 * installedProviders
 *
 */
static ::jace::proxy::java::util::List installedProviders();

/**
 * getScheme
 *
 */
::jace::proxy::java::lang::String getScheme();

/**
 * newFileSystem
 *
 */
::jace::proxy::java::nio::file::FileSystem newFileSystem( ::jace::proxy::java::net::URI p0, ::jace::proxy::java::util::Map p1 );

/**
 * getFileSystem
 *
 */
::jace::proxy::java::nio::file::FileSystem getFileSystem( ::jace::proxy::java::net::URI p0 );

/**
 * getPath
 *
 */
::jace::proxy::java::nio::file::Path getPath( ::jace::proxy::java::net::URI p0 );

/**
 * newFileSystem
 *
 */
::jace::proxy::java::nio::file::FileSystem newFileSystem( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::util::Map p1 );

/**
 * newInputStream
 *
 */
::jace::proxy::java::io::InputStream newInputStream( ::jace::proxy::java::nio::file::Path p0, ::jace::JArray< ::jace::proxy::java::nio::file::OpenOption > p1 );

/**
 * newOutputStream
 *
 */
::jace::proxy::java::io::OutputStream newOutputStream( ::jace::proxy::java::nio::file::Path p0, ::jace::JArray< ::jace::proxy::java::nio::file::OpenOption > p1 );

/**
 * newFileChannel
 *
 */
::jace::proxy::java::nio::channels::FileChannel newFileChannel( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::util::Set p1, ::jace::JArray< ::jace::proxy::java::nio::file::attribute::FileAttribute > p2 );

/**
 * newAsynchronousFileChannel
 *
 */
::jace::proxy::java::nio::channels::AsynchronousFileChannel newAsynchronousFileChannel( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::util::Set p1, ::jace::proxy::java::util::concurrent::ExecutorService p2, ::jace::JArray< ::jace::proxy::java::nio::file::attribute::FileAttribute > p3 );

/**
 * newByteChannel
 *
 */
::jace::proxy::java::nio::channels::SeekableByteChannel newByteChannel( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::util::Set p1, ::jace::JArray< ::jace::proxy::java::nio::file::attribute::FileAttribute > p2 );

/**
 * newDirectoryStream
 *
 */
::jace::proxy::java::nio::file::DirectoryStream newDirectoryStream( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::nio::file::DirectoryStream_Filter p1 );

/**
 * createDirectory
 *
 */
void createDirectory( ::jace::proxy::java::nio::file::Path p0, ::jace::JArray< ::jace::proxy::java::nio::file::attribute::FileAttribute > p1 );

/**
 * createSymbolicLink
 *
 */
void createSymbolicLink( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::nio::file::Path p1, ::jace::JArray< ::jace::proxy::java::nio::file::attribute::FileAttribute > p2 );

/**
 * createLink
 *
 */
void createLink( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::nio::file::Path p1 );

/**
 * delete_
 *
 */
void delete_( ::jace::proxy::java::nio::file::Path p0 );

/**
 * deleteIfExists
 *
 */
::jace::proxy::types::JBoolean deleteIfExists( ::jace::proxy::java::nio::file::Path p0 );

/**
 * readSymbolicLink
 *
 */
::jace::proxy::java::nio::file::Path readSymbolicLink( ::jace::proxy::java::nio::file::Path p0 );

/**
 * copy
 *
 */
void copy( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::nio::file::Path p1, ::jace::JArray< ::jace::proxy::java::nio::file::CopyOption > p2 );

/**
 * move
 *
 */
void move( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::nio::file::Path p1, ::jace::JArray< ::jace::proxy::java::nio::file::CopyOption > p2 );

/**
 * isSameFile
 *
 */
::jace::proxy::types::JBoolean isSameFile( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::nio::file::Path p1 );

/**
 * isHidden
 *
 */
::jace::proxy::types::JBoolean isHidden( ::jace::proxy::java::nio::file::Path p0 );

/**
 * getFileStore
 *
 */
::jace::proxy::java::nio::file::FileStore getFileStore( ::jace::proxy::java::nio::file::Path p0 );

/**
 * checkAccess
 *
 */
void checkAccess( ::jace::proxy::java::nio::file::Path p0, ::jace::JArray< ::jace::proxy::java::nio::file::AccessMode > p1 );

/**
 * getFileAttributeView
 *
 */
::jace::proxy::java::nio::file::attribute::FileAttributeView getFileAttributeView( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::lang::Class p1, ::jace::JArray< ::jace::proxy::java::nio::file::LinkOption > p2 );

/**
 * readAttributes
 *
 */
::jace::proxy::java::nio::file::attribute::BasicFileAttributes readAttributes( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::lang::Class p1, ::jace::JArray< ::jace::proxy::java::nio::file::LinkOption > p2 );

/**
 * readAttributes
 *
 */
::jace::proxy::java::util::Map readAttributes( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::lang::String p1, ::jace::JArray< ::jace::proxy::java::nio::file::LinkOption > p2 );

/**
 * setAttribute
 *
 */
void setAttribute( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::java::lang::Object p2, ::jace::JArray< ::jace::proxy::java::nio::file::LinkOption > p3 );

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
FileSystemProvider( jvalue value );
FileSystemProvider( jobject object );
FileSystemProvider( const FileSystemProvider& object );
FileSystemProvider( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< FileSystemProvider> enlister;
};

END_NAMESPACE_6( jace, proxy, java, nio, file, spi )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::nio::file::spi::FileSystemProvider>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::nio::file::spi::FileSystemProvider>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::file::spi::FileSystemProvider>& proxy );
#else
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
  template <> JFieldProxy< ::jace::proxy::java::nio::file::spi::FileSystemProvider>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::file::spi::FileSystemProvider>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::file::spi::FileSystemProvider>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::file::spi::FileSystemProvider>& object );
#else
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

#endif // #ifndef JACE_PROXY_JAVA_NIO_FILE_SPI_FILESYSTEMPROVIDER_H

