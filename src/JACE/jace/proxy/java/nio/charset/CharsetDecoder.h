
#ifndef JACE_PROXY_JAVA_NIO_CHARSET_CHARSETDECODER_H
#define JACE_PROXY_JAVA_NIO_CHARSET_CHARSETDECODER_H

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
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_5( jace, proxy, java, nio, charset )
class Charset;
END_NAMESPACE_5( jace, proxy, java, nio, charset )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

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
class ByteBuffer;
END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE_4( jace, proxy, java, nio )
class CharBuffer;
END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, charset )
class CharacterCodingException;
END_NAMESPACE_5( jace, proxy, java, nio, charset )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, charset )

/**
 * The Jace C++ proxy class for java/nio/charset/CharsetDecoder.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class CharsetDecoder : public virtual ::jace::proxy::java::lang::Object {

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
::jace::proxy::java::lang::String replacement();

/**
 * replaceWith
 *
 */
::jace::proxy::java::nio::charset::CharsetDecoder replaceWith( ::jace::proxy::java::lang::String p0 );

/**
 * malformedInputAction
 *
 */
::jace::proxy::java::nio::charset::CodingErrorAction malformedInputAction();

/**
 * onMalformedInput
 *
 */
::jace::proxy::java::nio::charset::CharsetDecoder onMalformedInput( ::jace::proxy::java::nio::charset::CodingErrorAction p0 );

/**
 * unmappableCharacterAction
 *
 */
::jace::proxy::java::nio::charset::CodingErrorAction unmappableCharacterAction();

/**
 * onUnmappableCharacter
 *
 */
::jace::proxy::java::nio::charset::CharsetDecoder onUnmappableCharacter( ::jace::proxy::java::nio::charset::CodingErrorAction p0 );

/**
 * averageCharsPerByte
 *
 */
::jace::proxy::types::JFloat averageCharsPerByte();

/**
 * maxCharsPerByte
 *
 */
::jace::proxy::types::JFloat maxCharsPerByte();

/**
 * decode
 *
 */
::jace::proxy::java::nio::charset::CoderResult decode( ::jace::proxy::java::nio::ByteBuffer p0, ::jace::proxy::java::nio::CharBuffer p1, ::jace::proxy::types::JBoolean p2 );

/**
 * flush
 *
 */
::jace::proxy::java::nio::charset::CoderResult flush( ::jace::proxy::java::nio::CharBuffer p0 );

/**
 * reset
 *
 */
::jace::proxy::java::nio::charset::CharsetDecoder reset();

/**
 * decode
 *
 */
::jace::proxy::java::nio::CharBuffer decode( ::jace::proxy::java::nio::ByteBuffer p0 );

/**
 * isAutoDetecting
 *
 */
::jace::proxy::types::JBoolean isAutoDetecting();

/**
 * isCharsetDetected
 *
 */
::jace::proxy::types::JBoolean isCharsetDetected();

/**
 * detectedCharset
 *
 */
::jace::proxy::java::nio::charset::Charset detectedCharset();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
CharsetDecoder( jvalue value );
CharsetDecoder( jobject object );
CharsetDecoder( const CharsetDecoder& object );
CharsetDecoder( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< CharsetDecoder> enlister;
};

END_NAMESPACE_5( jace, proxy, java, nio, charset )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::nio::charset::CharsetDecoder>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::nio::charset::CharsetDecoder>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::charset::CharsetDecoder>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::nio::charset::CharsetDecoder>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::charset::CharsetDecoder( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::charset::CharsetDecoder>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::charset::CharsetDecoder>& proxy ) : 
    ::jace::proxy::java::nio::charset::CharsetDecoder( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::nio::charset::CharsetDecoder>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::charset::CharsetDecoder>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::charset::CharsetDecoder>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::charset::CharsetDecoder>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::nio::charset::CharsetDecoder>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::charset::CharsetDecoder( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::charset::CharsetDecoder>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::charset::CharsetDecoder( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::charset::CharsetDecoder>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::charset::CharsetDecoder>& object ) : 
    ::jace::proxy::java::nio::charset::CharsetDecoder( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_NIO_CHARSET_CHARSETDECODER_H

