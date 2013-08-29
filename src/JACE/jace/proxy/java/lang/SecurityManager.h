
#ifndef JACE_PROXY_JAVA_LANG_SECURITYMANAGER_H
#define JACE_PROXY_JAVA_LANG_SECURITYMANAGER_H

#ifndef JACE_OS_DEP_H
#include "jace/os_dep.h"
#endif

#ifndef JACE_NAMESPACE_H
#include "jace/namespace.h"
#endif

#ifndef JACE_JOBJECT_H
#include "jace/proxy/JObject.h"
#endif

#ifndef JACE_JENLISTER_H
#include "jace/JEnlister.h"
#endif

#ifndef JACE_JARRAY_H
#include "jace/JArray.h"
#endif

#ifndef JACE_JFIELD_PROXY_H
#include "jace/JFieldProxy.h"
#endif

/**
 * The super class for this class.
 *
 */
#ifndef JACE_PROXY_JAVA_LANG_OBJECT_H
#include "jace/proxy/java/lang/Object.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, security )
class Permission;
END_NAMESPACE_4( jace, proxy, java, security )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class Thread;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class ThreadGroup;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class FileDescriptor;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, net )
class InetAddress;
END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JByte;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class Class;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )

/**
 * The Jace C++ proxy class for java/lang/SecurityManager.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class SecurityManager : public virtual ::jace::proxy::java::lang::Object {

public: 

/**
 * getInCheck
 *
 */
::jace::proxy::types::JBoolean getInCheck();

/**
 * SecurityManager
 *
 */
SecurityManager();

/**
 * getSecurityContext
 *
 */
::jace::proxy::java::lang::Object getSecurityContext();

/**
 * checkPermission
 *
 */
void checkPermission( ::jace::proxy::java::security::Permission p0 );

/**
 * checkPermission
 *
 */
void checkPermission( ::jace::proxy::java::security::Permission p0, ::jace::proxy::java::lang::Object p1 );

/**
 * checkCreateClassLoader
 *
 */
void checkCreateClassLoader();

/**
 * checkAccess
 *
 */
void checkAccess( ::jace::proxy::java::lang::Thread p0 );

/**
 * checkAccess
 *
 */
void checkAccess( ::jace::proxy::java::lang::ThreadGroup p0 );

/**
 * checkExit
 *
 */
void checkExit( ::jace::proxy::types::JInt p0 );

/**
 * checkExec
 *
 */
void checkExec( ::jace::proxy::java::lang::String p0 );

/**
 * checkLink
 *
 */
void checkLink( ::jace::proxy::java::lang::String p0 );

/**
 * checkRead
 *
 */
void checkRead( ::jace::proxy::java::io::FileDescriptor p0 );

/**
 * checkRead
 *
 */
void checkRead( ::jace::proxy::java::lang::String p0 );

/**
 * checkRead
 *
 */
void checkRead( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::Object p1 );

/**
 * checkWrite
 *
 */
void checkWrite( ::jace::proxy::java::io::FileDescriptor p0 );

/**
 * checkWrite
 *
 */
void checkWrite( ::jace::proxy::java::lang::String p0 );

/**
 * checkDelete
 *
 */
void checkDelete( ::jace::proxy::java::lang::String p0 );

/**
 * checkConnect
 *
 */
void checkConnect( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JInt p1 );

/**
 * checkConnect
 *
 */
void checkConnect( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JInt p1, ::jace::proxy::java::lang::Object p2 );

/**
 * checkListen
 *
 */
void checkListen( ::jace::proxy::types::JInt p0 );

/**
 * checkAccept
 *
 */
void checkAccept( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JInt p1 );

/**
 * checkMulticast
 *
 */
void checkMulticast( ::jace::proxy::java::net::InetAddress p0 );

/**
 * checkMulticast
 *
 */
void checkMulticast( ::jace::proxy::java::net::InetAddress p0, ::jace::proxy::types::JByte p1 );

/**
 * checkPropertiesAccess
 *
 */
void checkPropertiesAccess();

/**
 * checkPropertyAccess
 *
 */
void checkPropertyAccess( ::jace::proxy::java::lang::String p0 );

/**
 * checkTopLevelWindow
 *
 */
::jace::proxy::types::JBoolean checkTopLevelWindow( ::jace::proxy::java::lang::Object p0 );

/**
 * checkPrintJobAccess
 *
 */
void checkPrintJobAccess();

/**
 * checkSystemClipboardAccess
 *
 */
void checkSystemClipboardAccess();

/**
 * checkAwtEventQueueAccess
 *
 */
void checkAwtEventQueueAccess();

/**
 * checkPackageAccess
 *
 */
void checkPackageAccess( ::jace::proxy::java::lang::String p0 );

/**
 * checkPackageDefinition
 *
 */
void checkPackageDefinition( ::jace::proxy::java::lang::String p0 );

/**
 * checkSetFactory
 *
 */
void checkSetFactory();

/**
 * checkMemberAccess
 *
 */
void checkMemberAccess( ::jace::proxy::java::lang::Class p0, ::jace::proxy::types::JInt p1 );

/**
 * checkSecurityAccess
 *
 */
void checkSecurityAccess( ::jace::proxy::java::lang::String p0 );

/**
 * getThreadGroup
 *
 */
::jace::proxy::java::lang::ThreadGroup getThreadGroup();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
SecurityManager( jvalue value );
SecurityManager( jobject object );
SecurityManager( const SecurityManager& object );
SecurityManager( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< SecurityManager> enlister;
};

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::lang::SecurityManager>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::lang::SecurityManager>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::SecurityManager>& proxy );
#else
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
  template <> JFieldProxy< ::jace::proxy::java::lang::SecurityManager>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::lang::SecurityManager>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::lang::SecurityManager>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::SecurityManager>& object );
#else
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

#endif // #ifndef JACE_PROXY_JAVA_LANG_SECURITYMANAGER_H

