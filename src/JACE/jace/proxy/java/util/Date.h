
#ifndef JACE_PROXY_JAVA_UTIL_DATE_H
#define JACE_PROXY_JAVA_UTIL_DATE_H

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
#ifndef JACE_PROXY_JAVA_LANG_CLONEABLE_H
#include "jace/proxy/java/lang/Cloneable.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_COMPARABLE_H
#include "jace/proxy/java/lang/Comparable.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JLong;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, util )

/**
 * The Jace C++ proxy class for java/util/Date.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class Date : public virtual ::jace::proxy::java::lang::Object, public virtual ::jace::proxy::java::io::Serializable, public virtual ::jace::proxy::java::lang::Cloneable, public virtual ::jace::proxy::java::lang::Comparable {

public: 

/**
 * Date
 *
 */
Date();

/**
 * Date
 *
 */
Date( ::jace::proxy::types::JLong p0 );

/**
 * Date
 *
 */
Date( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * Date
 *
 */
Date( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2, ::jace::proxy::types::JInt p3, ::jace::proxy::types::JInt p4 );

/**
 * Date
 *
 */
Date( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2, ::jace::proxy::types::JInt p3, ::jace::proxy::types::JInt p4, ::jace::proxy::types::JInt p5 );

/**
 * Date
 *
 */
Date( ::jace::proxy::java::lang::String p0 );

/**
 * clone
 *
 */
::jace::proxy::java::lang::Object clone();

/**
 * UTC
 *
 */
static ::jace::proxy::types::JLong UTC( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2, ::jace::proxy::types::JInt p3, ::jace::proxy::types::JInt p4, ::jace::proxy::types::JInt p5 );

/**
 * parse
 *
 */
static ::jace::proxy::types::JLong parse( ::jace::proxy::java::lang::String p0 );

/**
 * getYear
 *
 */
::jace::proxy::types::JInt getYear();

/**
 * setYear
 *
 */
void setYear( ::jace::proxy::types::JInt p0 );

/**
 * getMonth
 *
 */
::jace::proxy::types::JInt getMonth();

/**
 * setMonth
 *
 */
void setMonth( ::jace::proxy::types::JInt p0 );

/**
 * getDate
 *
 */
::jace::proxy::types::JInt getDate();

/**
 * setDate
 *
 */
void setDate( ::jace::proxy::types::JInt p0 );

/**
 * getDay
 *
 */
::jace::proxy::types::JInt getDay();

/**
 * getHours
 *
 */
::jace::proxy::types::JInt getHours();

/**
 * setHours
 *
 */
void setHours( ::jace::proxy::types::JInt p0 );

/**
 * getMinutes
 *
 */
::jace::proxy::types::JInt getMinutes();

/**
 * setMinutes
 *
 */
void setMinutes( ::jace::proxy::types::JInt p0 );

/**
 * getSeconds
 *
 */
::jace::proxy::types::JInt getSeconds();

/**
 * setSeconds
 *
 */
void setSeconds( ::jace::proxy::types::JInt p0 );

/**
 * getTime
 *
 */
::jace::proxy::types::JLong getTime();

/**
 * setTime
 *
 */
void setTime( ::jace::proxy::types::JLong p0 );

/**
 * before
 *
 */
::jace::proxy::types::JBoolean before( ::jace::proxy::java::util::Date p0 );

/**
 * after
 *
 */
::jace::proxy::types::JBoolean after( ::jace::proxy::java::util::Date p0 );

/**
 * equals
 *
 */
::jace::proxy::types::JBoolean equals( ::jace::proxy::java::lang::Object p0 );

/**
 * compareTo
 *
 */
::jace::proxy::types::JInt compareTo( ::jace::proxy::java::util::Date p0 );

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
 * toLocaleString
 *
 */
::jace::proxy::java::lang::String toLocaleString();

/**
 * toGMTString
 *
 */
::jace::proxy::java::lang::String toGMTString();

/**
 * getTimezoneOffset
 *
 */
::jace::proxy::types::JInt getTimezoneOffset();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Date( jvalue value );
Date( jobject object );
Date( const Date& object );
Date( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< Date> enlister;
};

END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::util::Date>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::util::Date>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::Date>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::util::Date>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::Date( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::Date>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::Date>& proxy ) : 
    ::jace::proxy::java::util::Date( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::util::Date>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::util::Date>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::util::Date>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::Date>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::util::Date>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::Date( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Date>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::Date( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Date>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::Date>& object ) : 
    ::jace::proxy::java::util::Date( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_UTIL_DATE_H

