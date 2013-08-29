
#ifndef JACE_PROXY_JAVA_LANG_CLASSNOTFOUNDEXCEPTION_H
#include "jace/proxy/java/lang/ClassNotFoundException.h"
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
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_THROWABLE_H
#include "jace/proxy/java/lang/Throwable.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, lang )

/**
 * The Jace C++ proxy class source for java/lang/ClassNotFoundException.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define ClassNotFoundException_INITIALIZER : ::jace::proxy::java::lang::ReflectiveOperationException( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define ClassNotFoundException_INITIALIZER : ::jace::proxy::java::lang::ReflectiveOperationException( NO_OP )
#endif

ClassNotFoundException::ClassNotFoundException() ClassNotFoundException_INITIALIZER {
  ::jace::JArguments arguments;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

ClassNotFoundException::ClassNotFoundException( ::jace::proxy::java::lang::String p0 ) ClassNotFoundException_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

ClassNotFoundException::ClassNotFoundException( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::Throwable p1 ) ClassNotFoundException_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::java::lang::Throwable ClassNotFoundException::getException() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Throwable >( "getException" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Throwable ClassNotFoundException::getCause() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Throwable >( "getCause" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
ClassNotFoundException::ClassNotFoundException( jvalue value ) ClassNotFoundException_INITIALIZER {
  setJavaJniValue( value );
}

ClassNotFoundException::ClassNotFoundException( jobject object ) ClassNotFoundException_INITIALIZER {
  setJavaJniObject( object );
}

ClassNotFoundException::ClassNotFoundException( const ClassNotFoundException& object ) ClassNotFoundException_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

ClassNotFoundException::ClassNotFoundException( const NoOp& noOp ) ClassNotFoundException_INITIALIZER {
}

const JClass* ClassNotFoundException::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/lang/ClassNotFoundException" );
  return &javaClass;
}

const JClass* ClassNotFoundException::getJavaJniClass() const throw ( JNIException ) {
  return ClassNotFoundException::staticGetJavaJniClass();
}

JEnlister< ClassNotFoundException> ClassNotFoundException::enlister;

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::lang::ClassNotFoundException>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::ClassNotFoundException( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::ClassNotFoundException>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::ClassNotFoundException>& proxy ) : 
    ::jace::proxy::java::lang::ClassNotFoundException( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::lang::ClassNotFoundException>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::ClassNotFoundException( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::ClassNotFoundException>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::ClassNotFoundException( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::ClassNotFoundException>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::ClassNotFoundException>& object ) : 
    ::jace::proxy::java::lang::ClassNotFoundException( object.getJavaJniValue() ), Object( NO_OP ) {

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

