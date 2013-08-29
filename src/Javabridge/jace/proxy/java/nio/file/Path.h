
#ifndef JACE_PROXY_JAVA_NIO_FILE_PATH_H
#define JACE_PROXY_JAVA_NIO_FILE_PATH_H

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
#ifndef JACE_PROXY_JAVA_LANG_COMPARABLE_H
#include "jace/proxy/java/lang/Comparable.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_ITERABLE_H
#include "jace/proxy/java/lang/Iterable.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_WATCHABLE_H
#include "jace/proxy/java/nio/file/Watchable.h"
#endif

/**
 * Classes which this class is fully dependent upon.
 *
 */
#ifndef JACE_PROXY_JAVA_NIO_FILE_LINKOPTION_H
#include "jace/proxy/java/nio/file/LinkOption.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_WATCHEVENT_KIND_H
#include "jace/proxy/java/nio/file/WatchEvent.Kind.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_WATCHEVENT_MODIFIER_H
#include "jace/proxy/java/nio/file/WatchEvent.Modifier.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )
class FileSystem;
END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, net )
class URI;
END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class IOException;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class File;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )
class WatchKey;
END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )
class WatchService;
END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Iterator;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )

/**
 * The Jace C++ proxy class for java/nio/file/Path.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class Path : public virtual ::jace::proxy::java::lang::Object, public virtual ::jace::proxy::java::lang::Comparable, public virtual ::jace::proxy::java::lang::Iterable, public virtual ::jace::proxy::java::nio::file::Watchable {

public: 

/**
 * getFileSystem
 *
 */
::jace::proxy::java::nio::file::FileSystem getFileSystem();

/**
 * isAbsolute
 *
 */
::jace::proxy::types::JBoolean isAbsolute();

/**
 * getRoot
 *
 */
::jace::proxy::java::nio::file::Path getRoot();

/**
 * getFileName
 *
 */
::jace::proxy::java::nio::file::Path getFileName();

/**
 * getParent
 *
 */
::jace::proxy::java::nio::file::Path getParent();

/**
 * getNameCount
 *
 */
::jace::proxy::types::JInt getNameCount();

/**
 * getName
 *
 */
::jace::proxy::java::nio::file::Path getName( ::jace::proxy::types::JInt p0 );

/**
 * subpath
 *
 */
::jace::proxy::java::nio::file::Path subpath( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * startsWith
 *
 */
::jace::proxy::types::JBoolean startsWith( ::jace::proxy::java::nio::file::Path p0 );

/**
 * startsWith
 *
 */
::jace::proxy::types::JBoolean startsWith( ::jace::proxy::java::lang::String p0 );

/**
 * endsWith
 *
 */
::jace::proxy::types::JBoolean endsWith( ::jace::proxy::java::nio::file::Path p0 );

/**
 * endsWith
 *
 */
::jace::proxy::types::JBoolean endsWith( ::jace::proxy::java::lang::String p0 );

/**
 * normalize
 *
 */
::jace::proxy::java::nio::file::Path normalize();

/**
 * resolve
 *
 */
::jace::proxy::java::nio::file::Path resolve( ::jace::proxy::java::nio::file::Path p0 );

/**
 * resolve
 *
 */
::jace::proxy::java::nio::file::Path resolve( ::jace::proxy::java::lang::String p0 );

/**
 * resolveSibling
 *
 */
::jace::proxy::java::nio::file::Path resolveSibling( ::jace::proxy::java::nio::file::Path p0 );

/**
 * resolveSibling
 *
 */
::jace::proxy::java::nio::file::Path resolveSibling( ::jace::proxy::java::lang::String p0 );

/**
 * relativize
 *
 */
::jace::proxy::java::nio::file::Path relativize( ::jace::proxy::java::nio::file::Path p0 );

/**
 * toUri
 *
 */
::jace::proxy::java::net::URI toUri();

/**
 * toAbsolutePath
 *
 */
::jace::proxy::java::nio::file::Path toAbsolutePath();

/**
 * toRealPath
 *
 */
::jace::proxy::java::nio::file::Path toRealPath( ::jace::JArray< ::jace::proxy::java::nio::file::LinkOption > p0 );

/**
 * toFile
 *
 */
::jace::proxy::java::io::File toFile();

/**
 * register_
 *
 */
::jace::proxy::java::nio::file::WatchKey register_( ::jace::proxy::java::nio::file::WatchService p0, ::jace::JArray< ::jace::proxy::java::nio::file::WatchEvent_Kind > p1, ::jace::JArray< ::jace::proxy::java::nio::file::WatchEvent_Modifier > p2 );

/**
 * register_
 *
 */
::jace::proxy::java::nio::file::WatchKey register_( ::jace::proxy::java::nio::file::WatchService p0, ::jace::JArray< ::jace::proxy::java::nio::file::WatchEvent_Kind > p1 );

/**
 * iterator
 *
 */
::jace::proxy::java::util::Iterator iterator();

/**
 * compareTo
 *
 */
::jace::proxy::types::JInt compareTo( ::jace::proxy::java::nio::file::Path p0 );

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
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
/**
 * Special no arg constructor for interface virtual inheritance
 *
 */
Path();
Path( jvalue value );
Path( jobject object );
Path( const Path& object );
Path( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< Path> enlister;
};

END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::nio::file::Path>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::nio::file::Path>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::file::Path>& proxy );
#else
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
  template <> JFieldProxy< ::jace::proxy::java::nio::file::Path>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::file::Path>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::file::Path>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::file::Path>& object );
#else
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

#endif // #ifndef JACE_PROXY_JAVA_NIO_FILE_PATH_H

