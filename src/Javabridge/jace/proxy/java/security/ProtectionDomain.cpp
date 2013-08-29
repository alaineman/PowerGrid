
#ifndef JACE_PROXY_JAVA_SECURITY_PROTECTIONDOMAIN_H
#include "jace/proxy/java/security/ProtectionDomain.h"
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
#ifndef JACE_PROXY_JAVA_SECURITY_CODESOURCE_H
#include "jace/proxy/java/security/CodeSource.h"
#endif
#ifndef JACE_PROXY_JAVA_SECURITY_PERMISSIONCOLLECTION_H
#include "jace/proxy/java/security/PermissionCollection.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_CLASSLOADER_H
#include "jace/proxy/java/lang/ClassLoader.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_SECURITY_PERMISSION_H
#include "jace/proxy/java/security/Permission.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, security )

/**
 * The Jace C++ proxy class source for java/security/ProtectionDomain.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define ProtectionDomain_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define ProtectionDomain_INITIALIZER
#endif

ProtectionDomain::ProtectionDomain( ::jace::proxy::java::security::CodeSource p0, ::jace::proxy::java::security::PermissionCollection p1 ) ProtectionDomain_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

ProtectionDomain::ProtectionDomain( ::jace::proxy::java::security::CodeSource p0, ::jace::proxy::java::security::PermissionCollection p1, ::jace::proxy::java::lang::ClassLoader p2, ::jace::JArray< ::jace::proxy::java::security::Principal > p3 ) ProtectionDomain_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2 << p3;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::java::security::CodeSource ProtectionDomain::getCodeSource() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::security::CodeSource >( "getCodeSource" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::ClassLoader ProtectionDomain::getClassLoader() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::ClassLoader >( "getClassLoader" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::java::security::Principal > ProtectionDomain::getPrincipals() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::security::Principal > >( "getPrincipals" ).invoke( *this, arguments );
}

::jace::proxy::java::security::PermissionCollection ProtectionDomain::getPermissions() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::security::PermissionCollection >( "getPermissions" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean ProtectionDomain::implies( ::jace::proxy::java::security::Permission p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "implies" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String ProtectionDomain::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
ProtectionDomain::ProtectionDomain( jvalue value ) ProtectionDomain_INITIALIZER {
  setJavaJniValue( value );
}

ProtectionDomain::ProtectionDomain( jobject object ) ProtectionDomain_INITIALIZER {
  setJavaJniObject( object );
}

ProtectionDomain::ProtectionDomain( const ProtectionDomain& object ) ProtectionDomain_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

ProtectionDomain::ProtectionDomain( const NoOp& noOp ) ProtectionDomain_INITIALIZER {
}

const JClass* ProtectionDomain::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/security/ProtectionDomain" );
  return &javaClass;
}

const JClass* ProtectionDomain::getJavaJniClass() const throw ( JNIException ) {
  return ProtectionDomain::staticGetJavaJniClass();
}

JEnlister< ProtectionDomain> ProtectionDomain::enlister;

END_NAMESPACE_4( jace, proxy, java, security )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::security::ProtectionDomain>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::security::ProtectionDomain( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::security::ProtectionDomain>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::security::ProtectionDomain>& proxy ) : 
    ::jace::proxy::java::security::ProtectionDomain( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::security::ProtectionDomain>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::security::ProtectionDomain( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::ProtectionDomain>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::security::ProtectionDomain( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::ProtectionDomain>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::security::ProtectionDomain>& object ) : 
    ::jace::proxy::java::security::ProtectionDomain( object.getJavaJniValue() ), Object( NO_OP ) {

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

