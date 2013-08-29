
#ifndef JACE_PROXY_JAVA_LANG_CLASSLOADER_H
#define JACE_PROXY_JAVA_LANG_CLASSLOADER_H

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
BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class Class;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class ClassNotFoundException;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, net )
class URL;
END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Enumeration;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class IOException;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class InputStream;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )

/**
 * The Jace C++ proxy class for java/lang/ClassLoader.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class ClassLoader : public virtual ::jace::proxy::java::lang::Object {

public: 

/**
 * loadClass
 *
 */
::jace::proxy::java::lang::Class loadClass( ::jace::proxy::java::lang::String p0 );

/**
 * getResource
 *
 */
::jace::proxy::java::net::URL getResource( ::jace::proxy::java::lang::String p0 );

/**
 * getResources
 *
 */
::jace::proxy::java::util::Enumeration getResources( ::jace::proxy::java::lang::String p0 );

/**
 * getSystemResource
 *
 */
static ::jace::proxy::java::net::URL getSystemResource( ::jace::proxy::java::lang::String p0 );

/**
 * getSystemResources
 *
 */
static ::jace::proxy::java::util::Enumeration getSystemResources( ::jace::proxy::java::lang::String p0 );

/**
 * getResourceAsStream
 *
 */
::jace::proxy::java::io::InputStream getResourceAsStream( ::jace::proxy::java::lang::String p0 );

/**
 * getSystemResourceAsStream
 *
 */
static ::jace::proxy::java::io::InputStream getSystemResourceAsStream( ::jace::proxy::java::lang::String p0 );

/**
 * getParent
 *
 */
::jace::proxy::java::lang::ClassLoader getParent();

/**
 * getSystemClassLoader
 *
 */
static ::jace::proxy::java::lang::ClassLoader getSystemClassLoader();

/**
 * setDefaultAssertionStatus
 *
 */
void setDefaultAssertionStatus( ::jace::proxy::types::JBoolean p0 );

/**
 * setPackageAssertionStatus
 *
 */
void setPackageAssertionStatus( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JBoolean p1 );

/**
 * setClassAssertionStatus
 *
 */
void setClassAssertionStatus( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JBoolean p1 );

/**
 * clearAssertionStatus
 *
 */
void clearAssertionStatus();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
ClassLoader( jvalue value );
ClassLoader( jobject object );
ClassLoader( const ClassLoader& object );
ClassLoader( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< ClassLoader> enlister;
};

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::lang::ClassLoader>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::lang::ClassLoader>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::ClassLoader>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::lang::ClassLoader>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::ClassLoader( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::ClassLoader>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::ClassLoader>& proxy ) : 
    ::jace::proxy::java::lang::ClassLoader( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::lang::ClassLoader>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::lang::ClassLoader>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::lang::ClassLoader>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::ClassLoader>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::lang::ClassLoader>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::ClassLoader( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::ClassLoader>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::ClassLoader( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::ClassLoader>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::ClassLoader>& object ) : 
    ::jace::proxy::java::lang::ClassLoader( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_LANG_CLASSLOADER_H

