
#ifndef JACE_PROXY_JAVA_UTIL_CONCURRENT_TIMEUNIT_H
#include "jace/proxy/java/util/concurrent/TimeUnit.h"
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
#ifndef JACE_TYPES_JLONG_H
#include "jace/proxy/types/JLong.h"
#endif
#ifndef JACE_TYPES_JVOID_H
#include "jace/proxy/types/JVoid.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_OBJECT_H
#include "jace/proxy/java/lang/Object.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_INTERRUPTEDEXCEPTION_H
#include "jace/proxy/java/lang/InterruptedException.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_THREAD_H
#include "jace/proxy/java/lang/Thread.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, util, concurrent )

/**
 * The Jace C++ proxy class source for java/util/concurrent/TimeUnit.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define TimeUnit_INITIALIZER : ::jace::proxy::java::lang::Enum( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define TimeUnit_INITIALIZER : ::jace::proxy::java::lang::Enum( NO_OP )
#endif

::jace::JArray< ::jace::proxy::java::util::concurrent::TimeUnit > TimeUnit::values() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::util::concurrent::TimeUnit > >( "values" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::util::concurrent::TimeUnit TimeUnit::valueOf( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::util::concurrent::TimeUnit >( "valueOf" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::types::JLong TimeUnit::convert( ::jace::proxy::types::JLong p0, ::jace::proxy::java::util::concurrent::TimeUnit p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "convert" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong TimeUnit::toNanos( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "toNanos" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong TimeUnit::toMicros( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "toMicros" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong TimeUnit::toMillis( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "toMillis" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong TimeUnit::toSeconds( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "toSeconds" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong TimeUnit::toMinutes( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "toMinutes" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong TimeUnit::toHours( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "toHours" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong TimeUnit::toDays( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "toDays" ).invoke( *this, arguments );
}

void TimeUnit::timedWait( ::jace::proxy::java::lang::Object p0, ::jace::proxy::types::JLong p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "timedWait" ).invoke( *this, arguments );
}

void TimeUnit::timedJoin( ::jace::proxy::java::lang::Thread p0, ::jace::proxy::types::JLong p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "timedJoin" ).invoke( *this, arguments );
}

void TimeUnit::sleep( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "sleep" ).invoke( *this, arguments );
}

/**
 * public static final enum NANOSECONDS
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::concurrent::TimeUnit > TimeUnit::NANOSECONDS() {
  return ::jace::JField< ::jace::proxy::java::util::concurrent::TimeUnit >( "NANOSECONDS" ).get( staticGetJavaJniClass() );
}

/**
 * public static final enum MICROSECONDS
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::concurrent::TimeUnit > TimeUnit::MICROSECONDS() {
  return ::jace::JField< ::jace::proxy::java::util::concurrent::TimeUnit >( "MICROSECONDS" ).get( staticGetJavaJniClass() );
}

/**
 * public static final enum MILLISECONDS
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::concurrent::TimeUnit > TimeUnit::MILLISECONDS() {
  return ::jace::JField< ::jace::proxy::java::util::concurrent::TimeUnit >( "MILLISECONDS" ).get( staticGetJavaJniClass() );
}

/**
 * public static final enum SECONDS
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::concurrent::TimeUnit > TimeUnit::SECONDS() {
  return ::jace::JField< ::jace::proxy::java::util::concurrent::TimeUnit >( "SECONDS" ).get( staticGetJavaJniClass() );
}

/**
 * public static final enum MINUTES
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::concurrent::TimeUnit > TimeUnit::MINUTES() {
  return ::jace::JField< ::jace::proxy::java::util::concurrent::TimeUnit >( "MINUTES" ).get( staticGetJavaJniClass() );
}

/**
 * public static final enum HOURS
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::concurrent::TimeUnit > TimeUnit::HOURS() {
  return ::jace::JField< ::jace::proxy::java::util::concurrent::TimeUnit >( "HOURS" ).get( staticGetJavaJniClass() );
}

/**
 * public static final enum DAYS
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::concurrent::TimeUnit > TimeUnit::DAYS() {
  return ::jace::JField< ::jace::proxy::java::util::concurrent::TimeUnit >( "DAYS" ).get( staticGetJavaJniClass() );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
TimeUnit::TimeUnit( jvalue value ) TimeUnit_INITIALIZER {
  setJavaJniValue( value );
}

TimeUnit::TimeUnit( jobject object ) TimeUnit_INITIALIZER {
  setJavaJniObject( object );
}

TimeUnit::TimeUnit( const TimeUnit& object ) TimeUnit_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

TimeUnit::TimeUnit( const NoOp& noOp ) TimeUnit_INITIALIZER {
}

const JClass* TimeUnit::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/util/concurrent/TimeUnit" );
  return &javaClass;
}

const JClass* TimeUnit::getJavaJniClass() const throw ( JNIException ) {
  return TimeUnit::staticGetJavaJniClass();
}

JEnlister< TimeUnit> TimeUnit::enlister;

END_NAMESPACE_5( jace, proxy, java, util, concurrent )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::util::concurrent::TimeUnit>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::concurrent::TimeUnit( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::concurrent::TimeUnit>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::concurrent::TimeUnit>& proxy ) : 
    ::jace::proxy::java::util::concurrent::TimeUnit( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::util::concurrent::TimeUnit>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::concurrent::TimeUnit( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::concurrent::TimeUnit>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::concurrent::TimeUnit( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::concurrent::TimeUnit>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::concurrent::TimeUnit>& object ) : 
    ::jace::proxy::java::util::concurrent::TimeUnit( object.getJavaJniValue() ), Object( NO_OP ) {

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

