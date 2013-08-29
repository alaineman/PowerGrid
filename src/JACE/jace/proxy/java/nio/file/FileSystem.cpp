
#ifndef JACE_PROXY_JAVA_NIO_FILE_FILESYSTEM_H
#include "jace/proxy/java/nio/file/FileSystem.h"
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
#ifndef JACE_PROXY_JAVA_NIO_FILE_SPI_FILESYSTEMPROVIDER_H
#include "jace/proxy/java/nio/file/spi/FileSystemProvider.h"
#endif
#ifndef JACE_TYPES_JVOID_H
#include "jace/proxy/types/JVoid.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_ITERABLE_H
#include "jace/proxy/java/lang/Iterable.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_SET_H
#include "jace/proxy/java/util/Set.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_PATH_H
#include "jace/proxy/java/nio/file/Path.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_PATHMATCHER_H
#include "jace/proxy/java/nio/file/PathMatcher.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_ATTRIBUTE_USERPRINCIPALLOOKUPSERVICE_H
#include "jace/proxy/java/nio/file/attribute/UserPrincipalLookupService.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_WATCHSERVICE_H
#include "jace/proxy/java/nio/file/WatchService.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )

/**
 * The Jace C++ proxy class source for java/nio/file/FileSystem.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define FileSystem_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define FileSystem_INITIALIZER
#endif

::jace::proxy::java::nio::file::spi::FileSystemProvider FileSystem::provider() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::spi::FileSystemProvider >( "provider" ).invoke( *this, arguments );
}

void FileSystem::close() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "close" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean FileSystem::isOpen() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isOpen" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean FileSystem::isReadOnly() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isReadOnly" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String FileSystem::getSeparator() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getSeparator" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Iterable FileSystem::getRootDirectories() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Iterable >( "getRootDirectories" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Iterable FileSystem::getFileStores() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Iterable >( "getFileStores" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Set FileSystem::supportedFileAttributeViews() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Set >( "supportedFileAttributeViews" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::Path FileSystem::getPath( ::jace::proxy::java::lang::String p0, ::jace::JArray< ::jace::proxy::java::lang::String > p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::Path >( "getPath" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::PathMatcher FileSystem::getPathMatcher( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::PathMatcher >( "getPathMatcher" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::attribute::UserPrincipalLookupService FileSystem::getUserPrincipalLookupService() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::attribute::UserPrincipalLookupService >( "getUserPrincipalLookupService" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::WatchService FileSystem::newWatchService() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::WatchService >( "newWatchService" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
FileSystem::FileSystem( jvalue value ) FileSystem_INITIALIZER {
  setJavaJniValue( value );
}

FileSystem::FileSystem( jobject object ) FileSystem_INITIALIZER {
  setJavaJniObject( object );
}

FileSystem::FileSystem( const FileSystem& object ) FileSystem_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

FileSystem::FileSystem( const NoOp& noOp ) FileSystem_INITIALIZER {
}

const JClass* FileSystem::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/file/FileSystem" );
  return &javaClass;
}

const JClass* FileSystem::getJavaJniClass() const throw ( JNIException ) {
  return FileSystem::staticGetJavaJniClass();
}

JEnlister< FileSystem> FileSystem::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::FileSystem>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::file::FileSystem( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::FileSystem>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::file::FileSystem>& proxy ) : 
    ::jace::proxy::java::nio::file::FileSystem( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::FileSystem>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::file::FileSystem( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::FileSystem>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::file::FileSystem( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::FileSystem>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::file::FileSystem>& object ) : 
    ::jace::proxy::java::nio::file::FileSystem( object.getJavaJniValue() ), Object( NO_OP ) {

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

