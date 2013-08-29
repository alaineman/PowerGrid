
#ifndef JACE_PROXY_JAVA_UTIL_DICTIONARY_H
#include "jace/proxy/java/util/Dictionary.h"
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
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_ENUMERATION_H
#include "jace/proxy/java/util/Enumeration.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, util )

/**
 * The Jace C++ proxy class source for java/util/Dictionary.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Dictionary_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Dictionary_INITIALIZER
#endif

Dictionary::Dictionary() Dictionary_INITIALIZER {
  ::jace::JArguments arguments;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::types::JInt Dictionary::size() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "size" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Dictionary::isEmpty() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isEmpty" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Enumeration Dictionary::keys() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Enumeration >( "keys" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Enumeration Dictionary::elements() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Enumeration >( "elements" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object Dictionary::get( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "get" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object Dictionary::put( ::jace::proxy::java::lang::Object p0, ::jace::proxy::java::lang::Object p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "put" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object Dictionary::remove( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "remove" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Dictionary::Dictionary( jvalue value ) Dictionary_INITIALIZER {
  setJavaJniValue( value );
}

Dictionary::Dictionary( jobject object ) Dictionary_INITIALIZER {
  setJavaJniObject( object );
}

Dictionary::Dictionary( const Dictionary& object ) Dictionary_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Dictionary::Dictionary( const NoOp& noOp ) Dictionary_INITIALIZER {
}

const JClass* Dictionary::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/util/Dictionary" );
  return &javaClass;
}

const JClass* Dictionary::getJavaJniClass() const throw ( JNIException ) {
  return Dictionary::staticGetJavaJniClass();
}

JEnlister< Dictionary> Dictionary::enlister;

END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::util::Dictionary>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::Dictionary( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::Dictionary>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::Dictionary>& proxy ) : 
    ::jace::proxy::java::util::Dictionary( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::util::Dictionary>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::Dictionary( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Dictionary>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::Dictionary( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Dictionary>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::Dictionary>& object ) : 
    ::jace::proxy::java::util::Dictionary( object.getJavaJniValue() ), Object( NO_OP ) {

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

