
#ifndef JACE_PROXY_JAVA_LANG_REFLECT_TYPEVARIABLE_H
#include "jace/proxy/java/lang/reflect/TypeVariable.h"
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
#ifndef JACE_PROXY_JAVA_LANG_REFLECT_GENERICDECLARATION_H
#include "jace/proxy/java/lang/reflect/GenericDeclaration.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, lang, reflect )

/**
 * The Jace C++ proxy class source for java/lang/reflect/TypeVariable.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define TypeVariable_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define TypeVariable_INITIALIZER
#endif

::jace::JArray< ::jace::proxy::java::lang::reflect::Type > TypeVariable::getBounds() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::reflect::Type > >( "getBounds" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::reflect::GenericDeclaration TypeVariable::getGenericDeclaration() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::reflect::GenericDeclaration >( "getGenericDeclaration" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String TypeVariable::getName() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getName" ).invoke( *this, arguments );
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
TypeVariable::TypeVariable() : Object( NO_OP ) { 
}

TypeVariable::TypeVariable( jvalue value ) TypeVariable_INITIALIZER {
  setJavaJniValue( value );
}

TypeVariable::TypeVariable( jobject object ) TypeVariable_INITIALIZER {
  setJavaJniObject( object );
}

TypeVariable::TypeVariable( const TypeVariable& object ) TypeVariable_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

TypeVariable::TypeVariable( const NoOp& noOp ) TypeVariable_INITIALIZER {
}

const JClass* TypeVariable::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/lang/reflect/TypeVariable" );
  return &javaClass;
}

const JClass* TypeVariable::getJavaJniClass() const throw ( JNIException ) {
  return TypeVariable::staticGetJavaJniClass();
}

JEnlister< TypeVariable> TypeVariable::enlister;

END_NAMESPACE_5( jace, proxy, java, lang, reflect )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::lang::reflect::TypeVariable>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::reflect::TypeVariable( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::reflect::TypeVariable>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::reflect::TypeVariable>& proxy ) : 
    ::jace::proxy::java::lang::reflect::TypeVariable( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::lang::reflect::TypeVariable>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::reflect::TypeVariable( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::reflect::TypeVariable>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::reflect::TypeVariable( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::reflect::TypeVariable>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::reflect::TypeVariable>& object ) : 
    ::jace::proxy::java::lang::reflect::TypeVariable( object.getJavaJniValue() ), Object( NO_OP ) {

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

