
#ifndef JACE_PROXY_JAVA_NIO_FILE_OPENOPTION_H
#include "jace/proxy/java/nio/file/OpenOption.h"
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
 * The Jace C++ proxy class source for java/nio/file/OpenOption.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define OpenOption_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define OpenOption_INITIALIZER
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
OpenOption::OpenOption() : Object( NO_OP ) { 
}

OpenOption::OpenOption( jvalue value ) OpenOption_INITIALIZER {
  setJavaJniValue( value );
}

OpenOption::OpenOption( jobject object ) OpenOption_INITIALIZER {
  setJavaJniObject( object );
}

OpenOption::OpenOption( const OpenOption& object ) OpenOption_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

OpenOption::OpenOption( const NoOp& noOp ) OpenOption_INITIALIZER {
}

const JClass* OpenOption::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/file/OpenOption" );
  return &javaClass;
}

const JClass* OpenOption::getJavaJniClass() const throw ( JNIException ) {
  return OpenOption::staticGetJavaJniClass();
}

JEnlister< OpenOption> OpenOption::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::OpenOption>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::file::OpenOption( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::OpenOption>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::file::OpenOption>& proxy ) : 
    ::jace::proxy::java::nio::file::OpenOption( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::OpenOption>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::file::OpenOption( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::OpenOption>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::file::OpenOption( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::OpenOption>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::file::OpenOption>& object ) : 
    ::jace::proxy::java::nio::file::OpenOption( object.getJavaJniValue() ), Object( NO_OP ) {

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

