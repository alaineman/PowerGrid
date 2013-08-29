
#ifndef JACE_PROXY_JAVA_NIO_CHARSET_CHARSET_H
#define JACE_PROXY_JAVA_NIO_CHARSET_CHARSET_H

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

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class SortedMap;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Set;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Locale;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, charset )
class CharsetDecoder;
END_NAMESPACE_5( jace, proxy, java, nio, charset )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, charset )
class CharsetEncoder;
END_NAMESPACE_5( jace, proxy, java, nio, charset )

BEGIN_NAMESPACE_4( jace, proxy, java, nio )
class CharBuffer;
END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE_4( jace, proxy, java, nio )
class ByteBuffer;
END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, charset )

/**
 * The Jace C++ proxy class for java/nio/charset/Charset.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class Charset : public virtual ::jace::proxy::java::lang::Object, public virtual ::jace::proxy::java::lang::Comparable {

public: 

/**
 * isSupported
 *
 */
static ::jace::proxy::types::JBoolean isSupported( ::jace::proxy::java::lang::String p0 );

/**
 * forName
 *
 */
static ::jace::proxy::java::nio::charset::Charset forName( ::jace::proxy::java::lang::String p0 );

/**
 * availableCharsets
 *
 */
static ::jace::proxy::java::util::SortedMap availableCharsets();

/**
 * defaultCharset
 *
 */
static ::jace::proxy::java::nio::charset::Charset defaultCharset();

/**
 * name
 *
 */
::jace::proxy::java::lang::String name();

/**
 * aliases
 *
 */
::jace::proxy::java::util::Set aliases();

/**
 * displayName
 *
 */
::jace::proxy::java::lang::String displayName();

/**
 * isRegistered
 *
 */
::jace::proxy::types::JBoolean isRegistered();

/**
 * displayName
 *
 */
::jace::proxy::java::lang::String displayName( ::jace::proxy::java::util::Locale p0 );

/**
 * contains
 *
 */
::jace::proxy::types::JBoolean contains( ::jace::proxy::java::nio::charset::Charset p0 );

/**
 * newDecoder
 *
 */
::jace::proxy::java::nio::charset::CharsetDecoder newDecoder();

/**
 * newEncoder
 *
 */
::jace::proxy::java::nio::charset::CharsetEncoder newEncoder();

/**
 * canEncode
 *
 */
::jace::proxy::types::JBoolean canEncode();

/**
 * decode
 *
 */
::jace::proxy::java::nio::CharBuffer decode( ::jace::proxy::java::nio::ByteBuffer p0 );

/**
 * encode
 *
 */
::jace::proxy::java::nio::ByteBuffer encode( ::jace::proxy::java::nio::CharBuffer p0 );

/**
 * encode
 *
 */
::jace::proxy::java::nio::ByteBuffer encode( ::jace::proxy::java::lang::String p0 );

/**
 * compareTo
 *
 */
::jace::proxy::types::JInt compareTo( ::jace::proxy::java::nio::charset::Charset p0 );

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
 * toString
 *
 */
::jace::proxy::java::lang::String toString();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Charset( jvalue value );
Charset( jobject object );
Charset( const Charset& object );
Charset( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< Charset> enlister;
};

END_NAMESPACE_5( jace, proxy, java, nio, charset )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::nio::charset::Charset>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::nio::charset::Charset>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::charset::Charset>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::nio::charset::Charset>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::charset::Charset( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::charset::Charset>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::charset::Charset>& proxy ) : 
    ::jace::proxy::java::nio::charset::Charset( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::nio::charset::Charset>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::charset::Charset>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::charset::Charset>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::charset::Charset>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::nio::charset::Charset>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::charset::Charset( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::charset::Charset>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::charset::Charset( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::charset::Charset>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::charset::Charset>& object ) : 
    ::jace::proxy::java::nio::charset::Charset( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_NIO_CHARSET_CHARSET_H

