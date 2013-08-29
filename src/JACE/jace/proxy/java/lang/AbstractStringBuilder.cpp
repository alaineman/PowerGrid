
#ifndef JACE_PROXY_JAVA_LANG_ABSTRACTSTRINGBUILDER_H
#include "jace/proxy/java/lang/AbstractStringBuilder.h"
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
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_TYPES_JVOID_H
#include "jace/proxy/types/JVoid.h"
#endif
#ifndef JACE_TYPES_JCHAR_H
#include "jace/proxy/types/JChar.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRINGBUFFER_H
#include "jace/proxy/java/lang/StringBuffer.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
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
 * The Jace C++ proxy class source for java/lang/AbstractStringBuilder.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define AbstractStringBuilder_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define AbstractStringBuilder_INITIALIZER
#endif

::jace::proxy::types::JInt AbstractStringBuilder::length() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "length" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt AbstractStringBuilder::capacity() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "capacity" ).invoke( *this, arguments );
}

void AbstractStringBuilder::ensureCapacity( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "ensureCapacity" ).invoke( *this, arguments );
}

void AbstractStringBuilder::trimToSize() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "trimToSize" ).invoke( *this, arguments );
}

void AbstractStringBuilder::setLength( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setLength" ).invoke( *this, arguments );
}

::jace::proxy::types::JChar AbstractStringBuilder::charAt( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JChar >( "charAt" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt AbstractStringBuilder::codePointAt( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "codePointAt" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt AbstractStringBuilder::codePointBefore( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "codePointBefore" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt AbstractStringBuilder::codePointCount( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "codePointCount" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt AbstractStringBuilder::offsetByCodePoints( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "offsetByCodePoints" ).invoke( *this, arguments );
}

void AbstractStringBuilder::getChars( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::JArray< ::jace::proxy::types::JChar > p2, ::jace::proxy::types::JInt p3 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "getChars" ).invoke( *this, arguments );
}

void AbstractStringBuilder::setCharAt( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JChar p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setCharAt" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::append( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::append( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::append( ::jace::proxy::java::lang::StringBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::append( ::jace::proxy::java::lang::CharSequence p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::append( ::jace::proxy::java::lang::CharSequence p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::append( ::jace::JArray< ::jace::proxy::types::JChar > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::append( ::jace::JArray< ::jace::proxy::types::JChar > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::append( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::append( ::jace::proxy::types::JChar p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::append( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::append( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::append( ::jace::proxy::types::JFloat p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::append( ::jace::proxy::types::JDouble p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::delete_( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "delete_" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::appendCodePoint( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "appendCodePoint" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::deleteCharAt( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "deleteCharAt" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::replace( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::java::lang::String p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "replace" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String AbstractStringBuilder::substring( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "substring" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::CharSequence AbstractStringBuilder::subSequence( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::CharSequence >( "subSequence" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String AbstractStringBuilder::substring( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "substring" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::JArray< ::jace::proxy::types::JChar > p1, ::jace::proxy::types::JInt p2, ::jace::proxy::types::JInt p3 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::proxy::java::lang::Object p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::proxy::java::lang::String p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::JArray< ::jace::proxy::types::JChar > p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::proxy::java::lang::CharSequence p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::proxy::java::lang::CharSequence p1, ::jace::proxy::types::JInt p2, ::jace::proxy::types::JInt p3 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JBoolean p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JChar p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JLong p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JFloat p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JDouble p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt AbstractStringBuilder::indexOf( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "indexOf" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt AbstractStringBuilder::indexOf( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "indexOf" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt AbstractStringBuilder::lastIndexOf( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "lastIndexOf" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt AbstractStringBuilder::lastIndexOf( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "lastIndexOf" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::AbstractStringBuilder AbstractStringBuilder::reverse() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::AbstractStringBuilder >( "reverse" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String AbstractStringBuilder::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
AbstractStringBuilder::AbstractStringBuilder( jvalue value ) AbstractStringBuilder_INITIALIZER {
  setJavaJniValue( value );
}

AbstractStringBuilder::AbstractStringBuilder( jobject object ) AbstractStringBuilder_INITIALIZER {
  setJavaJniObject( object );
}

AbstractStringBuilder::AbstractStringBuilder( const AbstractStringBuilder& object ) AbstractStringBuilder_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

AbstractStringBuilder::AbstractStringBuilder( const NoOp& noOp ) AbstractStringBuilder_INITIALIZER {
}

const JClass* AbstractStringBuilder::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/lang/AbstractStringBuilder" );
  return &javaClass;
}

const JClass* AbstractStringBuilder::getJavaJniClass() const throw ( JNIException ) {
  return AbstractStringBuilder::staticGetJavaJniClass();
}

JEnlister< AbstractStringBuilder> AbstractStringBuilder::enlister;

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::lang::AbstractStringBuilder>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::AbstractStringBuilder( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::AbstractStringBuilder>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::AbstractStringBuilder>& proxy ) : 
    ::jace::proxy::java::lang::AbstractStringBuilder( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::lang::AbstractStringBuilder>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::AbstractStringBuilder( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::AbstractStringBuilder>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::AbstractStringBuilder( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::AbstractStringBuilder>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::AbstractStringBuilder>& object ) : 
    ::jace::proxy::java::lang::AbstractStringBuilder( object.getJavaJniValue() ), Object( NO_OP ) {

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

