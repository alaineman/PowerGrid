
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_ASYNCHRONOUSFILECHANNEL_H
#define JACE_PROXY_JAVA_NIO_CHANNELS_ASYNCHRONOUSFILECHANNEL_H

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
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_ASYNCHRONOUSCHANNEL_H
#include "jace/proxy/java/nio/channels/AsynchronousChannel.h"
#endif

/**
 * Classes which this class is fully dependent upon.
 *
 */
#ifndef JACE_PROXY_JAVA_NIO_FILE_ATTRIBUTE_FILEATTRIBUTE_H
#include "jace/proxy/java/nio/file/attribute/FileAttribute.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_OPENOPTION_H
#include "jace/proxy/java/nio/file/OpenOption.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )
class Path;
END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Set;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_5( jace, proxy, java, util, concurrent )
class ExecutorService;
END_NAMESPACE_5( jace, proxy, java, util, concurrent )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class IOException;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JLong;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )
class CompletionHandler;
END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE_5( jace, proxy, java, util, concurrent )
class Future;
END_NAMESPACE_5( jace, proxy, java, util, concurrent )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )
class FileLock;
END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE_4( jace, proxy, java, nio )
class ByteBuffer;
END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )

/**
 * The Jace C++ proxy class for java/nio/channels/AsynchronousFileChannel.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class AsynchronousFileChannel : public virtual ::jace::proxy::java::lang::Object, public virtual ::jace::proxy::java::nio::channels::AsynchronousChannel {

public: 

/**
 * open
 *
 */
static ::jace::proxy::java::nio::channels::AsynchronousFileChannel open( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::util::Set p1, ::jace::proxy::java::util::concurrent::ExecutorService p2, ::jace::JArray< ::jace::proxy::java::nio::file::attribute::FileAttribute > p3 );

/**
 * open
 *
 */
static ::jace::proxy::java::nio::channels::AsynchronousFileChannel open( ::jace::proxy::java::nio::file::Path p0, ::jace::JArray< ::jace::proxy::java::nio::file::OpenOption > p1 );

/**
 * size
 *
 */
::jace::proxy::types::JLong size();

/**
 * truncate
 *
 */
::jace::proxy::java::nio::channels::AsynchronousFileChannel truncate( ::jace::proxy::types::JLong p0 );

/**
 * force
 *
 */
void force( ::jace::proxy::types::JBoolean p0 );

/**
 * lock
 *
 */
void lock( ::jace::proxy::types::JLong p0, ::jace::proxy::types::JLong p1, ::jace::proxy::types::JBoolean p2, ::jace::proxy::java::lang::Object p3, ::jace::proxy::java::nio::channels::CompletionHandler p4 );

/**
 * lock
 *
 */
void lock( ::jace::proxy::java::lang::Object p0, ::jace::proxy::java::nio::channels::CompletionHandler p1 );

/**
 * lock
 *
 */
::jace::proxy::java::util::concurrent::Future lock( ::jace::proxy::types::JLong p0, ::jace::proxy::types::JLong p1, ::jace::proxy::types::JBoolean p2 );

/**
 * lock
 *
 */
::jace::proxy::java::util::concurrent::Future lock();

/**
 * tryLock
 *
 */
::jace::proxy::java::nio::channels::FileLock tryLock( ::jace::proxy::types::JLong p0, ::jace::proxy::types::JLong p1, ::jace::proxy::types::JBoolean p2 );

/**
 * tryLock
 *
 */
::jace::proxy::java::nio::channels::FileLock tryLock();

/**
 * read
 *
 */
void read( ::jace::proxy::java::nio::ByteBuffer p0, ::jace::proxy::types::JLong p1, ::jace::proxy::java::lang::Object p2, ::jace::proxy::java::nio::channels::CompletionHandler p3 );

/**
 * read
 *
 */
::jace::proxy::java::util::concurrent::Future read( ::jace::proxy::java::nio::ByteBuffer p0, ::jace::proxy::types::JLong p1 );

/**
 * write
 *
 */
void write( ::jace::proxy::java::nio::ByteBuffer p0, ::jace::proxy::types::JLong p1, ::jace::proxy::java::lang::Object p2, ::jace::proxy::java::nio::channels::CompletionHandler p3 );

/**
 * write
 *
 */
::jace::proxy::java::util::concurrent::Future write( ::jace::proxy::java::nio::ByteBuffer p0, ::jace::proxy::types::JLong p1 );

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
AsynchronousFileChannel( jvalue value );
AsynchronousFileChannel( jobject object );
AsynchronousFileChannel( const AsynchronousFileChannel& object );
AsynchronousFileChannel( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< AsynchronousFileChannel> enlister;
};

END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::nio::channels::AsynchronousFileChannel>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::nio::channels::AsynchronousFileChannel>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::channels::AsynchronousFileChannel>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::AsynchronousFileChannel>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::channels::AsynchronousFileChannel( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::AsynchronousFileChannel>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::channels::AsynchronousFileChannel>& proxy ) : 
    ::jace::proxy::java::nio::channels::AsynchronousFileChannel( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::nio::channels::AsynchronousFileChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::channels::AsynchronousFileChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::channels::AsynchronousFileChannel>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::channels::AsynchronousFileChannel>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::AsynchronousFileChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::channels::AsynchronousFileChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::AsynchronousFileChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::channels::AsynchronousFileChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::AsynchronousFileChannel>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::channels::AsynchronousFileChannel>& object ) : 
    ::jace::proxy::java::nio::channels::AsynchronousFileChannel( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_NIO_CHANNELS_ASYNCHRONOUSFILECHANNEL_H

