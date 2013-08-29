
#ifndef JACE_PROXY_JAVA_LANG_CLASSLOADER_H
#include "jace/proxy/java/lang/ClassLoader.h"
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
#ifndef JACE_PROXY_JAVA_LANG_CLASS_H
#include "jace/proxy/java/lang/Class.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_CLASSNOTFOUNDEXCEPTION_H
#include "jace/proxy/java/lang/ClassNotFoundException.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_URL_H
#include "jace/proxy/java/net/URL.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_ENUMERATION_H
#include "jace/proxy/java/util/Enumeration.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_INPUTSTREAM_H
#include "jace/proxy/java/io/InputStream.h"
#endif
#ifndef JACE_TYPES_JVOID_H
#include "jace/proxy/types/JVoid.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, lang )

/**
 * The Jace C++ proxy class source for java/lang/ClassLoader.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define ClassLoader_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define ClassLoader_INITIALIZER
#endif

::jace::proxy::java::lang::Class ClassLoader::loadClass( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::Class >( "loadClass" ).invoke( *this, arguments );
}

::jace::proxy::java::net::URL ClassLoader::getResource( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::net::URL >( "getResource" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Enumeration ClassLoader::getResources( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::util::Enumeration >( "getResources" ).invoke( *this, arguments );
}

::jace::proxy::java::net::URL ClassLoader::getSystemResource( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::net::URL >( "getSystemResource" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::util::Enumeration ClassLoader::getSystemResources( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::util::Enumeration >( "getSystemResources" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::io::InputStream ClassLoader::getResourceAsStream( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::io::InputStream >( "getResourceAsStream" ).invoke( *this, arguments );
}

::jace::proxy::java::io::InputStream ClassLoader::getSystemResourceAsStream( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::io::InputStream >( "getSystemResourceAsStream" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::ClassLoader ClassLoader::getParent() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::ClassLoader >( "getParent" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::ClassLoader ClassLoader::getSystemClassLoader() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::ClassLoader >( "getSystemClassLoader" ).invoke( staticGetJavaJniClass(), arguments );
}

void ClassLoader::setDefaultAssertionStatus( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setDefaultAssertionStatus" ).invoke( *this, arguments );
}

void ClassLoader::setPackageAssertionStatus( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JBoolean p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setPackageAssertionStatus" ).invoke( *this, arguments );
}

void ClassLoader::setClassAssertionStatus( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JBoolean p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setClassAssertionStatus" ).invoke( *this, arguments );
}

void ClassLoader::clearAssertionStatus() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "clearAssertionStatus" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
ClassLoader::ClassLoader( jvalue value ) ClassLoader_INITIALIZER {
  setJavaJniValue( value );
}

ClassLoader::ClassLoader( jobject object ) ClassLoader_INITIALIZER {
  setJavaJniObject( object );
}

ClassLoader::ClassLoader( const ClassLoader& object ) ClassLoader_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

ClassLoader::ClassLoader( const NoOp& noOp ) ClassLoader_INITIALIZER {
}

const JClass* ClassLoader::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/lang/ClassLoader" );
  return &javaClass;
}

const JClass* ClassLoader::getJavaJniClass() const throw ( JNIException ) {
  return ClassLoader::staticGetJavaJniClass();
}

JEnlister< ClassLoader> ClassLoader::enlister;

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::lang::ClassLoader>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::ClassLoader( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::ClassLoader>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::ClassLoader>& proxy ) : 
    ::jace::proxy::java::lang::ClassLoader( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::lang::ClassLoader>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::ClassLoader( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::ClassLoader>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::ClassLoader( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::ClassLoader>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::ClassLoader>& object ) : 
    ::jace::proxy::java::lang::ClassLoader( object.getJavaJniValue() ), Object( NO_OP ) {

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

