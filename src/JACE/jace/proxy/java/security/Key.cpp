
#ifndef JACE_PROXY_JAVA_SECURITY_KEY_H
#include "jace/proxy/java/security/Key.h"
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

BEGIN_NAMESPACE_4( jace, proxy, java, security )

/**
 * The Jace C++ proxy class source for java/security/Key.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Key_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Key_INITIALIZER
#endif

::jace::proxy::java::lang::String Key::getAlgorithm() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getAlgorithm" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Key::getFormat() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getFormat" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::types::JByte > Key::getEncoded() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::types::JByte > >( "getEncoded" ).invoke( *this, arguments );
}

/**
 * public static final serialVersionUID
 *
 */
::jace::JFieldProxy< ::jace::proxy::types::JLong > Key::serialVersionUID() {
  return ::jace::JField< ::jace::proxy::types::JLong >( "serialVersionUID" ).get( staticGetJavaJniClass() );
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
Key::Key() : Object( NO_OP ) { 
}

Key::Key( jvalue value ) Key_INITIALIZER {
  setJavaJniValue( value );
}

Key::Key( jobject object ) Key_INITIALIZER {
  setJavaJniObject( object );
}

Key::Key( const Key& object ) Key_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Key::Key( const NoOp& noOp ) Key_INITIALIZER {
}

const JClass* Key::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/security/Key" );
  return &javaClass;
}

const JClass* Key::getJavaJniClass() const throw ( JNIException ) {
  return Key::staticGetJavaJniClass();
}

JEnlister< Key> Key::enlister;

END_NAMESPACE_4( jace, proxy, java, security )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::security::Key>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::security::Key( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::security::Key>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::security::Key>& proxy ) : 
    ::jace::proxy::java::security::Key( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::security::Key>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::security::Key( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::Key>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::security::Key( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::Key>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::security::Key>& object ) : 
    ::jace::proxy::java::security::Key( object.getJavaJniValue() ), Object( NO_OP ) {

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

