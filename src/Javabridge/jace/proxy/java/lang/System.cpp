
#ifndef JACE_PROXY_JAVA_LANG_SYSTEM_H
#include "jace/proxy/java/lang/System.h"
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
#ifndef JACE_PROXY_JAVA_IO_INPUTSTREAM_H
#include "jace/proxy/java/io/InputStream.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_PRINTSTREAM_H
#include "jace/proxy/java/io/PrintStream.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_CONSOLE_H
#include "jace/proxy/java/io/Console.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_CHANNEL_H
#include "jace/proxy/java/nio/channels/Channel.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_SECURITYMANAGER_H
#include "jace/proxy/java/lang/SecurityManager.h"
#endif
#ifndef JACE_TYPES_JLONG_H
#include "jace/proxy/types/JLong.h"
#endif
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_PROPERTIES_H
#include "jace/proxy/java/util/Properties.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_MAP_H
#include "jace/proxy/java/util/Map.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, lang )

/**
 * The Jace C++ proxy class source for java/lang/System.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define System_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define System_INITIALIZER
#endif

void System::setIn( ::jace::proxy::java::io::InputStream p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setIn" ).invoke( staticGetJavaJniClass(), arguments );
}

void System::setOut( ::jace::proxy::java::io::PrintStream p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setOut" ).invoke( staticGetJavaJniClass(), arguments );
}

void System::setErr( ::jace::proxy::java::io::PrintStream p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setErr" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::io::Console System::console() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::io::Console >( "console" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::channels::Channel System::inheritedChannel() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::channels::Channel >( "inheritedChannel" ).invoke( staticGetJavaJniClass(), arguments );
}

void System::setSecurityManager( ::jace::proxy::java::lang::SecurityManager p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setSecurityManager" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::SecurityManager System::getSecurityManager() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::SecurityManager >( "getSecurityManager" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::types::JLong System::currentTimeMillis() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "currentTimeMillis" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::types::JLong System::nanoTime() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "nanoTime" ).invoke( staticGetJavaJniClass(), arguments );
}

void System::arraycopy( ::jace::proxy::java::lang::Object p0, ::jace::proxy::types::JInt p1, ::jace::proxy::java::lang::Object p2, ::jace::proxy::types::JInt p3, ::jace::proxy::types::JInt p4 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3 << p4;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "arraycopy" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::types::JInt System::identityHashCode( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "identityHashCode" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::util::Properties System::getProperties() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Properties >( "getProperties" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String System::lineSeparator() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "lineSeparator" ).invoke( staticGetJavaJniClass(), arguments );
}

void System::setProperties( ::jace::proxy::java::util::Properties p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setProperties" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String System::getProperty( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getProperty" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String System::getProperty( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getProperty" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String System::setProperty( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "setProperty" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String System::clearProperty( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "clearProperty" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String System::getenv( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getenv" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::util::Map System::getenv() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Map >( "getenv" ).invoke( staticGetJavaJniClass(), arguments );
}

void System::exit( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "exit" ).invoke( staticGetJavaJniClass(), arguments );
}

void System::gc() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "gc" ).invoke( staticGetJavaJniClass(), arguments );
}

void System::runFinalization() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "runFinalization" ).invoke( staticGetJavaJniClass(), arguments );
}

void System::runFinalizersOnExit( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "runFinalizersOnExit" ).invoke( staticGetJavaJniClass(), arguments );
}

void System::load( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "load" ).invoke( staticGetJavaJniClass(), arguments );
}

void System::loadLibrary( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "loadLibrary" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String System::mapLibraryName( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "mapLibraryName" ).invoke( staticGetJavaJniClass(), arguments );
}

/**
 * public static final in
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::io::InputStream > System::in() {
  return ::jace::JField< ::jace::proxy::java::io::InputStream >( "in" ).get( staticGetJavaJniClass() );
}

/**
 * public static final out
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::io::PrintStream > System::out() {
  return ::jace::JField< ::jace::proxy::java::io::PrintStream >( "out" ).get( staticGetJavaJniClass() );
}

/**
 * public static final err
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::io::PrintStream > System::err() {
  return ::jace::JField< ::jace::proxy::java::io::PrintStream >( "err" ).get( staticGetJavaJniClass() );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
System::System( jvalue value ) System_INITIALIZER {
  setJavaJniValue( value );
}

System::System( jobject object ) System_INITIALIZER {
  setJavaJniObject( object );
}

System::System( const System& object ) System_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

System::System( const NoOp& noOp ) System_INITIALIZER {
}

const JClass* System::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/lang/System" );
  return &javaClass;
}

const JClass* System::getJavaJniClass() const throw ( JNIException ) {
  return System::staticGetJavaJniClass();
}

JEnlister< System> System::enlister;

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
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

