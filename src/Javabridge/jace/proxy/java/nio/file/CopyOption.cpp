
#ifndef JACE_PROXY_JAVA_NIO_FILE_COPYOPTION_H
#include "jace/proxy/java/nio/file/CopyOption.h"
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

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )

/**
 * The Jace C++ proxy class source for java/nio/file/CopyOption.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define CopyOption_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define CopyOption_INITIALIZER
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
CopyOption::CopyOption() : Object( NO_OP ) { 
}

CopyOption::CopyOption( jvalue value ) CopyOption_INITIALIZER {
  setJavaJniValue( value );
}

CopyOption::CopyOption( jobject object ) CopyOption_INITIALIZER {
  setJavaJniObject( object );
}

CopyOption::CopyOption( const CopyOption& object ) CopyOption_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

CopyOption::CopyOption( const NoOp& noOp ) CopyOption_INITIALIZER {
}

const JClass* CopyOption::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/file/CopyOption" );
  return &javaClass;
}

const JClass* CopyOption::getJavaJniClass() const throw ( JNIException ) {
  return CopyOption::staticGetJavaJniClass();
}

JEnlister< CopyOption> CopyOption::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::CopyOption>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::file::CopyOption( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::CopyOption>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::file::CopyOption>& proxy ) : 
    ::jace::proxy::java::nio::file::CopyOption( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::CopyOption>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::file::CopyOption( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::CopyOption>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::file::CopyOption( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::CopyOption>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::file::CopyOption>& object ) : 
    ::jace::proxy::java::nio::file::CopyOption( object.getJavaJniValue() ), Object( NO_OP ) {

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

