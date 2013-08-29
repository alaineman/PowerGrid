
#ifndef JACE_PROXY_JAVA_IO_FILE_H
#define JACE_PROXY_JAVA_IO_FILE_H

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
 * The interfaces implemented by this class.
 *
 */
#ifndef JACE_PROXY_JAVA_IO_SERIALIZABLE_H
#include "jace/proxy/java/io/Serializable.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_COMPARABLE_H
#include "jace/proxy/java/lang/Comparable.h"
#endif

/**
 * Classes which this class is fully dependent upon.
 *
 */
#ifndef JACE_TYPES_JCHAR_H
#include "jace/proxy/types/JChar.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, net )
class URI;
END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class IOException;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, net )
class URL;
END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE_4( jace, proxy, java, net )
class MalformedURLException;
END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JLong;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class FilenameFilter;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class FileFilter;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )
class Path;
END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE_4( jace, proxy, java, io )

/**
 * The Jace C++ proxy class for java/io/File.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class File : public virtual ::jace::proxy::java::lang::Object, public virtual ::jace::proxy::java::io::Serializable, public virtual ::jace::proxy::java::lang::Comparable {

public: 

/**
 * File
 *
 */
File( ::jace::proxy::java::lang::String p0 );

/**
 * File
 *
 */
File( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 );

/**
 * File
 *
 */
File( ::jace::proxy::java::io::File p0, ::jace::proxy::java::lang::String p1 );

/**
 * File
 *
 */
File( ::jace::proxy::java::net::URI p0 );

/**
 * getName
 *
 */
::jace::proxy::java::lang::String getName();

/**
 * getParent
 *
 */
::jace::proxy::java::lang::String getParent();

/**
 * getParentFile
 *
 */
::jace::proxy::java::io::File getParentFile();

/**
 * getPath
 *
 */
::jace::proxy::java::lang::String getPath();

/**
 * isAbsolute
 *
 */
::jace::proxy::types::JBoolean isAbsolute();

/**
 * getAbsolutePath
 *
 */
::jace::proxy::java::lang::String getAbsolutePath();

/**
 * getAbsoluteFile
 *
 */
::jace::proxy::java::io::File getAbsoluteFile();

/**
 * getCanonicalPath
 *
 */
::jace::proxy::java::lang::String getCanonicalPath();

/**
 * getCanonicalFile
 *
 */
::jace::proxy::java::io::File getCanonicalFile();

/**
 * toURL
 *
 */
::jace::proxy::java::net::URL toURL();

/**
 * toURI
 *
 */
::jace::proxy::java::net::URI toURI();

/**
 * canRead
 *
 */
::jace::proxy::types::JBoolean canRead();

/**
 * canWrite
 *
 */
::jace::proxy::types::JBoolean canWrite();

/**
 * exists
 *
 */
::jace::proxy::types::JBoolean exists();

/**
 * isDirectory
 *
 */
::jace::proxy::types::JBoolean isDirectory();

/**
 * isFile
 *
 */
::jace::proxy::types::JBoolean isFile();

/**
 * isHidden
 *
 */
::jace::proxy::types::JBoolean isHidden();

/**
 * lastModified
 *
 */
::jace::proxy::types::JLong lastModified();

/**
 * length
 *
 */
::jace::proxy::types::JLong length();

/**
 * createNewFile
 *
 */
::jace::proxy::types::JBoolean createNewFile();

/**
 * delete_
 *
 */
::jace::proxy::types::JBoolean delete_();

/**
 * deleteOnExit
 *
 */
void deleteOnExit();

/**
 * list
 *
 */
::jace::JArray< ::jace::proxy::java::lang::String > list();

/**
 * list
 *
 */
::jace::JArray< ::jace::proxy::java::lang::String > list( ::jace::proxy::java::io::FilenameFilter p0 );

/**
 * listFiles
 *
 */
::jace::JArray< ::jace::proxy::java::io::File > listFiles();

