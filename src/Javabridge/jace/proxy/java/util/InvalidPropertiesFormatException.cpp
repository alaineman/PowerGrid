
#ifndef JACE_PROXY_JAVA_UTIL_INVALIDPROPERTIESFORMATEXCEPTION_H
#include "jace/proxy/java/util/InvalidPropertiesFormatException.h"
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
#ifndef JACE_PROXY_JAVA_LANG_THROWABLE_H
#include "jace/proxy/java/lang/Throwable.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, util )

/**
 * The Jace C++ proxy class source for java/util/InvalidPropertiesFormatException.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define InvalidPropertiesFormatException_INITIALIZER : ::jace::proxy::java::io::IOException( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define InvalidPropertiesFormatException_INITIALIZER : ::jace::proxy::java::io::IOException( NO_OP )
#endif

InvalidPropertiesFormatException::InvalidPropertiesFormatException( ::jace::proxy::java::lang::Throwable p0 ) InvalidPropertiesFormatException_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

InvalidPropertiesFormatException::InvalidPropertiesFormatException( ::jace::proxy::java::lang::String p0 ) InvalidPropertiesFormatException_INITIALIZER {
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
InvalidPropertiesFormatException::InvalidPropertiesFormatException( jvalue value ) InvalidPropertiesFormatException_INITIALIZER {
  setJavaJniValue( value );
}

InvalidPropertiesFormatException::InvalidPropertiesFormatException( jobject object ) InvalidPropertiesFormatException_INITIALIZER {
  setJavaJniObject( object );
}

InvalidPropertiesFormatException::InvalidPropertiesFormatException( const InvalidPropertiesFormatException& object ) InvalidPropertiesFormatException_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

InvalidPropertiesFormatException::InvalidPropertiesFormatException( const NoOp& noOp ) InvalidPropertiesFormatException_INITIALIZER {
}

const JClass* InvalidPropertiesFormatException::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/util/InvalidPropertiesFormatException" );
  return &javaClass;
}

const JClass* InvalidPropertiesFormatException::getJavaJniClass() const throw ( JNIException ) {
  return InvalidPropertiesFormatException::staticGetJavaJniClass();
}

JEnlister< InvalidPropertiesFormatException> InvalidPropertiesFormatException::enlister;

END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::util::InvalidPropertiesFormatException>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::InvalidPropertiesFormatException( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::InvalidPropertiesFormatException>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::InvalidPropertiesFormatException>& proxy ) : 
    ::jace::proxy::java::util::InvalidPropertiesFormatException( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::util::InvalidPropertiesFormatException>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::InvalidPropertiesFormatException( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::InvalidPropertiesFormatException>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::InvalidPropertiesFormatException( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::InvalidPropertiesFormatException>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::InvalidPropertiesFormatException>& object ) : 
    ::jace::proxy::java::util::InvalidPropertiesFormatException( object.getJavaJniValue() ), Object( NO_OP ) {

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

