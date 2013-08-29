
#ifndef JACE_PROXY_JAVA_LANG_CLASS_H
#define JACE_PROXY_JAVA_LANG_CLASS_H

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
#ifndef JACE_PROXY_JAVA_LANG_OBJECT_H
#include "jace/proxy/java/lang/Object.h"
#endif

/**
 * The interfaces implemented by this class.
 *
 */
#ifndef JACE_PROXY_JAVA_IO_SERIALIZABLE_H
#include "jace/proxy/java/io/Serializable.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_REFLECT_GENERICDECLARATION_H
#include "jace/proxy/java/lang/reflect/GenericDeclaration.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_REFLECT_TYPE_H
#include "jace/proxy/java/lang/reflect/Type.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_REFLECT_ANNOTATEDELEMENT_H
#include "jace/proxy/java/lang/reflect/AnnotatedElement.h"
#endif

/**
 * Classes which this class is fully dependent upon.
 *
 */
#ifndef JACE_PROXY_JAVA_LANG_REFLECT_TYPEVARIABLE_H
#include "jace/proxy/java/lang/reflect/TypeVariable.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_REFLECT_FIELD_H
#include "jace/proxy/java/lang/reflect/Field.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_REFLECT_METHOD_H
#include "jace/proxy/java/lang/reflect/Method.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_REFLECT_CONSTRUCTOR_H
#include "jace/proxy/java/lang/reflect/Constructor.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_ANNOTATION_ANNOTATION_H
#include "jace/proxy/java/lang/annotation/Annotation.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class ClassNotFoundException;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class ClassLoader;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class InstantiationException;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class IllegalAccessException;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class Package;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_5( jace, proxy, java, lang, reflect )
class Method;
END_NAMESPACE_5( jace, proxy, java, lang, reflect )

BEGIN_NAMESPACE_5( jace, proxy, java, lang, reflect )
class Constructor;
END_NAMESPACE_5( jace, proxy, java, lang, reflect )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class SecurityException;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_5( jace, proxy, java, lang, reflect )
class Field;
END_NAMESPACE_5( jace, proxy, java, lang, reflect )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class NoSuchFieldException;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class NoSuchMethodException;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class InputStream;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, net )
class URL;
END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE_4( jace, proxy, java, security )
class ProtectionDomain;
END_NAMESPACE_4( jace, proxy, java, security )

BEGIN_NAMESPACE_5( jace, proxy, java, lang, annotation )
class Annotation;
END_NAMESPACE_5( jace, proxy, java, lang, annotation )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )

/**
 * The Jace C++ proxy class for java/lang/Class.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class Class : public virtual ::jace::proxy::java::lang::Object, public virtual ::jace::proxy::java::io::Serializable, public virtual ::jace::proxy::java::lang::reflect::GenericDeclaration, public virtual ::jace::proxy::java::lang::reflect::Type, public virtual ::jace::proxy::java::lang::reflect::AnnotatedElement {

public: 

/**
 * toString
 *
 */
::jace::proxy::java::lang::String toString();

/**
 * forName
 *
 */
static ::jace::proxy::java::lang::Class forName( ::jace::proxy::java::lang::String p0 );

/**
 * forName
 *
 */
static ::jace::proxy::java::lang::Class forName( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JBoolean p1, ::jace::proxy::java::lang::ClassLoader p2 );

/**
 * newInstance
 *
 */
::jace::proxy::java::lang::Object newInstance();

/**
 * isInstance
 *
 */
::jace::proxy::types::JBoolean isInstance( ::jace::proxy::java::lang::Object p0 );

/**
 * isAssignableFrom
 *
 */
::jace::proxy::types::JBoolean isAssignableFrom( ::jace::proxy::java::lang::Class p0 );

/**
 * isInterface
 *
 */
::jace::proxy::types::JBoolean isInterface();

/**
 * isArray
 *
 */
::jace::proxy::types::JBoolean isArray();

/**
 * isPrimitive
 *
 */
::jace::proxy::types::JBoolean isPrimitive();

/**
 * isAnnotation
 *
 */
::jace::proxy::types::JBoolean isAnnotation();

/**
 * isSynthetic
 *
 */
::jace::proxy::types::JBoolean isSynthetic();

/**
 * getName
 *
 */
::jace::proxy::java::lang::String getName();

/**
 * getClassLoader
 *
 */
::jace::proxy::java::lang::ClassLoader getClassLoader();

/**
 * getTypeParameters
 *
 */
::jace::JArray< ::jace::proxy::java::lang::reflect::TypeVariable > getTypeParameters();

/**
 * getSuperclass
 *
 */
::jace::proxy::java::lang::Class getSuperclass();

/**
 * getGenericSuperclass
 *
 */
::jace::proxy::java::lang::reflect::Type getGenericSuperclass();

/**
 * getPackage
 *
 */
::jace::proxy::java::lang::Package getPackage();

/**
 * getInterfaces
 *
 */
::jace::JArray< ::jace::proxy::java::lang::Class > getInterfaces();

/**
 * getGenericInterfaces
 *
 */
::jace::JArray< ::jace::proxy::java::lang::reflect::Type > getGenericInterfaces();

/**
 * getComponentType
 *
 */
::jace::proxy::java::lang::Class getComponentType();

/**
 * getModifiers
 *
 */
::jace::proxy::types::JInt getModifiers();

/**
 * getSigners
 *
 */
::jace::JArray< ::jace::proxy::java::lang::Object > getSigners();

/**
 * getEnclosingMethod
 *
 */
