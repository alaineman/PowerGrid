
#ifndef JACE_PROXY_JAVA_LANG_REFLECT_MEMBER_H
#include "jace/proxy/java/lang/reflect/Member.h"
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
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, lang, reflect )

/**
 * The Jace C++ proxy class source for java/lang/reflect/Member.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Member_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Member_INITIALIZER
#endif

::jace::proxy::java::lang::Class Member::getDeclaringClass() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Class >( "getDeclaringClass" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Member::getName() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getName" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt Member::getModifiers() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "getModifiers" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Member::isSynthetic() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isSynthetic" ).invoke( *this, arguments );
}

/**
 * public static final PUBLIC
 *
 */
::jace::JFieldProxy< ::jace::proxy::types::JInt > Member::PUBLIC() {
  return ::jace::JField< ::jace::proxy::types::JInt >( "PUBLIC" ).get( staticGetJavaJniClass() );
}

/**
 * public static final DECLARED
 *
 */
::jace::JFieldProxy< ::jace::proxy::types::JInt > Member::DECLARED() {
  return ::jace::JField< ::jace::proxy::types::JInt >( "DECLARED" ).get( staticGetJavaJniClass() );
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
Member::Member() : Object( NO_OP ) { 
}

Member::Member( jvalue value ) Member_INITIALIZER {
  setJavaJniValue( value );
}

Member::Member( jobject object ) Member_INITIALIZER {
  setJavaJniObject( object );
}

Member::Member( const Member& object ) Member_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Member::Member( const NoOp& noOp ) Member_INITIALIZER {
}

const JClass* Member::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/lang/reflect/Member" );
  return &javaClass;
}

const JClass* Member::getJavaJniClass() const throw ( JNIException ) {
  return Member::staticGetJavaJniClass();
}

JEnlister< Member> Member::enlister;

END_NAMESPACE_5( jace, proxy, java, lang, reflect )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::lang::reflect::Member>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::reflect::Member( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::reflect::Member>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::reflect::Member>& proxy ) : 
    ::jace::proxy::java::lang::reflect::Member( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::lang::reflect::Member>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::reflect::Member( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::reflect::Member>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::reflect::Member( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::reflect::Member>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::reflect::Member>& object ) : 
    ::jace::proxy::java::lang::reflect::Member( object.getJavaJniValue() ), Object( NO_OP ) {

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

