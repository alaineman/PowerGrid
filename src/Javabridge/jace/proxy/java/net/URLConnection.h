
#ifndef JACE_PROXY_JAVA_NET_URLCONNECTION_H
#define JACE_PROXY_JAVA_NET_URLCONNECTION_H

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
#ifndef JACE_PROXY_JAVA_LANG_CLASS_H
#include "jace/proxy/java/lang/Class.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_4( jace, proxy, java, net )
class FileNameMap;
END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class IOException;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, net )
class URL;
END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JLong;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Map;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_4( jace, proxy, java, security )
class Permission;
END_NAMESPACE_4( jace, proxy, java, security )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class InputStream;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class OutputStream;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, net )
class ContentHandlerFactory;
END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE_4( jace, proxy, java, net )

/**
 * The Jace C++ proxy class for java/net/URLConnection.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class URLConnection : public virtual ::jace::proxy::java::lang::Object {

public: 

/**
 * getFileNameMap
 *
 */
static ::jace::proxy::java::net::FileNameMap getFileNameMap();

/**
 * setFileNameMap
 *
 */
static void setFileNameMap( ::jace::proxy::java::net::FileNameMap p0 );

/**
 * connect
 *
 */
void connect();

/**
 * setConnectTimeout
 *
 */
void setConnectTimeout( ::jace::proxy::types::JInt p0 );

/**
 * getConnectTimeout
 *
 */
::jace::proxy::types::JInt getConnectTimeout();

/**
 * setReadTimeout
 *
 */
void setReadTimeout( ::jace::proxy::types::JInt p0 );

/**
 * getReadTimeout
 *
 */
::jace::proxy::types::JInt getReadTimeout();

/**
 * getURL
 *
 */
::jace::proxy::java::net::URL getURL();

/**
 * getContentLength
 *
 */
::jace::proxy::types::JInt getContentLength();

/**
 * getContentLengthLong
 *
 */
::jace::proxy::types::JLong getContentLengthLong();

/**
 * getContentType
 *
 */
::jace::proxy::java::lang::String getContentType();

/**
 * getContentEncoding
 *
 */
::jace::proxy::java::lang::String getContentEncoding();

/**
 * getExpiration
 *
 */
::jace::proxy::types::JLong getExpiration();

/**
 * getDate
 *
 */
::jace::proxy::types::JLong getDate();

/**
 * getLastModified
 *
 */
::jace::proxy::types::JLong getLastModified();

/**
 * getHeaderField
 *
 */
::jace::proxy::java::lang::String getHeaderField( ::jace::proxy::java::lang::String p0 );

/**
 * getHeaderFields
 *
 */
::jace::proxy::java::util::Map getHeaderFields();

/**
 * getHeaderFieldInt
 *
 */
::jace::proxy::types::JInt getHeaderFieldInt( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JInt p1 );

/**
 * getHeaderFieldLong
 *
 */
::jace::proxy::types::JLong getHeaderFieldLong( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JLong p1 );

/**
 * getHeaderFieldDate
 *
 */
::jace::proxy::types::JLong getHeaderFieldDate( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JLong p1 );

/**
 * getHeaderFieldKey
 *
 */
::jace::proxy::java::lang::String getHeaderFieldKey( ::jace::proxy::types::JInt p0 );

/**
 * getHeaderField
 *
 */
::jace::proxy::java::lang::String getHeaderField( ::jace::proxy::types::JInt p0 );

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
 * getPermission
 *
 */
::jace::proxy::java::security::Permission getPermission();

/**
 * getInputStream
 *
 */
::jace::proxy::java::io::InputStream getInputStream();

/**
 * getOutputStream
 *
 */
::jace::proxy::java::io::OutputStream getOutputStream();

/**
 * toString
 *
 */
::jace::proxy::java::lang::String toString();

/**
 * setDoInput
 *
 */
void setDoInput( ::jace::proxy::types::JBoolean p0 );

/**
 * getDoInput
 *
 */
::jace::proxy::types::JBoolean getDoInput();

/**
 * setDoOutput
 *
 */
void setDoOutput( ::jace::proxy::types::JBoolean p0 );

/**
 * getDoOutput
 *
 */
::jace::proxy::types::JBoolean getDoOutput();

/**
 * setAllowUserInteraction
 *
 */
void setAllowUserInteraction( ::jace::proxy::types::JBoolean p0 );

/**
 * getAllowUserInteraction
 *
 */
::jace::proxy::types::JBoolean getAllowUserInteraction();

/**
 * setDefaultAllowUserInteraction
 *
 */
static void setDefaultAllowUserInteraction( ::jace::proxy::types::JBoolean p0 );

/**
 * getDefaultAllowUserInteraction
 *
 */
static ::jace::proxy::types::JBoolean getDefaultAllowUserInteraction();

/**
 * setUseCaches
 *
 */
void setUseCaches( ::jace::proxy::types::JBoolean p0 );

/**
 * getUseCaches
 *
 */
::jace::proxy::types::JBoolean getUseCaches();

/**
 * setIfModifiedSince
 *
 */
void setIfModifiedSince( ::jace::proxy::types::JLong p0 );

/**
 * getIfModifiedSince
 *
 */
::jace::proxy::types::JLong getIfModifiedSince();

/**
 * getDefaultUseCaches
 *
 */
::jace::proxy::types::JBoolean getDefaultUseCaches();

/**
 * setDefaultUseCaches
 *
 */
void setDefaultUseCaches( ::jace::proxy::types::JBoolean p0 );

/**
 * setRequestProperty
 *
 */
void setRequestProperty( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 );

/**
 * addRequestProperty
 *
 */
void addRequestProperty( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 );

/**
 * getRequestProperty
 *
 */
::jace::proxy::java::lang::String getRequestProperty( ::jace::proxy::java::lang::String p0 );

/**
 * getRequestProperties
 *
 */
::jace::proxy::java::util::Map getRequestProperties();

/**
 * setDefaultRequestProperty
 *
 */
static void setDefaultRequestProperty( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 );

/**
 * getDefaultRequestProperty
 *
 */
static ::jace::proxy::java::lang::String getDefaultRequestProperty( ::jace::proxy::java::lang::String p0 );

/**
 * setContentHandlerFactory
 *
 */
static void setContentHandlerFactory( ::jace::proxy::java::net::ContentHandlerFactory p0 );

/**
 * guessContentTypeFromName
 *
 */
static ::jace::proxy::java::lang::String guessContentTypeFromName( ::jace::proxy::java::lang::String p0 );

/**
 * guessContentTypeFromStream
 *
 */
static ::jace::proxy::java::lang::String guessContentTypeFromStream( ::jace::proxy::java::io::InputStream p0 );

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
URLConnection( jvalue value );
URLConnection( jobject object );
URLConnection( const URLConnection& object );
URLConnection( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< URLConnection> enlister;
};

END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::net::URLConnection>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::net::URLConnection>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::net::URLConnection>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::net::URLConnection>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::net::URLConnection( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::net::URLConnection>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::net::URLConnection>& proxy ) : 
    ::jace::proxy::java::net::URLConnection( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::net::URLConnection>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::net::URLConnection>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::net::URLConnection>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::net::URLConnection>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::net::URLConnection>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::net::URLConnection( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::URLConnection>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::net::URLConnection( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::net::URLConnection>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::net::URLConnection>& object ) : 
    ::jace::proxy::java::net::URLConnection( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_NET_URLCONNECTION_H

