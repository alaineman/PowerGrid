
#ifndef JACE_PROXY_JAVA_UTIL_LISTITERATOR_H
#include "jace/proxy/java/util/ListIterator.h"
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
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_TYPES_JVOID_H
#include "jace/proxy/types/JVoid.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, util )

/**
 * The Jace C++ proxy class source for java/util/ListIterator.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define ListIterator_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define ListIterator_INITIALIZER
#endif

::jace::proxy::types::JBoolean ListIterator::hasNext() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "hasNext" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object ListIterator::next() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "next" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean ListIterator::hasPrevious() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "hasPrevious" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object ListIterator::previous() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "previous" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt ListIterator::nextIndex() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "nextIndex" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt ListIterator::previousIndex() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "previousIndex" ).invoke( *this, arguments );
}

void ListIterator::remove() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "remove" ).invoke( *this, arguments );
}

void ListIterator::set( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "set" ).invoke( *this, arguments );
}

void ListIterator::add( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "add" ).invoke( *this, arguments );
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
ListIterator::ListIterator() : Object( NO_OP ) { 
}

ListIterator::ListIterator( jvalue value ) ListIterator_INITIALIZER {
  setJavaJniValue( value );
}

ListIterator::ListIterator( jobject object ) ListIterator_INITIALIZER {
  setJavaJniObject( object );
}

ListIterator::ListIterator( const ListIterator& object ) ListIterator_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

ListIterator::ListIterator( const NoOp& noOp ) ListIterator_INITIALIZER {
}

const JClass* ListIterator::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/util/ListIterator" );
  return &javaClass;
}

const JClass* ListIterator::getJavaJniClass() const throw ( JNIException ) {
  return ListIterator::staticGetJavaJniClass();
}

JEnlister< ListIterator> ListIterator::enlister;

END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::util::ListIterator>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::ListIterator( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::ListIterator>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::ListIterator>& proxy ) : 
    ::jace::proxy::java::util::ListIterator( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::util::ListIterator>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::ListIterator( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::ListIterator>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::ListIterator( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::ListIterator>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::ListIterator>& object ) : 
    ::jace::proxy::java::util::ListIterator( object.getJavaJniValue() ), Object( NO_OP ) {

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

