
#ifndef JACE_PROXY_JAVA_NIO_CHARSET_CHARSETDECODER_H
#include "jace/proxy/java/nio/charset/CharsetDecoder.h"
#endif

/**
 * Standard Jace headers needed to implement this class.
 *
 */
#ifndef JACE_JARGUMENTS_H
#include "jace/JArguments.h"
#endif
using jace::JArguments;

#ifndef JACE_JMETHOD_H
#include "jace/JMethod.h"
#endif
using jace::JMethod;

#ifndef JACE_JFIELD_H
#include "jace/JField.h"
#endif
using jace::JField;

#ifndef JACE_JCLASS_IMPL_H
#include "jace/JClassImpl.h"
#endif
using jace::JClassImpl;


/**
 * Headers for the classes that this class uses.
 *
 */
#ifndef JACE_PROXY_JAVA_NIO_CHARSET_CHARSET_H
#include "jace/proxy/java/nio/charset/Charset.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHARSET_CODINGERRORACTION_H
#include "jace/proxy/java/nio/charset/CodingErrorAction.h"
#endif
#ifndef JACE_TYPES_JFLOAT_H
#include "jace/proxy/types/JFloat.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHARSET_CODERRESULT_H
#include "jace/proxy/java/nio/charset/CoderResult.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_BYTEBUFFER_H
#include "jace/proxy/java/nio/ByteBuffer.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHARBUFFER_H
#include "jace/proxy/java/nio/CharBuffer.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHARSET_CHARACTERCODINGEXCEPTION_H
#include "jace/proxy/java/nio/charset/CharacterCodingException.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, nio, charset )

/**
 * The Jace C++ proxy class source for java/nio/charset/CharsetDecoder.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define CharsetDecoder_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define CharsetDecoder_INITIALIZER
#endif

::jace::proxy::java::nio::charset::Charset CharsetDecoder::charset() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::Charset >( "charset" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String CharsetDecoder::replacement() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "replacement" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::charset::CharsetDecoder CharsetDecoder::replaceWith( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::CharsetDecoder >( "replaceWith" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::charset::CodingErrorAction CharsetDecoder::malformedInputAction() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::CodingErrorAction >( "malformedInputAction" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::charset::CharsetDecoder CharsetDecoder::onMalformedInput( ::jace::proxy::java::nio::charset::CodingErrorAction p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::CharsetDecoder >( "onMalformedInput" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::charset::CodingErrorAction CharsetDecoder::unmappableCharacterAction() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::CodingErrorAction >( "unmappableCharacterAction" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::charset::CharsetDecoder CharsetDecoder::onUnmappableCharacter( ::jace::proxy::java::nio::charset::CodingErrorAction p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::CharsetDecoder >( "onUnmappableCharacter" ).invoke( *this, arguments );
}

::jace::proxy::types::JFloat CharsetDecoder::averageCharsPerByte() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JFloat >( "averageCharsPerByte" ).invoke( *this, arguments );
}

::jace::proxy::types::JFloat CharsetDecoder::maxCharsPerByte() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JFloat >( "maxCharsPerByte" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::charset::CoderResult CharsetDecoder::decode( ::jace::proxy::java::nio::ByteBuffer p0, ::jace::proxy::java::nio::CharBuffer p1, ::jace::proxy::types::JBoolean p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::CoderResult >( "decode" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::charset::CoderResult CharsetDecoder::flush( ::jace::proxy::java::nio::CharBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::CoderResult >( "flush" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::charset::CharsetDecoder CharsetDecoder::reset() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::CharsetDecoder >( "reset" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::CharBuffer CharsetDecoder::decode( ::jace::proxy::java::nio::ByteBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "decode" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean CharsetDecoder::isAutoDetecting() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isAutoDetecting" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean CharsetDecoder::isCharsetDetected() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isCharsetDetected" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::charset::Charset CharsetDecoder::detectedCharset() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::Charset >( "detectedCharset" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
CharsetDecoder::CharsetDecoder( jvalue value ) CharsetDecoder_INITIALIZER {
  setJavaJniValue( value );
}

CharsetDecoder::CharsetDecoder( jobject object ) CharsetDecoder_INITIALIZER {
  setJavaJniObject( object );
}

CharsetDecoder::CharsetDecoder( const CharsetDecoder& object ) CharsetDecoder_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

CharsetDecoder::CharsetDecoder( const NoOp& noOp ) CharsetDecoder_INITIALIZER {
}

const JClass* CharsetDecoder::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/charset/CharsetDecoder" );
  return &javaClass;
}

const JClass* CharsetDecoder::getJavaJniClass() const throw ( JNIException ) {
  return CharsetDecoder::staticGetJavaJniClass();
}

JEnlister< CharsetDecoder> CharsetDecoder::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, charset )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
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

