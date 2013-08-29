
#ifndef JACE_PROXY_JAVA_UTIL_COLLECTION_H
#include "jace/proxy/java/util/Collection.h"
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
#ifndef JACE_PROXY_JAVA_UTIL_ITERATOR_H
#include "jace/proxy/java/util/Iterator.h"
#endif
#ifndef JACE_TYPES_JVOID_H
#include "jace/proxy/types/JVoid.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, util )

/**
 * The Jace C++ proxy class source for java/util/Collection.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Collection_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Collection_INITIALIZER
#endif

::jace::proxy::types::JInt Collection::size() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "size" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Collection::isEmpty() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isEmpty" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Collection::contains( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "contains" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Iterator Collection::iterator() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Iterator >( "iterator" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::lang::Object > Collection::toArray() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::Object > >( "toArray" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::lang::Object > Collection::toArray( ::jace::JArray< ::jace::proxy::java::lang::Object > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::Object > >( "toArray" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Collection::add( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "add" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Collection::remove( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "remove" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Collection::containsAll( ::jace::proxy::java::util::Collection p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "containsAll" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Collection::addAll( ::jace::proxy::java::util::Collection p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "addAll" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Collection::removeAll( ::jace::proxy::java::util::Collection p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "removeAll" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Collection::retainAll( ::jace::proxy::java::util::Collection p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "retainAll" ).invoke( *this, arguments );
}

void Collection::clear() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "clear" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Collection::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt Collection::hashCode() {
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
Collection::Collection() : Object( NO_OP ) { 
}

Collection::Collection( jvalue value ) Collection_INITIALIZER {
  setJavaJniValue( value );
}

Collection::Collection( jobject object ) Collection_INITIALIZER {
  setJavaJniObject( object );
}

Collection::Collection( const Collection& object ) Collection_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Collection::Collection( const NoOp& noOp ) Collection_INITIALIZER {
}

const JClass* Collection::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/util/Collection" );
  return &javaClass;
}

const JClass* Collection::getJavaJniClass() const throw ( JNIException ) {
  return Collection::staticGetJavaJniClass();
}

JEnlister< Collection> Collection::enlister;

END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::util::Collection>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::Collection( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::Collection>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::Collection>& proxy ) : 
    ::jace::proxy::java::util::Collection( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::util::Collection>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::Collection( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Collection>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::Collection( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Collection>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::Collection>& object ) : 
    ::jace::proxy::java::util::Collection( object.getJavaJniValue() ), Object( NO_OP ) {

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

