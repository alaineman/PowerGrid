
#ifndef JACE_PROXY_JAVA_UTIL_PROPERTIES_H
#define JACE_PROXY_JAVA_UTIL_PROPERTIES_H

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
#ifndef JACE_PROXY_JAVA_UTIL_HASHTABLE_H
#include "jace/proxy/java/util/Hashtable.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class Object;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class Reader;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class IOException;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class InputStream;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class OutputStream;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class Writer;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class InvalidPropertiesFormatException;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Enumeration;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Set;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class PrintStream;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class PrintWriter;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, util )

/**
 * The Jace C++ proxy class for java/util/Properties.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class Properties : public ::jace::proxy::java::util::Hashtable {

public: 

/**
 * Properties
 *
 */
Properties();

/**
 * Properties
 *
 */
Properties( ::jace::proxy::java::util::Properties p0, CopyConstructorSpecifier ccs );

/**
 * setProperty
 *
 */
::jace::proxy::java::lang::Object setProperty( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 );

/**
 * load
 *
 */
void load( ::jace::proxy::java::io::Reader p0 );

/**
 * load
 *
 */
void load( ::jace::proxy::java::io::InputStream p0 );

/**
 * save
 *
 */
void save( ::jace::proxy::java::io::OutputStream p0, ::jace::proxy::java::lang::String p1 );

/**
 * store
 *
 */
void store( ::jace::proxy::java::io::Writer p0, ::jace::proxy::java::lang::String p1 );

/**
 * store
 *
 */
void store( ::jace::proxy::java::io::OutputStream p0, ::jace::proxy::java::lang::String p1 );

/**
 * loadFromXML
 *
 */
void loadFromXML( ::jace::proxy::java::io::InputStream p0 );

/**
 * storeToXML
 *
 */
void storeToXML( ::jace::proxy::java::io::OutputStream p0, ::jace::proxy::java::lang::String p1 );

/**
 * storeToXML
 *
 */
void storeToXML( ::jace::proxy::java::io::OutputStream p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::java::lang::String p2 );

/**
 * getProperty
 *
 */
::jace::proxy::java::lang::String getProperty( ::jace::proxy::java::lang::String p0 );

/**
 * getProperty
 *
 */
::jace::proxy::java::lang::String getProperty( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 );

/**
 * propertyNames
 *
 */
::jace::proxy::java::util::Enumeration propertyNames();

/**
 * stringPropertyNames
 *
 */
::jace::proxy::java::util::Set stringPropertyNames();

/**
 * list
 *
 */
void list( ::jace::proxy::java::io::PrintStream p0 );

/**
 * list
 *
 */
void list( ::jace::proxy::java::io::PrintWriter p0 );

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Properties( jvalue value );
Properties( jobject object );
Properties( const Properties& object );
Properties( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< Properties> enlister;
};

END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::util::Properties>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::util::Properties>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::Properties>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::util::Properties>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::Properties( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::Properties>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::Properties>& proxy ) : 
    ::jace::proxy::java::util::Properties( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::util::Properties>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::util::Properties>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::util::Properties>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::Properties>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::util::Properties>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::Properties( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Properties>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::Properties( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Properties>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::Properties>& object ) : 
    ::jace::proxy::java::util::Properties( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_UTIL_PROPERTIES_H

