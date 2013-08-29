
#ifndef JACE_PROXY_JAVA_NIO_FILE_ATTRIBUTE_USERPRINCIPAL_H
#include "jace/proxy/java/nio/file/attribute/UserPrincipal.h"
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

BEGIN_NAMESPACE_6( jace, proxy, java, nio, file, attribute )

/**
 * The Jace C++ proxy class source for java/nio/file/attribute/UserPrincipal.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define UserPrincipal_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define UserPrincipal_INITIALIZER
#endif

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
/**
 * Special no arg constructor for interface virtual inheritance
 *
 */
UserPrincipal::UserPrincipal() : Object( NO_OP ) { 
}

UserPrincipal::UserPrincipal( jvalue value ) UserPrincipal_INITIALIZER {
  setJavaJniValue( value );
}

UserPrincipal::UserPrincipal( jobject object ) UserPrincipal_INITIALIZER {
  setJavaJniObject( object );
}

UserPrincipal::UserPrincipal( const UserPrincipal& object ) UserPrincipal_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

UserPrincipal::UserPrincipal( const NoOp& noOp ) UserPrincipal_INITIALIZER {
}

const JClass* UserPrincipal::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/file/attribute/UserPrincipal" );
  return &javaClass;
}

const JClass* UserPrincipal::getJavaJniClass() const throw ( JNIException ) {
  return UserPrincipal::staticGetJavaJniClass();
}

JEnlister< UserPrincipal> UserPrincipal::enlister;

END_NAMESPACE_6( jace, proxy, java, nio, file, attribute )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::attribute::UserPrincipal>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::file::attribute::UserPrincipal( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::attribute::UserPrincipal>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::file::attribute::UserPrincipal>& proxy ) : 
    ::jace::proxy::java::nio::file::attribute::UserPrincipal( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::attribute::UserPrincipal>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::file::attribute::UserPrincipal( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::attribute::UserPrincipal>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::file::attribute::UserPrincipal( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::attribute::UserPrincipal>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::file::attribute::UserPrincipal>& object ) : 
    ::jace::proxy::java::nio::file::attribute::UserPrincipal( object.getJavaJniValue() ), Object( NO_OP ) {

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

