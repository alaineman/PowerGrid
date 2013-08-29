
#ifndef JACE_PROXY_JAVA_UTIL_CONCURRENT_TIMEOUTEXCEPTION_H
#include "jace/proxy/java/util/concurrent/TimeoutException.h"
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

BEGIN_NAMESPACE_5( jace, proxy, java, util, concurrent )

/**
 * The Jace C++ proxy class source for java/util/concurrent/TimeoutException.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define TimeoutException_INITIALIZER : ::jace::proxy::java::lang::Exception( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define TimeoutException_INITIALIZER : ::jace::proxy::java::lang::Exception( NO_OP )
#endif

TimeoutException::TimeoutException() TimeoutException_INITIALIZER {
  ::jace::JArguments arguments;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

TimeoutException::TimeoutException( ::jace::proxy::java::lang::String p0 ) TimeoutException_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
TimeoutException::TimeoutException( jvalue value ) TimeoutException_INITIALIZER {
  setJavaJniValue( value );
}

TimeoutException::TimeoutException( jobject object ) TimeoutException_INITIALIZER {
  setJavaJniObject( object );
}

TimeoutException::TimeoutException( const TimeoutException& object ) TimeoutException_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

TimeoutException::TimeoutException( const NoOp& noOp ) TimeoutException_INITIALIZER {
}

const JClass* TimeoutException::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/util/concurrent/TimeoutException" );
  return &javaClass;
}

const JClass* TimeoutException::getJavaJniClass() const throw ( JNIException ) {
  return TimeoutException::staticGetJavaJniClass();
}

JEnlister< TimeoutException> TimeoutException::enlister;

END_NAMESPACE_5( jace, proxy, java, util, concurrent )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::util::concurrent::TimeoutException>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::concurrent::TimeoutException( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::concurrent::TimeoutException>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::concurrent::TimeoutException>& proxy ) : 
    ::jace::proxy::java::util::concurrent::TimeoutException( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::util::concurrent::TimeoutException>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::concurrent::TimeoutException( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::concurrent::TimeoutException>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::concurrent::TimeoutException( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::concurrent::TimeoutException>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::concurrent::TimeoutException>& object ) : 
    ::jace::proxy::java::util::concurrent::TimeoutException( object.getJavaJniValue() ), Object( NO_OP ) {

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

