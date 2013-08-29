
#ifndef JACE_PROXY_JAVA_NIO_CHARSET_CHARSETENCODER_H
#include "jace/proxy/java/nio/charset/CharsetEncoder.h"
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
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
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
#ifndef JACE_PROXY_JAVA_NIO_CHARBUFFER_H
#include "jace/proxy/java/nio/CharBuffer.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_BYTEBUFFER_H
#include "jace/proxy/java/nio/ByteBuffer.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHARSET_CHARACTERCODINGEXCEPTION_H
#include "jace/proxy/java/nio/charset/CharacterCodingException.h"
#endif
#ifndef JACE_TYPES_JCHAR_H
#include "jace/proxy/types/JChar.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_CHARSEQUENCE_H
#include "jace/proxy/java/lang/CharSequence.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, nio, charset )

/**
 * The Jace C++ proxy class source for java/nio/charset/CharsetEncoder.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define CharsetEncoder_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define CharsetEncoder_INITIALIZER
#endif

::jace::proxy::java::nio::charset::Charset CharsetEncoder::charset() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::Charset >( "charset" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::types::JByte > CharsetEncoder::replacement() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::types::JByte > >( "replacement" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::charset::CharsetEncoder CharsetEncoder::replaceWith( ::jace::JArray< ::jace::proxy::types::JByte > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::CharsetEncoder >( "replaceWith" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean CharsetEncoder::isLegalReplacement( ::jace::JArray< ::jace::proxy::types::JByte > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isLegalReplacement" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::charset::CodingErrorAction CharsetEncoder::malformedInputAction() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::CodingErrorAction >( "malformedInputAction" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::charset::CharsetEncoder CharsetEncoder::onMalformedInput( ::jace::proxy::java::nio::charset::CodingErrorAction p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::CharsetEncoder >( "onMalformedInput" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::charset::CodingErrorAction CharsetEncoder::unmappableCharacterAction() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::CodingErrorAction >( "unmappableCharacterAction" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::charset::CharsetEncoder CharsetEncoder::onUnmappableCharacter( ::jace::proxy::java::nio::charset::CodingErrorAction p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::CharsetEncoder >( "onUnmappableCharacter" ).invoke( *this, arguments );
}

::jace::proxy::types::JFloat CharsetEncoder::averageBytesPerChar() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JFloat >( "averageBytesPerChar" ).invoke( *this, arguments );
}

::jace::proxy::types::JFloat CharsetEncoder::maxBytesPerChar() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JFloat >( "maxBytesPerChar" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::charset::CoderResult CharsetEncoder::encode( ::jace::proxy::java::nio::CharBuffer p0, ::jace::proxy::java::nio::ByteBuffer p1, ::jace::proxy::types::JBoolean p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::CoderResult >( "encode" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::charset::CoderResult CharsetEncoder::flush( ::jace::proxy::java::nio::ByteBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::CoderResult >( "flush" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::charset::CharsetEncoder CharsetEncoder::reset() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::CharsetEncoder >( "reset" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer CharsetEncoder::encode( ::jace::proxy::java::nio::CharBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "encode" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean CharsetEncoder::canEncode( ::jace::proxy::types::JChar p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "canEncode" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean CharsetEncoder::canEncode( ::jace::proxy::java::lang::CharSequence p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "canEncode" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
CharsetEncoder::CharsetEncoder( jvalue value ) CharsetEncoder_INITIALIZER {
  setJavaJniValue( value );
}

CharsetEncoder::CharsetEncoder( jobject object ) CharsetEncoder_INITIALIZER {
  setJavaJniObject( object );
}

CharsetEncoder::CharsetEncoder( const CharsetEncoder& object ) CharsetEncoder_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

CharsetEncoder::CharsetEncoder( const NoOp& noOp ) CharsetEncoder_INITIALIZER {
}

const JClass* CharsetEncoder::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/charset/CharsetEncoder" );
  return &javaClass;
}

const JClass* CharsetEncoder::getJavaJniClass() const throw ( JNIException ) {
  return CharsetEncoder::staticGetJavaJniClass();
}

JEnlister< CharsetEncoder> CharsetEncoder::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, charset )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
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

