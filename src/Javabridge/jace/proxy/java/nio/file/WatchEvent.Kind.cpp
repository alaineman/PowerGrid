
#ifndef JACE_PROXY_JAVA_NIO_FILE_WATCHEVENT_KIND_H
#include "jace/proxy/java/nio/file/WatchEvent.Kind.h"
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
#ifndef JACE_PROXY_JAVA_LANG_CLASS_H
#include "jace/proxy/java/lang/Class.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )

/**
 * The Jace C++ proxy class source for java/nio/file/WatchEvent$Kind.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define WatchEvent_Kind_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define WatchEvent_Kind_INITIALIZER
#endif

::jace::proxy::java::lang::String WatchEvent_Kind::name() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "name" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Class WatchEvent_Kind::type() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Class >( "type" ).invoke( *this, arguments );
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
WatchEvent_Kind::WatchEvent_Kind() : Object( NO_OP ) { 
}

WatchEvent_Kind::WatchEvent_Kind( jvalue value ) WatchEvent_Kind_INITIALIZER {
  setJavaJniValue( value );
}

WatchEvent_Kind::WatchEvent_Kind( jobject object ) WatchEvent_Kind_INITIALIZER {
  setJavaJniObject( object );
}

WatchEvent_Kind::WatchEvent_Kind( const WatchEvent_Kind& object ) WatchEvent_Kind_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

WatchEvent_Kind::WatchEvent_Kind( const NoOp& noOp ) WatchEvent_Kind_INITIALIZER {
}

const JClass* WatchEvent_Kind::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/file/WatchEvent$Kind" );
  return &javaClass;
}

const JClass* WatchEvent_Kind::getJavaJniClass() const throw ( JNIException ) {
  return WatchEvent_Kind::staticGetJavaJniClass();
}

JEnlister< WatchEvent_Kind> WatchEvent_Kind::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::WatchEvent_Kind>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::file::WatchEvent_Kind( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::WatchEvent_Kind>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::file::WatchEvent_Kind>& proxy ) : 
    ::jace::proxy::java::nio::file::WatchEvent_Kind( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::WatchEvent_Kind>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::file::WatchEvent_Kind( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::WatchEvent_Kind>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::file::WatchEvent_Kind( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::WatchEvent_Kind>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::file::WatchEvent_Kind>& object ) : 
    ::jace::proxy::java::nio::file::WatchEvent_Kind( object.getJavaJniValue() ), Object( NO_OP ) {

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

