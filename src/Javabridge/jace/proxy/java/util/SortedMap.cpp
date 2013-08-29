
#ifndef JACE_PROXY_JAVA_UTIL_SORTEDMAP_H
#include "jace/proxy/java/util/SortedMap.h"
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
#ifndef JACE_PROXY_JAVA_UTIL_COMPARATOR_H
#include "jace/proxy/java/util/Comparator.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_SET_H
#include "jace/proxy/java/util/Set.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_COLLECTION_H
#include "jace/proxy/java/util/Collection.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, util )

/**
 * The Jace C++ proxy class source for java/util/SortedMap.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define SortedMap_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define SortedMap_INITIALIZER
#endif

::jace::proxy::java::util::Comparator SortedMap::comparator() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Comparator >( "comparator" ).invoke( *this, arguments );
}

::jace::proxy::java::util::SortedMap SortedMap::subMap( ::jace::proxy::java::lang::Object p0, ::jace::proxy::java::lang::Object p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::util::SortedMap >( "subMap" ).invoke( *this, arguments );
}

::jace::proxy::java::util::SortedMap SortedMap::headMap( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::util::SortedMap >( "headMap" ).invoke( *this, arguments );
}

::jace::proxy::java::util::SortedMap SortedMap::tailMap( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::util::SortedMap >( "tailMap" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object SortedMap::firstKey() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "firstKey" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object SortedMap::lastKey() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "lastKey" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Set SortedMap::keySet() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Set >( "keySet" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Collection SortedMap::values() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Collection >( "values" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Set SortedMap::entrySet() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Set >( "entrySet" ).invoke( *this, arguments );
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
SortedMap::SortedMap() : Object( NO_OP ) { 
}

SortedMap::SortedMap( jvalue value ) SortedMap_INITIALIZER {
  setJavaJniValue( value );
}

SortedMap::SortedMap( jobject object ) SortedMap_INITIALIZER {
  setJavaJniObject( object );
}

SortedMap::SortedMap( const SortedMap& object ) SortedMap_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

SortedMap::SortedMap( const NoOp& noOp ) SortedMap_INITIALIZER {
}

const JClass* SortedMap::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/util/SortedMap" );
  return &javaClass;
}

const JClass* SortedMap::getJavaJniClass() const throw ( JNIException ) {
  return SortedMap::staticGetJavaJniClass();
}

JEnlister< SortedMap> SortedMap::enlister;

END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::util::SortedMap>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::SortedMap( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::SortedMap>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::SortedMap>& proxy ) : 
    ::jace::proxy::java::util::SortedMap( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::util::SortedMap>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::SortedMap( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::SortedMap>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::SortedMap( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::SortedMap>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::SortedMap>& object ) : 
    ::jace::proxy::java::util::SortedMap( object.getJavaJniValue() ), Object( NO_OP ) {

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

