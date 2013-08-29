
#ifndef JACE_PROXY_JAVA_UTIL_MAP_H
#include "jace/proxy/java/util/Map.h"
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
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_TYPES_JVOID_H
#include "jace/proxy/types/JVoid.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_SET_H
#include "jace/proxy/java/util/Set.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_COLLECTION_H
#include "jace/proxy/java/util/Collection.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, util )

/**
 * The Jace C++ proxy class source for java/util/Map.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Map_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Map_INITIALIZER
#endif

::jace::proxy::types::JInt Map::size() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "size" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Map::isEmpty() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isEmpty" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Map::containsKey( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "containsKey" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Map::containsValue( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "containsValue" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object Map::get( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object Map::put( ::jace::proxy::java::lang::Object p0, ::jace::proxy::java::lang::Object p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "put" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object Map::remove( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "remove" ).invoke( *this, arguments );
}

void Map::putAll( ::jace::proxy::java::util::Map p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "putAll" ).invoke( *this, arguments );
}

void Map::clear() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "clear" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Set Map::keySet() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Set >( "keySet" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Collection Map::values() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Collection >( "values" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Set Map::entrySet() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Set >( "entrySet" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Map::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt Map::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
/**
 * Special no arg constructor for interface virtual inheritance
 *
 */
Map::Map() : Object( NO_OP ) { 
}

Map::Map( jvalue value ) Map_INITIALIZER {
  setJavaJniValue( value );
}

Map::Map( jobject object ) Map_INITIALIZER {
  setJavaJniObject( object );
}

Map::Map( const Map& object ) Map_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Map::Map( const NoOp& noOp ) Map_INITIALIZER {
}

const JClass* Map::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/util/Map" );
  return &javaClass;
}

const JClass* Map::getJavaJniClass() const throw ( JNIException ) {
  return Map::staticGetJavaJniClass();
}

JEnlister< Map> Map::enlister;

END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::util::Map>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::Map( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::Map>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::Map>& proxy ) : 
    ::jace::proxy::java::util::Map( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::util::Map>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::Map( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Map>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::Map( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Map>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::Map>& object ) : 
    ::jace::proxy::java::util::Map( object.getJavaJniValue() ), Object( NO_OP ) {

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

