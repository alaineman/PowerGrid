
#ifndef JACE_PROXY_JAVA_LANG_THREADGROUP_H
#include "jace/proxy/java/lang/ThreadGroup.h"
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
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_THREAD_H
#include "jace/proxy/java/lang/Thread.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_THROWABLE_H
#include "jace/proxy/java/lang/Throwable.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, lang )

/**
 * The Jace C++ proxy class source for java/lang/ThreadGroup.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define ThreadGroup_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define ThreadGroup_INITIALIZER
#endif

ThreadGroup::ThreadGroup( ::jace::proxy::java::lang::String p0 ) ThreadGroup_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

ThreadGroup::ThreadGroup( ::jace::proxy::java::lang::ThreadGroup p0, ::jace::proxy::java::lang::String p1 ) ThreadGroup_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::java::lang::String ThreadGroup::getName() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getName" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::ThreadGroup ThreadGroup::getParent() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::ThreadGroup >( "getParent" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt ThreadGroup::getMaxPriority() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "getMaxPriority" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean ThreadGroup::isDaemon() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isDaemon" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean ThreadGroup::isDestroyed() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isDestroyed" ).invoke( *this, arguments );
}

void ThreadGroup::setDaemon( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setDaemon" ).invoke( *this, arguments );
}

void ThreadGroup::setMaxPriority( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setMaxPriority" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean ThreadGroup::parentOf( ::jace::proxy::java::lang::ThreadGroup p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "parentOf" ).invoke( *this, arguments );
}

void ThreadGroup::checkAccess() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkAccess" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt ThreadGroup::activeCount() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "activeCount" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt ThreadGroup::enumerate( ::jace::JArray< ::jace::proxy::java::lang::Thread > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "enumerate" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt ThreadGroup::enumerate( ::jace::JArray< ::jace::proxy::java::lang::Thread > p0, ::jace::proxy::types::JBoolean p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "enumerate" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt ThreadGroup::activeGroupCount() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "activeGroupCount" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt ThreadGroup::enumerate( ::jace::JArray< ::jace::proxy::java::lang::ThreadGroup > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "enumerate" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt ThreadGroup::enumerate( ::jace::JArray< ::jace::proxy::java::lang::ThreadGroup > p0, ::jace::proxy::types::JBoolean p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "enumerate" ).invoke( *this, arguments );
}

void ThreadGroup::stop() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "stop" ).invoke( *this, arguments );
}

void ThreadGroup::interrupt() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "interrupt" ).invoke( *this, arguments );
}

void ThreadGroup::suspend() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "suspend" ).invoke( *this, arguments );
}

void ThreadGroup::resume() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "resume" ).invoke( *this, arguments );
}

void ThreadGroup::destroy() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "destroy" ).invoke( *this, arguments );
}

void ThreadGroup::list() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "list" ).invoke( *this, arguments );
}

void ThreadGroup::uncaughtException( ::jace::proxy::java::lang::Thread p0, ::jace::proxy::java::lang::Throwable p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "uncaughtException" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean ThreadGroup::allowThreadSuspension( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "allowThreadSuspension" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String ThreadGroup::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
ThreadGroup::ThreadGroup( jvalue value ) ThreadGroup_INITIALIZER {
  setJavaJniValue( value );
}

ThreadGroup::ThreadGroup( jobject object ) ThreadGroup_INITIALIZER {
  setJavaJniObject( object );
}

ThreadGroup::ThreadGroup( const ThreadGroup& object ) ThreadGroup_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

ThreadGroup::ThreadGroup( const NoOp& noOp ) ThreadGroup_INITIALIZER {
}

const JClass* ThreadGroup::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/lang/ThreadGroup" );
  return &javaClass;
}

const JClass* ThreadGroup::getJavaJniClass() const throw ( JNIException ) {
  return ThreadGroup::staticGetJavaJniClass();
}

JEnlister< ThreadGroup> ThreadGroup::enlister;

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::lang::ThreadGroup>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::ThreadGroup( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::ThreadGroup>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::ThreadGroup>& proxy ) : 
    ::jace::proxy::java::lang::ThreadGroup( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::lang::ThreadGroup>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::ThreadGroup( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::ThreadGroup>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::ThreadGroup( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::ThreadGroup>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::ThreadGroup>& object ) : 
    ::jace::proxy::java::lang::ThreadGroup( object.getJavaJniValue() ), Object( NO_OP ) {

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

