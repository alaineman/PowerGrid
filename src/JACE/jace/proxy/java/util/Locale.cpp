
#ifndef JACE_PROXY_JAVA_UTIL_LOCALE_H
#include "jace/proxy/java/util/Locale.h"
#endif

/**
 * Standard Jace headers needed to implement this class.
 *
 */
#ifndef JACE_JARGUMENTS_H
#include "jace/JArguments.h"
#endif
using jace::JArguments;

#ifndef JACE_JMETHOD_H
#include "jace/JMethod.h"
#endif
using jace::JMethod;

#ifndef JACE_JFIELD_H
#include "jace/JField.h"
#endif
using jace::JField;

#ifndef JACE_JCLASS_IMPL_H
#include "jace/JClassImpl.h"
#endif
using jace::JClassImpl;


/**
 * Headers for the classes that this class uses.
 *
 */
#ifndef JACE_TYPES_JVOID_H
#include "jace/proxy/types/JVoid.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_LOCALE_CATEGORY_H
#include "jace/proxy/java/util/Locale.Category.h"
#endif
#ifndef JACE_TYPES_JCHAR_H
#include "jace/proxy/types/JChar.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_SET_H
#include "jace/proxy/java/util/Set.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_MISSINGRESOURCEEXCEPTION_H
#include "jace/proxy/java/util/MissingResourceException.h"
#endif
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, util )

