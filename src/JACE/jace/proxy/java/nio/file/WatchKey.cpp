
#ifndef JACE_PROXY_JAVA_NIO_FILE_WATCHKEY_H
#include "jace/proxy/java/nio/file/WatchKey.h"
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
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_LIST_H
#include "jace/proxy/java/util/List.h"
#endif
#ifndef JACE_TYPES_JVOID_H
#include "jace/proxy/types/JVoid.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_WATCHABLE_H
#include "jace/proxy/java/nio/file/Watchable.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )

/**
 * The Jace C++ proxy class source for java/nio/file/WatchKey.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define WatchKey_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define WatchKey_INITIALIZER
#endif

::jace::proxy::types::JBoolean WatchKey::isValid() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isValid" ).invoke( *this, arguments );
}

::jace::proxy::java::util::List WatchKey::pollEvents() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::List >( "pollEvents" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean WatchKey::reset() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "reset" ).invoke( *this, arguments );
}

void WatchKey::cancel() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "cancel" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::Watchable WatchKey::watchable() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::Watchable >( "watchable" ).invoke( *this, arguments );
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
WatchKey::WatchKey() : Object( NO_OP ) { 
}

WatchKey::WatchKey( jvalue value ) WatchKey_INITIALIZER {
  setJavaJniValue( value );
}

WatchKey::WatchKey( jobject object ) WatchKey_INITIALIZER {
  setJavaJniObject( object );
}

WatchKey::WatchKey( const WatchKey& object ) WatchKey_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

WatchKey::WatchKey( const NoOp& noOp ) WatchKey_INITIALIZER {
}

const JClass* WatchKey::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/file/WatchKey" );
  return &javaClass;
}

const JClass* WatchKey::getJavaJniClass() const throw ( JNIException ) {
  return WatchKey::staticGetJavaJniClass();
}

JEnlister< WatchKey> WatchKey::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::WatchKey>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::file::WatchKey( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::WatchKey>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::file::WatchKey>& proxy ) : 
    ::jace::proxy::java::nio::file::WatchKey( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::WatchKey>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::file::WatchKey( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::WatchKey>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::file::WatchKey( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::WatchKey>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::file::WatchKey>& object ) : 
    ::jace::proxy::java::nio::file::WatchKey( object.getJavaJniValue() ), Object( NO_OP ) {

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

