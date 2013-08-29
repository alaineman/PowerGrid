
#ifndef JACE_PROXY_JAVA_NIO_BYTEBUFFER_H
#define JACE_PROXY_JAVA_NIO_BYTEBUFFER_H

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
#ifndef JACE_PROXY_JAVA_NIO_BUFFER_H
#include "jace/proxy/java/nio/Buffer.h"
#endif

/**
 * The interfaces implemented by this class.
 *
 */
#ifndef JACE_PROXY_JAVA_LANG_COMPARABLE_H
#include "jace/proxy/java/lang/Comparable.h"
#endif

/**
 * Classes which this class is fully dependent upon.
 *
 */
#ifndef JACE_TYPES_JBYTE_H
#include "jace/proxy/types/JByte.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JByte;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class Object;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, nio )
class ByteOrder;
END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JChar;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, nio )
class CharBuffer;
END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JShort;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, nio )
class ShortBuffer;
END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE_4( jace, proxy, java, nio )
class IntBuffer;
END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JLong;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, nio )
class LongBuffer;
END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JFloat;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, nio )
class FloatBuffer;
END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JDouble;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, nio )
class DoubleBuffer;
END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE_4( jace, proxy, java, nio )

/**
 * The Jace C++ proxy class for java/nio/ByteBuffer.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class ByteBuffer : public ::jace::proxy::java::nio::Buffer, public virtual ::jace::proxy::java::lang::Comparable {

public: 

/**
 * allocateDirect
 *
 */
static ::jace::proxy::java::nio::ByteBuffer allocateDirect( ::jace::proxy::types::JInt p0 );

/**
 * allocate
 *
 */
static ::jace::proxy::java::nio::ByteBuffer allocate( ::jace::proxy::types::JInt p0 );

/**
 * wrap
 *
 */
