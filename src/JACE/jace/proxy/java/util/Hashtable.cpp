
#ifndef JACE_PROXY_JAVA_UTIL_HASHTABLE_H
#include "jace/proxy/java/util/Hashtable.h"
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
#ifndef JACE_TYPES_JFLOAT_H
#include "jace/proxy/types/JFloat.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_ENUMERATION_H
#include "jace/proxy/java/util/Enumeration.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_OBJECT_H
#include "jace/proxy/java/lang/Object.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_SET_H
#include "jace/proxy/java/util/Set.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_COLLECTION_H
#include "jace/proxy/java/util/Collection.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, util )

/**
 * The Jace C++ proxy class source for java/util/Hashtable.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Hashtable_INITIALIZER : ::jace::proxy::java::util::Dictionary( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Hashtable_INITIALIZER : ::jace::proxy::java::util::Dictionary( NO_OP )
#endif

Hashtable::Hashtable( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JFloat p1 ) Hashtable_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

Hashtable::Hashtable( ::jace::proxy::types::JInt p0 ) Hashtable_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

Hashtable::Hashtable() Hashtable_INITIALIZER {
  ::jace::JArguments arguments;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

Hashtable::Hashtable( ::jace::proxy::java::util::Map p0 ) Hashtable_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::types::JInt Hashtable::size() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "size" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Hashtable::isEmpty() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isEmpty" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Enumeration Hashtable::keys() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Enumeration >( "keys" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Enumeration Hashtable::elements() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Enumeration >( "elements" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Hashtable::contains( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "contains" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Hashtable::containsValue( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "containsValue" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Hashtable::containsKey( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "containsKey" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object Hashtable::get( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object Hashtable::put( ::jace::proxy::java::lang::Object p0, ::jace::proxy::java::lang::Object p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "put" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object Hashtable::remove( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "remove" ).invoke( *this, arguments );
}

void Hashtable::putAll( ::jace::proxy::java::util::Map p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "putAll" ).invoke( *this, arguments );
}

void Hashtable::clear() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "clear" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object Hashtable::clone() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "clone" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Hashtable::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Set Hashtable::keySet() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Set >( "keySet" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Set Hashtable::entrySet() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Set >( "entrySet" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Collection Hashtable::values() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Collection >( "values" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Hashtable::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt Hashtable::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Hashtable::Hashtable( jvalue value ) Hashtable_INITIALIZER {
  setJavaJniValue( value );
}

Hashtable::Hashtable( jobject object ) Hashtable_INITIALIZER {
  setJavaJniObject( object );
}

Hashtable::Hashtable( const Hashtable& object ) Hashtable_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Hashtable::Hashtable( const NoOp& noOp ) Hashtable_INITIALIZER {
}

const JClass* Hashtable::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/util/Hashtable" );
  return &javaClass;
}

const JClass* Hashtable::getJavaJniClass() const throw ( JNIException ) {
  return Hashtable::staticGetJavaJniClass();
}

JEnlister< Hashtable> Hashtable::enlister;

END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::util::Hashtable>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::Hashtable( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::Hashtable>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::Hashtable>& proxy ) : 
    ::jace::proxy::java::util::Hashtable( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::util::Hashtable>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::Hashtable( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Hashtable>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::Hashtable( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Hashtable>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::Hashtable>& object ) : 
    ::jace::proxy::java::util::Hashtable( object.getJavaJniValue() ), Object( NO_OP ) {

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

