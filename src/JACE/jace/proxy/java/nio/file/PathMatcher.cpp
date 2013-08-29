
#ifndef JACE_PROXY_JAVA_NIO_FILE_PATHMATCHER_H
#include "jace/proxy/java/nio/file/PathMatcher.h"
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
#ifndef JACE_PROXY_JAVA_NIO_FILE_PATH_H
#include "jace/proxy/java/nio/file/Path.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )

/**
 * The Jace C++ proxy class source for java/nio/file/PathMatcher.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define PathMatcher_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define PathMatcher_INITIALIZER
#endif

::jace::proxy::types::JBoolean PathMatcher::matches( ::jace::proxy::java::nio::file::Path p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "matches" ).invoke( *this, arguments );
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
PathMatcher::PathMatcher() : Object( NO_OP ) { 
}

PathMatcher::PathMatcher( jvalue value ) PathMatcher_INITIALIZER {
  setJavaJniValue( value );
}

PathMatcher::PathMatcher( jobject object ) PathMatcher_INITIALIZER {
  setJavaJniObject( object );
}

PathMatcher::PathMatcher( const PathMatcher& object ) PathMatcher_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

PathMatcher::PathMatcher( const NoOp& noOp ) PathMatcher_INITIALIZER {
}

const JClass* PathMatcher::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/file/PathMatcher" );
  return &javaClass;
}

const JClass* PathMatcher::getJavaJniClass() const throw ( JNIException ) {
  return PathMatcher::staticGetJavaJniClass();
}

JEnlister< PathMatcher> PathMatcher::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::PathMatcher>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::file::PathMatcher( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::PathMatcher>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::file::PathMatcher>& proxy ) : 
    ::jace::proxy::java::nio::file::PathMatcher( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::PathMatcher>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::file::PathMatcher( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::PathMatcher>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::file::PathMatcher( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::PathMatcher>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::file::PathMatcher>& object ) : 
    ::jace::proxy::java::nio::file::PathMatcher( object.getJavaJniValue() ), Object( NO_OP ) {

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

