
#ifndef JACE_PROXY_JAVA_LANG_ILLEGALARGUMENTEXCEPTION_H
#include "jace/proxy/java/lang/IllegalArgumentException.h"
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
#ifndef JACE_PROXY_JAVA_LANG_THROWABLE_H
#include "jace/proxy/java/lang/Throwable.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, lang )

/**
 * The Jace C++ proxy class source for java/lang/IllegalArgumentException.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define IllegalArgumentException_INITIALIZER : ::jace::proxy::java::lang::RuntimeException( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define IllegalArgumentException_INITIALIZER : ::jace::proxy::java::lang::RuntimeException( NO_OP )
#endif

IllegalArgumentException::IllegalArgumentException() IllegalArgumentException_INITIALIZER {
  ::jace::JArguments arguments;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

IllegalArgumentException::IllegalArgumentException( ::jace::proxy::java::lang::String p0 ) IllegalArgumentException_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

IllegalArgumentException::IllegalArgumentException( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::Throwable p1 ) IllegalArgumentException_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

IllegalArgumentException::IllegalArgumentException( ::jace::proxy::java::lang::Throwable p0 ) IllegalArgumentException_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
IllegalArgumentException::IllegalArgumentException( jvalue value ) IllegalArgumentException_INITIALIZER {
  setJavaJniValue( value );
}

IllegalArgumentException::IllegalArgumentException( jobject object ) IllegalArgumentException_INITIALIZER {
  setJavaJniObject( object );
}

IllegalArgumentException::IllegalArgumentException( const IllegalArgumentException& object ) IllegalArgumentException_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

IllegalArgumentException::IllegalArgumentException( const NoOp& noOp ) IllegalArgumentException_INITIALIZER {
}

const JClass* IllegalArgumentException::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/lang/IllegalArgumentException" );
  return &javaClass;
}

const JClass* IllegalArgumentException::getJavaJniClass() const throw ( JNIException ) {
  return IllegalArgumentException::staticGetJavaJniClass();
}

JEnlister< IllegalArgumentException> IllegalArgumentException::enlister;

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::lang::IllegalArgumentException>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::IllegalArgumentException( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::IllegalArgumentException>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::IllegalArgumentException>& proxy ) : 
    ::jace::proxy::java::lang::IllegalArgumentException( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::lang::IllegalArgumentException>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::IllegalArgumentException( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::IllegalArgumentException>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::IllegalArgumentException( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::IllegalArgumentException>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::IllegalArgumentException>& object ) : 
    ::jace::proxy::java::lang::IllegalArgumentException( object.getJavaJniValue() ), Object( NO_OP ) {

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

