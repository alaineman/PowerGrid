
#ifndef JACE_PROXY_JAVA_LANG_THREAD_H
#include "jace/proxy/java/lang/Thread.h"
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
#ifndef JACE_TYPES_JLONG_H
#include "jace/proxy/types/JLong.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_INTERRUPTEDEXCEPTION_H
#include "jace/proxy/java/lang/InterruptedException.h"
#endif
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_THREADGROUP_H
#include "jace/proxy/java/lang/ThreadGroup.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_THROWABLE_H
#include "jace/proxy/java/lang/Throwable.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_CLASSLOADER_H
#include "jace/proxy/java/lang/ClassLoader.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_MAP_H
#include "jace/proxy/java/util/Map.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_THREAD_STATE_H
#include "jace/proxy/java/lang/Thread.State.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_THREAD_UNCAUGHTEXCEPTIONHANDLER_H
#include "jace/proxy/java/lang/Thread.UncaughtExceptionHandler.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, lang )

/**
 * The Jace C++ proxy class source for java/lang/Thread.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Thread_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Thread_INITIALIZER
#endif

::jace::proxy::java::lang::Thread Thread::currentThread() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Thread >( "currentThread" ).invoke( staticGetJavaJniClass(), arguments );
}

void Thread::yield() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "yield" ).invoke( staticGetJavaJniClass(), arguments );
}

void Thread::sleep( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "sleep" ).invoke( staticGetJavaJniClass(), arguments );
}

void Thread::sleep( ::jace::proxy::types::JLong p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "sleep" ).invoke( staticGetJavaJniClass(), arguments );
}

Thread::Thread() Thread_INITIALIZER {
  ::jace::JArguments arguments;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

Thread::Thread( ::jace::proxy::java::lang::Runnable p0 ) Thread_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

Thread::Thread( ::jace::proxy::java::lang::ThreadGroup p0, ::jace::proxy::java::lang::Runnable p1 ) Thread_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

Thread::Thread( ::jace::proxy::java::lang::String p0 ) Thread_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

Thread::Thread( ::jace::proxy::java::lang::ThreadGroup p0, ::jace::proxy::java::lang::String p1 ) Thread_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

Thread::Thread( ::jace::proxy::java::lang::Runnable p0, ::jace::proxy::java::lang::String p1 ) Thread_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

Thread::Thread( ::jace::proxy::java::lang::ThreadGroup p0, ::jace::proxy::java::lang::Runnable p1, ::jace::proxy::java::lang::String p2 ) Thread_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

Thread::Thread( ::jace::proxy::java::lang::ThreadGroup p0, ::jace::proxy::java::lang::Runnable p1, ::jace::proxy::java::lang::String p2, ::jace::proxy::types::JLong p3 ) Thread_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

void Thread::start() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "start" ).invoke( *this, arguments );
}

void Thread::run() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "run" ).invoke( *this, arguments );
}

void Thread::stop() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "stop" ).invoke( *this, arguments );
}

void Thread::stop( ::jace::proxy::java::lang::Throwable p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "stop" ).invoke( *this, arguments );
}

void Thread::interrupt() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "interrupt" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Thread::interrupted() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "interrupted" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::types::JBoolean Thread::isInterrupted() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isInterrupted" ).invoke( *this, arguments );
}

void Thread::destroy() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "destroy" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Thread::isAlive() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isAlive" ).invoke( *this, arguments );
}

void Thread::suspend() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "suspend" ).invoke( *this, arguments );
}

void Thread::resume() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "resume" ).invoke( *this, arguments );
}

void Thread::setPriority( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setPriority" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt Thread::getPriority() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "getPriority" ).invoke( *this, arguments );
}

void Thread::setName( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setName" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Thread::getName() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getName" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::ThreadGroup Thread::getThreadGroup() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::ThreadGroup >( "getThreadGroup" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt Thread::activeCount() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "activeCount" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::types::JInt Thread::enumerate( ::jace::JArray< ::jace::proxy::java::lang::Thread > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "enumerate" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::types::JInt Thread::countStackFrames() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "countStackFrames" ).invoke( *this, arguments );
}

void Thread::join( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "join" ).invoke( *this, arguments );
}

void Thread::join( ::jace::proxy::types::JLong p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "join" ).invoke( *this, arguments );
}

void Thread::join() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "join" ).invoke( *this, arguments );
}

void Thread::dumpStack() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "dumpStack" ).invoke( staticGetJavaJniClass(), arguments );
}

void Thread::setDaemon( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setDaemon" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Thread::isDaemon() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isDaemon" ).invoke( *this, arguments );
}

void Thread::checkAccess() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkAccess" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Thread::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::ClassLoader Thread::getContextClassLoader() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::ClassLoader >( "getContextClassLoader" ).invoke( *this, arguments );
}

void Thread::setContextClassLoader( ::jace::proxy::java::lang::ClassLoader p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setContextClassLoader" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Thread::holdsLock( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "holdsLock" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::JArray< ::jace::proxy::java::lang::StackTraceElement > Thread::getStackTrace() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::StackTraceElement > >( "getStackTrace" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Map Thread::getAllStackTraces() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Map >( "getAllStackTraces" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::types::JLong Thread::getId() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "getId" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Thread_State Thread::getState() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Thread_State >( "getState" ).invoke( *this, arguments );
}

void Thread::setDefaultUncaughtExceptionHandler( ::jace::proxy::java::lang::Thread_UncaughtExceptionHandler p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setDefaultUncaughtExceptionHandler" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::Thread_UncaughtExceptionHandler Thread::getDefaultUncaughtExceptionHandler() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Thread_UncaughtExceptionHandler >( "getDefaultUncaughtExceptionHandler" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::Thread_UncaughtExceptionHandler Thread::getUncaughtExceptionHandler() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Thread_UncaughtExceptionHandler >( "getUncaughtExceptionHandler" ).invoke( *this, arguments );
}

void Thread::setUncaughtExceptionHandler( ::jace::proxy::java::lang::Thread_UncaughtExceptionHandler p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setUncaughtExceptionHandler" ).invoke( *this, arguments );
}

/**
 * public static final MIN_PRIORITY
 *
 */
