
#ifndef JACE_PROXY_JAVA_NIO_CHARSET_CHARSETENCODER_H
#define JACE_PROXY_JAVA_NIO_CHARSET_CHARSETENCODER_H

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
BEGIN_NAMESPACE_5( jace, proxy, java, nio, charset )
class Charset;
END_NAMESPACE_5( jace, proxy, java, nio, charset )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, charset )
class CodingErrorAction;
END_NAMESPACE_5( jace, proxy, java, nio, charset )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JFloat;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, charset )
class CoderResult;
END_NAMESPACE_5( jace, proxy, java, nio, charset )

BEGIN_NAMESPACE_4( jace, proxy, java, nio )
class CharBuffer;
END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE_4( jace, proxy, java, nio )
class ByteBuffer;
END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, charset )
class CharacterCodingException;
END_NAMESPACE_5( jace, proxy, java, nio, charset )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JChar;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class CharSequence;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, charset )

/**
 * The Jace C++ proxy class for java/nio/charset/CharsetEncoder.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class CharsetEncoder : public virtual ::jace::proxy::java::lang::Object {

public: 

/**
 * charset
 *
 */
::jace::proxy::java::nio::charset::Charset charset();

/**
 * replacement
 *
 */
::jace::JArray< ::jace::proxy::types::JByte > replacement();

/**
 * replaceWith
 *
 */
::jace::proxy::java::nio::charset::CharsetEncoder replaceWith( ::jace::JArray< ::jace::proxy::types::JByte > p0 );

/**
 * isLegalReplacement
 *
 */
::jace::proxy::types::JBoolean isLegalReplacement( ::jace::JArray< ::jace::proxy::types::JByte > p0 );

/**
 * malformedInputAction
 *
 */
::jace::proxy::java::nio::charset::CodingErrorAction malformedInputAction();

/**
 * onMalformedInput
 *
 */
::jace::proxy::java::nio::charset::CharsetEncoder onMalformedInput( ::jace::proxy::java::nio::charset::CodingErrorAction p0 );

/**
 * unmappableCharacterAction
 *
 */
::jace::proxy::java::nio::charset::CodingErrorAction unmappableCharacterAction();

/**
 * onUnmappableCharacter
 *
 */
::jace::proxy::java::nio::charset::CharsetEncoder onUnmappableCharacter( ::jace::proxy::java::nio::charset::CodingErrorAction p0 );

/**
 * averageBytesPerChar
 *
 */
::jace::proxy::types::JFloat averageBytesPerChar();

/**
 * maxBytesPerChar
 *
 */
::jace::proxy::types::JFloat maxBytesPerChar();

/**
 * encode
 *
 */
::jace::proxy::java::nio::charset::CoderResult encode( ::jace::proxy::java::nio::CharBuffer p0, ::jace::proxy::java::nio::ByteBuffer p1, ::jace::proxy::types::JBoolean p2 );

/**
 * flush
 *
 */
::jace::proxy::java::nio::charset::CoderResult flush( ::jace::proxy::java::nio::ByteBuffer p0 );

/**
 * reset
 *
 */
::jace::proxy::java::nio::charset::CharsetEncoder reset();

/**
 * encode
 *
 */
::jace::proxy::java::nio::ByteBuffer encode( ::jace::proxy::java::nio::CharBuffer p0 );

/**
 * canEncode
 *
 */
::jace::proxy::types::JBoolean canEncode( ::jace::proxy::types::JChar p0 );

/**
 * canEncode
 *
 */
::jace::proxy::types::JBoolean canEncode( ::jace::proxy::java::lang::CharSequence p0 );

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
CharsetEncoder( jvalue value );
CharsetEncoder( jobject object );
CharsetEncoder( const CharsetEncoder& object );
CharsetEncoder( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< CharsetEncoder> enlister;
};

END_NAMESPACE_5( jace, proxy, java, nio, charset )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::nio::charset::CharsetEncoder>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::nio::charset::CharsetEncoder>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::charset::CharsetEncoder>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::nio::charset::CharsetEncoder>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::charset::CharsetEncoder( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::charset::CharsetEncoder>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::charset::CharsetEncoder>& proxy ) : 
    ::jace::proxy::java::nio::charset::CharsetEncoder( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::nio::charset::CharsetEncoder>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::charset::CharsetEncoder>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::charset::CharsetEncoder>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::charset::CharsetEncoder>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::nio::charset::CharsetEncoder>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::charset::CharsetEncoder( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::charset::CharsetEncoder>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::charset::CharsetEncoder( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::charset::CharsetEncoder>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::charset::CharsetEncoder>& object ) : 
    ::jace::proxy::java::nio::charset::CharsetEncoder( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_NIO_CHARSET_CHARSETENCODER_H

