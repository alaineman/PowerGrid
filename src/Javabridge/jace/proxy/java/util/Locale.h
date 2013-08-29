
#ifndef JACE_PROXY_JAVA_UTIL_LOCALE_H
#define JACE_PROXY_JAVA_UTIL_LOCALE_H

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
#ifndef JACE_PROXY_JAVA_LANG_CLONEABLE_H
#include "jace/proxy/java/lang/Cloneable.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_SERIALIZABLE_H
#include "jace/proxy/java/io/Serializable.h"
#endif

/**
 * Classes which this class is fully dependent upon.
 *
 */
#ifndef JACE_TYPES_JCHAR_H
#include "jace/proxy/types/JChar.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Locale_Category;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JChar;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Set;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class MissingResourceException;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, util )

/**
 * The Jace C++ proxy class for java/util/Locale.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class Locale : public virtual ::jace::proxy::java::lang::Object, public virtual ::jace::proxy::java::lang::Cloneable, public virtual ::jace::proxy::java::io::Serializable {

public: 

/**
 * Locale
 *
 */
Locale( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::java::lang::String p2 );

/**
 * Locale
 *
 */
Locale( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 );

/**
 * Locale
 *
 */
Locale( ::jace::proxy::java::lang::String p0 );

/**
 * getDefault
 *
 */
static ::jace::proxy::java::util::Locale getDefault();

/**
 * getDefault
 *
 */
static ::jace::proxy::java::util::Locale getDefault( ::jace::proxy::java::util::Locale_Category p0 );

/**
 * setDefault
 *
 */
static void setDefault( ::jace::proxy::java::util::Locale p0 );

/**
 * setDefault
 *
 */
static void setDefault( ::jace::proxy::java::util::Locale_Category p0, ::jace::proxy::java::util::Locale p1 );

/**
 * getAvailableLocales
 *
 */
static ::jace::JArray< ::jace::proxy::java::util::Locale > getAvailableLocales();

/**
 * getISOCountries
 *
 */
static ::jace::JArray< ::jace::proxy::java::lang::String > getISOCountries();

/**
 * getISOLanguages
 *
 */
static ::jace::JArray< ::jace::proxy::java::lang::String > getISOLanguages();

/**
 * getLanguage
 *
 */
::jace::proxy::java::lang::String getLanguage();

/**
 * getScript
 *
 */
::jace::proxy::java::lang::String getScript();

/**
 * getCountry
 *
 */
::jace::proxy::java::lang::String getCountry();

/**
 * getVariant
 *
 */
::jace::proxy::java::lang::String getVariant();

/**
 * getExtension
 *
 */
::jace::proxy::java::lang::String getExtension( ::jace::proxy::types::JChar p0 );

/**
 * getExtensionKeys
 *
 */
::jace::proxy::java::util::Set getExtensionKeys();

/**
 * getUnicodeLocaleAttributes
 *
 */
::jace::proxy::java::util::Set getUnicodeLocaleAttributes();

/**
 * getUnicodeLocaleType
 *
 */
::jace::proxy::java::lang::String getUnicodeLocaleType( ::jace::proxy::java::lang::String p0 );

/**
 * getUnicodeLocaleKeys
 *
 */
::jace::proxy::java::util::Set getUnicodeLocaleKeys();

/**
 * toString
 *
 */
::jace::proxy::java::lang::String toString();

/**
 * toLanguageTag
 *
 */
::jace::proxy::java::lang::String toLanguageTag();

/**
 * forLanguageTag
 *
 */
static ::jace::proxy::java::util::Locale forLanguageTag( ::jace::proxy::java::lang::String p0 );

/**
 * getISO3Language
 *
 */
::jace::proxy::java::lang::String getISO3Language();

/**
 * getISO3Country
 *
 */
::jace::proxy::java::lang::String getISO3Country();

/**
 * getDisplayLanguage
 *
 */
::jace::proxy::java::lang::String getDisplayLanguage();

