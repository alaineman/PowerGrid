
#ifndef JACE_PROXY_JAVA_NIO_CHARBUFFER_H
#define JACE_PROXY_JAVA_NIO_CHARBUFFER_H

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
#ifndef JACE_PROXY_JAVA_LANG_APPENDABLE_H
#include "jace/proxy/java/lang/Appendable.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_CHARSEQUENCE_H
#include "jace/proxy/java/lang/CharSequence.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_READABLE_H
#include "jace/proxy/java/lang/Readable.h"
#endif

/**
 * Classes which this class is fully dependent upon.
 *
 */
#ifndef JACE_TYPES_JCHAR_H
#include "jace/proxy/types/JChar.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class IOException;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JChar;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class Object;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, nio )
class ByteOrder;
END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE_4( jace, proxy, java, nio )

/**
 * The Jace C++ proxy class for java/nio/CharBuffer.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class CharBuffer : public ::jace::proxy::java::nio::Buffer, public virtual ::jace::proxy::java::lang::Comparable, public virtual ::jace::proxy::java::lang::Appendable, public virtual ::jace::proxy::java::lang::CharSequence, public virtual ::jace::proxy::java::lang::Readable {

public: 

/**
 * allocate
 *
 */
static ::jace::proxy::java::nio::CharBuffer allocate( ::jace::proxy::types::JInt p0 );

/**
 * wrap
 *
 */
static ::jace::proxy::java::nio::CharBuffer wrap( ::jace::JArray< ::jace::proxy::types::JChar > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * wrap
 *
 */
static ::jace::proxy::java::nio::CharBuffer wrap( ::jace::JArray< ::jace::proxy::types::JChar > p0 );

/**
 * read
 *
 */
::jace::proxy::types::JInt read( ::jace::proxy::java::nio::CharBuffer p0 );

/**
 * wrap
 *
 */
static ::jace::proxy::java::nio::CharBuffer wrap( ::jace::proxy::java::lang::CharSequence p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * wrap
 *
 */
static ::jace::proxy::java::nio::CharBuffer wrap( ::jace::proxy::java::lang::CharSequence p0 );

/**
 * slice
 *
 */
::jace::proxy::java::nio::CharBuffer slice();

/**
 * duplicate
 *
 */
::jace::proxy::java::nio::CharBuffer duplicate();

/**
 * asReadOnlyBuffer
 *
 */
::jace::proxy::java::nio::CharBuffer asReadOnlyBuffer();

/**
 * get
 *
 */
::jace::proxy::types::JChar get();

/**
 * put
 *
 */
::jace::proxy::java::nio::CharBuffer put( ::jace::proxy::types::JChar p0 );

/**
 * get
 *
 */
::jace::proxy::types::JChar get( ::jace::proxy::types::JInt p0 );

/**
 * put
 *
 */
::jace::proxy::java::nio::CharBuffer put( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JChar p1 );

/**
 * get
 *
 */
::jace::proxy::java::nio::CharBuffer get( ::jace::JArray< ::jace::proxy::types::JChar > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * get
 *
 */
::jace::proxy::java::nio::CharBuffer get( ::jace::JArray< ::jace::proxy::types::JChar > p0 );

/**
 * put
 *
 */
::jace::proxy::java::nio::CharBuffer put( ::jace::proxy::java::nio::CharBuffer p0 );

/**
 * put
 *
 */
::jace::proxy::java::nio::CharBuffer put( ::jace::JArray< ::jace::proxy::types::JChar > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * put
 *
 */
::jace::proxy::java::nio::CharBuffer put( ::jace::JArray< ::jace::proxy::types::JChar > p0 );

/**
 * put
 *
 */
::jace::proxy::java::nio::CharBuffer put( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * put
 *
 */
::jace::proxy::java::nio::CharBuffer put( ::jace::proxy::java::lang::String p0 );

/**
 * hasArray
 *
 */
::jace::proxy::types::JBoolean hasArray();

/**
 * array
 *
 */
::jace::JArray< ::jace::proxy::types::JChar > array();

/**
 * arrayOffset
 *
 */
::jace::proxy::types::JInt arrayOffset();

/**
 * compact
 *
 */
::jace::proxy::java::nio::CharBuffer compact();

/**
 * isDirect
 *
 */
::jace::proxy::types::JBoolean isDirect();

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
::jace::proxy::types::JInt compareTo( ::jace::proxy::java::nio::CharBuffer p0 );

/**
 * toString
 *
 */
::jace::proxy::java::lang::String toString();

/**
 * length
 *
 */
::jace::proxy::types::JInt length();

/**
 * charAt
 *
 */
::jace::proxy::types::JChar charAt( ::jace::proxy::types::JInt p0 );

/**
 * subSequence
 *
 */
::jace::proxy::java::nio::CharBuffer subSequence( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * append
 *
 */
::jace::proxy::java::nio::CharBuffer append( ::jace::proxy::java::lang::CharSequence p0 );

/**
 * append
 *
 */
::jace::proxy::java::nio::CharBuffer append( ::jace::proxy::java::lang::CharSequence p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * append
 *
 */
::jace::proxy::java::nio::CharBuffer append( ::jace::proxy::types::JChar p0 );

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
CharBuffer( jvalue value );
CharBuffer( jobject object );
CharBuffer( const CharBuffer& object );
CharBuffer( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< CharBuffer> enlister;
};

END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::nio::CharBuffer>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::nio::CharBuffer>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::CharBuffer>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::nio::CharBuffer>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::CharBuffer( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::CharBuffer>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::CharBuffer>& proxy ) : 
    ::jace::proxy::java::nio::CharBuffer( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::nio::CharBuffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::CharBuffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::CharBuffer>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::CharBuffer>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::nio::CharBuffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::CharBuffer( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::CharBuffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::CharBuffer( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::CharBuffer>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::CharBuffer>& object ) : 
    ::jace::proxy::java::nio::CharBuffer( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_NIO_CHARBUFFER_H

