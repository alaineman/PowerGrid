
#ifndef JACE_PROXY_JAVA_LANG_THREAD_UNCAUGHTEXCEPTIONHANDLER_H
#include "jace/proxy/java/lang/Thread.UncaughtExceptionHandler.h"
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
#ifndef JACE_PROXY_JAVA_LANG_THREAD_H
#include "jace/proxy/java/lang/Thread.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_THROWABLE_H
#include "jace/proxy/java/lang/Throwable.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, lang )

/**
 * The Jace C++ proxy class source for java/lang/Thread$UncaughtExceptionHandler.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Thread_UncaughtExceptionHandler_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Thread_UncaughtExceptionHandler_INITIALIZER
#endif

void Thread_UncaughtExceptionHandler::uncaughtException( ::jace::proxy::java::lang::Thread p0, ::jace::proxy::java::lang::Throwable p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "uncaughtException" ).invoke( *this, arguments );
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
Thread_UncaughtExceptionHandler::Thread_UncaughtExceptionHandler() : Object( NO_OP ) { 
}

Thread_UncaughtExceptionHandler::Thread_UncaughtExceptionHandler( jvalue value ) Thread_UncaughtExceptionHandler_INITIALIZER {
  setJavaJniValue( value );
}

Thread_UncaughtExceptionHandler::Thread_UncaughtExceptionHandler( jobject object ) Thread_UncaughtExceptionHandler_INITIALIZER {
  setJavaJniObject( object );
}

Thread_UncaughtExceptionHandler::Thread_UncaughtExceptionHandler( const Thread_UncaughtExceptionHandler& object ) Thread_UncaughtExceptionHandler_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Thread_UncaughtExceptionHandler::Thread_UncaughtExceptionHandler( const NoOp& noOp ) Thread_UncaughtExceptionHandler_INITIALIZER {
}

const JClass* Thread_UncaughtExceptionHandler::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/lang/Thread$UncaughtExceptionHandler" );
  return &javaClass;
}

const JClass* Thread_UncaughtExceptionHandler::getJavaJniClass() const throw ( JNIException ) {
  return Thread_UncaughtExceptionHandler::staticGetJavaJniClass();
}

JEnlister< Thread_UncaughtExceptionHandler> Thread_UncaughtExceptionHandler::enlister;

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::lang::Thread_UncaughtExceptionHandler>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::Thread_UncaughtExceptionHandler( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::Thread_UncaughtExceptionHandler>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::Thread_UncaughtExceptionHandler>& proxy ) : 
    ::jace::proxy::java::lang::Thread_UncaughtExceptionHandler( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Thread_UncaughtExceptionHandler>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::Thread_UncaughtExceptionHandler( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Thread_UncaughtExceptionHandler>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::Thread_UncaughtExceptionHandler( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Thread_UncaughtExceptionHandler>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::Thread_UncaughtExceptionHandler>& object ) : 
    ::jace::proxy::java::lang::Thread_UncaughtExceptionHandler( object.getJavaJniValue() ), Object( NO_OP ) {

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

