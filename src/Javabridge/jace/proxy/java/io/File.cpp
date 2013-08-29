
#ifndef JACE_PROXY_JAVA_IO_FILE_H
#include "jace/proxy/java/io/File.h"
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
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_URI_H
#include "jace/proxy/java/net/URI.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_URL_H
#include "jace/proxy/java/net/URL.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_MALFORMEDURLEXCEPTION_H
#include "jace/proxy/java/net/MalformedURLException.h"
#endif
#ifndef JACE_TYPES_JLONG_H
#include "jace/proxy/types/JLong.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_FILENAMEFILTER_H
#include "jace/proxy/java/io/FilenameFilter.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_FILEFILTER_H
#include "jace/proxy/java/io/FileFilter.h"
#endif
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_PATH_H
#include "jace/proxy/java/nio/file/Path.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, io )

/**
 * The Jace C++ proxy class source for java/io/File.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define File_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define File_INITIALIZER
#endif

File::File( ::jace::proxy::java::lang::String p0 ) File_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

File::File( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 ) File_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

File::File( ::jace::proxy::java::io::File p0, ::jace::proxy::java::lang::String p1 ) File_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

File::File( ::jace::proxy::java::net::URI p0 ) File_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::java::lang::String File::getName() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getName" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String File::getParent() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getParent" ).invoke( *this, arguments );
}

::jace::proxy::java::io::File File::getParentFile() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::io::File >( "getParentFile" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String File::getPath() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getPath" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean File::isAbsolute() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isAbsolute" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String File::getAbsolutePath() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getAbsolutePath" ).invoke( *this, arguments );
}

::jace::proxy::java::io::File File::getAbsoluteFile() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::io::File >( "getAbsoluteFile" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String File::getCanonicalPath() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getCanonicalPath" ).invoke( *this, arguments );
}

::jace::proxy::java::io::File File::getCanonicalFile() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::io::File >( "getCanonicalFile" ).invoke( *this, arguments );
}

::jace::proxy::java::net::URL File::toURL() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::net::URL >( "toURL" ).invoke( *this, arguments );
}

::jace::proxy::java::net::URI File::toURI() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::net::URI >( "toURI" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean File::canRead() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "canRead" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean File::canWrite() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "canWrite" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean File::exists() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "exists" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean File::isDirectory() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isDirectory" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean File::isFile() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isFile" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean File::isHidden() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isHidden" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong File::lastModified() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "lastModified" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong File::length() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "length" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean File::createNewFile() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "createNewFile" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean File::delete_() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "delete_" ).invoke( *this, arguments );
}

void File::deleteOnExit() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "deleteOnExit" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::lang::String > File::list() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::String > >( "list" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::lang::String > File::list( ::jace::proxy::java::io::FilenameFilter p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::String > >( "list" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::io::File > File::listFiles() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::io::File > >( "listFiles" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::io::File > File::listFiles( ::jace::proxy::java::io::FilenameFilter p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::io::File > >( "listFiles" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::io::File > File::listFiles( ::jace::proxy::java::io::FileFilter p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::io::File > >( "listFiles" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean File::mkdir() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "mkdir" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean File::mkdirs() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "mkdirs" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean File::renameTo( ::jace::proxy::java::io::File p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "renameTo" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean File::setLastModified( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "setLastModified" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean File::setReadOnly() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "setReadOnly" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean File::setWritable( ::jace::proxy::types::JBoolean p0, ::jace::proxy::types::JBoolean p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "setWritable" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean File::setWritable( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "setWritable" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean File::setReadable( ::jace::proxy::types::JBoolean p0, ::jace::proxy::types::JBoolean p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "setReadable" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean File::setReadable( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "setReadable" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean File::setExecutable( ::jace::proxy::types::JBoolean p0, ::jace::proxy::types::JBoolean p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "setExecutable" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean File::setExecutable( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "setExecutable" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean File::canExecute() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "canExecute" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::io::File > File::listRoots() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::io::File > >( "listRoots" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::types::JLong File::getTotalSpace() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "getTotalSpace" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong File::getFreeSpace() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "getFreeSpace" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong File::getUsableSpace() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "getUsableSpace" ).invoke( *this, arguments );
}

::jace::proxy::java::io::File File::createTempFile( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::java::io::File p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::io::File >( "createTempFile" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::io::File File::createTempFile( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::io::File >( "createTempFile" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::types::JInt File::compareTo( ::jace::proxy::java::io::File p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "compareTo" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean File::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt File::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String File::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::Path File::toPath() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::Path >( "toPath" ).invoke( *this, arguments );
}

/**
 * public static final separatorChar
 *
 */
::jace::JFieldProxy< ::jace::proxy::types::JChar > File::separatorChar() {
  return ::jace::JField< ::jace::proxy::types::JChar >( "separatorChar" ).get( staticGetJavaJniClass() );
}

/**
 * public static final separator
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::lang::String > File::separator() {
  return ::jace::JField< ::jace::proxy::java::lang::String >( "separator" ).get( staticGetJavaJniClass() );
}

/**
 * public static final pathSeparatorChar
 *
 */
::jace::JFieldProxy< ::jace::proxy::types::JChar > File::pathSeparatorChar() {
  return ::jace::JField< ::jace::proxy::types::JChar >( "pathSeparatorChar" ).get( staticGetJavaJniClass() );
}

/**
 * public static final pathSeparator
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::lang::String > File::pathSeparator() {
  return ::jace::JField< ::jace::proxy::java::lang::String >( "pathSeparator" ).get( staticGetJavaJniClass() );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
File::File( jvalue value ) File_INITIALIZER {
  setJavaJniValue( value );
}

File::File( jobject object ) File_INITIALIZER {
  setJavaJniObject( object );
}

File::File( const File& object ) File_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

File::File( const NoOp& noOp ) File_INITIALIZER {
}

const JClass* File::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/io/File" );
  return &javaClass;
}

const JClass* File::getJavaJniClass() const throw ( JNIException ) {
  return File::staticGetJavaJniClass();
}

JEnlister< File> File::enlister;

END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::io::File>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::io::File( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::io::File>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::io::File>& proxy ) : 
    ::jace::proxy::java::io::File( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::io::File>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::io::File( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::io::File>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::io::File( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::io::File>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::io::File>& object ) : 
    ::jace::proxy::java::io::File( object.getJavaJniValue() ), Object( NO_OP ) {

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

