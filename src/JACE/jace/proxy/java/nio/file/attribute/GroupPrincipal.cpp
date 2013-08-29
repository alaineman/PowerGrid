
#ifndef JACE_PROXY_JAVA_NIO_FILE_ATTRIBUTE_GROUPPRINCIPAL_H
#include "jace/proxy/java/nio/file/attribute/GroupPrincipal.h"
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
 * The Jace C++ proxy class source for java/nio/file/attribute/GroupPrincipal.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define GroupPrincipal_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define GroupPrincipal_INITIALIZER
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
GroupPrincipal::GroupPrincipal() : Object( NO_OP ) { 
}

GroupPrincipal::GroupPrincipal( jvalue value ) GroupPrincipal_INITIALIZER {
  setJavaJniValue( value );
}

GroupPrincipal::GroupPrincipal( jobject object ) GroupPrincipal_INITIALIZER {
  setJavaJniObject( object );
}

GroupPrincipal::GroupPrincipal( const GroupPrincipal& object ) GroupPrincipal_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

GroupPrincipal::GroupPrincipal( const NoOp& noOp ) GroupPrincipal_INITIALIZER {
}

const JClass* GroupPrincipal::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/file/attribute/GroupPrincipal" );
  return &javaClass;
}

const JClass* GroupPrincipal::getJavaJniClass() const throw ( JNIException ) {
  return GroupPrincipal::staticGetJavaJniClass();
}

JEnlister< GroupPrincipal> GroupPrincipal::enlister;

END_NAMESPACE_6( jace, proxy, java, nio, file, attribute )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::attribute::GroupPrincipal>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::file::attribute::GroupPrincipal( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::attribute::GroupPrincipal>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::file::attribute::GroupPrincipal>& proxy ) : 
    ::jace::proxy::java::nio::file::attribute::GroupPrincipal( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::attribute::GroupPrincipal>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::file::attribute::GroupPrincipal( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::attribute::GroupPrincipal>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::file::attribute::GroupPrincipal( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::attribute::GroupPrincipal>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::file::attribute::GroupPrincipal>& object ) : 
    ::jace::proxy::java::nio::file::attribute::GroupPrincipal( object.getJavaJniValue() ), Object( NO_OP ) {

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

