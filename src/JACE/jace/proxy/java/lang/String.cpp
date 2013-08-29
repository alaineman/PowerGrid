
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
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
#ifndef JACE_TYPES_JVOID_H
#include "jace/proxy/types/JVoid.h"
#endif
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_UNSUPPORTEDENCODINGEXCEPTION_H
#include "jace/proxy/java/io/UnsupportedEncodingException.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHARSET_CHARSET_H
#include "jace/proxy/java/nio/charset/Charset.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRINGBUFFER_H
#include "jace/proxy/java/lang/StringBuffer.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRINGBUILDER_H
#include "jace/proxy/java/lang/StringBuilder.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_TYPES_JCHAR_H
#include "jace/proxy/types/JChar.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_LOCALE_H
#include "jace/proxy/java/util/Locale.h"
#endif
#ifndef JACE_TYPES_JLONG_H
#include "jace/proxy/types/JLong.h"
#endif
#ifndef JACE_TYPES_JFLOAT_H
#include "jace/proxy/types/JFloat.h"
#endif
#ifndef JACE_TYPES_JDOUBLE_H
#include "jace/proxy/types/JDouble.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, lang )

/**
 * The Jace C++ proxy class source for java/lang/String.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define String_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define String_INITIALIZER
#endif

String::String() String_INITIALIZER {
  ::jace::JArguments arguments;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

String::String( ::jace::proxy::java::lang::String p0, CopyConstructorSpecifier ccs ) String_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

String::String( ::jace::JArray< ::jace::proxy::types::JChar > p0 ) String_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

String::String( ::jace::JArray< ::jace::proxy::types::JChar > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) String_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

String::String( ::jace::JArray< ::jace::proxy::types::JInt > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) String_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

String::String( ::jace::JArray< ::jace::proxy::types::JByte > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2, ::jace::proxy::types::JInt p3 ) String_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

String::String( ::jace::JArray< ::jace::proxy::types::JByte > p0, ::jace::proxy::types::JInt p1 ) String_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

String::String( ::jace::JArray< ::jace::proxy::types::JByte > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2, ::jace::proxy::java::lang::String p3 ) String_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

String::String( ::jace::JArray< ::jace::proxy::types::JByte > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2, ::jace::proxy::java::nio::charset::Charset p3 ) String_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

String::String( ::jace::JArray< ::jace::proxy::types::JByte > p0, ::jace::proxy::java::lang::String p1 ) String_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

String::String( ::jace::JArray< ::jace::proxy::types::JByte > p0, ::jace::proxy::java::nio::charset::Charset p1 ) String_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

String::String( ::jace::JArray< ::jace::proxy::types::JByte > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) String_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

String::String( ::jace::JArray< ::jace::proxy::types::JByte > p0 ) String_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

String::String( ::jace::proxy::java::lang::StringBuffer p0 ) String_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

String::String( ::jace::proxy::java::lang::StringBuilder p0 ) String_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::types::JInt String::length() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "length" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean String::isEmpty() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isEmpty" ).invoke( *this, arguments );
}

::jace::proxy::types::JChar String::charAt( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JChar >( "charAt" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt String::codePointAt( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "codePointAt" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt String::codePointBefore( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "codePointBefore" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt String::codePointCount( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "codePointCount" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt String::offsetByCodePoints( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "offsetByCodePoints" ).invoke( *this, arguments );
}

void String::getChars( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::JArray< ::jace::proxy::types::JChar > p2, ::jace::proxy::types::JInt p3 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "getChars" ).invoke( *this, arguments );
}

void String::getBytes( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::JArray< ::jace::proxy::types::JByte > p2, ::jace::proxy::types::JInt p3 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "getBytes" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::types::JByte > String::getBytes( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::types::JByte > >( "getBytes" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::types::JByte > String::getBytes( ::jace::proxy::java::nio::charset::Charset p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::types::JByte > >( "getBytes" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::types::JByte > String::getBytes() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::types::JByte > >( "getBytes" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean String::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean String::contentEquals( ::jace::proxy::java::lang::StringBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "contentEquals" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean String::contentEquals( ::jace::proxy::java::lang::CharSequence p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "contentEquals" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean String::equalsIgnoreCase( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equalsIgnoreCase" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt String::compareTo( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "compareTo" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt String::compareToIgnoreCase( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "compareToIgnoreCase" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean String::regionMatches( ::jace::proxy::types::JInt p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::types::JInt p2, ::jace::proxy::types::JInt p3 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "regionMatches" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean String::regionMatches( ::jace::proxy::types::JBoolean p0, ::jace::proxy::types::JInt p1, ::jace::proxy::java::lang::String p2, ::jace::proxy::types::JInt p3, ::jace::proxy::types::JInt p4 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3 << p4;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "regionMatches" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean String::startsWith( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "startsWith" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean String::startsWith( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "startsWith" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean String::endsWith( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "endsWith" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt String::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt String::indexOf( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "indexOf" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt String::indexOf( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "indexOf" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt String::lastIndexOf( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "lastIndexOf" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt String::lastIndexOf( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "lastIndexOf" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt String::indexOf( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "indexOf" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt String::indexOf( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "indexOf" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt String::lastIndexOf( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "lastIndexOf" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt String::lastIndexOf( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "lastIndexOf" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String String::substring( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "substring" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String String::substring( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "substring" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::CharSequence String::subSequence( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::CharSequence >( "subSequence" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String String::concat( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "concat" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String String::replace( ::jace::proxy::types::JChar p0, ::jace::proxy::types::JChar p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "replace" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean String::matches( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "matches" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean String::contains( ::jace::proxy::java::lang::CharSequence p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "contains" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String String::replaceFirst( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "replaceFirst" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String String::replaceAll( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "replaceAll" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String String::replace( ::jace::proxy::java::lang::CharSequence p0, ::jace::proxy::java::lang::CharSequence p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "replace" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::lang::String > String::split( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::String > >( "split" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::lang::String > String::split( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::String > >( "split" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String String::toLowerCase( ::jace::proxy::java::util::Locale p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toLowerCase" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String String::toLowerCase() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toLowerCase" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String String::toUpperCase( ::jace::proxy::java::util::Locale p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toUpperCase" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String String::toUpperCase() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toUpperCase" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String String::trim() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "trim" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String String::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::types::JChar > String::toCharArray() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::types::JChar > >( "toCharArray" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String String::format( ::jace::proxy::java::lang::String p0, ::jace::JArray< ::jace::proxy::java::lang::Object > p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "format" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String String::format( ::jace::proxy::java::util::Locale p0, ::jace::proxy::java::lang::String p1, ::jace::JArray< ::jace::proxy::java::lang::Object > p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "format" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String String::valueOf( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "valueOf" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String String::valueOf( ::jace::JArray< ::jace::proxy::types::JChar > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "valueOf" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String String::valueOf( ::jace::JArray< ::jace::proxy::types::JChar > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "valueOf" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String String::copyValueOf( ::jace::JArray< ::jace::proxy::types::JChar > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "copyValueOf" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String String::copyValueOf( ::jace::JArray< ::jace::proxy::types::JChar > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "copyValueOf" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String String::valueOf( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "valueOf" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String String::valueOf( ::jace::proxy::types::JChar p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "valueOf" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String String::valueOf( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "valueOf" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String String::valueOf( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "valueOf" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String String::valueOf( ::jace::proxy::types::JFloat p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "valueOf" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String String::valueOf( ::jace::proxy::types::JDouble p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "valueOf" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String String::intern() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "intern" ).invoke( *this, arguments );
}

String::String( const std::string& str ) : Object( NO_OP ) {
  jstring strRef = createString( str );
  setJavaJniObject( strRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, strRef );
}

String::String( const char* str ) : Object( NO_OP ) {
  jstring strRef = createString( str );
  setJavaJniObject( strRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, strRef );
}

String& String::operator=( const String& str ) {
  setJavaJniObject( str.getJavaJniObject() );
  return *this;
}

std::string String::getCString() const {
  JNIEnv* env = helper::attach();
  jstring thisString = static_cast<jstring>( getJavaJniObject() );
  jclass cls = getJavaJniClass()->getClass();
  jmethodID getBytes = env->GetMethodID( cls, "getBytes", "()[B" );
  jbyteArray array = static_cast<jbyteArray>( env->CallObjectMethod( thisString, getBytes ) );

  if ( ! array ) {
    env->ExceptionDescribe();
    env->ExceptionClear();
    std::string msg = "String::getCString - Unable to get the contents of the java String.";
    throw JNIException( msg );
  }

  int arraySize = env->GetArrayLength( array );
  jbyte* byteArray = env->GetByteArrayElements( array, 0 );

  if ( ! byteArray ) {
    env->ExceptionDescribe();
    env->ExceptionClear();
    std::string msg = "String::getCString - Unable to get the contents of the java String.";
    throw JNIException( msg );
  }

  std::string str( ( char* ) byteArray, ( char* ) byteArray + arraySize );
  env->ReleaseByteArrayElements( array, byteArray, JNI_ABORT );
  ::jace::helper::deleteLocalRef( env, array );
  return str;
}

jstring String::createString( const std::string& str ) {
  JNIEnv* env = helper::attach();
  jsize bufLen = jsize( str.size() );
  jbyteArray jbuf = env->NewByteArray( bufLen );

  if ( ! jbuf ) {
    env->ExceptionDescribe();
    env->ExceptionClear();
    std::string msg = "String::createString - Unable to allocate a new java String.";
    throw JNIException( msg );
  }

  env->SetByteArrayRegion( jbuf, 0, bufLen, ( jbyte* ) str.c_str() );
  jclass cls = getJavaJniClass()->getClass();
  jmethodID init = env->GetMethodID( cls, "<init>", "([BII)V");
  jstring jstr = ( jstring ) env->NewObject( cls, init, jbuf, 0, bufLen); 

  if ( ! jstr ) {
    env->ExceptionDescribe();
    env->ExceptionClear();
    std::string msg = "String::createString - Unable to allocate a new java String.";
    throw JNIException( msg );
  }

  ::jace::helper::deleteLocalRef( env, jbuf );
  return jstr;
}

std::ostream& operator<<( std::ostream& stream, const String& str ) {
  return stream << str.getCString();
}

std::string operator+( const std::string& stdStr, const String& jStr ) {
  return stdStr + jStr.getCString();
}

std::string operator+( const String& jStr, const std::string& stdStr ) {
  return jStr.getCString() + stdStr;
}

String String::operator+( String str ) {
  return getCString() + str.getCString();
}

bool operator==( const std::string& stdStr, const String& str ) {
  return str.getCString() == stdStr;
}

bool operator==( const String& str, const std::string& stdStr ) {
  return str.getCString() == stdStr;
}

/**
 * public static final CASE_INSENSITIVE_ORDER
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Comparator > String::CASE_INSENSITIVE_ORDER() {
  return ::jace::JField< ::jace::proxy::java::util::Comparator >( "CASE_INSENSITIVE_ORDER" ).get( staticGetJavaJniClass() );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
String::String( jvalue value ) String_INITIALIZER {
  setJavaJniValue( value );
}

String::String( jobject object ) String_INITIALIZER {
  setJavaJniObject( object );
}

String::String( const String& object ) String_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

String::String( const NoOp& noOp ) String_INITIALIZER {
}

const JClass* String::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/lang/String" );
  return &javaClass;
}

const JClass* String::getJavaJniClass() const throw ( JNIException ) {
  return String::staticGetJavaJniClass();
}

JEnlister< String> String::enlister;

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::lang::String>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::String( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::String>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::String>& proxy ) : 
    ::jace::proxy::java::lang::String( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::lang::String>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::String( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::String>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::String( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::String>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::String>& object ) : 
    ::jace::proxy::java::lang::String( object.getJavaJniValue() ), Object( NO_OP ) {

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

