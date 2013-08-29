
#ifndef JACE_PROXY_JAVA_NIO_CHARSET_CHARSET_H
#include "jace/proxy/java/nio/charset/Charset.h"
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
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_SORTEDMAP_H
#include "jace/proxy/java/util/SortedMap.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_SET_H
#include "jace/proxy/java/util/Set.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_LOCALE_H
#include "jace/proxy/java/util/Locale.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHARSET_CHARSETDECODER_H
#include "jace/proxy/java/nio/charset/CharsetDecoder.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHARSET_CHARSETENCODER_H
#include "jace/proxy/java/nio/charset/CharsetEncoder.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHARBUFFER_H
#include "jace/proxy/java/nio/CharBuffer.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_BYTEBUFFER_H
#include "jace/proxy/java/nio/ByteBuffer.h"
#endif
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, nio, charset )

/**
 * The Jace C++ proxy class source for java/nio/charset/Charset.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Charset_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Charset_INITIALIZER
#endif

::jace::proxy::types::JBoolean Charset::isSupported( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isSupported" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::charset::Charset Charset::forName( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::Charset >( "forName" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::util::SortedMap Charset::availableCharsets() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::SortedMap >( "availableCharsets" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::charset::Charset Charset::defaultCharset() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::Charset >( "defaultCharset" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String Charset::name() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "name" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Set Charset::aliases() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Set >( "aliases" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Charset::displayName() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "displayName" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Charset::isRegistered() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isRegistered" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Charset::displayName( ::jace::proxy::java::util::Locale p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "displayName" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Charset::contains( ::jace::proxy::java::nio::charset::Charset p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "contains" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::charset::CharsetDecoder Charset::newDecoder() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::CharsetDecoder >( "newDecoder" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::charset::CharsetEncoder Charset::newEncoder() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::charset::CharsetEncoder >( "newEncoder" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Charset::canEncode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "canEncode" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::CharBuffer Charset::decode( ::jace::proxy::java::nio::ByteBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::CharBuffer >( "decode" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer Charset::encode( ::jace::proxy::java::nio::CharBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "encode" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::ByteBuffer Charset::encode( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteBuffer >( "encode" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt Charset::compareTo( ::jace::proxy::java::nio::charset::Charset p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "compareTo" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt Charset::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Charset::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Charset::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Charset::Charset( jvalue value ) Charset_INITIALIZER {
  setJavaJniValue( value );
}

Charset::Charset( jobject object ) Charset_INITIALIZER {
  setJavaJniObject( object );
}

Charset::Charset( const Charset& object ) Charset_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Charset::Charset( const NoOp& noOp ) Charset_INITIALIZER {
}

const JClass* Charset::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/charset/Charset" );
  return &javaClass;
}

const JClass* Charset::getJavaJniClass() const throw ( JNIException ) {
  return Charset::staticGetJavaJniClass();
}

JEnlister< Charset> Charset::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, charset )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
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

