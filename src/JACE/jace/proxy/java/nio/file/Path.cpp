
#ifndef JACE_PROXY_JAVA_NIO_FILE_PATH_H
#include "jace/proxy/java/nio/file/Path.h"
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
#ifndef JACE_PROXY_JAVA_NIO_FILE_FILESYSTEM_H
#include "jace/proxy/java/nio/file/FileSystem.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_URI_H
#include "jace/proxy/java/net/URI.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_FILE_H
#include "jace/proxy/java/io/File.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_WATCHKEY_H
#include "jace/proxy/java/nio/file/WatchKey.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_WATCHSERVICE_H
#include "jace/proxy/java/nio/file/WatchService.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_ITERATOR_H
#include "jace/proxy/java/util/Iterator.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )

/**
 * The Jace C++ proxy class source for java/nio/file/Path.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Path_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Path_INITIALIZER
#endif

::jace::proxy::java::nio::file::FileSystem Path::getFileSystem() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::FileSystem >( "getFileSystem" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Path::isAbsolute() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isAbsolute" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::Path Path::getRoot() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::Path >( "getRoot" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::Path Path::getFileName() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::Path >( "getFileName" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::Path Path::getParent() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::Path >( "getParent" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt Path::getNameCount() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "getNameCount" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::Path Path::getName( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::Path >( "getName" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::Path Path::subpath( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::Path >( "subpath" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Path::startsWith( ::jace::proxy::java::nio::file::Path p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "startsWith" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Path::startsWith( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "startsWith" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Path::endsWith( ::jace::proxy::java::nio::file::Path p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "endsWith" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Path::endsWith( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "endsWith" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::Path Path::normalize() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::Path >( "normalize" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::Path Path::resolve( ::jace::proxy::java::nio::file::Path p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::Path >( "resolve" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::Path Path::resolve( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::Path >( "resolve" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::Path Path::resolveSibling( ::jace::proxy::java::nio::file::Path p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::Path >( "resolveSibling" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::Path Path::resolveSibling( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::Path >( "resolveSibling" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::Path Path::relativize( ::jace::proxy::java::nio::file::Path p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::Path >( "relativize" ).invoke( *this, arguments );
}

::jace::proxy::java::net::URI Path::toUri() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::net::URI >( "toUri" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::Path Path::toAbsolutePath() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::Path >( "toAbsolutePath" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::Path Path::toRealPath( ::jace::JArray< ::jace::proxy::java::nio::file::LinkOption > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::Path >( "toRealPath" ).invoke( *this, arguments );
}

::jace::proxy::java::io::File Path::toFile() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::io::File >( "toFile" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::WatchKey Path::register_( ::jace::proxy::java::nio::file::WatchService p0, ::jace::JArray< ::jace::proxy::java::nio::file::WatchEvent_Kind > p1, ::jace::JArray< ::jace::proxy::java::nio::file::WatchEvent_Modifier > p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::WatchKey >( "register_" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::WatchKey Path::register_( ::jace::proxy::java::nio::file::WatchService p0, ::jace::JArray< ::jace::proxy::java::nio::file::WatchEvent_Kind > p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::WatchKey >( "register_" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Iterator Path::iterator() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Iterator >( "iterator" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt Path::compareTo( ::jace::proxy::java::nio::file::Path p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "compareTo" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Path::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt Path::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Path::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
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
Path::Path() : Object( NO_OP ) { 
}

Path::Path( jvalue value ) Path_INITIALIZER {
  setJavaJniValue( value );
}

Path::Path( jobject object ) Path_INITIALIZER {
  setJavaJniObject( object );
}

Path::Path( const Path& object ) Path_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Path::Path( const NoOp& noOp ) Path_INITIALIZER {
}

const JClass* Path::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/file/Path" );
  return &javaClass;
}

const JClass* Path::getJavaJniClass() const throw ( JNIException ) {
  return Path::staticGetJavaJniClass();
}

JEnlister< Path> Path::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::Path>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::file::Path( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::Path>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::file::Path>& proxy ) : 
    ::jace::proxy::java::nio::file::Path( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::Path>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::file::Path( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::Path>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::file::Path( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::Path>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::file::Path>& object ) : 
    ::jace::proxy::java::nio::file::Path( object.getJavaJniValue() ), Object( NO_OP ) {

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

