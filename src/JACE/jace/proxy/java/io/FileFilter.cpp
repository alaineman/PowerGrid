
#ifndef JACE_PROXY_JAVA_IO_FILEFILTER_H
#include "jace/proxy/java/io/FileFilter.h"
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
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_FILE_H
#include "jace/proxy/java/io/File.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, io )

/**
 * The Jace C++ proxy class source for java/io/FileFilter.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define FileFilter_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define FileFilter_INITIALIZER
#endif

::jace::proxy::types::JBoolean FileFilter::accept( ::jace::proxy::java::io::File p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "accept" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
/**
 * Special no arg constructor for interface virtual inheritance
 *
 */
FileFilter::FileFilter() : Object( NO_OP ) { 
}

FileFilter::FileFilter( jvalue value ) FileFilter_INITIALIZER {
  setJavaJniValue( value );
}

FileFilter::FileFilter( jobject object ) FileFilter_INITIALIZER {
  setJavaJniObject( object );
}

FileFilter::FileFilter( const FileFilter& object ) FileFilter_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

FileFilter::FileFilter( const NoOp& noOp ) FileFilter_INITIALIZER {
}

const JClass* FileFilter::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/io/FileFilter" );
  return &javaClass;
}

const JClass* FileFilter::getJavaJniClass() const throw ( JNIException ) {
  return FileFilter::staticGetJavaJniClass();
}

JEnlister< FileFilter> FileFilter::enlister;

END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::io::FileFilter>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::io::FileFilter( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::io::FileFilter>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::io::FileFilter>& proxy ) : 
    ::jace::proxy::java::io::FileFilter( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::io::FileFilter>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::io::FileFilter( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::io::FileFilter>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::io::FileFilter( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::io::FileFilter>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::io::FileFilter>& object ) : 
    ::jace::proxy::java::io::FileFilter( object.getJavaJniValue() ), Object( NO_OP ) {

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