::jace::JFieldProxy< ::jace::proxy::types::JInt > Thread::MIN_PRIORITY() {
  return ::jace::JField< ::jace::proxy::types::JInt >( "MIN_PRIORITY" ).get( staticGetJavaJniClass() );
}

/**
 * public static final NORM_PRIORITY
 *
 */
::jace::JFieldProxy< ::jace::proxy::types::JInt > Thread::NORM_PRIORITY() {
  return ::jace::JField< ::jace::proxy::types::JInt >( "NORM_PRIORITY" ).get( staticGetJavaJniClass() );
}

/**
 * public static final MAX_PRIORITY
 *
 */
::jace::JFieldProxy< ::jace::proxy::types::JInt > Thread::MAX_PRIORITY() {
  return ::jace::JField< ::jace::proxy::types::JInt >( "MAX_PRIORITY" ).get( staticGetJavaJniClass() );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Thread::Thread( jvalue value ) Thread_INITIALIZER {
  setJavaJniValue( value );
}

Thread::Thread( jobject object ) Thread_INITIALIZER {
  setJavaJniObject( object );
}

Thread::Thread( const Thread& object ) Thread_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Thread::Thread( const NoOp& noOp ) Thread_INITIALIZER {
}

const JClass* Thread::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/lang/Thread" );
  return &javaClass;
}

const JClass* Thread::getJavaJniClass() const throw ( JNIException ) {
  return Thread::staticGetJavaJniClass();
}

JEnlister< Thread> Thread::enlister;

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::lang::Thread>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::Thread( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::Thread>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::Thread>& proxy ) : 
    ::jace::proxy::java::lang::Thread( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Thread>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::Thread( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Thread>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::Thread( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Thread>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::Thread>& object ) : 
    ::jace::proxy::java::lang::Thread( object.getJavaJniValue() ), Object( NO_OP ) {

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

