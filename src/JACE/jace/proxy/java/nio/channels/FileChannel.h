
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_FILECHANNEL_H
#define JACE_PROXY_JAVA_NIO_CHANNELS_FILECHANNEL_H

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
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_SPI_ABSTRACTINTERRUPTIBLECHANNEL_H
#include "jace/proxy/java/nio/channels/spi/AbstractInterruptibleChannel.h"
#endif

/**
 * The interfaces implemented by this class.
 *
 */
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_SEEKABLEBYTECHANNEL_H
#include "jace/proxy/java/nio/channels/SeekableByteChannel.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_GATHERINGBYTECHANNEL_H
#include "jace/proxy/java/nio/channels/GatheringByteChannel.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_SCATTERINGBYTECHANNEL_H
#include "jace/proxy/java/nio/channels/ScatteringByteChannel.h"
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
#ifndef JACE_PROXY_JAVA_NIO_BYTEBUFFER_H
#include "jace/proxy/java/nio/ByteBuffer.h"
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

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class IOException;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, nio )
class ByteBuffer;
END_NAMESPACE_4( jace, proxy, java, nio )

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
class WritableByteChannel;
END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )
class ReadableByteChannel;
END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE_4( jace, proxy, java, nio )
class MappedByteBuffer;
END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )
class FileChannel_MapMode;
END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )
class FileLock;
END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )

/**
 * The Jace C++ proxy class for java/nio/channels/FileChannel.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class FileChannel : public ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel, public virtual ::jace::proxy::java::nio::channels::SeekableByteChannel, public virtual ::jace::proxy::java::nio::channels::GatheringByteChannel, public virtual ::jace::proxy::java::nio::channels::ScatteringByteChannel {

public: 

/**
 * open
 *
 */
static ::jace::proxy::java::nio::channels::FileChannel open( ::jace::proxy::java::nio::file::Path p0, ::jace::proxy::java::util::Set p1, ::jace::JArray< ::jace::proxy::java::nio::file::attribute::FileAttribute > p2 );

/**
 * open
 *
 */
static ::jace::proxy::java::nio::channels::FileChannel open( ::jace::proxy::java::nio::file::Path p0, ::jace::JArray< ::jace::proxy::java::nio::file::OpenOption > p1 );

/**
 * read
 *
 */
::jace::proxy::types::JInt read( ::jace::proxy::java::nio::ByteBuffer p0 );

/**
 * read
 *
 */
::jace::proxy::types::JLong read( ::jace::JArray< ::jace::proxy::java::nio::ByteBuffer > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * read
 *
 */
::jace::proxy::types::JLong read( ::jace::JArray< ::jace::proxy::java::nio::ByteBuffer > p0 );

/**
 * write
 *
 */
::jace::proxy::types::JInt write( ::jace::proxy::java::nio::ByteBuffer p0 );

/**
 * write
 *
 */
::jace::proxy::types::JLong write( ::jace::JArray< ::jace::proxy::java::nio::ByteBuffer > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * write
 *
 */
::jace::proxy::types::JLong write( ::jace::JArray< ::jace::proxy::java::nio::ByteBuffer > p0 );

/**
 * position
 *
 */
::jace::proxy::types::JLong position();

/**
 * position
 *
 */
::jace::proxy::java::nio::channels::FileChannel position( ::jace::proxy::types::JLong p0 );

/**
 * size
 *
 */
::jace::proxy::types::JLong size();

/**
 * truncate
 *
 */
::jace::proxy::java::nio::channels::FileChannel truncate( ::jace::proxy::types::JLong p0 );

/**
 * force
 *
 */
void force( ::jace::proxy::types::JBoolean p0 );

/**
 * transferTo
 *
 */
::jace::proxy::types::JLong transferTo( ::jace::proxy::types::JLong p0, ::jace::proxy::types::JLong p1, ::jace::proxy::java::nio::channels::WritableByteChannel p2 );

/**
 * transferFrom
 *
 */
::jace::proxy::types::JLong transferFrom( ::jace::proxy::java::nio::channels::ReadableByteChannel p0, ::jace::proxy::types::JLong p1, ::jace::proxy::types::JLong p2 );

/**
 * read
 *
 */
::jace::proxy::types::JInt read( ::jace::proxy::java::nio::ByteBuffer p0, ::jace::proxy::types::JLong p1 );

/**
 * write
 *
 */
::jace::proxy::types::JInt write( ::jace::proxy::java::nio::ByteBuffer p0, ::jace::proxy::types::JLong p1 );

/**
 * map
 *
 */
::jace::proxy::java::nio::MappedByteBuffer map( ::jace::proxy::java::nio::channels::FileChannel_MapMode p0, ::jace::proxy::types::JLong p1, ::jace::proxy::types::JLong p2 );

/**
 * lock
 *
 */
::jace::proxy::java::nio::channels::FileLock lock( ::jace::proxy::types::JLong p0, ::jace::proxy::types::JLong p1, ::jace::proxy::types::JBoolean p2 );

/**
 * lock
 *
 */
::jace::proxy::java::nio::channels::FileLock lock();

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
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
FileChannel( jvalue value );
FileChannel( jobject object );
FileChannel( const FileChannel& object );
FileChannel( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< FileChannel> enlister;
};

END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::nio::channels::FileChannel>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::nio::channels::FileChannel>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::channels::FileChannel>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::FileChannel>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::channels::FileChannel( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::FileChannel>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::channels::FileChannel>& proxy ) : 
    ::jace::proxy::java::nio::channels::FileChannel( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::nio::channels::FileChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::channels::FileChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::channels::FileChannel>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::channels::FileChannel>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::FileChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::channels::FileChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::FileChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::channels::FileChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::FileChannel>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::channels::FileChannel>& object ) : 
    ::jace::proxy::java::nio::channels::FileChannel( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_NIO_CHANNELS_FILECHANNEL_H

