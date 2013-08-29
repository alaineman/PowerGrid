
#ifndef JACE_PROXY_JAVA_LANG_ABSTRACTSTRINGBUILDER_H
#define JACE_PROXY_JAVA_LANG_ABSTRACTSTRINGBUILDER_H

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
#ifndef JACE_PROXY_JAVA_LANG_APPENDABLE_H
#include "jace/proxy/java/lang/Appendable.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_CHARSEQUENCE_H
#include "jace/proxy/java/lang/CharSequence.h"
#endif

/**
 * Classes which this class is fully dependent upon.
 *
 */
#ifndef JACE_TYPES_JCHAR_H
#include "jace/proxy/types/JChar.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JChar;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class StringBuffer;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JLong;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JFloat;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JDouble;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )

/**
 * The Jace C++ proxy class for java/lang/AbstractStringBuilder.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class AbstractStringBuilder : public virtual ::jace::proxy::java::lang::Object, public virtual ::jace::proxy::java::lang::Appendable, public virtual ::jace::proxy::java::lang::CharSequence {

public: 

/**
 * length
 *
 */
::jace::proxy::types::JInt length();

/**
 * capacity
 *
 */
::jace::proxy::types::JInt capacity();

/**
 * ensureCapacity
 *
 */
void ensureCapacity( ::jace::proxy::types::JInt p0 );

/**
 * trimToSize
 *
 */
void trimToSize();

/**
 * setLength
 *
 */
void setLength( ::jace::proxy::types::JInt p0 );

/**
 * charAt
 *
 */
::jace::proxy::types::JChar charAt( ::jace::proxy::types::JInt p0 );

/**
 * codePointAt
 *
 */
::jace::proxy::types::JInt codePointAt( ::jace::proxy::types::JInt p0 );

/**
 * codePointBefore
 *
 */
::jace::proxy::types::JInt codePointBefore( ::jace::proxy::types::JInt p0 );

/**
 * codePointCount
 *
 */
::jace::proxy::types::JInt codePointCount( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * offsetByCodePoints
 *
 */
::jace::proxy::types::JInt offsetByCodePoints( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getChars
 *
 */
void getChars( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::JArray< ::jace::proxy::types::JChar > p2, ::jace::proxy::types::JInt p3 );

/**
 * setCharAt
 *
 */
void setCharAt( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JChar p1 );

/**
 * append
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder append( ::jace::proxy::java::lang::Object p0 );

/**
 * append
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder append( ::jace::proxy::java::lang::String p0 );

/**
 * append
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder append( ::jace::proxy::java::lang::StringBuffer p0 );

/**
 * append
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder append( ::jace::proxy::java::lang::CharSequence p0 );

/**
 * append
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder append( ::jace::proxy::java::lang::CharSequence p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * append
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder append( ::jace::JArray< ::jace::proxy::types::JChar > p0 );

/**
 * append
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder append( ::jace::JArray< ::jace::proxy::types::JChar > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * append
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder append( ::jace::proxy::types::JBoolean p0 );

/**
 * append
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder append( ::jace::proxy::types::JChar p0 );

/**
 * append
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder append( ::jace::proxy::types::JInt p0 );

/**
 * append
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder append( ::jace::proxy::types::JLong p0 );

/**
 * append
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder append( ::jace::proxy::types::JFloat p0 );

/**
 * append
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder append( ::jace::proxy::types::JDouble p0 );

/**
 * delete_
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder delete_( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * appendCodePoint
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder appendCodePoint( ::jace::proxy::types::JInt p0 );

/**
 * deleteCharAt
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder deleteCharAt( ::jace::proxy::types::JInt p0 );

/**
 * replace
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder replace( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::java::lang::String p2 );

/**
 * substring
 *
 */
::jace::proxy::java::lang::String substring( ::jace::proxy::types::JInt p0 );

/**
 * subSequence
 *
 */
::jace::proxy::java::lang::CharSequence subSequence( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * substring
 *
 */
::jace::proxy::java::lang::String substring( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * insert
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder insert( ::jace::proxy::types::JInt p0, ::jace::JArray< ::jace::proxy::types::JChar > p1, ::jace::proxy::types::JInt p2, ::jace::proxy::types::JInt p3 );

/**
 * insert
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder insert( ::jace::proxy::types::JInt p0, ::jace::proxy::java::lang::Object p1 );

/**
 * insert
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder insert( ::jace::proxy::types::JInt p0, ::jace::proxy::java::lang::String p1 );

/**
 * insert
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder insert( ::jace::proxy::types::JInt p0, ::jace::JArray< ::jace::proxy::types::JChar > p1 );

/**
 * insert
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder insert( ::jace::proxy::types::JInt p0, ::jace::proxy::java::lang::CharSequence p1 );

/**
 * insert
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder insert( ::jace::proxy::types::JInt p0, ::jace::proxy::java::lang::CharSequence p1, ::jace::proxy::types::JInt p2, ::jace::proxy::types::JInt p3 );

/**
 * insert
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder insert( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JBoolean p1 );

/**
 * insert
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder insert( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JChar p1 );

/**
 * insert
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder insert( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * insert
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder insert( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JLong p1 );

/**
 * insert
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder insert( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JFloat p1 );

/**
 * insert
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder insert( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JDouble p1 );

/**
 * indexOf
 *
 */
::jace::proxy::types::JInt indexOf( ::jace::proxy::java::lang::String p0 );

/**
 * indexOf
 *
 */
::jace::proxy::types::JInt indexOf( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JInt p1 );

/**
 * lastIndexOf
 *
 */
::jace::proxy::types::JInt lastIndexOf( ::jace::proxy::java::lang::String p0 );

/**
 * lastIndexOf
 *
 */
::jace::proxy::types::JInt lastIndexOf( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JInt p1 );

/**
 * reverse
 *
 */
::jace::proxy::java::lang::AbstractStringBuilder reverse();

/**
 * toString
 *
 */
::jace::proxy::java::lang::String toString();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
AbstractStringBuilder( jvalue value );
AbstractStringBuilder( jobject object );
AbstractStringBuilder( const AbstractStringBuilder& object );
AbstractStringBuilder( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< AbstractStringBuilder> enlister;
};

END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::lang::AbstractStringBuilder>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::lang::AbstractStringBuilder>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::AbstractStringBuilder>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::lang::AbstractStringBuilder>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::lang::AbstractStringBuilder( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::lang::AbstractStringBuilder>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::lang::AbstractStringBuilder>& proxy ) : 
    ::jace::proxy::java::lang::AbstractStringBuilder( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::lang::AbstractStringBuilder>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::lang::AbstractStringBuilder>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::lang::AbstractStringBuilder>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::AbstractStringBuilder>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::lang::AbstractStringBuilder>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::lang::AbstractStringBuilder( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::AbstractStringBuilder>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::lang::AbstractStringBuilder( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::lang::AbstractStringBuilder>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::lang::AbstractStringBuilder>& object ) : 
    ::jace::proxy::java::lang::AbstractStringBuilder( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_LANG_ABSTRACTSTRINGBUILDER_H

