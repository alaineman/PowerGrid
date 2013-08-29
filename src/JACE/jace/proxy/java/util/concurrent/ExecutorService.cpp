
#ifndef JACE_PROXY_JAVA_UTIL_CONCURRENT_EXECUTORSERVICE_H
#include "jace/proxy/java/util/concurrent/ExecutorService.h"
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
#ifndef JACE_PROXY_JAVA_UTIL_LIST_H
#include "jace/proxy/java/util/List.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_TYPES_JLONG_H
#include "jace/proxy/types/JLong.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_CONCURRENT_TIMEUNIT_H
#include "jace/proxy/java/util/concurrent/TimeUnit.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_INTERRUPTEDEXCEPTION_H
#include "jace/proxy/java/lang/InterruptedException.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_CONCURRENT_FUTURE_H
#include "jace/proxy/java/util/concurrent/Future.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_CONCURRENT_CALLABLE_H
#include "jace/proxy/java/util/concurrent/Callable.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_RUNNABLE_H
#include "jace/proxy/java/lang/Runnable.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_COLLECTION_H
#include "jace/proxy/java/util/Collection.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_CONCURRENT_EXECUTIONEXCEPTION_H
#include "jace/proxy/java/util/concurrent/ExecutionException.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_CONCURRENT_TIMEOUTEXCEPTION_H
#include "jace/proxy/java/util/concurrent/TimeoutException.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, util, concurrent )

/**
 * The Jace C++ proxy class source for java/util/concurrent/ExecutorService.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define ExecutorService_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define ExecutorService_INITIALIZER
#endif

void ExecutorService::shutdown() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "shutdown" ).invoke( *this, arguments );
}

::jace::proxy::java::util::List ExecutorService::shutdownNow() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::List >( "shutdownNow" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean ExecutorService::isShutdown() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isShutdown" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean ExecutorService::isTerminated() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isTerminated" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean ExecutorService::awaitTermination( ::jace::proxy::types::JLong p0, ::jace::proxy::java::util::concurrent::TimeUnit p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "awaitTermination" ).invoke( *this, arguments );
}

::jace::proxy::java::util::concurrent::Future ExecutorService::submit( ::jace::proxy::java::util::concurrent::Callable p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::util::concurrent::Future >( "submit" ).invoke( *this, arguments );
}

::jace::proxy::java::util::concurrent::Future ExecutorService::submit( ::jace::proxy::java::lang::Runnable p0, ::jace::proxy::java::lang::Object p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::util::concurrent::Future >( "submit" ).invoke( *this, arguments );
}

::jace::proxy::java::util::concurrent::Future ExecutorService::submit( ::jace::proxy::java::lang::Runnable p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::util::concurrent::Future >( "submit" ).invoke( *this, arguments );
}

::jace::proxy::java::util::List ExecutorService::invokeAll( ::jace::proxy::java::util::Collection p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::util::List >( "invokeAll" ).invoke( *this, arguments );
}

::jace::proxy::java::util::List ExecutorService::invokeAll( ::jace::proxy::java::util::Collection p0, ::jace::proxy::types::JLong p1, ::jace::proxy::java::util::concurrent::TimeUnit p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::util::List >( "invokeAll" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object ExecutorService::invokeAny( ::jace::proxy::java::util::Collection p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "invokeAny" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object ExecutorService::invokeAny( ::jace::proxy::java::util::Collection p0, ::jace::proxy::types::JLong p1, ::jace::proxy::java::util::concurrent::TimeUnit p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "invokeAny" ).invoke( *this, arguments );
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
ExecutorService::ExecutorService() : Object( NO_OP ) { 
}

ExecutorService::ExecutorService( jvalue value ) ExecutorService_INITIALIZER {
  setJavaJniValue( value );
}

ExecutorService::ExecutorService( jobject object ) ExecutorService_INITIALIZER {
  setJavaJniObject( object );
}

ExecutorService::ExecutorService( const ExecutorService& object ) ExecutorService_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

ExecutorService::ExecutorService( const NoOp& noOp ) ExecutorService_INITIALIZER {
}

const JClass* ExecutorService::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/util/concurrent/ExecutorService" );
  return &javaClass;
}

const JClass* ExecutorService::getJavaJniClass() const throw ( JNIException ) {
  return ExecutorService::staticGetJavaJniClass();
}

JEnlister< ExecutorService> ExecutorService::enlister;

END_NAMESPACE_5( jace, proxy, java, util, concurrent )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::util::concurrent::ExecutorService>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::concurrent::ExecutorService( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::concurrent::ExecutorService>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::concurrent::ExecutorService>& proxy ) : 
    ::jace::proxy::java::util::concurrent::ExecutorService( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::util::concurrent::ExecutorService>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::concurrent::ExecutorService( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::concurrent::ExecutorService>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::concurrent::ExecutorService( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::concurrent::ExecutorService>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::concurrent::ExecutorService>& object ) : 
    ::jace::proxy::java::util::concurrent::ExecutorService( object.getJavaJniValue() ), Object( NO_OP ) {

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

