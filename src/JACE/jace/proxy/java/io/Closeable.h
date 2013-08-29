#ifndef JACE_PROXY_JAVA_IO_CLOSEABLE_H
#define JACE_PROXY_JAVA_IO_CLOSEABLE_H

#include "jace/os_dep.h"
#include "jace/namespace.h"
#include "jace/proxy/JObject.h"
#include "jace/JEnlister.h"
#include "jace/JArray.h"
#include "jace/JFieldProxy.h"

/**
 * The super class for this class.
 *
 */
#include "jace/proxy/java/lang/Object.h"

/**
 * The interfaces implemented by this class.
 *
 */
#include "jace/proxy/java/lang/AutoCloseable.h"

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class IOException;

/**
 * The Jace C++ proxy class for java/io/Closeable.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class Closeable : public virtual ::jace::proxy::java::lang::Object, public virtual ::jace::proxy::java::lang::AutoCloseable {

public: 

/**
 * close
 *
 */
void close();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
/**
 * Special no arg constructor for interface virtual inheritance
 *
 */
Closeable();
Closeable( jvalue value );
Closeable( jobject object );
Closeable( const Closeable& object );
Closeable( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< Closeable> enlister;
};

END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::io::Closeable>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::io::Closeable>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::io::Closeable>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::io::Closeable>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::io::Closeable( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::io::Closeable>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::io::Closeable>& proxy ) : 
    ::jace::proxy::java::io::Closeable( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::io::Closeable>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::io::Closeable>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::io::Closeable>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::io::Closeable>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::io::Closeable>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::io::Closeable( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::io::Closeable>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::io::Closeable( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::io::Closeable>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::io::Closeable>& object ) : 
    ::jace::proxy::java::io::Closeable( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_IO_CLOSEABLE_H

