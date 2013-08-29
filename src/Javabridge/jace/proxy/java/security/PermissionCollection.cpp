
#ifndef JACE_PROXY_JAVA_SECURITY_PERMISSIONCOLLECTION_H
#include "jace/proxy/java/security/PermissionCollection.h"
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
#ifndef JACE_PROXY_JAVA_SECURITY_PERMISSION_H
#include "jace/proxy/java/security/Permission.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_ENUMERATION_H
#include "jace/proxy/java/util/Enumeration.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, security )

/**
 * The Jace C++ proxy class source for java/security/PermissionCollection.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define PermissionCollection_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define PermissionCollection_INITIALIZER
#endif

PermissionCollection::PermissionCollection() PermissionCollection_INITIALIZER {
  ::jace::JArguments arguments;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

void PermissionCollection::add( ::jace::proxy::java::security::Permission p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "add" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean PermissionCollection::implies( ::jace::proxy::java::security::Permission p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "implies" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Enumeration PermissionCollection::elements() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Enumeration >( "elements" ).invoke( *this, arguments );
}

void PermissionCollection::setReadOnly() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setReadOnly" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean PermissionCollection::isReadOnly() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isReadOnly" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String PermissionCollection::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
PermissionCollection::PermissionCollection( jvalue value ) PermissionCollection_INITIALIZER {
  setJavaJniValue( value );
}

PermissionCollection::PermissionCollection( jobject object ) PermissionCollection_INITIALIZER {
  setJavaJniObject( object );
}

PermissionCollection::PermissionCollection( const PermissionCollection& object ) PermissionCollection_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

PermissionCollection::PermissionCollection( const NoOp& noOp ) PermissionCollection_INITIALIZER {
}

const JClass* PermissionCollection::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/security/PermissionCollection" );
  return &javaClass;
}

const JClass* PermissionCollection::getJavaJniClass() const throw ( JNIException ) {
  return PermissionCollection::staticGetJavaJniClass();
}

JEnlister< PermissionCollection> PermissionCollection::enlister;

END_NAMESPACE_4( jace, proxy, java, security )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::security::PermissionCollection>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::security::PermissionCollection( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::security::PermissionCollection>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::security::PermissionCollection>& proxy ) : 
    ::jace::proxy::java::security::PermissionCollection( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::security::PermissionCollection>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::security::PermissionCollection( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::PermissionCollection>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::security::PermissionCollection( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::PermissionCollection>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::security::PermissionCollection>& object ) : 
    ::jace::proxy::java::security::PermissionCollection( object.getJavaJniValue() ), Object( NO_OP ) {

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