/**
 * The Jace C++ proxy class source for java/util/Locale.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Locale_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Locale_INITIALIZER
#endif

Locale::Locale( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::java::lang::String p2 ) Locale_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

Locale::Locale( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 ) Locale_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

Locale::Locale( ::jace::proxy::java::lang::String p0 ) Locale_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::java::util::Locale Locale::getDefault() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Locale >( "getDefault" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::util::Locale Locale::getDefault( ::jace::proxy::java::util::Locale_Category p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::util::Locale >( "getDefault" ).invoke( staticGetJavaJniClass(), arguments );
}

void Locale::setDefault( ::jace::proxy::java::util::Locale p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setDefault" ).invoke( staticGetJavaJniClass(), arguments );
}

void Locale::setDefault( ::jace::proxy::java::util::Locale_Category p0, ::jace::proxy::java::util::Locale p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "setDefault" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::JArray< ::jace::proxy::java::util::Locale > Locale::getAvailableLocales() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::util::Locale > >( "getAvailableLocales" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::JArray< ::jace::proxy::java::lang::String > Locale::getISOCountries() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::String > >( "getISOCountries" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::JArray< ::jace::proxy::java::lang::String > Locale::getISOLanguages() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::lang::String > >( "getISOLanguages" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String Locale::getLanguage() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getLanguage" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Locale::getScript() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getScript" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Locale::getCountry() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getCountry" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Locale::getVariant() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getVariant" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Locale::getExtension( ::jace::proxy::types::JChar p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getExtension" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Set Locale::getExtensionKeys() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Set >( "getExtensionKeys" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Set Locale::getUnicodeLocaleAttributes() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Set >( "getUnicodeLocaleAttributes" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Locale::getUnicodeLocaleType( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getUnicodeLocaleType" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Set Locale::getUnicodeLocaleKeys() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Set >( "getUnicodeLocaleKeys" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Locale::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Locale::toLanguageTag() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toLanguageTag" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Locale Locale::forLanguageTag( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::util::Locale >( "forLanguageTag" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::lang::String Locale::getISO3Language() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getISO3Language" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Locale::getISO3Country() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getISO3Country" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Locale::getDisplayLanguage() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getDisplayLanguage" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Locale::getDisplayLanguage( ::jace::proxy::java::util::Locale p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getDisplayLanguage" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Locale::getDisplayScript() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getDisplayScript" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Locale::getDisplayScript( ::jace::proxy::java::util::Locale p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getDisplayScript" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Locale::getDisplayCountry() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getDisplayCountry" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Locale::getDisplayCountry( ::jace::proxy::java::util::Locale p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getDisplayCountry" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Locale::getDisplayVariant() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getDisplayVariant" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Locale::getDisplayVariant( ::jace::proxy::java::util::Locale p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getDisplayVariant" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Locale::getDisplayName() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getDisplayName" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Locale::getDisplayName( ::jace::proxy::java::util::Locale p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getDisplayName" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object Locale::clone() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "clone" ).invoke( *this, arguments );
}

::jace::proxy::types::JInt Locale::hashCode() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JInt >( "hashCode" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean Locale::equals( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "equals" ).invoke( *this, arguments );
}

/**
 * public static final ENGLISH
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale > Locale::ENGLISH() {
  return ::jace::JField< ::jace::proxy::java::util::Locale >( "ENGLISH" ).get( staticGetJavaJniClass() );
}

/**
 * public static final FRENCH
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale > Locale::FRENCH() {
  return ::jace::JField< ::jace::proxy::java::util::Locale >( "FRENCH" ).get( staticGetJavaJniClass() );
}

/**
 * public static final GERMAN
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale > Locale::GERMAN() {
  return ::jace::JField< ::jace::proxy::java::util::Locale >( "GERMAN" ).get( staticGetJavaJniClass() );
}

/**
 * public static final ITALIAN
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale > Locale::ITALIAN() {
  return ::jace::JField< ::jace::proxy::java::util::Locale >( "ITALIAN" ).get( staticGetJavaJniClass() );
}

/**
 * public static final JAPANESE
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale > Locale::JAPANESE() {
  return ::jace::JField< ::jace::proxy::java::util::Locale >( "JAPANESE" ).get( staticGetJavaJniClass() );
}

/**
 * public static final KOREAN
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale > Locale::KOREAN() {
  return ::jace::JField< ::jace::proxy::java::util::Locale >( "KOREAN" ).get( staticGetJavaJniClass() );
}

/**
 * public static final CHINESE
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale > Locale::CHINESE() {
  return ::jace::JField< ::jace::proxy::java::util::Locale >( "CHINESE" ).get( staticGetJavaJniClass() );
}

/**
 * public static final SIMPLIFIED_CHINESE
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale > Locale::SIMPLIFIED_CHINESE() {
  return ::jace::JField< ::jace::proxy::java::util::Locale >( "SIMPLIFIED_CHINESE" ).get( staticGetJavaJniClass() );
}

/**
 * public static final TRADITIONAL_CHINESE
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale > Locale::TRADITIONAL_CHINESE() {
  return ::jace::JField< ::jace::proxy::java::util::Locale >( "TRADITIONAL_CHINESE" ).get( staticGetJavaJniClass() );
}

/**
 * public static final FRANCE
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale > Locale::FRANCE() {
  return ::jace::JField< ::jace::proxy::java::util::Locale >( "FRANCE" ).get( staticGetJavaJniClass() );
}

/**
 * public static final GERMANY
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale > Locale::GERMANY() {
  return ::jace::JField< ::jace::proxy::java::util::Locale >( "GERMANY" ).get( staticGetJavaJniClass() );
}

/**
 * public static final ITALY
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale > Locale::ITALY() {
  return ::jace::JField< ::jace::proxy::java::util::Locale >( "ITALY" ).get( staticGetJavaJniClass() );
}

/**
 * public static final JAPAN
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale > Locale::JAPAN() {
  return ::jace::JField< ::jace::proxy::java::util::Locale >( "JAPAN" ).get( staticGetJavaJniClass() );
}

/**
 * public static final KOREA
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale > Locale::KOREA() {
  return ::jace::JField< ::jace::proxy::java::util::Locale >( "KOREA" ).get( staticGetJavaJniClass() );
}

/**
 * public static final CHINA
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale > Locale::CHINA() {
  return ::jace::JField< ::jace::proxy::java::util::Locale >( "CHINA" ).get( staticGetJavaJniClass() );
}

/**
 * public static final PRC
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale > Locale::PRC() {
  return ::jace::JField< ::jace::proxy::java::util::Locale >( "PRC" ).get( staticGetJavaJniClass() );
}

/**
 * public static final TAIWAN
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale > Locale::TAIWAN() {
  return ::jace::JField< ::jace::proxy::java::util::Locale >( "TAIWAN" ).get( staticGetJavaJniClass() );
}

/**
 * public static final UK
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale > Locale::UK() {
  return ::jace::JField< ::jace::proxy::java::util::Locale >( "UK" ).get( staticGetJavaJniClass() );
}

/**
 * public static final US
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale > Locale::US() {
  return ::jace::JField< ::jace::proxy::java::util::Locale >( "US" ).get( staticGetJavaJniClass() );
}

/**
 * public static final CANADA
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale > Locale::CANADA() {
  return ::jace::JField< ::jace::proxy::java::util::Locale >( "CANADA" ).get( staticGetJavaJniClass() );
}

/**
 * public static final CANADA_FRENCH
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale > Locale::CANADA_FRENCH() {
  return ::jace::JField< ::jace::proxy::java::util::Locale >( "CANADA_FRENCH" ).get( staticGetJavaJniClass() );
}

/**
 * public static final ROOT
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale > Locale::ROOT() {
  return ::jace::JField< ::jace::proxy::java::util::Locale >( "ROOT" ).get( staticGetJavaJniClass() );
}

/**
 * public static final PRIVATE_USE_EXTENSION
 *
 */
::jace::JFieldProxy< ::jace::proxy::types::JChar > Locale::PRIVATE_USE_EXTENSION() {
  return ::jace::JField< ::jace::proxy::types::JChar >( "PRIVATE_USE_EXTENSION" ).get( staticGetJavaJniClass() );
}

/**
 * public static final UNICODE_LOCALE_EXTENSION
 *
 */
::jace::JFieldProxy< ::jace::proxy::types::JChar > Locale::UNICODE_LOCALE_EXTENSION() {
  return ::jace::JField< ::jace::proxy::types::JChar >( "UNICODE_LOCALE_EXTENSION" ).get( staticGetJavaJniClass() );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Locale::Locale( jvalue value ) Locale_INITIALIZER {
  setJavaJniValue( value );
}

Locale::Locale( jobject object ) Locale_INITIALIZER {
  setJavaJniObject( object );
}

Locale::Locale( const Locale& object ) Locale_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Locale::Locale( const NoOp& noOp ) Locale_INITIALIZER {
}

const JClass* Locale::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/util/Locale" );
  return &javaClass;
}

const JClass* Locale::getJavaJniClass() const throw ( JNIException ) {
  return Locale::staticGetJavaJniClass();
}

JEnlister< Locale> Locale::enlister;

END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
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

