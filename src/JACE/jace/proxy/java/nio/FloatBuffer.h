
#ifndef JACE_PROXY_JAVA_NIO_FLOATBUFFER_H
#define JACE_PROXY_JAVA_NIO_FLOATBUFFER_H

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
#ifndef JACE_TYPES_JFLOAT_H
#include "jace/proxy/types/JFloat.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JFloat;
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

BEGIN_NAMESPACE_4( jace, proxy, java, nio )

/**
 * The Jace C++ proxy class for java/nio/FloatBuffer.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class FloatBuffer : public ::jace::proxy::java::nio::Buffer, public virtual ::jace::proxy::java::lang::Comparable {

public: 

/**
 * allocate
 *
 */
static ::jace::proxy::java::nio::FloatBuffer allocate( ::jace::proxy::types::JInt p0 );

/**
 * wrap
 *
 */
static ::jace::proxy::java::nio::FloatBuffer wrap( ::jace::JArray< ::jace::proxy::types::JFloat > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * wrap
 *
 */
static ::jace::proxy::java::nio::FloatBuffer wrap( ::jace::JArray< ::jace::proxy::types::JFloat > p0 );

/**
 * slice
 *
 */
::jace::proxy::java::nio::FloatBuffer slice();

/**
 * duplicate
 *
 */
::jace::proxy::java::nio::FloatBuffer duplicate();

/**
 * asReadOnlyBuffer
 *
 */
::jace::proxy::java::nio::FloatBuffer asReadOnlyBuffer();

/**
 * get
 *
 */
::jace::proxy::types::JFloat get();

/**
 * put
 *
 */
::jace::proxy::java::nio::FloatBuffer put( ::jace::proxy::types::JFloat p0 );

/**
 * get
 *
 */
::jace::proxy::types::JFloat get( ::jace::proxy::types::JInt p0 );

/**
 * put
 *
 */
::jace::proxy::java::nio::FloatBuffer put( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JFloat p1 );

/**
 * get
 *
 */
::jace::proxy::java::nio::FloatBuffer get( ::jace::JArray< ::jace::proxy::types::JFloat > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * get
 *
 */
::jace::proxy::java::nio::FloatBuffer get( ::jace::JArray< ::jace::proxy::types::JFloat > p0 );

/**
 * put
 *
 */
::jace::proxy::java::nio::FloatBuffer put( ::jace::proxy::java::nio::FloatBuffer p0 );

/**
 * put
 *
 */
::jace::proxy::java::nio::FloatBuffer put( ::jace::JArray< ::jace::proxy::types::JFloat > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * put
 *
 */
::jace::proxy::java::nio::FloatBuffer put( ::jace::JArray< ::jace::proxy::types::JFloat > p0 );

/**
 * hasArray
 *
 */
::jace::proxy::types::JBoolean hasArray();

/**
 * array
 *
 */
::jace::JArray< ::jace::proxy::types::JFloat > array();

/**
 * arrayOffset
 *
 */
::jace::proxy::types::JInt arrayOffset();

/**
 * compact
 *
 */
::jace::proxy::java::nio::FloatBuffer compact();

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
::jace::proxy::types::JInt compareTo( ::jace::proxy::java::nio::FloatBuffer p0 );

/**
 * order
 *
 */
::jace::proxy::java::nio::ByteOrder order();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
FloatBuffer( jvalue value );
FloatBuffer( jobject object );
FloatBuffer( const FloatBuffer& object );
FloatBuffer( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< FloatBuffer> enlister;
};

END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::nio::FloatBuffer>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::nio::FloatBuffer>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::FloatBuffer>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::nio::FloatBuffer>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::FloatBuffer( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::FloatBuffer>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::FloatBuffer>& proxy ) : 
    ::jace::proxy::java::nio::FloatBuffer( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::nio::FloatBuffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::FloatBuffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::FloatBuffer>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::FloatBuffer>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::nio::FloatBuffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::FloatBuffer( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::FloatBuffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::FloatBuffer( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::FloatBuffer>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::FloatBuffer>& object ) : 
    ::jace::proxy::java::nio::FloatBuffer( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_NIO_FLOATBUFFER_H