static ::jace::proxy::java::nio::ByteBuffer wrap( ::jace::JArray< ::jace::proxy::types::JByte > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * wrap
 *
 */
static ::jace::proxy::java::nio::ByteBuffer wrap( ::jace::JArray< ::jace::proxy::types::JByte > p0 );

/**
 * slice
 *
 */
::jace::proxy::java::nio::ByteBuffer slice();

/**
 * duplicate
 *
 */
::jace::proxy::java::nio::ByteBuffer duplicate();

/**
 * asReadOnlyBuffer
 *
 */
::jace::proxy::java::nio::ByteBuffer asReadOnlyBuffer();

/**
 * get
 *
 */
::jace::proxy::types::JByte get();

/**
 * put
 *
 */
::jace::proxy::java::nio::ByteBuffer put( ::jace::proxy::types::JByte p0 );

/**
 * get
 *
 */
::jace::proxy::types::JByte get( ::jace::proxy::types::JInt p0 );

/**
 * put
 *
 */
::jace::proxy::java::nio::ByteBuffer put( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JByte p1 );

/**
 * get
 *
 */
::jace::proxy::java::nio::ByteBuffer get( ::jace::JArray< ::jace::proxy::types::JByte > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * get
 *
 */
::jace::proxy::java::nio::ByteBuffer get( ::jace::JArray< ::jace::proxy::types::JByte > p0 );

/**
 * put
 *
 */
::jace::proxy::java::nio::ByteBuffer put( ::jace::proxy::java::nio::ByteBuffer p0 );

/**
 * put
 *
 */
::jace::proxy::java::nio::ByteBuffer put( ::jace::JArray< ::jace::proxy::types::JByte > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * put
 *
 */
::jace::proxy::java::nio::ByteBuffer put( ::jace::JArray< ::jace::proxy::types::JByte > p0 );

/**
 * hasArray
 *
 */
::jace::proxy::types::JBoolean hasArray();

/**
 * array
 *
 */
::jace::JArray< ::jace::proxy::types::JByte > array();

/**
 * arrayOffset
 *
 */
::jace::proxy::types::JInt arrayOffset();

/**
 * compact
 *
 */
::jace::proxy::java::nio::ByteBuffer compact();

/**
 * isDirect
 *
 */
::jace::proxy::types::JBoolean isDirect();

/**
 * toString
 *
 */
::jace::proxy::java::lang::String toString();

/**
 * hashCode
 *
 */
::jace::proxy::types::JInt hashCode();

/**
 * equals
 *
 */
::jace::proxy::types::JBoolean equals( ::jace::proxy::java::lang::Object p0 );

/**
 * compareTo
 *
 */
::jace::proxy::types::JInt compareTo( ::jace::proxy::java::nio::ByteBuffer p0 );

/**
 * order
 *
 */
::jace::proxy::java::nio::ByteOrder order();

/**
 * order
 *
 */
::jace::proxy::java::nio::ByteBuffer order( ::jace::proxy::java::nio::ByteOrder p0 );

/**
 * getChar
 *
 */
::jace::proxy::types::JChar getChar();

/**
 * putChar
 *
 */
::jace::proxy::java::nio::ByteBuffer putChar( ::jace::proxy::types::JChar p0 );

/**
 * getChar
 *
 */
::jace::proxy::types::JChar getChar( ::jace::proxy::types::JInt p0 );

/**
 * putChar
 *
 */
::jace::proxy::java::nio::ByteBuffer putChar( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JChar p1 );

/**
 * asCharBuffer
 *
 */
::jace::proxy::java::nio::CharBuffer asCharBuffer();

/**
 * getShort
 *
 */
::jace::proxy::types::JShort getShort();

/**
 * putShort
 *
 */
::jace::proxy::java::nio::ByteBuffer putShort( ::jace::proxy::types::JShort p0 );

/**
 * getShort
 *
 */
::jace::proxy::types::JShort getShort( ::jace::proxy::types::JInt p0 );

/**
 * putShort
 *
 */
::jace::proxy::java::nio::ByteBuffer putShort( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JShort p1 );

/**
 * asShortBuffer
 *
 */
::jace::proxy::java::nio::ShortBuffer asShortBuffer();

/**
 * getInt
 *
 */
::jace::proxy::types::JInt getInt();

/**
 * putInt
 *
 */
::jace::proxy::java::nio::ByteBuffer putInt( ::jace::proxy::types::JInt p0 );

/**
 * getInt
 *
 */
::jace::proxy::types::JInt getInt( ::jace::proxy::types::JInt p0 );

/**
 * putInt
 *
 */
::jace::proxy::java::nio::ByteBuffer putInt( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * asIntBuffer
 *
 */
::jace::proxy::java::nio::IntBuffer asIntBuffer();

/**
 * getLong
 *
 */
::jace::proxy::types::JLong getLong();

/**
 * putLong
 *
 */
::jace::proxy::java::nio::ByteBuffer putLong( ::jace::proxy::types::JLong p0 );

/**
 * getLong
 *
 */
::jace::proxy::types::JLong getLong( ::jace::proxy::types::JInt p0 );

/**
 * putLong
 *
 */
::jace::proxy::java::nio::ByteBuffer putLong( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JLong p1 );

/**
 * asLongBuffer
 *
 */
::jace::proxy::java::nio::LongBuffer asLongBuffer();

/**
 * getFloat
 *
 */
::jace::proxy::types::JFloat getFloat();

/**
 * putFloat
 *
 */
::jace::proxy::java::nio::ByteBuffer putFloat( ::jace::proxy::types::JFloat p0 );

/**
 * getFloat
 *
 */
::jace::proxy::types::JFloat getFloat( ::jace::proxy::types::JInt p0 );

/**
 * putFloat
 *
 */
::jace::proxy::java::nio::ByteBuffer putFloat( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JFloat p1 );

/**
 * asFloatBuffer
 *
 */
::jace::proxy::java::nio::FloatBuffer asFloatBuffer();

/**
 * getDouble
 *
 */
::jace::proxy::types::JDouble getDouble();

/**
 * putDouble
 *
 */
::jace::proxy::java::nio::ByteBuffer putDouble( ::jace::proxy::types::JDouble p0 );

/**
 * getDouble
 *
 */
::jace::proxy::types::JDouble getDouble( ::jace::proxy::types::JInt p0 );

/**
 * putDouble
 *
 */
::jace::proxy::java::nio::ByteBuffer putDouble( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JDouble p1 );

/**
 * asDoubleBuffer
 *
 */
::jace::proxy::java::nio::DoubleBuffer asDoubleBuffer();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
ByteBuffer( jvalue value );
ByteBuffer( jobject object );
ByteBuffer( const ByteBuffer& object );
ByteBuffer( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< ByteBuffer> enlister;
};

END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::nio::ByteBuffer>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::nio::ByteBuffer>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::ByteBuffer>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::nio::ByteBuffer>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::ByteBuffer( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::ByteBuffer>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::ByteBuffer>& proxy ) : 
    ::jace::proxy::java::nio::ByteBuffer( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::nio::ByteBuffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::ByteBuffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::ByteBuffer>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::ByteBuffer>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::nio::ByteBuffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::ByteBuffer( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::ByteBuffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::ByteBuffer( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::ByteBuffer>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::ByteBuffer>& object ) : 
    ::jace::proxy::java::nio::ByteBuffer( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_NIO_BYTEBUFFER_H

