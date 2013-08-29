
#ifndef JACE_PROXY_JAVA_UTIL_CONCURRENT_EXECUTOR_H
#include "jace/proxy/java/util/concurrent/Executor.h"
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
#ifndef JACE_PROXY_JAVA_LANG_RUNNABLE_H
#include "jace/proxy/java/lang/Runnable.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, util, concurrent )

/**
 * The Jace C++ proxy class source for java/util/concurrent/Executor.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Executor_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Executor_INITIALIZER
#endif

void Executor::execute( ::jace::proxy::java::lang::Runnable p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "execute" ).invoke( *this, arguments );
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
Executor::Executor() : Object( NO_OP ) { 
}

Executor::Executor( jvalue value ) Executor_INITIALIZER {
  setJavaJniValue( value );
}

Executor::Executor( jobject object ) Executor_INITIALIZER {
  setJavaJniObject( object );
}

Executor::Executor( const Executor& object ) Executor_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Executor::Executor( const NoOp& noOp ) Executor_INITIALIZER {
}

const JClass* Executor::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/util/concurrent/Executor" );
  return &javaClass;
}

const JClass* Executor::getJavaJniClass() const throw ( JNIException ) {
  return Executor::staticGetJavaJniClass();
}

JEnlister< Executor> Executor::enlister;

END_NAMESPACE_5( jace, proxy, java, util, concurrent )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::util::concurrent::Executor>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::concurrent::Executor( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::concurrent::Executor>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::concurrent::Executor>& proxy ) : 
    ::jace::proxy::java::util::concurrent::Executor( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::util::concurrent::Executor>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::concurrent::Executor( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::concurrent::Executor>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::concurrent::Executor( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::concurrent::Executor>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::concurrent::Executor>& object ) : 
    ::jace::proxy::java::util::concurrent::Executor( object.getJavaJniValue() ), Object( NO_OP ) {

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

