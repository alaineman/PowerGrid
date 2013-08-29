
#ifndef JACE_PROXY_JAVA_LANG_CHARSEQUENCE_H
#include "jace/proxy/java/lang/CharSequence.h"
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
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_TYPES_JCHAR_H
#include "jace/proxy/types/JChar.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, lang )

/**
 * The Jace C++ proxy class source for java/lang/CharSequence.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define CharSequence_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define CharSequence_INITIALIZER
#endif

::jace::proxy::types::JInt CharSequence::length() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "length" ).invoke( *this, arguments );
}

::jace::proxy::types::JChar CharSequence::charAt( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JChar >( "charAt" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::CharSequence CharSequence::subSequence( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::CharSequence >( "subSequence" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String CharSequence::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
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
CharSequence::CharSequence() : Object( NO_OP ) { 
}

CharSequence::CharSequence( jvalue value ) CharSequence_INITIALIZER {
  setJavaJniValue( value );
}

CharSequence::CharSequence( jobject object ) CharSequence_INITIALIZER {
  setJavaJniObject( object );
}

CharSequence::CharSequence( const CharSequence& object ) CharSequence_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

CharSequence::CharSequence( const NoOp& noOp ) CharSequence_INITIALIZER {
}

const JClass* CharSequence::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/lang/CharSequence" );
  return &javaClass;
}

const JClass* CharSequence::getJavaJniClass() const throw ( JNIException ) {
  return CharSequence::staticGetJavaJniClass();
}

JEnlister< CharSequence> CharSequence::enlister;

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::lang::CharSequence>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::CharSequence( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::CharSequence>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::CharSequence>& proxy ) : 
    ::jace::proxy::java::lang::CharSequence( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::lang::CharSequence>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::CharSequence( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::CharSequence>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::CharSequence( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::CharSequence>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::CharSequence>& object ) : 
    ::jace::proxy::java::lang::CharSequence( object.getJavaJniValue() ), Object( NO_OP ) {

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

