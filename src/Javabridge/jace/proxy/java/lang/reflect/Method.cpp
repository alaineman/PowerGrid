
#ifndef JACE_PROXY_JAVA_LANG_REFLECT_METHOD_H
#include "jace/proxy/java/lang/reflect/Method.h"
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
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_REFLECT_TYPE_H
#include "jace/proxy/java/lang/reflect/Type.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_OBJECT_H
#include "jace/proxy/java/lang/Object.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_ILLEGALACCESSEXCEPTION_H
#include "jace/proxy/java/lang/IllegalAccessException.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_ILLEGALARGUMENTEXCEPTION_H
#include "jace/proxy/java/lang/IllegalArgumentException.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_REFLECT_INVOCATIONTARGETEXCEPTION_H
#include "jace/proxy/java/lang/reflect/InvocationTargetException.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_ANNOTATION_ANNOTATION_H
#include "jace/proxy/java/lang/annotation/Annotation.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, lang, reflect )

/**
 * The Jace C++ proxy class source for java/lang/reflect/Method.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Method_INITIALIZER : ::jace::proxy::java::lang::reflect::AccessibleObject( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Method_INITIALIZER : ::jace::proxy::java::lang::reflect::AccessibleObject( NO_OP )
#endif

::jace::proxy::java::lang::Class Method::getDeclaringClass() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Class >( "getDeclaringClass" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Method::getName() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getName" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt Method::getModifiers() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "getModifiers" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::lang::reflect::TypeVariable > Method::getTypeParameters() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::reflect::TypeVariable > >( "getTypeParameters" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Class Method::getReturnType() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Class >( "getReturnType" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::reflect::Type Method::getGenericReturnType() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::reflect::Type >( "getGenericReturnType" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::lang::Class > Method::getParameterTypes() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::Class > >( "getParameterTypes" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::lang::reflect::Type > Method::getGenericParameterTypes() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::reflect::Type > >( "getGenericParameterTypes" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::lang::Class > Method::getExceptionTypes() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::Class > >( "getExceptionTypes" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::lang::reflect::Type > Method::getGenericExceptionTypes() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::reflect::Type > >( "getGenericExceptionTypes" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Method::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt Method::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Method::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Method::toGenericString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toGenericString" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object Method::invoke( ::jace::proxy::java::lang::Object p0, ::jace::JArray< ::jace::proxy::java::lang::Object > p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "invoke" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Method::isBridge() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isBridge" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Method::isVarArgs() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isVarArgs" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Method::isSynthetic() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isSynthetic" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::annotation::Annotation Method::getAnnotation( ::jace::proxy::java::lang::Class p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::annotation::Annotation >( "getAnnotation" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::lang::annotation::Annotation > Method::getDeclaredAnnotations() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::annotation::Annotation > >( "getDeclaredAnnotations" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object Method::getDefaultValue() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "getDefaultValue" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::JArray< ::jace::proxy::java::lang::annotation::Annotation > > Method::getParameterAnnotations() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::JArray< ::jace::proxy::java::lang::annotation::Annotation > > >( "getParameterAnnotations" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Method::Method( jvalue value ) Method_INITIALIZER {
  setJavaJniValue( value );
}

Method::Method( jobject object ) Method_INITIALIZER {
  setJavaJniObject( object );
}

Method::Method( const Method& object ) Method_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Method::Method( const NoOp& noOp ) Method_INITIALIZER {
}

const JClass* Method::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/lang/reflect/Method" );
  return &javaClass;
}

const JClass* Method::getJavaJniClass() const throw ( JNIException ) {
  return Method::staticGetJavaJniClass();
}

JEnlister< Method> Method::enlister;

END_NAMESPACE_5( jace, proxy, java, lang, reflect )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::lang::reflect::Method>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::reflect::Method( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::reflect::Method>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::reflect::Method>& proxy ) : 
    ::jace::proxy::java::lang::reflect::Method( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::lang::reflect::Method>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::reflect::Method( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::reflect::Method>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::reflect::Method( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::reflect::Method>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::reflect::Method>& object ) : 
    ::jace::proxy::java::lang::reflect::Method( object.getJavaJniValue() ), Object( NO_OP ) {

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

