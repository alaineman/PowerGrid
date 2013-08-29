
#ifndef JACE_PROXY_JAVA_LANG_APPENDABLE_H
#include "jace/proxy/java/lang/Appendable.h"
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
#ifndef JACE_PROXY_JAVA_LANG_CHARSEQUENCE_H
#include "jace/proxy/java/lang/CharSequence.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_TYPES_JCHAR_H
#include "jace/proxy/types/JChar.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, lang )

/**
 * The Jace C++ proxy class source for java/lang/Appendable.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Appendable_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Appendable_INITIALIZER
#endif

::jace::proxy::java::lang::Appendable Appendable::append( ::jace::proxy::java::lang::CharSequence p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::Appendable >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Appendable Appendable::append( ::jace::proxy::java::lang::CharSequence p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::lang::Appendable >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Appendable Appendable::append( ::jace::proxy::types::JChar p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::Appendable >( "append" ).invoke( *this, arguments );
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
Appendable::Appendable() : Object( NO_OP ) { 
}

Appendable::Appendable( jvalue value ) Appendable_INITIALIZER {
  setJavaJniValue( value );
}

Appendable::Appendable( jobject object ) Appendable_INITIALIZER {
  setJavaJniObject( object );
}

Appendable::Appendable( const Appendable& object ) Appendable_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Appendable::Appendable( const NoOp& noOp ) Appendable_INITIALIZER {
}

const JClass* Appendable::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/lang/Appendable" );
  return &javaClass;
}

const JClass* Appendable::getJavaJniClass() const throw ( JNIException ) {
  return Appendable::staticGetJavaJniClass();
}

JEnlister< Appendable> Appendable::enlister;

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::lang::Appendable>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::Appendable( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::Appendable>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::Appendable>& proxy ) : 
    ::jace::proxy::java::lang::Appendable( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Appendable>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::Appendable( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Appendable>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::Appendable( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Appendable>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::Appendable>& object ) : 
    ::jace::proxy::java::lang::Appendable( object.getJavaJniValue() ), Object( NO_OP ) {

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

