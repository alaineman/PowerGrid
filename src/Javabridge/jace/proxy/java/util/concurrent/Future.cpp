
#ifndef JACE_PROXY_JAVA_UTIL_CONCURRENT_FUTURE_H
#include "jace/proxy/java/util/concurrent/Future.h"
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
#ifndef JACE_PROXY_JAVA_LANG_INTERRUPTEDEXCEPTION_H
#include "jace/proxy/java/lang/InterruptedException.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_CONCURRENT_EXECUTIONEXCEPTION_H
#include "jace/proxy/java/util/concurrent/ExecutionException.h"
#endif
#ifndef JACE_TYPES_JLONG_H
#include "jace/proxy/types/JLong.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_CONCURRENT_TIMEUNIT_H
#include "jace/proxy/java/util/concurrent/TimeUnit.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_CONCURRENT_TIMEOUTEXCEPTION_H
#include "jace/proxy/java/util/concurrent/TimeoutException.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, util, concurrent )

/**
 * The Jace C++ proxy class source for java/util/concurrent/Future.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Future_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Future_INITIALIZER
#endif

::jace::proxy::types::JBoolean Future::cancel( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "cancel" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Future::isCancelled() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isCancelled" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Future::isDone() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isDone" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object Future::get() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object Future::get( ::jace::proxy::types::JLong p0, ::jace::proxy::java::util::concurrent::TimeUnit p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "get" ).invoke( *this, arguments );
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
Future::Future() : Object( NO_OP ) { 
}

Future::Future( jvalue value ) Future_INITIALIZER {
  setJavaJniValue( value );
}

Future::Future( jobject object ) Future_INITIALIZER {
  setJavaJniObject( object );
}

Future::Future( const Future& object ) Future_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Future::Future( const NoOp& noOp ) Future_INITIALIZER {
}

const JClass* Future::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/util/concurrent/Future" );
  return &javaClass;
}

const JClass* Future::getJavaJniClass() const throw ( JNIException ) {
  return Future::staticGetJavaJniClass();
}

JEnlister< Future> Future::enlister;

END_NAMESPACE_5( jace, proxy, java, util, concurrent )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::util::concurrent::Future>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::concurrent::Future( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::concurrent::Future>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::concurrent::Future>& proxy ) : 
    ::jace::proxy::java::util::concurrent::Future( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::util::concurrent::Future>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::concurrent::Future( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::concurrent::Future>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::concurrent::Future( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::concurrent::Future>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::concurrent::Future>& object ) : 
    ::jace::proxy::java::util::concurrent::Future( object.getJavaJniValue() ), Object( NO_OP ) {

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

