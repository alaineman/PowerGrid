
#ifndef JACE_PROXY_JAVA_UTIL_LOCALE_CATEGORY_H
#include "jace/proxy/java/util/Locale.Category.h"
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
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, util )

/**
 * The Jace C++ proxy class source for java/util/Locale$Category.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Locale_Category_INITIALIZER : ::jace::proxy::java::lang::Enum( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Locale_Category_INITIALIZER : ::jace::proxy::java::lang::Enum( NO_OP )
#endif

::jace::JArray< ::jace::proxy::java::util::Locale_Category > Locale_Category::values() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::java::util::Locale_Category > >( "values" ).invoke( staticGetJavaJniClass(), arguments );
}

::jace::proxy::java::util::Locale_Category Locale_Category::valueOf( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::util::Locale_Category >( "valueOf" ).invoke( staticGetJavaJniClass(), arguments );
}

/**
 * public static final enum DISPLAY
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale_Category > Locale_Category::DISPLAY() {
  return ::jace::JField< ::jace::proxy::java::util::Locale_Category >( "DISPLAY" ).get( staticGetJavaJniClass() );
}

/**
 * public static final enum FORMAT
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::util::Locale_Category > Locale_Category::FORMAT() {
  return ::jace::JField< ::jace::proxy::java::util::Locale_Category >( "FORMAT" ).get( staticGetJavaJniClass() );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Locale_Category::Locale_Category( jvalue value ) Locale_Category_INITIALIZER {
  setJavaJniValue( value );
}

Locale_Category::Locale_Category( jobject object ) Locale_Category_INITIALIZER {
  setJavaJniObject( object );
}

Locale_Category::Locale_Category( const Locale_Category& object ) Locale_Category_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Locale_Category::Locale_Category( const NoOp& noOp ) Locale_Category_INITIALIZER {
}

const JClass* Locale_Category::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/util/Locale$Category" );
  return &javaClass;
}

const JClass* Locale_Category::getJavaJniClass() const throw ( JNIException ) {
  return Locale_Category::staticGetJavaJniClass();
}

JEnlister< Locale_Category> Locale_Category::enlister;

END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
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

