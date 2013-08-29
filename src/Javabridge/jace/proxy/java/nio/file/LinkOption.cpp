
#ifndef JACE_PROXY_JAVA_NIO_FILE_LINKOPTION_H
#include "jace/proxy/java/nio/file/LinkOption.h"
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

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )

/**
 * The Jace C++ proxy class source for java/nio/file/LinkOption.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define LinkOption_INITIALIZER : ::jace::proxy::java::lang::Enum( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define LinkOption_INITIALIZER : ::jace::proxy::java::lang::Enum( NO_OP )
#endif

::jace::JArray< ::jace::proxy::java::nio::file::LinkOption > LinkOption::values() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::nio::file::LinkOption > >( "values" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::nio::file::LinkOption LinkOption::valueOf( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::LinkOption >( "valueOf" ).invoke( staticGetJavaJniClass(), arguments );
}

/**
 * public static final enum NOFOLLOW_LINKS
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::nio::file::LinkOption > LinkOption::NOFOLLOW_LINKS() {
  return ::jace::JField< ::jace::proxy::java::nio::file::LinkOption >( "NOFOLLOW_LINKS" ).get( staticGetJavaJniClass() );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
LinkOption::LinkOption( jvalue value ) LinkOption_INITIALIZER {
  setJavaJniValue( value );
}

LinkOption::LinkOption( jobject object ) LinkOption_INITIALIZER {
  setJavaJniObject( object );
}

LinkOption::LinkOption( const LinkOption& object ) LinkOption_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

LinkOption::LinkOption( const NoOp& noOp ) LinkOption_INITIALIZER {
}

const JClass* LinkOption::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/file/LinkOption" );
  return &javaClass;
}

const JClass* LinkOption::getJavaJniClass() const throw ( JNIException ) {
  return LinkOption::staticGetJavaJniClass();
}

JEnlister< LinkOption> LinkOption::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::LinkOption>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::file::LinkOption( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::LinkOption>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::file::LinkOption>& proxy ) : 
    ::jace::proxy::java::nio::file::LinkOption( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::LinkOption>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::file::LinkOption( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::LinkOption>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::file::LinkOption( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::LinkOption>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::file::LinkOption>& object ) : 
    ::jace::proxy::java::nio::file::LinkOption( object.getJavaJniValue() ), Object( NO_OP ) {

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

