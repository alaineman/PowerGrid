
#ifndef JACE_PROXY_JAVA_LANG_THROWABLE_H
#include "jace/proxy/java/lang/Throwable.h"
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
#ifndef JACE_PROXY_JAVA_IO_PRINTSTREAM_H
#include "jace/proxy/java/io/PrintStream.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_PRINTWRITER_H
#include "jace/proxy/java/io/PrintWriter.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, lang )

/**
 * The Jace C++ proxy class source for java/lang/Throwable.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Throwable_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Throwable_INITIALIZER
#endif

Throwable::Throwable() Throwable_INITIALIZER {
  ::jace::JArguments arguments;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

Throwable::Throwable( ::jace::proxy::java::lang::String p0 ) Throwable_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

Throwable::Throwable( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::Throwable p1 ) Throwable_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

Throwable::Throwable( ::jace::proxy::java::lang::Throwable p0, CopyConstructorSpecifier ccs ) Throwable_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::java::lang::String Throwable::getMessage() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getMessage" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Throwable::getLocalizedMessage() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getLocalizedMessage" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Throwable Throwable::getCause() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Throwable >( "getCause" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Throwable Throwable::initCause( ::jace::proxy::java::lang::Throwable p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::Throwable >( "initCause" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Throwable::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

void Throwable::printStackTrace() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "printStackTrace" ).invoke( *this, arguments );
}

void Throwable::printStackTrace( ::jace::proxy::java::io::PrintStream p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "printStackTrace" ).invoke( *this, arguments );
}

void Throwable::printStackTrace( ::jace::proxy::java::io::PrintWriter p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "printStackTrace" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Throwable Throwable::fillInStackTrace() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Throwable >( "fillInStackTrace" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::lang::StackTraceElement > Throwable::getStackTrace() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::StackTraceElement > >( "getStackTrace" ).invoke( *this, arguments );
}

void Throwable::setStackTrace( ::jace::JArray< ::jace::proxy::java::lang::StackTraceElement > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setStackTrace" ).invoke( *this, arguments );
}

void Throwable::addSuppressed( ::jace::proxy::java::lang::Throwable p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "addSuppressed" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::lang::Throwable > Throwable::getSuppressed() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::Throwable > >( "getSuppressed" ).invoke( *this, arguments );
}

Throwable::~Throwable() throw () {
}

const char* Throwable::what() const throw() {

  /* JACE really isn't const correct like it should be, yet.
   * For now, the easiest way to get around this is to cast constness away.
   */
  Throwable* t = const_cast<Throwable*>( this );

  /* Get the string contents of this exception.
   */
  t->msg = t->toString();

  /* Return a handle to the msg.
   */
  return t->msg.c_str();
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Throwable::Throwable( jvalue value ) Throwable_INITIALIZER {
  setJavaJniValue( value );
}

Throwable::Throwable( jobject object ) Throwable_INITIALIZER {
  setJavaJniObject( object );
}

Throwable::Throwable( const Throwable& object ) Throwable_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Throwable::Throwable( const NoOp& noOp ) Throwable_INITIALIZER {
}

const JClass* Throwable::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/lang/Throwable" );
  return &javaClass;
}

const JClass* Throwable::getJavaJniClass() const throw ( JNIException ) {
  return Throwable::staticGetJavaJniClass();
}

JEnlister< Throwable> Throwable::enlister;

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::lang::Throwable>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::Throwable( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::Throwable>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::Throwable>& proxy ) : 
    ::jace::proxy::java::lang::Throwable( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Throwable>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::Throwable( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Throwable>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::Throwable( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Throwable>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::Throwable>& object ) : 
    ::jace::proxy::java::lang::Throwable( object.getJavaJniValue() ), Object( NO_OP ) {

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