/**
 * getDisplayLanguage
 *
 */
::jace::proxy::java::lang::String getDisplayLanguage( ::jace::proxy::java::util::Locale p0 );

/**
 * getDisplayScript
 *
 */
::jace::proxy::java::lang::String getDisplayScript();

/**
 * getDisplayScript
 *
 */
::jace::proxy::java::lang::String getDisplayScript( ::jace::proxy::java::util::Locale p0 );

/**
 * getDisplayCountry
 *
 */
::jace::proxy::java::lang::String getDisplayCountry();

/**
 * getDisplayCountry
 *
 */
::jace::proxy::java::lang::String getDisplayCountry( ::jace::proxy::java::util::Locale p0 );

/**
 * getDisplayVariant
 *
 */
::jace::proxy::java::lang::String getDisplayVariant();

/**
 * getDisplayVariant
 *
 */
::jace::proxy::java::lang::String getDisplayVariant( ::jace::proxy::java::util::Locale p0 );

/**
 * getDisplayName
 *
 */
::jace::proxy::java::lang::String getDisplayName();

/**
 * getDisplayName
 *
 */
::jace::proxy::java::lang::String getDisplayName( ::jace::proxy::java::util::Locale p0 );

/**
 * clone
 *
 */
::jace::proxy::java::lang::Object clone();

/**
 * hashCode
 *
 */
::jace::proxy::types::JInt hashCode();

/**
 * equals
 *
 */
::jace::proxy::types::JBoolean equals( ::jace::proxy::java::lang::Object p0 );

/**
 * public static final ENGLISH
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale > ENGLISH();

/**
 * public static final FRENCH
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale > FRENCH();

/**
 * public static final GERMAN
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale > GERMAN();

/**
 * public static final ITALIAN
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale > ITALIAN();

/**
 * public static final JAPANESE
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale > JAPANESE();

/**
 * public static final KOREAN
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale > KOREAN();

/**
 * public static final CHINESE
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale > CHINESE();

/**
 * public static final SIMPLIFIED_CHINESE
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale > SIMPLIFIED_CHINESE();

/**
 * public static final TRADITIONAL_CHINESE
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale > TRADITIONAL_CHINESE();

/**
 * public static final FRANCE
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale > FRANCE();

/**
 * public static final GERMANY
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale > GERMANY();

/**
 * public static final ITALY
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale > ITALY();

/**
 * public static final JAPAN
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale > JAPAN();

/**
 * public static final KOREA
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale > KOREA();

/**
 * public static final CHINA
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale > CHINA();

/**
 * public static final PRC
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale > PRC();

/**
 * public static final TAIWAN
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale > TAIWAN();

/**
 * public static final UK
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale > UK();

/**
 * public static final US
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale > US();

/**
 * public static final CANADA
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale > CANADA();

/**
 * public static final CANADA_FRENCH
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale > CANADA_FRENCH();

/**
 * public static final ROOT
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::java::util::Locale > ROOT();

/**
 * public static final PRIVATE_USE_EXTENSION
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::types::JChar > PRIVATE_USE_EXTENSION();

/**
 * public static final UNICODE_LOCALE_EXTENSION
 *
 */
static ::jace::JFieldProxy< ::jace::proxy::types::JChar > UNICODE_LOCALE_EXTENSION();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Locale( jvalue value );
Locale( jobject object );
Locale( const Locale& object );
Locale( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< Locale> enlister;
};

END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::util::Locale>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::util::Locale>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::Locale>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::util::Locale>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::Locale( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::Locale>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::Locale>& proxy ) : 
    ::jace::proxy::java::util::Locale( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::util::Locale>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::util::Locale>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::util::Locale>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::Locale>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::util::Locale>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::Locale( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Locale>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::Locale( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Locale>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::Locale>& object ) : 
    ::jace::proxy::java::util::Locale( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_UTIL_LOCALE_H

