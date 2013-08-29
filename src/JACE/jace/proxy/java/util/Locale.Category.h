
#ifndef JACE_PROXY_JAVA_UTIL_LOCALE_CATEGORY_H
#define JACE_PROXY_JAVA_UTIL_LOCALE_CATEGORY_H

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
#ifndef JACE_PROXY_JAVA_LANG_ENUM_H
#include "jace/proxy/java/lang/Enum.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, util )

/**
 * The Jace C++ proxy class for java/util/Locale$Category.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class Locale_Category : public ::jace::proxy::java::lang::Enum {

public: 

/**
 * values
 *
 */
static ::jace::JArray< ::jace::proxy::java::util::Locale_Category > values();

/**
 * valueOf
 *
 */
static ::jace::proxy::java::util::Locale_Category valueOf( ::jace::proxy::java::lang::String p0 );

/**
 * public static final enum DISPLAY
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale_Category > DISPLAY();

/**
 * public static final enum FORMAT
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale_Category > FORMAT();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Locale_Category( jvalue value );
Locale_Category( jobject object );
Locale_Category( const Locale_Category& object );
Locale_Category( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< Locale_Category> enlister;
};

END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::util::Locale_Category>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::util::Locale_Category>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::Locale_Category>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::util::Locale_Category>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::Locale_Category( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::Locale_Category>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::Locale_Category>& proxy ) : 
    ::jace::proxy::java::util::Locale_Category( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::util::Locale_Category>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::util::Locale_Category>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::util::Locale_Category>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::Locale_Category>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::util::Locale_Category>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::Locale_Category( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Locale_Category>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::Locale_Category( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Locale_Category>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::Locale_Category>& object ) : 
    ::jace::proxy::java::util::Locale_Category( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_UTIL_LOCALE_CATEGORY_H

