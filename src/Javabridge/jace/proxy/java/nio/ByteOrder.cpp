
#ifndef JACE_PROXY_JAVA_NIO_BYTEORDER_H
#include "jace/proxy/java/nio/ByteOrder.h"
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

BEGIN_NAMESPACE_4( jace, proxy, java, nio )

/**
 * The Jace C++ proxy class source for java/nio/ByteOrder.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define ByteOrder_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define ByteOrder_INITIALIZER
#endif

::jace::proxy::java::nio::ByteOrder ByteOrder::nativeOrder() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::ByteOrder >( "nativeOrder" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String ByteOrder::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

/**
 * public static final BIG_ENDIAN_Jace
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::nio::ByteOrder > ByteOrder::BIG_ENDIAN_Jace() {
  return ::jace::JField< ::jace::proxy::java::nio::ByteOrder >( "BIG_ENDIAN_Jace" ).get( staticGetJavaJniClass() );
}

/**
 * public static final LITTLE_ENDIAN_Jace
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::nio::ByteOrder > ByteOrder::LITTLE_ENDIAN_Jace() {
  return ::jace::JField< ::jace::proxy::java::nio::ByteOrder >( "LITTLE_ENDIAN_Jace" ).get( staticGetJavaJniClass() );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
ByteOrder::ByteOrder( jvalue value ) ByteOrder_INITIALIZER {
  setJavaJniValue( value );
}

ByteOrder::ByteOrder( jobject object ) ByteOrder_INITIALIZER {
  setJavaJniObject( object );
}

ByteOrder::ByteOrder( const ByteOrder& object ) ByteOrder_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

ByteOrder::ByteOrder( const NoOp& noOp ) ByteOrder_INITIALIZER {
}

const JClass* ByteOrder::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/ByteOrder" );
  return &javaClass;
}

const JClass* ByteOrder::getJavaJniClass() const throw ( JNIException ) {
  return ByteOrder::staticGetJavaJniClass();
}

JEnlister< ByteOrder> ByteOrder::enlister;

END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::ByteOrder>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::ByteOrder( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::ByteOrder>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::ByteOrder>& proxy ) : 
    ::jace::proxy::java::nio::ByteOrder( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::ByteOrder>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::ByteOrder( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::ByteOrder>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::ByteOrder( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::ByteOrder>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::ByteOrder>& object ) : 
    ::jace::proxy::java::nio::ByteOrder( object.getJavaJniValue() ), Object( NO_OP ) {

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

