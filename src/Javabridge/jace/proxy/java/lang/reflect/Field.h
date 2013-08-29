
#ifndef JACE_PROXY_JAVA_LANG_REFLECT_FIELD_H
#define JACE_PROXY_JAVA_LANG_REFLECT_FIELD_H

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
#ifndef JACE_PROXY_JAVA_LANG_REFLECT_MEMBER_H
#include "jace/proxy/java/lang/reflect/Member.h"
#endif

/**
 * Classes which this class is fully dependent upon.
 *
 */
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

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_5( jace, proxy, java, lang, reflect )
class Type;
END_NAMESPACE_5( jace, proxy, java, lang, reflect )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class Object;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class IllegalArgumentException;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class IllegalAccessException;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JByte;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JChar;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JShort;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JLong;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JFloat;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JDouble;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_5( jace, proxy, java, lang, annotation )
class Annotation;
END_NAMESPACE_5( jace, proxy, java, lang, annotation )

BEGIN_NAMESPACE_5( jace, proxy, java, lang, reflect )

/**
 * The Jace C++ proxy class for java/lang/reflect/Field.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class Field : public ::jace::proxy::java::lang::reflect::AccessibleObject, public virtual ::jace::proxy::java::lang::reflect::Member {

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
 * isEnumConstant
 *
 */
::jace::proxy::types::JBoolean isEnumConstant();

/**
 * isSynthetic
 *
 */
::jace::proxy::types::JBoolean isSynthetic();

/**
 * getType
 *
 */
::jace::proxy::java::lang::Class getType();

/**
 * getGenericType
 *
 */
::jace::proxy::java::lang::reflect::Type getGenericType();

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
 * get
 *
 */
::jace::proxy::java::lang::Object get( ::jace::proxy::java::lang::Object p0 );

/**
 * getBoolean
 *
 */
::jace::proxy::types::JBoolean getBoolean( ::jace::proxy::java::lang::Object p0 );

/**
 * getByte
 *
 */
::jace::proxy::types::JByte getByte( ::jace::proxy::java::lang::Object p0 );

/**
 * getChar
 *
 */
::jace::proxy::types::JChar getChar( ::jace::proxy::java::lang::Object p0 );

/**
 * getShort
 *
 */
::jace::proxy::types::JShort getShort( ::jace::proxy::java::lang::Object p0 );

/**
 * getInt
 *
 */
::jace::proxy::types::JInt getInt( ::jace::proxy::java::lang::Object p0 );

/**
 * getLong
 *
 */
::jace::proxy::types::JLong getLong( ::jace::proxy::java::lang::Object p0 );

/**
 * getFloat
 *
 */
::jace::proxy::types::JFloat getFloat( ::jace::proxy::java::lang::Object p0 );

/**
 * getDouble
 *
 */
::jace::proxy::types::JDouble getDouble( ::jace::proxy::java::lang::Object p0 );

/**
 * set
 *
 */
void set( ::jace::proxy::java::lang::Object p0, ::jace::proxy::java::lang::Object p1 );

/**
 * setBoolean
 *
 */
void setBoolean( ::jace::proxy::java::lang::Object p0, ::jace::proxy::types::JBoolean p1 );

/**
 * setByte
 *
 */
void setByte( ::jace::proxy::java::lang::Object p0, ::jace::proxy::types::JByte p1 );

/**
 * setChar
 *
 */
void setChar( ::jace::proxy::java::lang::Object p0, ::jace::proxy::types::JChar p1 );

/**
 * setShort
 *
 */
void setShort( ::jace::proxy::java::lang::Object p0, ::jace::proxy::types::JShort p1 );

/**
 * setInt
 *
 */
void setInt( ::jace::proxy::java::lang::Object p0, ::jace::proxy::types::JInt p1 );

/**
 * setLong
 *
 */
void setLong( ::jace::proxy::java::lang::Object p0, ::jace::proxy::types::JLong p1 );

/**
 * setFloat
 *
 */
void setFloat( ::jace::proxy::java::lang::Object p0, ::jace::proxy::types::JFloat p1 );

/**
 * setDouble
 *
 */
void setDouble( ::jace::proxy::java::lang::Object p0, ::jace::proxy::types::JDouble p1 );

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
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Field( jvalue value );
Field( jobject object );
Field( const Field& object );
Field( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< Field> enlister;
};

END_NAMESPACE_5( jace, proxy, java, lang, reflect )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::lang::reflect::Field>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::lang::reflect::Field>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::reflect::Field>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::lang::reflect::Field>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::reflect::Field( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::reflect::Field>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::reflect::Field>& proxy ) : 
    ::jace::proxy::java::lang::reflect::Field( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::lang::reflect::Field>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::lang::reflect::Field>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::lang::reflect::Field>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::reflect::Field>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::lang::reflect::Field>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::reflect::Field( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::reflect::Field>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::reflect::Field( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::reflect::Field>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::reflect::Field>& object ) : 
    ::jace::proxy::java::lang::reflect::Field( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_LANG_REFLECT_FIELD_H

