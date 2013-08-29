
#ifndef JACE_PROXY_JAVA_NET_NETWORKINTERFACE_H
#define JACE_PROXY_JAVA_NET_NETWORKINTERFACE_H

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
 * Classes which this class is fully dependent upon.
 *
 */
#ifndef JACE_TYPES_JBYTE_H
#include "jace/proxy/types/JByte.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Enumeration;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class List;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, net )
class SocketException;
END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE_4( jace, proxy, java, net )
class InetAddress;
END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, net )

/**
 * The Jace C++ proxy class for java/net/NetworkInterface.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class NetworkInterface : public virtual ::jace::proxy::java::lang::Object {

public: 

/**
 * getName
 *
 */
::jace::proxy::java::lang::String getName();

/**
 * getInetAddresses
 *
 */
::jace::proxy::java::util::Enumeration getInetAddresses();

/**
 * getInterfaceAddresses
 *
 */
::jace::proxy::java::util::List getInterfaceAddresses();

/**
 * getSubInterfaces
 *
 */
::jace::proxy::java::util::Enumeration getSubInterfaces();

/**
 * getParent
 *
 */
::jace::proxy::java::net::NetworkInterface getParent();

/**
 * getIndex
 *
 */
::jace::proxy::types::JInt getIndex();

/**
 * getDisplayName
 *
 */
::jace::proxy::java::lang::String getDisplayName();

/**
 * getByName
 *
 */
static ::jace::proxy::java::net::NetworkInterface getByName( ::jace::proxy::java::lang::String p0 );

/**
 * getByIndex
 *
 */
static ::jace::proxy::java::net::NetworkInterface getByIndex( ::jace::proxy::types::JInt p0 );

/**
 * getByInetAddress
 *
 */
static ::jace::proxy::java::net::NetworkInterface getByInetAddress( ::jace::proxy::java::net::InetAddress p0 );

/**
 * getNetworkInterfaces
 *
 */
static ::jace::proxy::java::util::Enumeration getNetworkInterfaces();

/**
 * isUp
 *
 */
::jace::proxy::types::JBoolean isUp();

/**
 * isLoopback
 *
 */
::jace::proxy::types::JBoolean isLoopback();

/**
 * isPointToPoint
 *
 */
::jace::proxy::types::JBoolean isPointToPoint();

/**
 * supportsMulticast
 *
 */
::jace::proxy::types::JBoolean supportsMulticast();

/**
 * getHardwareAddress
 *
 */
::jace::JArray< ::jace::proxy::types::JByte > getHardwareAddress();

/**
 * getMTU
 *
 */
::jace::proxy::types::JInt getMTU();

/**
 * isVirtual
 *
 */
::jace::proxy::types::JBoolean isVirtual();

/**
 * equals
 *
 */
::jace::proxy::types::JBoolean equals( ::jace::proxy::java::lang::Object p0 );

/**
 * hashCode
 *
 */
::jace::proxy::types::JInt hashCode();

/**
 * toString
 *
 */
::jace::proxy::java::lang::String toString();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
NetworkInterface( jvalue value );
NetworkInterface( jobject object );
NetworkInterface( const NetworkInterface& object );
NetworkInterface( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< NetworkInterface> enlister;
};

END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::net::NetworkInterface>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::net::NetworkInterface>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::net::NetworkInterface>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::net::NetworkInterface>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::net::NetworkInterface( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::net::NetworkInterface>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::net::NetworkInterface>& proxy ) : 
    ::jace::proxy::java::net::NetworkInterface( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::net::NetworkInterface>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::net::NetworkInterface>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::net::NetworkInterface>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::net::NetworkInterface>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::net::NetworkInterface>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::net::NetworkInterface( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::NetworkInterface>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::net::NetworkInterface( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::NetworkInterface>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::net::NetworkInterface>& object ) : 
    ::jace::proxy::java::net::NetworkInterface( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_NET_NETWORKINTERFACE_H

