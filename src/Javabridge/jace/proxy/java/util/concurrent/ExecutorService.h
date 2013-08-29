
#ifndef JACE_PROXY_JAVA_UTIL_CONCURRENT_EXECUTORSERVICE_H
#define JACE_PROXY_JAVA_UTIL_CONCURRENT_EXECUTORSERVICE_H

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
#ifndef JACE_PROXY_JAVA_LANG_OBJECT_H
#include "jace/proxy/java/lang/Object.h"
#endif

/**
 * The interfaces implemented by this class.
 *
 */
#ifndef JACE_PROXY_JAVA_UTIL_CONCURRENT_EXECUTOR_H
#include "jace/proxy/java/util/concurrent/Executor.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class List;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JLong;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_5( jace, proxy, java, util, concurrent )
class TimeUnit;
END_NAMESPACE_5( jace, proxy, java, util, concurrent )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class InterruptedException;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_5( jace, proxy, java, util, concurrent )
class Future;
END_NAMESPACE_5( jace, proxy, java, util, concurrent )

BEGIN_NAMESPACE_5( jace, proxy, java, util, concurrent )
class Callable;
END_NAMESPACE_5( jace, proxy, java, util, concurrent )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class Runnable;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Collection;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_5( jace, proxy, java, util, concurrent )
class ExecutionException;
END_NAMESPACE_5( jace, proxy, java, util, concurrent )

BEGIN_NAMESPACE_5( jace, proxy, java, util, concurrent )
class TimeoutException;
END_NAMESPACE_5( jace, proxy, java, util, concurrent )

BEGIN_NAMESPACE_5( jace, proxy, java, util, concurrent )

/**
 * The Jace C++ proxy class for java/util/concurrent/ExecutorService.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class ExecutorService : public virtual ::jace::proxy::java::lang::Object, public virtual ::jace::proxy::java::util::concurrent::Executor {

public: 

/**
 * shutdown
 *
 */
void shutdown();

/**
 * shutdownNow
 *
 */
::jace::proxy::java::util::List shutdownNow();

/**
 * isShutdown
 *
 */
::jace::proxy::types::JBoolean isShutdown();

/**
 * isTerminated
 *
 */
::jace::proxy::types::JBoolean isTerminated();

/**
 * awaitTermination
 *
 */
::jace::proxy::types::JBoolean awaitTermination( ::jace::proxy::types::JLong p0, ::jace::proxy::java::util::concurrent::TimeUnit p1 );

/**
 * submit
 *
 */
::jace::proxy::java::util::concurrent::Future submit( ::jace::proxy::java::util::concurrent::Callable p0 );

/**
 * submit
 *
 */
::jace::proxy::java::util::concurrent::Future submit( ::jace::proxy::java::lang::Runnable p0, ::jace::proxy::java::lang::Object p1 );

/**
 * submit
 *
 */
::jace::proxy::java::util::concurrent::Future submit( ::jace::proxy::java::lang::Runnable p0 );

/**
 * invokeAll
 *
 */
::jace::proxy::java::util::List invokeAll( ::jace::proxy::java::util::Collection p0 );

/**
 * invokeAll
 *
 */
::jace::proxy::java::util::List invokeAll( ::jace::proxy::java::util::Collection p0, ::jace::proxy::types::JLong p1, ::jace::proxy::java::util::concurrent::TimeUnit p2 );

/**
 * invokeAny
 *
 */
::jace::proxy::java::lang::Object invokeAny( ::jace::proxy::java::util::Collection p0 );

/**
 * invokeAny
 *
 */
::jace::proxy::java::lang::Object invokeAny( ::jace::proxy::java::util::Collection p0, ::jace::proxy::types::JLong p1, ::jace::proxy::java::util::concurrent::TimeUnit p2 );

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
/**
 * Special no arg constructor for interface virtual inheritance
 *
 */
ExecutorService();
ExecutorService( jvalue value );
ExecutorService( jobject object );
ExecutorService( const ExecutorService& object );
ExecutorService( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< ExecutorService> enlister;
};

END_NAMESPACE_5( jace, proxy, java, util, concurrent )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::util::concurrent::ExecutorService>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::util::concurrent::ExecutorService>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::concurrent::ExecutorService>& proxy );
#else
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
  template <> JFieldProxy< ::jace::proxy::java::util::concurrent::ExecutorService>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::util::concurrent::ExecutorService>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::util::concurrent::ExecutorService>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::concurrent::ExecutorService>& object );
#else
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

#endif // #ifndef JACE_PROXY_JAVA_UTIL_CONCURRENT_EXECUTORSERVICE_H

