
#ifndef JACE_PROXY_JAVA_LANG_STACKTRACEELEMENT_H
#include "jace/proxy/java/lang/StackTraceElement.h"
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
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, lang )

/**
 * The Jace C++ proxy class source for java/lang/StackTraceElement.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define StackTraceElement_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define StackTraceElement_INITIALIZER
#endif

StackTraceElement::StackTraceElement( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::java::lang::String p2, ::jace::proxy::types::JInt p3 ) StackTraceElement_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::java::lang::String StackTraceElement::getFileName() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getFileName" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt StackTraceElement::getLineNumber() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "getLineNumber" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String StackTraceElement::getClassName() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getClassName" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String StackTraceElement::getMethodName() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getMethodName" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean StackTraceElement::isNativeMethod() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isNativeMethod" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String StackTraceElement::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean StackTraceElement::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt StackTraceElement::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
StackTraceElement::StackTraceElement( jvalue value ) StackTraceElement_INITIALIZER {
  setJavaJniValue( value );
}

StackTraceElement::StackTraceElement( jobject object ) StackTraceElement_INITIALIZER {
  setJavaJniObject( object );
}

StackTraceElement::StackTraceElement( const StackTraceElement& object ) StackTraceElement_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

StackTraceElement::StackTraceElement( const NoOp& noOp ) StackTraceElement_INITIALIZER {
}

const JClass* StackTraceElement::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/lang/StackTraceElement" );
  return &javaClass;
}

const JClass* StackTraceElement::getJavaJniClass() const throw ( JNIException ) {
  return StackTraceElement::staticGetJavaJniClass();
}

JEnlister< StackTraceElement> StackTraceElement::enlister;

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::lang::StackTraceElement>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::StackTraceElement( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::StackTraceElement>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::StackTraceElement>& proxy ) : 
    ::jace::proxy::java::lang::StackTraceElement( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::lang::StackTraceElement>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::StackTraceElement( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::StackTraceElement>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::StackTraceElement( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::StackTraceElement>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::StackTraceElement>& object ) : 
    ::jace::proxy::java::lang::StackTraceElement( object.getJavaJniValue() ), Object( NO_OP ) {

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

