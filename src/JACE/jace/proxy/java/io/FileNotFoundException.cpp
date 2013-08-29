
#ifndef JACE_PROXY_JAVA_IO_FILENOTFOUNDEXCEPTION_H
#include "jace/proxy/java/io/FileNotFoundException.h"
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

BEGIN_NAMESPACE_4( jace, proxy, java, io )

/**
 * The Jace C++ proxy class source for java/io/FileNotFoundException.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define FileNotFoundException_INITIALIZER : ::jace::proxy::java::io::IOException( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define FileNotFoundException_INITIALIZER : ::jace::proxy::java::io::IOException( NO_OP )
#endif

FileNotFoundException::FileNotFoundException() FileNotFoundException_INITIALIZER {
  ::jace::JArguments arguments;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

FileNotFoundException::FileNotFoundException( ::jace::proxy::java::lang::String p0 ) FileNotFoundException_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
FileNotFoundException::FileNotFoundException( jvalue value ) FileNotFoundException_INITIALIZER {
  setJavaJniValue( value );
}

FileNotFoundException::FileNotFoundException( jobject object ) FileNotFoundException_INITIALIZER {
  setJavaJniObject( object );
}

FileNotFoundException::FileNotFoundException( const FileNotFoundException& object ) FileNotFoundException_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

FileNotFoundException::FileNotFoundException( const NoOp& noOp ) FileNotFoundException_INITIALIZER {
}

const JClass* FileNotFoundException::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/io/FileNotFoundException" );
  return &javaClass;
}

const JClass* FileNotFoundException::getJavaJniClass() const throw ( JNIException ) {
  return FileNotFoundException::staticGetJavaJniClass();
}

JEnlister< FileNotFoundException> FileNotFoundException::enlister;

END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::io::FileNotFoundException>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::io::FileNotFoundException( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::io::FileNotFoundException>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::io::FileNotFoundException>& proxy ) : 
    ::jace::proxy::java::io::FileNotFoundException( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::io::FileNotFoundException>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::io::FileNotFoundException( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::io::FileNotFoundException>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::io::FileNotFoundException( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::io::FileNotFoundException>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::io::FileNotFoundException>& object ) : 
    ::jace::proxy::java::io::FileNotFoundException( object.getJavaJniValue() ), Object( NO_OP ) {

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

