
#ifndef JACE_PROXY_JAVA_UTIL_CONCURRENT_TIMEUNIT_H
#define JACE_PROXY_JAVA_UTIL_CONCURRENT_TIMEUNIT_H

#ifndef JACE_OS_DEP_H
#include "jace/os_dep.h"
#endif

#ifndef JACE_NAMESPACE_H
#include "jace/namespace.h"
#endif

#ifndef JACE_JOBJECT_H
#include "jace/proxy/JObject.h"
#endif

#ifndef JACE_JENLISTER_H
#include "jace/JEnlister.h"
#endif

#ifndef JACE_JARRAY_H
#include "jace/JArray.h"
#endif

#ifndef JACE_JFIELD_PROXY_H
#include "jace/JFieldProxy.h"
#endif

/**
 * The super class for this class.
 *
 */
#ifndef JACE_PROXY_JAVA_LANG_ENUM_H
#include "jace/proxy/java/lang/Enum.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JLong;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class Object;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class InterruptedException;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class Thread;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_5( jace, proxy, java, util, concurrent )

/**
 * The Jace C++ proxy class for java/util/concurrent/TimeUnit.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class TimeUnit : public ::jace::proxy::java::lang::Enum {

public: 

/**
 * values
 *
 */
static ::jace::JArray< ::jace::proxy::java::util::concurrent::TimeUnit > values();

/**
 * valueOf
 *
 */
static ::jace::proxy::java::util::concurrent::TimeUnit valueOf( ::jace::proxy::java::lang::String p0 );

/**
 * convert
 *
 */
::jace::proxy::types::JLong convert( ::jace::proxy::types::JLong p0, ::jace::proxy::java::util::concurrent::TimeUnit p1 );

/**
 * toNanos
 *
 */
::jace::proxy::types::JLong toNanos( ::jace::proxy::types::JLong p0 );

/**
 * toMicros
 *
 */
::jace::proxy::types::JLong toMicros( ::jace::proxy::types::JLong p0 );

/**
 * toMillis
 *
 */
::jace::proxy::types::JLong toMillis( ::jace::proxy::types::JLong p0 );

/**
 * toSeconds
 *
 */
::jace::proxy::types::JLong toSeconds( ::jace::proxy::types::JLong p0 );

/**
 * toMinutes
 *
 */
::jace::proxy::types::JLong toMinutes( ::jace::proxy::types::JLong p0 );

/**
 * toHours
 *
 */
::jace::proxy::types::JLong toHours( ::jace::proxy::types::JLong p0 );

/**
 * toDays
 *
 */
::jace::proxy::types::JLong toDays( ::jace::proxy::types::JLong p0 );

/**
 * timedWait
 *
 */
void timedWait( ::jace::proxy::java::lang::Object p0, ::jace::proxy::types::JLong p1 );

/**
 * timedJoin
 *
 */
void timedJoin( ::jace::proxy::java::lang::Thread p0, ::jace::proxy::types::JLong p1 );

/**
 * sleep
 *
 */
void sleep( ::jace::proxy::types::JLong p0 );

/**
 * public static final enum NANOSECONDS
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::concurrent::TimeUnit > NANOSECONDS();

/**
 * public static final enum MICROSECONDS
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::concurrent::TimeUnit > MICROSECONDS();

/**
 * public static final enum MILLISECONDS
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::concurrent::TimeUnit > MILLISECONDS();

/**
 * public static final enum SECONDS
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::concurrent::TimeUnit > SECONDS();

/**
 * public static final enum MINUTES
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::concurrent::TimeUnit > MINUTES();

/**
 * public static final enum HOURS
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::concurrent::TimeUnit > HOURS();

/**
 * public static final enum DAYS
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::concurrent::TimeUnit > DAYS();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
TimeUnit( jvalue value );
TimeUnit( jobject object );
TimeUnit( const TimeUnit& object );
TimeUnit( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< TimeUnit> enlister;
};

END_NAMESPACE_5( jace, proxy, java, util, concurrent )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::util::concurrent::TimeUnit>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::util::concurrent::TimeUnit>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::concurrent::TimeUnit>& proxy );
#else
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
  template <> JFieldProxy< ::jace::proxy::java::util::concurrent::TimeUnit>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::util::concurrent::TimeUnit>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::util::concurrent::TimeUnit>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::concurrent::TimeUnit>& object );
#else
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

#endif // #ifndef JACE_PROXY_JAVA_UTIL_CONCURRENT_TIMEUNIT_H

