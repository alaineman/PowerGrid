
#ifndef JACE_PROXY_JAVA_UTIL_SORTEDMAP_H
#define JACE_PROXY_JAVA_UTIL_SORTEDMAP_H

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
#ifndef JACE_PROXY_JAVA_UTIL_MAP_H
#include "jace/proxy/java/util/Map.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Comparator;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Set;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Collection;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_4( jace, proxy, java, util )

/**
 * The Jace C++ proxy class for java/util/SortedMap.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class SortedMap : public virtual ::jace::proxy::java::lang::Object, public virtual ::jace::proxy::java::util::Map {

public: 

/**
 * comparator
 *
 */
::jace::proxy::java::util::Comparator comparator();

/**
 * subMap
 *
 */
::jace::proxy::java::util::SortedMap subMap( ::jace::proxy::java::lang::Object p0, ::jace::proxy::java::lang::Object p1 );

/**
 * headMap
 *
 */
::jace::proxy::java::util::SortedMap headMap( ::jace::proxy::java::lang::Object p0 );

/**
 * tailMap
 *
 */
::jace::proxy::java::util::SortedMap tailMap( ::jace::proxy::java::lang::Object p0 );

/**
 * firstKey
 *
 */
::jace::proxy::java::lang::Object firstKey();

/**
 * lastKey
 *
 */
::jace::proxy::java::lang::Object lastKey();

/**
 * keySet
 *
 */
::jace::proxy::java::util::Set keySet();

/**
 * values
 *
 */
::jace::proxy::java::util::Collection values();

/**
 * entrySet
 *
 */
::jace::proxy::java::util::Set entrySet();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
/**
 * Special no arg constructor for interface virtual inheritance
 *
 */
SortedMap();
SortedMap( jvalue value );
SortedMap( jobject object );
SortedMap( const SortedMap& object );
SortedMap( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< SortedMap> enlister;
};

END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::util::SortedMap>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::util::SortedMap>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::SortedMap>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::util::SortedMap>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::SortedMap( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::SortedMap>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::SortedMap>& proxy ) : 
    ::jace::proxy::java::util::SortedMap( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::util::SortedMap>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::util::SortedMap>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::util::SortedMap>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::SortedMap>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::util::SortedMap>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::SortedMap( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::SortedMap>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::SortedMap( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::SortedMap>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::SortedMap>& object ) : 
    ::jace::proxy::java::util::SortedMap( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_UTIL_SORTEDMAP_H

