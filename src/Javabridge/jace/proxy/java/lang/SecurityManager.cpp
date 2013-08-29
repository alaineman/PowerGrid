
#ifndef JACE_PROXY_JAVA_LANG_SECURITYMANAGER_H
#include "jace/proxy/java/lang/SecurityManager.h"
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
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_TYPES_JVOID_H
#include "jace/proxy/types/JVoid.h"
#endif
#ifndef JACE_PROXY_JAVA_SECURITY_PERMISSION_H
#include "jace/proxy/java/security/Permission.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_THREAD_H
#include "jace/proxy/java/lang/Thread.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_THREADGROUP_H
#include "jace/proxy/java/lang/ThreadGroup.h"
#endif
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_FILEDESCRIPTOR_H
#include "jace/proxy/java/io/FileDescriptor.h"
#endif
#ifndef JACE_PROXY_JAVA_NET_INETADDRESS_H
#include "jace/proxy/java/net/InetAddress.h"
#endif
#ifndef JACE_TYPES_JBYTE_H
#include "jace/proxy/types/JByte.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_CLASS_H
#include "jace/proxy/java/lang/Class.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, lang )

/**
 * The Jace C++ proxy class source for java/lang/SecurityManager.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define SecurityManager_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define SecurityManager_INITIALIZER
#endif

::jace::proxy::types::JBoolean SecurityManager::getInCheck() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "getInCheck" ).invoke( *this, arguments );
}

SecurityManager::SecurityManager() SecurityManager_INITIALIZER {
  ::jace::JArguments arguments;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::java::lang::Object SecurityManager::getSecurityContext() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "getSecurityContext" ).invoke( *this, arguments );
}

void SecurityManager::checkPermission( ::jace::proxy::java::security::Permission p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkPermission" ).invoke( *this, arguments );
}

void SecurityManager::checkPermission( ::jace::proxy::java::security::Permission p0, ::jace::proxy::java::lang::Object p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkPermission" ).invoke( *this, arguments );
}

void SecurityManager::checkCreateClassLoader() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkCreateClassLoader" ).invoke( *this, arguments );
}

void SecurityManager::checkAccess( ::jace::proxy::java::lang::Thread p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkAccess" ).invoke( *this, arguments );
}

void SecurityManager::checkAccess( ::jace::proxy::java::lang::ThreadGroup p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkAccess" ).invoke( *this, arguments );
}

void SecurityManager::checkExit( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkExit" ).invoke( *this, arguments );
}

void SecurityManager::checkExec( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkExec" ).invoke( *this, arguments );
}

void SecurityManager::checkLink( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkLink" ).invoke( *this, arguments );
}

void SecurityManager::checkRead( ::jace::proxy::java::io::FileDescriptor p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkRead" ).invoke( *this, arguments );
}

void SecurityManager::checkRead( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkRead" ).invoke( *this, arguments );
}

void SecurityManager::checkRead( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::Object p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkRead" ).invoke( *this, arguments );
}

void SecurityManager::checkWrite( ::jace::proxy::java::io::FileDescriptor p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkWrite" ).invoke( *this, arguments );
}

void SecurityManager::checkWrite( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkWrite" ).invoke( *this, arguments );
}

void SecurityManager::checkDelete( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkDelete" ).invoke( *this, arguments );
}

void SecurityManager::checkConnect( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkConnect" ).invoke( *this, arguments );
}

void SecurityManager::checkConnect( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JInt p1, ::jace::proxy::java::lang::Object p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkConnect" ).invoke( *this, arguments );
}

void SecurityManager::checkListen( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkListen" ).invoke( *this, arguments );
}

void SecurityManager::checkAccept( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkAccept" ).invoke( *this, arguments );
}

void SecurityManager::checkMulticast( ::jace::proxy::java::net::InetAddress p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkMulticast" ).invoke( *this, arguments );
}

void SecurityManager::checkMulticast( ::jace::proxy::java::net::InetAddress p0, ::jace::proxy::types::JByte p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkMulticast" ).invoke( *this, arguments );
}

void SecurityManager::checkPropertiesAccess() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkPropertiesAccess" ).invoke( *this, arguments );
}

void SecurityManager::checkPropertyAccess( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkPropertyAccess" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean SecurityManager::checkTopLevelWindow( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "checkTopLevelWindow" ).invoke( *this, arguments );
}

void SecurityManager::checkPrintJobAccess() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkPrintJobAccess" ).invoke( *this, arguments );
}

void SecurityManager::checkSystemClipboardAccess() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkSystemClipboardAccess" ).invoke( *this, arguments );
}

void SecurityManager::checkAwtEventQueueAccess() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkAwtEventQueueAccess" ).invoke( *this, arguments );
}

void SecurityManager::checkPackageAccess( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkPackageAccess" ).invoke( *this, arguments );
}

void SecurityManager::checkPackageDefinition( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkPackageDefinition" ).invoke( *this, arguments );
}

void SecurityManager::checkSetFactory() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkSetFactory" ).invoke( *this, arguments );
}

void SecurityManager::checkMemberAccess( ::jace::proxy::java::lang::Class p0, ::jace::proxy::types::JInt p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkMemberAccess" ).invoke( *this, arguments );
}

void SecurityManager::checkSecurityAccess( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "checkSecurityAccess" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::ThreadGroup SecurityManager::getThreadGroup() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::ThreadGroup >( "getThreadGroup" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
SecurityManager::SecurityManager( jvalue value ) SecurityManager_INITIALIZER {
  setJavaJniValue( value );
}

SecurityManager::SecurityManager( jobject object ) SecurityManager_INITIALIZER {
  setJavaJniObject( object );
}

SecurityManager::SecurityManager( const SecurityManager& object ) SecurityManager_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

SecurityManager::SecurityManager( const NoOp& noOp ) SecurityManager_INITIALIZER {
}

const JClass* SecurityManager::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/lang/SecurityManager" );
  return &javaClass;
}

const JClass* SecurityManager::getJavaJniClass() const throw ( JNIException ) {
  return SecurityManager::staticGetJavaJniClass();
}

JEnlister< SecurityManager> SecurityManager::enlister;

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::lang::SecurityManager>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::SecurityManager( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::SecurityManager>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::SecurityManager>& proxy ) : 
    ::jace::proxy::java::lang::SecurityManager( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::lang::SecurityManager>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::SecurityManager( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::SecurityManager>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::SecurityManager( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::SecurityManager>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::SecurityManager>& object ) : 
    ::jace::proxy::java::lang::SecurityManager( object.getJavaJniValue() ), Object( NO_OP ) {

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

