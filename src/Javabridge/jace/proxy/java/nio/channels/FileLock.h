
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_FILELOCK_H
#define JACE_PROXY_JAVA_NIO_CHANNELS_FILELOCK_H

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
#ifndef JACE_PROXY_JAVA_LANG_AUTOCLOSEABLE_H
#include "jace/proxy/java/lang/AutoCloseable.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )
class FileChannel;
END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )
class Channel;
END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JLong;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class IOException;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )

/**
 * The Jace C++ proxy class for java/nio/channels/FileLock.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class FileLock : public virtual ::jace::proxy::java::lang::Object, public virtual ::jace::proxy::java::lang::AutoCloseable {

public: 

/**
 * channel
 *
 */
::jace::proxy::java::nio::channels::FileChannel channel();

/**
 * acquiredBy
 *
 */
::jace::proxy::java::nio::channels::Channel acquiredBy();

/**
 * position
 *
 */
::jace::proxy::types::JLong position();

/**
 * size
 *
 */
::jace::proxy::types::JLong size();

/**
 * isShared
 *
 */
::jace::proxy::types::JBoolean isShared();

/**
 * overlaps
 *
 */
::jace::proxy::types::JBoolean overlaps( ::jace::proxy::types::JLong p0, ::jace::proxy::types::JLong p1 );

/**
 * isValid
 *
 */
::jace::proxy::types::JBoolean isValid();

/**
 * release
 *
 */
void release();

/**
 * close
 *
 */
void close();

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
FileLock( jvalue value );
FileLock( jobject object );
FileLock( const FileLock& object );
FileLock( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< FileLock> enlister;
};

END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::nio::channels::FileLock>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::nio::channels::FileLock>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::channels::FileLock>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::FileLock>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::channels::FileLock( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::FileLock>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::channels::FileLock>& proxy ) : 
    ::jace::proxy::java::nio::channels::FileLock( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::nio::channels::FileLock>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::channels::FileLock>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::channels::FileLock>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::channels::FileLock>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::FileLock>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::channels::FileLock( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::FileLock>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::channels::FileLock( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::FileLock>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::channels::FileLock>& object ) : 
    ::jace::proxy::java::nio::channels::FileLock( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_NIO_CHANNELS_FILELOCK_H

