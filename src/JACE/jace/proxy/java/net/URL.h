
#ifndef JACE_PROXY_JAVA_NET_URL_H
#define JACE_PROXY_JAVA_NET_URL_H

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
 * The interfaces implemented by this class.
 *
 */
#ifndef JACE_PROXY_JAVA_IO_SERIALIZABLE_H
#include "jace/proxy/java/io/Serializable.h"
#endif

/**
 * Classes which this class is fully dependent upon.
 *
 */
#ifndef JACE_PROXY_JAVA_LANG_CLASS_H
#include "jace/proxy/java/lang/Class.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, net )
class MalformedURLException;
END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE_4( jace, proxy, java, net )
class URLStreamHandler;
END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, net )
class URI;
END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE_4( jace, proxy, java, net )
class URISyntaxException;
END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE_4( jace, proxy, java, net )
class URLConnection;
END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class IOException;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, net )
class Proxy;
END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class InputStream;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, net )
class URLStreamHandlerFactory;
END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE_4( jace, proxy, java, net )

/**
 * The Jace C++ proxy class for java/net/URL.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class URL : public virtual ::jace::proxy::java::lang::Object, public virtual ::jace::proxy::java::io::Serializable {

public: 

/**
 * URL
 *
 */
URL( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::types::JInt p2, ::jace::proxy::java::lang::String p3 );

/**
 * URL
 *
 */
URL( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::java::lang::String p2 );

/**
 * URL
 *
 */
URL( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::types::JInt p2, ::jace::proxy::java::lang::String p3, ::jace::proxy::java::net::URLStreamHandler p4 );

/**
 * URL
 *
 */
URL( ::jace::proxy::java::lang::String p0 );

/**
 * URL
 *
 */
URL( ::jace::proxy::java::net::URL p0, ::jace::proxy::java::lang::String p1 );

/**
 * URL
 *
 */
URL( ::jace::proxy::java::net::URL p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::java::net::URLStreamHandler p2 );

/**
 * getQuery
 *
 */
::jace::proxy::java::lang::String getQuery();

/**
 * getPath
 *
 */
::jace::proxy::java::lang::String getPath();

/**
 * getUserInfo
 *
 */
::jace::proxy::java::lang::String getUserInfo();

/**
 * getAuthority
 *
 */
::jace::proxy::java::lang::String getAuthority();

/**
 * getPort
 *
 */
::jace::proxy::types::JInt getPort();

/**
 * getDefaultPort
 *
 */
::jace::proxy::types::JInt getDefaultPort();

/**
 * getProtocol
 *
 */
::jace::proxy::java::lang::String getProtocol();

/**
 * getHost
 *
 */
::jace::proxy::java::lang::String getHost();

/**
 * getFile
 *
 */
::jace::proxy::java::lang::String getFile();

/**
 * getRef
 *
 */
::jace::proxy::java::lang::String getRef();

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
 * sameFile
 *
 */
::jace::proxy::types::JBoolean sameFile( ::jace::proxy::java::net::URL p0 );

/**
 * toString
 *
 */
::jace::proxy::java::lang::String toString();

/**
 * toExternalForm
 *
 */
::jace::proxy::java::lang::String toExternalForm();

/**
 * toURI
 *
 */
::jace::proxy::java::net::URI toURI();

/**
 * openConnection
 *
 */
::jace::proxy::java::net::URLConnection openConnection();

/**
 * openConnection
 *
 */
::jace::proxy::java::net::URLConnection openConnection( ::jace::proxy::java::net::Proxy p0 );

/**
 * openStream
 *
 */
::jace::proxy::java::io::InputStream openStream();

/**
 * getContent
 *
 */
::jace::proxy::java::lang::Object getContent();

/**
 * getContent
 *
 */
::jace::proxy::java::lang::Object getContent( ::jace::JArray< ::jace::proxy::java::lang::Class > p0 );

/**
 * setURLStreamHandlerFactory
 *
 */
static void setURLStreamHandlerFactory( ::jace::proxy::java::net::URLStreamHandlerFactory p0 );

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
URL( jvalue value );
URL( jobject object );
URL( const URL& object );
URL( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< URL> enlister;
};

END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::net::URL>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::net::URL>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::net::URL>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::net::URL>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::net::URL( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::net::URL>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::net::URL>& proxy ) : 
    ::jace::proxy::java::net::URL( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::net::URL>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::net::URL>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::net::URL>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::net::URL>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::net::URL>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::net::URL( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::URL>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::net::URL( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::URL>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::net::URL>& object ) : 
    ::jace::proxy::java::net::URL( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_NET_URL_H

