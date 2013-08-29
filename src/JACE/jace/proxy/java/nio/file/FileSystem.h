
#ifndef JACE_PROXY_JAVA_NIO_FILE_FILESYSTEM_H
#define JACE_PROXY_JAVA_NIO_FILE_FILESYSTEM_H

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
#ifndef JACE_PROXY_JAVA_IO_CLOSEABLE_H
#include "jace/proxy/java/io/Closeable.h"
#endif

/**
 * Classes which this class is fully dependent upon.
 *
 */
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_6( jace, proxy, java, nio, file, spi )
class FileSystemProvider;
END_NAMESPACE_6( jace, proxy, java, nio, file, spi )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class IOException;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class Iterable;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Set;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )
class Path;
END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )
class PathMatcher;
END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE_6( jace, proxy, java, nio, file, attribute )
class UserPrincipalLookupService;
END_NAMESPACE_6( jace, proxy, java, nio, file, attribute )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )
class WatchService;
END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )

/**
 * The Jace C++ proxy class for java/nio/file/FileSystem.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class FileSystem : public virtual ::jace::proxy::java::lang::Object, public virtual ::jace::proxy::java::io::Closeable {

public: 

/**
 * provider
 *
 */
::jace::proxy::java::nio::file::spi::FileSystemProvider provider();

/**
 * close
 *
 */
void close();

/**
 * isOpen
 *
 */
::jace::proxy::types::JBoolean isOpen();

/**
 * isReadOnly
 *
 */
::jace::proxy::types::JBoolean isReadOnly();

/**
 * getSeparator
 *
 */
::jace::proxy::java::lang::String getSeparator();

/**
 * getRootDirectories
 *
 */
::jace::proxy::java::lang::Iterable getRootDirectories();

/**
 * getFileStores
 *
 */
::jace::proxy::java::lang::Iterable getFileStores();

/**
 * supportedFileAttributeViews
 *
 */
::jace::proxy::java::util::Set supportedFileAttributeViews();

/**
 * getPath
 *
 */
::jace::proxy::java::nio::file::Path getPath( ::jace::proxy::java::lang::String p0, ::jace::JArray< ::jace::proxy::java::lang::String > p1 );

/**
 * getPathMatcher
 *
 */
::jace::proxy::java::nio::file::PathMatcher getPathMatcher( ::jace::proxy::java::lang::String p0 );

/**
 * getUserPrincipalLookupService
 *
 */
::jace::proxy::java::nio::file::attribute::UserPrincipalLookupService getUserPrincipalLookupService();

/**
 * newWatchService
 *
 */
::jace::proxy::java::nio::file::WatchService newWatchService();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
FileSystem( jvalue value );
FileSystem( jobject object );
FileSystem( const FileSystem& object );
FileSystem( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< FileSystem> enlister;
};

END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::nio::file::FileSystem>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::nio::file::FileSystem>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::file::FileSystem>& proxy );
#else
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
  template <> JFieldProxy< ::jace::proxy::java::nio::file::FileSystem>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::file::FileSystem>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::file::FileSystem>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::file::FileSystem>& object );
#else
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

#endif // #ifndef JACE_PROXY_JAVA_NIO_FILE_FILESYSTEM_H

