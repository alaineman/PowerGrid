
#ifndef JACE_PROXY_JAVA_LANG_REFLECT_METHOD_H
#define JACE_PROXY_JAVA_LANG_REFLECT_METHOD_H

#ifndef JACE_OS_DEP_H
#include "jace/os_dep.h"
#endif

#ifndef JACE_NAMESPACE_H
#include "jace/namespace.h"
#endif

#ifndef JACE_JOBJECT_H
#include "jace/proxy/JObject.h"
#endif

#ifndef JACE_JENLISTER_H
#include "jace/JEnlister.h"
#endif

#ifndef JACE_JARRAY_H
#include "jace/JArray.h"
#endif

#ifndef JACE_JFIELD_PROXY_H
#include "jace/JFieldProxy.h"
#endif

/**
 * The super class for this class.
 *
 */
#ifndef JACE_PROXY_JAVA_LANG_REFLECT_ACCESSIBLEOBJECT_H
#include "jace/proxy/java/lang/reflect/AccessibleObject.h"
#endif

/**
 * The interfaces implemented by this class.
 *
 */
#ifndef JACE_PROXY_JAVA_LANG_REFLECT_GENERICDECLARATION_H
#include "jace/proxy/java/lang/reflect/GenericDeclaration.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_REFLECT_MEMBER_H
#include "jace/proxy/java/lang/reflect/Member.h"
#endif

/**
 * Classes which this class is fully dependent upon.
 *
 */
#ifndef JACE_PROXY_JAVA_LANG_REFLECT_TYPEVARIABLE_H
#include "jace/proxy/java/lang/reflect/TypeVariable.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_CLASS_H
#include "jace/proxy/java/lang/Class.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_REFLECT_TYPE_H
#include "jace/proxy/java/lang/reflect/Type.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_OBJECT_H
#include "jace/proxy/java/lang/Object.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_ANNOTATION_ANNOTATION_H
#include "jace/proxy/java/lang/annotation/Annotation.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class Class;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_5( jace, proxy, java, lang, reflect )
class Type;
END_NAMESPACE_5( jace, proxy, java, lang, reflect )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class Object;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class IllegalAccessException;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class IllegalArgumentException;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_5( jace, proxy, java, lang, reflect )
class InvocationTargetException;
END_NAMESPACE_5( jace, proxy, java, lang, reflect )

BEGIN_NAMESPACE_5( jace, proxy, java, lang, annotation )
class Annotation;
END_NAMESPACE_5( jace, proxy, java, lang, annotation )

BEGIN_NAMESPACE_5( jace, proxy, java, lang, reflect )

/**
 * The Jace C++ proxy class for java/lang/reflect/Method.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class Method : public ::jace::proxy::java::lang::reflect::AccessibleObject, public virtual ::jace::proxy::java::lang::reflect::GenericDeclaration, public virtual ::jace::proxy::java::lang::reflect::Member {

public: 

/**
 * getDeclaringClass
 *
 */
::jace::proxy::java::lang::Class getDeclaringClass();

/**
 * getName
 *
 */
::jace::proxy::java::lang::String getName();

/**
 * getModifiers
 *
 */
::jace::proxy::types::JInt getModifiers();

/**
 * getTypeParameters
 *
 */
::jace::JArray< ::jace::proxy::java::lang::reflect::TypeVariable > getTypeParameters();

/**
 * getReturnType
 *
 */
::jace::proxy::java::lang::Class getReturnType();

/**
 * getGenericReturnType
 *
 */
::jace::proxy::java::lang::reflect::Type getGenericReturnType();

/**
 * getParameterTypes
 *
 */
::jace::JArray< ::jace::proxy::java::lang::Class > getParameterTypes();

/**
 * getGenericParameterTypes
 *
 */
::jace::JArray< ::jace::proxy::java::lang::reflect::Type > getGenericParameterTypes();

/**
 * getExceptionTypes
 *
 */
::jace::JArray< ::jace::proxy::java::lang::Class > getExceptionTypes();

/**
 * getGenericExceptionTypes
 *
 */
::jace::JArray< ::jace::proxy::java::lang::reflect::Type > getGenericExceptionTypes();

/**
 * equals
 *
 */
::jace::proxy::types::JBoolean equals( ::jace::proxy::java::lang::Object p0 );

/**
 * hashCode
 *
 */
::jace::proxy::types::JInt hashCode();

/**
 * toString
 *
 */
::jace::proxy::java::lang::String toString();

/**
 * toGenericString
 *
 */
::jace::proxy::java::lang::String toGenericString();

/**
 * invoke
 *
 */
::jace::proxy::java::lang::Object invoke( ::jace::proxy::java::lang::Object p0, ::jace::JArray< ::jace::proxy::java::lang::Object > p1 );

/**
 * isBridge
 *
 */
::jace::proxy::types::JBoolean isBridge();

/**
 * isVarArgs
 *
 */
::jace::proxy::types::JBoolean isVarArgs();

/**
 * isSynthetic
 *
 */
::jace::proxy::types::JBoolean isSynthetic();

/**
 * getAnnotation
 *
 */
::jace::proxy::java::lang::annotation::Annotation getAnnotation( ::jace::proxy::java::lang::Class p0 );

/**
 * getDeclaredAnnotations
 *
 */
::jace::JArray< ::jace::proxy::java::lang::annotation::Annotation > getDeclaredAnnotations();

/**
 * getDefaultValue
 *
 */
::jace::proxy::java::lang::Object getDefaultValue();

/**
 * getParameterAnnotations
 *
 */
::jace::JArray< ::jace::JArray< ::jace::proxy::java::lang::annotation::Annotation > > getParameterAnnotations();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Method( jvalue value );
Method( jobject object );
Method( const Method& object );
Method( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< Method> enlister;
};

END_NAMESPACE_5( jace, proxy, java, lang, reflect )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::lang::reflect::Method>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::lang::reflect::Method>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::reflect::Method>& proxy );
#else
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
  template <> JFieldProxy< ::jace::proxy::java::lang::reflect::Method>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::lang::reflect::Method>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::lang::reflect::Method>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::reflect::Method>& object );
#else
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

#endif // #ifndef JACE_PROXY_JAVA_LANG_REFLECT_METHOD_H

