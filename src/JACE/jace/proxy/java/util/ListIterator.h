
#ifndef JACE_PROXY_JAVA_UTIL_LISTITERATOR_H
#define JACE_PROXY_JAVA_UTIL_LISTITERATOR_H

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
#ifndef JACE_PROXY_JAVA_UTIL_ITERATOR_H
#include "jace/proxy/java/util/Iterator.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, util )

/**
 * The Jace C++ proxy class for java/util/ListIterator.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class ListIterator : public virtual ::jace::proxy::java::lang::Object, public virtual ::jace::proxy::java::util::Iterator {

public: 

/**
 * hasNext
 *
 */
::jace::proxy::types::JBoolean hasNext();

/**
 * next
 *
 */
::jace::proxy::java::lang::Object next();

/**
 * hasPrevious
 *
 */
::jace::proxy::types::JBoolean hasPrevious();

/**
 * previous
 *
 */
::jace::proxy::java::lang::Object previous();

/**
 * nextIndex
 *
 */
::jace::proxy::types::JInt nextIndex();

/**
 * previousIndex
 *
 */
::jace::proxy::types::JInt previousIndex();

/**
 * remove
 *
 */
void remove();

/**
 * set
 *
 */
void set( ::jace::proxy::java::lang::Object p0 );

/**
 * add
 *
 */
void add( ::jace::proxy::java::lang::Object p0 );

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
/**
 * Special no arg constructor for interface virtual inheritance
 *
 */
ListIterator();
ListIterator( jvalue value );
ListIterator( jobject object );
ListIterator( const ListIterator& object );
ListIterator( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< ListIterator> enlister;
};

END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::util::ListIterator>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::util::ListIterator>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::ListIterator>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::util::ListIterator>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::ListIterator( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::ListIterator>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::ListIterator>& proxy ) : 
    ::jace::proxy::java::util::ListIterator( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::util::ListIterator>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::util::ListIterator>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::util::ListIterator>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::ListIterator>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::util::ListIterator>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::ListIterator( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::ListIterator>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::ListIterator( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::ListIterator>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::ListIterator>& object ) : 
    ::jace::proxy::java::util::ListIterator( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_UTIL_LISTITERATOR_H