/**
 * listFiles
 *
 */
::jace::JArray< ::jace::proxy::java::io::File > listFiles( ::jace::proxy::java::io::FilenameFilter p0 );

/**
 * listFiles
 *
 */
::jace::JArray< ::jace::proxy::java::io::File > listFiles( ::jace::proxy::java::io::FileFilter p0 );

/**
 * mkdir
 *
 */
::jace::proxy::types::JBoolean mkdir();

/**
 * mkdirs
 *
 */
::jace::proxy::types::JBoolean mkdirs();

/**
 * renameTo
 *
 */
::jace::proxy::types::JBoolean renameTo( ::jace::proxy::java::io::File p0 );

/**
 * setLastModified
 *
 */
::jace::proxy::types::JBoolean setLastModified( ::jace::proxy::types::JLong p0 );

/**
 * setReadOnly
 *
 */
::jace::proxy::types::JBoolean setReadOnly();

/**
 * setWritable
 *
 */
::jace::proxy::types::JBoolean setWritable( ::jace::proxy::types::JBoolean p0, ::jace::proxy::types::JBoolean p1 );

/**
 * setWritable
 *
 */
::jace::proxy::types::JBoolean setWritable( ::jace::proxy::types::JBoolean p0 );

/**
 * setReadable
 *
 */
::jace::proxy::types::JBoolean setReadable( ::jace::proxy::types::JBoolean p0, ::jace::proxy::types::JBoolean p1 );

/**
 * setReadable
 *
 */
::jace::proxy::types::JBoolean setReadable( ::jace::proxy::types::JBoolean p0 );

/**
 * setExecutable
 *
 */
::jace::proxy::types::JBoolean setExecutable( ::jace::proxy::types::JBoolean p0, ::jace::proxy::types::JBoolean p1 );

/**
 * setExecutable
 *
 */
::jace::proxy::types::JBoolean setExecutable( ::jace::proxy::types::JBoolean p0 );

/**
 * canExecute
 *
 */
::jace::proxy::types::JBoolean canExecute();

/**
 * listRoots
 *
 */
static ::jace::JArray< ::jace::proxy::java::io::File > listRoots();

/**
 * getTotalSpace
 *
 */
::jace::proxy::types::JLong getTotalSpace();

/**
 * getFreeSpace
 *
 */
::jace::proxy::types::JLong getFreeSpace();

/**
 * getUsableSpace
 *
 */
::jace::proxy::types::JLong getUsableSpace();

/**
 * createTempFile
 *
 */
static ::jace::proxy::java::io::File createTempFile( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::java::io::File p2 );

/**
 * createTempFile
 *
 */
static ::jace::proxy::java::io::File createTempFile( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 );

/**
 * compareTo
 *
 */
::jace::proxy::types::JInt compareTo( ::jace::proxy::java::io::File p0 );

/**
 * equals
 *
 */
::jace::proxy::types::JBoolean equals( ::jace::proxy::java::lang::Object p0 );

/**
 * hashCode
 *
 */
::jace::proxy::types::JInt hashCode();

/**
 * toString
 *
 */
::jace::proxy::java::lang::String toString();

/**
 * toPath
 *
 */
::jace::proxy::java::nio::file::Path toPath();

/**
 * public static final separatorChar
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::types::JChar > separatorChar();

/**
 * public static final separator
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::lang::String > separator();

/**
 * public static final pathSeparatorChar
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::types::JChar > pathSeparatorChar();

/**
 * public static final pathSeparator
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::lang::String > pathSeparator();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
File( jvalue value );
File( jobject object );
File( const File& object );
File( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< File> enlister;
};

END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::io::File>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::io::File>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::io::File>& proxy );
#else
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
  template <> JFieldProxy< ::jace::proxy::java::io::File>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::io::File>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::io::File>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::io::File>& object );
#else
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

#endif // #ifndef JACE_PROXY_JAVA_IO_FILE_H

