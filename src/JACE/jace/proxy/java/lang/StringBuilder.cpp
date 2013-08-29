
#ifndef JACE_PROXY_JAVA_LANG_STRINGBUILDER_H
#include "jace/proxy/java/lang/StringBuilder.h"
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
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_OBJECT_H
#include "jace/proxy/java/lang/Object.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRINGBUFFER_H
#include "jace/proxy/java/lang/StringBuffer.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_TYPES_JCHAR_H
#include "jace/proxy/types/JChar.h"
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
 * The Jace C++ proxy class source for java/lang/StringBuilder.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define StringBuilder_INITIALIZER : ::jace::proxy::java::lang::AbstractStringBuilder( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define StringBuilder_INITIALIZER : ::jace::proxy::java::lang::AbstractStringBuilder( NO_OP )
#endif

StringBuilder::StringBuilder() StringBuilder_INITIALIZER {
  ::jace::JArguments arguments;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

StringBuilder::StringBuilder( ::jace::proxy::types::JInt p0 ) StringBuilder_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

StringBuilder::StringBuilder( ::jace::proxy::java::lang::String p0 ) StringBuilder_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

StringBuilder::StringBuilder( ::jace::proxy::java::lang::CharSequence p0 ) StringBuilder_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::append( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::append( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::append( ::jace::proxy::java::lang::StringBuffer p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::append( ::jace::proxy::java::lang::CharSequence p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::append( ::jace::proxy::java::lang::CharSequence p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::append( ::jace::JArray< ::jace::proxy::types::JChar > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::append( ::jace::JArray< ::jace::proxy::types::JChar > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::append( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::append( ::jace::proxy::types::JChar p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::append( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::append( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::append( ::jace::proxy::types::JFloat p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::append( ::jace::proxy::types::JDouble p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::appendCodePoint( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "appendCodePoint" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::delete_( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "delete_" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::deleteCharAt( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "deleteCharAt" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::replace( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::java::lang::String p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "replace" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::JArray< ::jace::proxy::types::JChar > p1, ::jace::proxy::types::JInt p2, ::jace::proxy::types::JInt p3 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::proxy::java::lang::Object p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::proxy::java::lang::String p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::JArray< ::jace::proxy::types::JChar > p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::proxy::java::lang::CharSequence p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::proxy::java::lang::CharSequence p1, ::jace::proxy::types::JInt p2, ::jace::proxy::types::JInt p3 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JBoolean p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JChar p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JLong p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JFloat p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::insert( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JDouble p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "insert" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt StringBuilder::indexOf( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "indexOf" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt StringBuilder::indexOf( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "indexOf" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt StringBuilder::lastIndexOf( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "lastIndexOf" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt StringBuilder::lastIndexOf( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "lastIndexOf" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::StringBuilder StringBuilder::reverse() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::StringBuilder >( "reverse" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String StringBuilder::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
StringBuilder::StringBuilder( jvalue value ) StringBuilder_INITIALIZER {
  setJavaJniValue( value );
}

StringBuilder::StringBuilder( jobject object ) StringBuilder_INITIALIZER {
  setJavaJniObject( object );
}

StringBuilder::StringBuilder( const StringBuilder& object ) StringBuilder_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

StringBuilder::StringBuilder( const NoOp& noOp ) StringBuilder_INITIALIZER {
}

const JClass* StringBuilder::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/lang/StringBuilder" );
  return &javaClass;
}

const JClass* StringBuilder::getJavaJniClass() const throw ( JNIException ) {
  return StringBuilder::staticGetJavaJniClass();
}

JEnlister< StringBuilder> StringBuilder::enlister;

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::lang::StringBuilder>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::StringBuilder( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::StringBuilder>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::StringBuilder>& proxy ) : 
    ::jace::proxy::java::lang::StringBuilder( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::lang::StringBuilder>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::StringBuilder( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::StringBuilder>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::StringBuilder( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::StringBuilder>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::StringBuilder>& object ) : 
    ::jace::proxy::java::lang::StringBuilder( object.getJavaJniValue() ), Object( NO_OP ) {

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

