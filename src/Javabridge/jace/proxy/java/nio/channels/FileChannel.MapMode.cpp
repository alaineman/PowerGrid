
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_FILECHANNEL_MAPMODE_H
#include "jace/proxy/java/nio/channels/FileChannel.MapMode.h"
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

BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )

/**
 * The Jace C++ proxy class source for java/nio/channels/FileChannel$MapMode.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define FileChannel_MapMode_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define FileChannel_MapMode_INITIALIZER
#endif

::jace::proxy::java::lang::String FileChannel_MapMode::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

/**
 * public static final READ_ONLY
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::nio::channels::FileChannel_MapMode > FileChannel_MapMode::READ_ONLY() {
  return ::jace::JField< ::jace::proxy::java::nio::channels::FileChannel_MapMode >( "READ_ONLY" ).get( staticGetJavaJniClass() );
}

/**
 * public static final READ_WRITE
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::nio::channels::FileChannel_MapMode > FileChannel_MapMode::READ_WRITE() {
  return ::jace::JField< ::jace::proxy::java::nio::channels::FileChannel_MapMode >( "READ_WRITE" ).get( staticGetJavaJniClass() );
}

/**
 * public static final PRIVATE
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::nio::channels::FileChannel_MapMode > FileChannel_MapMode::PRIVATE() {
  return ::jace::JField< ::jace::proxy::java::nio::channels::FileChannel_MapMode >( "PRIVATE" ).get( staticGetJavaJniClass() );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
FileChannel_MapMode::FileChannel_MapMode( jvalue value ) FileChannel_MapMode_INITIALIZER {
  setJavaJniValue( value );
}

FileChannel_MapMode::FileChannel_MapMode( jobject object ) FileChannel_MapMode_INITIALIZER {
  setJavaJniObject( object );
}

FileChannel_MapMode::FileChannel_MapMode( const FileChannel_MapMode& object ) FileChannel_MapMode_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

FileChannel_MapMode::FileChannel_MapMode( const NoOp& noOp ) FileChannel_MapMode_INITIALIZER {
}

const JClass* FileChannel_MapMode::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/channels/FileChannel$MapMode" );
  return &javaClass;
}

const JClass* FileChannel_MapMode::getJavaJniClass() const throw ( JNIException ) {
  return FileChannel_MapMode::staticGetJavaJniClass();
}

JEnlister< FileChannel_MapMode> FileChannel_MapMode::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::FileChannel_MapMode>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::channels::FileChannel_MapMode( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::FileChannel_MapMode>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::channels::FileChannel_MapMode>& proxy ) : 
    ::jace::proxy::java::nio::channels::FileChannel_MapMode( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::FileChannel_MapMode>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::channels::FileChannel_MapMode( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::FileChannel_MapMode>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::channels::FileChannel_MapMode( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::FileChannel_MapMode>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::channels::FileChannel_MapMode>& object ) : 
    ::jace::proxy::java::nio::channels::FileChannel_MapMode( object.getJavaJniValue() ), Object( NO_OP ) {

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

