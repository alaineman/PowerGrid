
#ifndef JACE_PROXY_JAVA_UTIL_COMPARATOR_H
#include "jace/proxy/java/util/Comparator.h"
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

BEGIN_NAMESPACE_4( jace, proxy, java, util )

/**
 * The Jace C++ proxy class source for java/util/Comparator.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Comparator_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Comparator_INITIALIZER
#endif

::jace::proxy::types::JInt Comparator::compare( ::jace::proxy::java::lang::Object p0, ::jace::proxy::java::lang::Object p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "compare" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Comparator::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
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
Comparator::Comparator() : Object( NO_OP ) { 
}

Comparator::Comparator( jvalue value ) Comparator_INITIALIZER {
  setJavaJniValue( value );
}

Comparator::Comparator( jobject object ) Comparator_INITIALIZER {
  setJavaJniObject( object );
}

Comparator::Comparator( const Comparator& object ) Comparator_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Comparator::Comparator( const NoOp& noOp ) Comparator_INITIALIZER {
}

const JClass* Comparator::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/util/Comparator" );
  return &javaClass;
}

const JClass* Comparator::getJavaJniClass() const throw ( JNIException ) {
  return Comparator::staticGetJavaJniClass();
}

JEnlister< Comparator> Comparator::enlister;

END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::util::Comparator>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::Comparator( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::Comparator>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::Comparator>& proxy ) : 
    ::jace::proxy::java::util::Comparator( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::util::Comparator>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::Comparator( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Comparator>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::Comparator( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Comparator>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::Comparator>& object ) : 
    ::jace::proxy::java::util::Comparator( object.getJavaJniValue() ), Object( NO_OP ) {

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

