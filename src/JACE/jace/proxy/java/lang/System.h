
#ifndef JACE_PROXY_JAVA_LANG_SYSTEM_H
#define JACE_PROXY_JAVA_LANG_SYSTEM_H

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
 * Classes which this class is fully dependent upon.
 *
 */
#ifndef JACE_PROXY_JAVA_IO_INPUTSTREAM_H
#include "jace/proxy/java/io/InputStream.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_PRINTSTREAM_H
#include "jace/proxy/java/io/PrintStream.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class InputStream;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class PrintStream;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class Console;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )
class Channel;
END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class IOException;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class SecurityManager;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JLong;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Properties;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Map;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )

/**
 * The Jace C++ proxy class for java/lang/System.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class System : public virtual ::jace::proxy::java::lang::Object {

public: 

/**
 * setIn
 *
 */
static void setIn( ::jace::proxy::java::io::InputStream p0 );

/**
 * setOut
 *
 */
static void setOut( ::jace::proxy::java::io::PrintStream p0 );

/**
 * setErr
 *
 */
static void setErr( ::jace::proxy::java::io::PrintStream p0 );

/**
 * console
 *
 */
static ::jace::proxy::java::io::Console console();

/**
 * inheritedChannel
 *
 */
static ::jace::proxy::java::nio::channels::Channel inheritedChannel();

/**
 * setSecurityManager
 *
 */
static void setSecurityManager( ::jace::proxy::java::lang::SecurityManager p0 );

/**
 * getSecurityManager
 *
 */
static ::jace::proxy::java::lang::SecurityManager getSecurityManager();

/**
 * currentTimeMillis
 *
 */
static ::jace::proxy::types::JLong currentTimeMillis();

/**
 * nanoTime
 *
 */
static ::jace::proxy::types::JLong nanoTime();

/**
 * arraycopy
 *
 */
static void arraycopy( ::jace::proxy::java::lang::Object p0, ::jace::proxy::types::JInt p1, ::jace::proxy::java::lang::Object p2, ::jace::proxy::types::JInt p3, ::jace::proxy::types::JInt p4 );

/**
 * identityHashCode
 *
 */
static ::jace::proxy::types::JInt identityHashCode( ::jace::proxy::java::lang::Object p0 );

/**
 * getProperties
 *
 */
static ::jace::proxy::java::util::Properties getProperties();

/**
 * lineSeparator
 *
 */
static ::jace::proxy::java::lang::String lineSeparator();

/**
 * setProperties
 *
 */
static void setProperties( ::jace::proxy::java::util::Properties p0 );

/**
 * getProperty
 *
 */
static ::jace::proxy::java::lang::String getProperty( ::jace::proxy::java::lang::String p0 );

/**
 * getProperty
 *
 */
static ::jace::proxy::java::lang::String getProperty( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 );

/**
 * setProperty
 *
 */
static ::jace::proxy::java::lang::String setProperty( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 );

/**
 * clearProperty
 *
 */
static ::jace::proxy::java::lang::String clearProperty( ::jace::proxy::java::lang::String p0 );

/**
 * getenv
 *
 */
static ::jace::proxy::java::lang::String getenv( ::jace::proxy::java::lang::String p0 );

/**
 * getenv
 *
 */
static ::jace::proxy::java::util::Map getenv();

/**
 * exit
 *
 */
static void exit( ::jace::proxy::types::JInt p0 );

/**
 * gc
 *
 */
static void gc();

/**
 * runFinalization
 *
 */
static void runFinalization();

/**
 * runFinalizersOnExit
 *
 */
static void runFinalizersOnExit( ::jace::proxy::types::JBoolean p0 );

/**
 * load
 *
 */
static void load( ::jace::proxy::java::lang::String p0 );

/**
 * loadLibrary
 *
 */
static void loadLibrary( ::jace::proxy::java::lang::String p0 );

/**
 * mapLibraryName
 *
 */
static ::jace::proxy::java::lang::String mapLibraryName( ::jace::proxy::java::lang::String p0 );

/**
 * public static final in
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::io::InputStream > in();

/**
 * public static final out
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::io::PrintStream > out();

/**
 * public static final err
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::io::PrintStream > err();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
System( jvalue value );
System( jobject object );
System( const System& object );
System( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< System> enlister;
};

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::lang::System>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::lang::System>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::System>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::lang::System>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::System( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::System>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::System>& proxy ) : 
    ::jace::proxy::java::lang::System( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::lang::System>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::lang::System>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::lang::System>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::System>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::lang::System>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::System( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::System>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::System( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::System>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::System>& object ) : 
    ::jace::proxy::java::lang::System( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_LANG_SYSTEM_H

