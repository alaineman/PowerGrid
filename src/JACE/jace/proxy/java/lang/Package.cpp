
#ifndef JACE_PROXY_JAVA_LANG_PACKAGE_H
#include "jace/proxy/java/lang/Package.h"
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
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_URL_H
#include "jace/proxy/java/net/URL.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_NUMBERFORMATEXCEPTION_H
#include "jace/proxy/java/lang/NumberFormatException.h"
#endif
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_ANNOTATION_ANNOTATION_H
#include "jace/proxy/java/lang/annotation/Annotation.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_CLASS_H
#include "jace/proxy/java/lang/Class.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, lang )

/**
 * The Jace C++ proxy class source for java/lang/Package.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Package_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Package_INITIALIZER
#endif

::jace::proxy::java::lang::String Package::getName() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getName" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Package::getSpecificationTitle() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getSpecificationTitle" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Package::getSpecificationVersion() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getSpecificationVersion" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Package::getSpecificationVendor() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getSpecificationVendor" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Package::getImplementationTitle() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getImplementationTitle" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Package::getImplementationVersion() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getImplementationVersion" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Package::getImplementationVendor() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getImplementationVendor" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Package::isSealed() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isSealed" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Package::isSealed( ::jace::proxy::java::net::URL p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isSealed" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Package::isCompatibleWith( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isCompatibleWith" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Package Package::getPackage( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::Package >( "getPackage" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::JArray< ::jace::proxy::java::lang::Package > Package::getPackages() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::Package > >( "getPackages" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::types::JInt Package::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Package::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::annotation::Annotation Package::getAnnotation( ::jace::proxy::java::lang::Class p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::annotation::Annotation >( "getAnnotation" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Package::isAnnotationPresent( ::jace::proxy::java::lang::Class p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isAnnotationPresent" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::lang::annotation::Annotation > Package::getAnnotations() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::annotation::Annotation > >( "getAnnotations" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::lang::annotation::Annotation > Package::getDeclaredAnnotations() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::annotation::Annotation > >( "getDeclaredAnnotations" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Package::Package( jvalue value ) Package_INITIALIZER {
  setJavaJniValue( value );
}

Package::Package( jobject object ) Package_INITIALIZER {
  setJavaJniObject( object );
}

Package::Package( const Package& object ) Package_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Package::Package( const NoOp& noOp ) Package_INITIALIZER {
}

const JClass* Package::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/lang/Package" );
  return &javaClass;
}

const JClass* Package::getJavaJniClass() const throw ( JNIException ) {
  return Package::staticGetJavaJniClass();
}

JEnlister< Package> Package::enlister;

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::lang::Package>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::Package( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::Package>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::Package>& proxy ) : 
    ::jace::proxy::java::lang::Package( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Package>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::Package( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Package>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::Package( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::Package>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::Package>& object ) : 
    ::jace::proxy::java::lang::Package( object.getJavaJniValue() ), Object( NO_OP ) {

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

