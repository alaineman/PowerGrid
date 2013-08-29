
#ifndef JACE_PROXY_JAVA_NIO_CHARSET_CODINGERRORACTION_H
#include "jace/proxy/java/nio/charset/CodingErrorAction.h"
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
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, nio, charset )

/**
 * The Jace C++ proxy class source for java/nio/charset/CodingErrorAction.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define CodingErrorAction_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define CodingErrorAction_INITIALIZER
#endif

::jace::proxy::java::lang::String CodingErrorAction::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

/**
 * public static final IGNORE
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::nio::charset::CodingErrorAction > CodingErrorAction::IGNORE() {
  return ::jace::JField< ::jace::proxy::java::nio::charset::CodingErrorAction >( "IGNORE" ).get( staticGetJavaJniClass() );
}

/**
 * public static final REPLACE
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::nio::charset::CodingErrorAction > CodingErrorAction::REPLACE() {
  return ::jace::JField< ::jace::proxy::java::nio::charset::CodingErrorAction >( "REPLACE" ).get( staticGetJavaJniClass() );
}

/**
 * public static final REPORT
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::nio::charset::CodingErrorAction > CodingErrorAction::REPORT() {
  return ::jace::JField< ::jace::proxy::java::nio::charset::CodingErrorAction >( "REPORT" ).get( staticGetJavaJniClass() );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
CodingErrorAction::CodingErrorAction( jvalue value ) CodingErrorAction_INITIALIZER {
  setJavaJniValue( value );
}

CodingErrorAction::CodingErrorAction( jobject object ) CodingErrorAction_INITIALIZER {
  setJavaJniObject( object );
}

CodingErrorAction::CodingErrorAction( const CodingErrorAction& object ) CodingErrorAction_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

CodingErrorAction::CodingErrorAction( const NoOp& noOp ) CodingErrorAction_INITIALIZER {
}

const JClass* CodingErrorAction::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/charset/CodingErrorAction" );
  return &javaClass;
}

const JClass* CodingErrorAction::getJavaJniClass() const throw ( JNIException ) {
  return CodingErrorAction::staticGetJavaJniClass();
}

JEnlister< CodingErrorAction> CodingErrorAction::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, charset )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::charset::CodingErrorAction>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::charset::CodingErrorAction( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::charset::CodingErrorAction>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::charset::CodingErrorAction>& proxy ) : 
    ::jace::proxy::java::nio::charset::CodingErrorAction( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::charset::CodingErrorAction>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::charset::CodingErrorAction( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::charset::CodingErrorAction>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::charset::CodingErrorAction( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::charset::CodingErrorAction>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::charset::CodingErrorAction>& object ) : 
    ::jace::proxy::java::nio::charset::CodingErrorAction( object.getJavaJniValue() ), Object( NO_OP ) {

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

