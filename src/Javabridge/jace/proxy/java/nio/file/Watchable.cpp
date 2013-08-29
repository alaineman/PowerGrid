
#ifndef JACE_PROXY_JAVA_NIO_FILE_WATCHABLE_H
#include "jace/proxy/java/nio/file/Watchable.h"
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
#ifndef JACE_PROXY_JAVA_NIO_FILE_WATCHKEY_H
#include "jace/proxy/java/nio/file/WatchKey.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_WATCHSERVICE_H
#include "jace/proxy/java/nio/file/WatchService.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )

/**
 * The Jace C++ proxy class source for java/nio/file/Watchable.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Watchable_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Watchable_INITIALIZER
#endif

::jace::proxy::java::nio::file::WatchKey Watchable::register_( ::jace::proxy::java::nio::file::WatchService p0, ::jace::JArray< ::jace::proxy::java::nio::file::WatchEvent_Kind > p1, ::jace::JArray< ::jace::proxy::java::nio::file::WatchEvent_Modifier > p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::WatchKey >( "register_" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::WatchKey Watchable::register_( ::jace::proxy::java::nio::file::WatchService p0, ::jace::JArray< ::jace::proxy::java::nio::file::WatchEvent_Kind > p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::WatchKey >( "register_" ).invoke( *this, arguments );
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
Watchable::Watchable() : Object( NO_OP ) { 
}

Watchable::Watchable( jvalue value ) Watchable_INITIALIZER {
  setJavaJniValue( value );
}

Watchable::Watchable( jobject object ) Watchable_INITIALIZER {
  setJavaJniObject( object );
}

Watchable::Watchable( const Watchable& object ) Watchable_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Watchable::Watchable( const NoOp& noOp ) Watchable_INITIALIZER {
}

const JClass* Watchable::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/file/Watchable" );
  return &javaClass;
}

const JClass* Watchable::getJavaJniClass() const throw ( JNIException ) {
  return Watchable::staticGetJavaJniClass();
}

JEnlister< Watchable> Watchable::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::Watchable>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::file::Watchable( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::Watchable>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::file::Watchable>& proxy ) : 
    ::jace::proxy::java::nio::file::Watchable( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::Watchable>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::file::Watchable( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::Watchable>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::file::Watchable( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::Watchable>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::file::Watchable>& object ) : 
    ::jace::proxy::java::nio::file::Watchable( object.getJavaJniValue() ), Object( NO_OP ) {

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

