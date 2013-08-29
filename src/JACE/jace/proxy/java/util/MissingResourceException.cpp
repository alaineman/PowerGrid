
#ifndef JACE_PROXY_JAVA_UTIL_MISSINGRESOURCEEXCEPTION_H
#include "jace/proxy/java/util/MissingResourceException.h"
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
#ifndef JACE_TYPES_JVOID_H
#include "jace/proxy/types/JVoid.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, util )

/**
 * The Jace C++ proxy class source for java/util/MissingResourceException.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define MissingResourceException_INITIALIZER : ::jace::proxy::java::lang::RuntimeException( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define MissingResourceException_INITIALIZER : ::jace::proxy::java::lang::RuntimeException( NO_OP )
#endif

MissingResourceException::MissingResourceException( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::java::lang::String p2 ) MissingResourceException_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::java::lang::String MissingResourceException::getClassName() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getClassName" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String MissingResourceException::getKey() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getKey" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
MissingResourceException::MissingResourceException( jvalue value ) MissingResourceException_INITIALIZER {
  setJavaJniValue( value );
}

MissingResourceException::MissingResourceException( jobject object ) MissingResourceException_INITIALIZER {
  setJavaJniObject( object );
}

MissingResourceException::MissingResourceException( const MissingResourceException& object ) MissingResourceException_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

MissingResourceException::MissingResourceException( const NoOp& noOp ) MissingResourceException_INITIALIZER {
}

const JClass* MissingResourceException::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/util/MissingResourceException" );
  return &javaClass;
}

const JClass* MissingResourceException::getJavaJniClass() const throw ( JNIException ) {
  return MissingResourceException::staticGetJavaJniClass();
}

JEnlister< MissingResourceException> MissingResourceException::enlister;

END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::util::MissingResourceException>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::MissingResourceException( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::MissingResourceException>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::MissingResourceException>& proxy ) : 
    ::jace::proxy::java::util::MissingResourceException( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::util::MissingResourceException>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::MissingResourceException( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::MissingResourceException>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::MissingResourceException( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::MissingResourceException>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::MissingResourceException>& object ) : 
    ::jace::proxy::java::util::MissingResourceException( object.getJavaJniValue() ), Object( NO_OP ) {

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

