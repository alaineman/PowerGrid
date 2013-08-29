
#ifndef JACE_PROXY_JAVA_NIO_BUFFER_H
#define JACE_PROXY_JAVA_NIO_BUFFER_H

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
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, nio )

/**
 * The Jace C++ proxy class for java/nio/Buffer.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class Buffer : public virtual ::jace::proxy::java::lang::Object {

public: 

/**
 * capacity
 *
 */
::jace::proxy::types::JInt capacity();

/**
 * position
 *
 */
::jace::proxy::types::JInt position();

/**
 * position
 *
 */
::jace::proxy::java::nio::Buffer position( ::jace::proxy::types::JInt p0 );

/**
 * limit
 *
 */
::jace::proxy::types::JInt limit();

/**
 * limit
 *
 */
::jace::proxy::java::nio::Buffer limit( ::jace::proxy::types::JInt p0 );

/**
 * mark
 *
 */
::jace::proxy::java::nio::Buffer mark();

/**
 * reset
 *
 */
::jace::proxy::java::nio::Buffer reset();

/**
 * clear
 *
 */
::jace::proxy::java::nio::Buffer clear();

/**
 * flip
 *
 */
::jace::proxy::java::nio::Buffer flip();

/**
 * rewind
 *
 */
::jace::proxy::java::nio::Buffer rewind();

/**
 * remaining
 *
 */
::jace::proxy::types::JInt remaining();

/**
 * hasRemaining
 *
 */
::jace::proxy::types::JBoolean hasRemaining();

/**
 * isReadOnly
 *
 */
::jace::proxy::types::JBoolean isReadOnly();

/**
 * hasArray
 *
 */
::jace::proxy::types::JBoolean hasArray();

/**
 * array
 *
 */
::jace::proxy::java::lang::Object array();

/**
 * arrayOffset
 *
 */
::jace::proxy::types::JInt arrayOffset();

/**
 * isDirect
 *
 */
::jace::proxy::types::JBoolean isDirect();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Buffer( jvalue value );
Buffer( jobject object );
Buffer( const Buffer& object );
Buffer( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< Buffer> enlister;
};

END_NAMESPACE_4( jace, proxy, java, nio )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::nio::Buffer>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::nio::Buffer>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::Buffer>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::nio::Buffer>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::Buffer( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::Buffer>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::Buffer>& proxy ) : 
    ::jace::proxy::java::nio::Buffer( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::nio::Buffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::Buffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::Buffer>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::Buffer>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::nio::Buffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::Buffer( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::Buffer>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::Buffer( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::Buffer>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::Buffer>& object ) : 
    ::jace::proxy::java::nio::Buffer( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_NIO_BUFFER_H

