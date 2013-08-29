
#ifndef JACE_PROXY_JAVA_LANG_THREAD_STATE_H
#include "jace/proxy/java/lang/Thread.State.h"
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
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, lang )

/**
 * The Jace C++ proxy class source for java/lang/Thread$State.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Thread_State_INITIALIZER : ::jace::proxy::java::lang::Enum( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Thread_State_INITIALIZER : ::jace::proxy::java::lang::Enum( NO_OP )
#endif

::jace::JArray< ::jace::proxy::java::lang::Thread_State > Thread_State::values() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::Thread_State > >( "values" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::Thread_State Thread_State::valueOf( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::Thread_State >( "valueOf" ).invoke( staticGetJavaJniClass(), arguments );
}

/**
 * public static final enum NEW
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::lang::Thread_State > Thread_State::NEW() {
  return ::jace::JField< ::jace::proxy::java::lang::Thread_State >( "NEW" ).get( staticGetJavaJniClass() );
}

/**
 * public static final enum RUNNABLE
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::lang::Thread_State > Thread_State::RUNNABLE() {
  return ::jace::JField< ::jace::proxy::java::lang::Thread_State >( "RUNNABLE" ).get( staticGetJavaJniClass() );
}

/**
 * public static final enum BLOCKED
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::lang::Thread_State > Thread_State::BLOCKED() {
  return ::jace::JField< ::jace::proxy::java::lang::Thread_State >( "BLOCKED" ).get( staticGetJavaJniClass() );
}

/**
 * public static final enum WAITING
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::lang::Thread_State > Thread_State::WAITING() {
  return ::jace::JField< ::jace::proxy::java::lang::Thread_State >( "WAITING" ).get( staticGetJavaJniClass() );
}

/**
 * public static final enum TIMED_WAITING
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::lang::Thread_State > Thread_State::TIMED_WAITING() {
  return ::jace::JField< ::jace::proxy::java::lang::Thread_State >( "TIMED_WAITING" ).get( staticGetJavaJniClass() );
}

/**
 * public static final enum TERMINATED
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::lang::Thread_State > Thread_State::TERMINATED() {
  return ::jace::JField< ::jace::proxy::java::lang::Thread_State >( "TERMINATED" ).get( staticGetJavaJniClass() );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Thread_State::Thread_State( jvalue value ) Thread_State_INITIALIZER {
  setJavaJniValue( value );
}

Thread_State::Thread_State( jobject object ) Thread_State_INITIALIZER {
  setJavaJniObject( object );
}

Thread_State::Thread_State( const Thread_State& object ) Thread_State_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Thread_State::Thread_State( const NoOp& noOp ) Thread_State_INITIALIZER {
}

const JClass* Thread_State::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/lang/Thread$State" );
  return &javaClass;
}

const JClass* Thread_State::getJavaJniClass() const throw ( JNIException ) {
  return Thread_State::staticGetJavaJniClass();
}

JEnlister< Thread_State> Thread_State::enlister;

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::lang::Thread_State>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::Thread_State( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::Thread_State>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::Thread_State>& proxy ) : 
    ::jace::proxy::java::lang::Thread_State( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Thread_State>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::Thread_State( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Thread_State>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::Thread_State( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Thread_State>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::Thread_State>& object ) : 
    ::jace::proxy::java::lang::Thread_State( object.getJavaJniValue() ), Object( NO_OP ) {

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