::jace::proxy::java::lang::reflect::Method getEnclosingMethod();

/**
 * getEnclosingConstructor
 *
 */
::jace::proxy::java::lang::reflect::Constructor getEnclosingConstructor();

/**
 * getDeclaringClass
 *
 */
::jace::proxy::java::lang::Class getDeclaringClass();

/**
 * getEnclosingClass
 *
 */
::jace::proxy::java::lang::Class getEnclosingClass();

/**
 * getSimpleName
 *
 */
::jace::proxy::java::lang::String getSimpleName();

/**
 * getCanonicalName
 *
 */
::jace::proxy::java::lang::String getCanonicalName();

/**
 * isAnonymousClass
 *
 */
::jace::proxy::types::JBoolean isAnonymousClass();

/**
 * isLocalClass
 *
 */
::jace::proxy::types::JBoolean isLocalClass();

/**
 * isMemberClass
 *
 */
::jace::proxy::types::JBoolean isMemberClass();

/**
 * getClasses
 *
 */
::jace::JArray< ::jace::proxy::java::lang::Class > getClasses();

/**
 * getFields
 *
 */
::jace::JArray< ::jace::proxy::java::lang::reflect::Field > getFields();

/**
 * getMethods
 *
 */
::jace::JArray< ::jace::proxy::java::lang::reflect::Method > getMethods();

/**
 * getConstructors
 *
 */
::jace::JArray< ::jace::proxy::java::lang::reflect::Constructor > getConstructors();

/**
 * getField
 *
 */
::jace::proxy::java::lang::reflect::Field getField( ::jace::proxy::java::lang::String p0 );

/**
 * getMethod
 *
 */
::jace::proxy::java::lang::reflect::Method getMethod( ::jace::proxy::java::lang::String p0, ::jace::JArray< ::jace::proxy::java::lang::Class > p1 );

/**
 * getConstructor
 *
 */
::jace::proxy::java::lang::reflect::Constructor getConstructor( ::jace::JArray< ::jace::proxy::java::lang::Class > p0 );

/**
 * getDeclaredClasses
 *
 */
::jace::JArray< ::jace::proxy::java::lang::Class > getDeclaredClasses();

/**
 * getDeclaredFields
 *
 */
::jace::JArray< ::jace::proxy::java::lang::reflect::Field > getDeclaredFields();

/**
 * getDeclaredMethods
 *
 */
::jace::JArray< ::jace::proxy::java::lang::reflect::Method > getDeclaredMethods();

/**
 * getDeclaredConstructors
 *
 */
::jace::JArray< ::jace::proxy::java::lang::reflect::Constructor > getDeclaredConstructors();

/**
 * getDeclaredField
 *
 */
::jace::proxy::java::lang::reflect::Field getDeclaredField( ::jace::proxy::java::lang::String p0 );

/**
 * getDeclaredMethod
 *
 */
::jace::proxy::java::lang::reflect::Method getDeclaredMethod( ::jace::proxy::java::lang::String p0, ::jace::JArray< ::jace::proxy::java::lang::Class > p1 );

/**
 * getDeclaredConstructor
 *
 */
::jace::proxy::java::lang::reflect::Constructor getDeclaredConstructor( ::jace::JArray< ::jace::proxy::java::lang::Class > p0 );

/**
 * getResourceAsStream
 *
 */
::jace::proxy::java::io::InputStream getResourceAsStream( ::jace::proxy::java::lang::String p0 );

/**
 * getResource
 *
 */
::jace::proxy::java::net::URL getResource( ::jace::proxy::java::lang::String p0 );

/**
 * getProtectionDomain
 *
 */
::jace::proxy::java::security::ProtectionDomain getProtectionDomain();

/**
 * desiredAssertionStatus
 *
 */
::jace::proxy::types::JBoolean desiredAssertionStatus();

/**
 * isEnum
 *
 */
::jace::proxy::types::JBoolean isEnum();

/**
 * getEnumConstants
 *
 */
::jace::JArray< ::jace::proxy::java::lang::Object > getEnumConstants();

/**
 * cast
 *
 */
::jace::proxy::java::lang::Object cast( ::jace::proxy::java::lang::Object p0 );

/**
 * asSubclass
 *
 */
::jace::proxy::java::lang::Class asSubclass( ::jace::proxy::java::lang::Class p0 );

/**
 * getAnnotation
 *
 */
::jace::proxy::java::lang::annotation::Annotation getAnnotation( ::jace::proxy::java::lang::Class p0 );

/**
 * isAnnotationPresent
 *
 */
::jace::proxy::types::JBoolean isAnnotationPresent( ::jace::proxy::java::lang::Class p0 );

/**
 * getAnnotations
 *
 */
::jace::JArray< ::jace::proxy::java::lang::annotation::Annotation > getAnnotations();

/**
 * getDeclaredAnnotations
 *
 */
::jace::JArray< ::jace::proxy::java::lang::annotation::Annotation > getDeclaredAnnotations();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Class( jvalue value );
Class( jobject object );
Class( const Class& object );
Class( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< Class> enlister;
};

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::lang::Class>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::lang::Class>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::Class>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::lang::Class>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::Class( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::Class>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::Class>& proxy ) : 
    ::jace::proxy::java::lang::Class( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::lang::Class>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::lang::Class>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::lang::Class>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::Class>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Class>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::Class( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Class>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::Class( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Class>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::Class>& object ) : 
    ::jace::proxy::java::lang::Class( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_LANG_CLASS_H

