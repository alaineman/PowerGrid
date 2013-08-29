
#ifndef JACE_PROXY_JAVA_UTIL_DICTIONARY_H
#define JACE_PROXY_JAVA_UTIL_DICTIONARY_H

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
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Enumeration;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_4( jace, proxy, java, util )

/**
 * The Jace C++ proxy class for java/util/Dictionary.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class Dictionary : public virtual ::jace::proxy::java::lang::Object {

public: 

/**
 * Dictionary
 *
 */
Dictionary();

/**
 * size
 *
 */
::jace::proxy::types::JInt size();

/**
 * isEmpty
 *
 */
::jace::proxy::types::JBoolean isEmpty();

/**
 * keys
 *
 */
::jace::proxy::java::util::Enumeration keys();

/**
 * elements
 *
 */
::jace::proxy::java::util::Enumeration elements();

/**
 * get
 *
 */
::jace::proxy::java::lang::Object get( ::jace::proxy::java::lang::Object p0 );

/**
 * put
 *
 */
::jace::proxy::java::lang::Object put( ::jace::proxy::java::lang::Object p0, ::jace::proxy::java::lang::Object p1 );

/**
 * remove
 *
 */
::jace::proxy::java::lang::Object remove( ::jace::proxy::java::lang::Object p0 );

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Dictionary( jvalue value );
Dictionary( jobject object );
Dictionary( const Dictionary& object );
Dictionary( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< Dictionary> enlister;
};

END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::util::Dictionary>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::util::Dictionary>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::Dictionary>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::util::Dictionary>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::Dictionary( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::Dictionary>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::Dictionary>& proxy ) : 
    ::jace::proxy::java::util::Dictionary( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::util::Dictionary>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::util::Dictionary>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::util::Dictionary>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::Dictionary>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::util::Dictionary>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::Dictionary( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Dictionary>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::Dictionary( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Dictionary>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::Dictionary>& object ) : 
    ::jace::proxy::java::util::Dictionary( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_UTIL_DICTIONARY_H

