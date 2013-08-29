
#ifndef JACE_PROXY_JAVA_LANG_REFLECT_ACCESSIBLEOBJECT_H
#include "jace/proxy/java/lang/reflect/AccessibleObject.h"
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
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_SECURITYEXCEPTION_H
#include "jace/proxy/java/lang/SecurityException.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_ANNOTATION_ANNOTATION_H
#include "jace/proxy/java/lang/annotation/Annotation.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_CLASS_H
#include "jace/proxy/java/lang/Class.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, lang, reflect )

/**
 * The Jace C++ proxy class source for java/lang/reflect/AccessibleObject.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define AccessibleObject_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define AccessibleObject_INITIALIZER
#endif

void AccessibleObject::setAccessible( ::jace::JArray< ::jace::proxy::java::lang::reflect::AccessibleObject > p0, ::jace::proxy::types::JBoolean p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setAccessible" ).invoke( staticGetJavaJniClass(), arguments );
}

void AccessibleObject::setAccessible( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setAccessible" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean AccessibleObject::isAccessible() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isAccessible" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::annotation::Annotation AccessibleObject::getAnnotation( ::jace::proxy::java::lang::Class p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::annotation::Annotation >( "getAnnotation" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean AccessibleObject::isAnnotationPresent( ::jace::proxy::java::lang::Class p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isAnnotationPresent" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::lang::annotation::Annotation > AccessibleObject::getAnnotations() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::annotation::Annotation > >( "getAnnotations" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::lang::annotation::Annotation > AccessibleObject::getDeclaredAnnotations() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::annotation::Annotation > >( "getDeclaredAnnotations" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
AccessibleObject::AccessibleObject( jvalue value ) AccessibleObject_INITIALIZER {
  setJavaJniValue( value );
}

AccessibleObject::AccessibleObject( jobject object ) AccessibleObject_INITIALIZER {
  setJavaJniObject( object );
}

AccessibleObject::AccessibleObject( const AccessibleObject& object ) AccessibleObject_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

AccessibleObject::AccessibleObject( const NoOp& noOp ) AccessibleObject_INITIALIZER {
}

const JClass* AccessibleObject::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/lang/reflect/AccessibleObject" );
  return &javaClass;
}

const JClass* AccessibleObject::getJavaJniClass() const throw ( JNIException ) {
  return AccessibleObject::staticGetJavaJniClass();
}

JEnlister< AccessibleObject> AccessibleObject::enlister;

END_NAMESPACE_5( jace, proxy, java, lang, reflect )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::lang::reflect::AccessibleObject>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::reflect::AccessibleObject( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::reflect::AccessibleObject>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::reflect::AccessibleObject>& proxy ) : 
    ::jace::proxy::java::lang::reflect::AccessibleObject( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::lang::reflect::AccessibleObject>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::reflect::AccessibleObject( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::reflect::AccessibleObject>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::reflect::AccessibleObject( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::reflect::AccessibleObject>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::reflect::AccessibleObject>& object ) : 
    ::jace::proxy::java::lang::reflect::AccessibleObject( object.getJavaJniValue() ), Object( NO_OP ) {

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

