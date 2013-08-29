
#ifndef JACE_PROXY_JAVA_NIO_FILE_DIRECTORYSTREAM_FILTER_H
#include "jace/proxy/java/nio/file/DirectoryStream.Filter.h"
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
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )

/**
 * The Jace C++ proxy class source for java/nio/file/DirectoryStream$Filter.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define DirectoryStream_Filter_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define DirectoryStream_Filter_INITIALIZER
#endif

::jace::proxy::types::JBoolean DirectoryStream_Filter::accept( ::jace::proxy::java::lang::Object p0 ) {
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
DirectoryStream_Filter::DirectoryStream_Filter() : Object( NO_OP ) { 
}

DirectoryStream_Filter::DirectoryStream_Filter( jvalue value ) DirectoryStream_Filter_INITIALIZER {
  setJavaJniValue( value );
}

DirectoryStream_Filter::DirectoryStream_Filter( jobject object ) DirectoryStream_Filter_INITIALIZER {
  setJavaJniObject( object );
}

DirectoryStream_Filter::DirectoryStream_Filter( const DirectoryStream_Filter& object ) DirectoryStream_Filter_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

DirectoryStream_Filter::DirectoryStream_Filter( const NoOp& noOp ) DirectoryStream_Filter_INITIALIZER {
}

const JClass* DirectoryStream_Filter::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/file/DirectoryStream$Filter" );
  return &javaClass;
}

const JClass* DirectoryStream_Filter::getJavaJniClass() const throw ( JNIException ) {
  return DirectoryStream_Filter::staticGetJavaJniClass();
}

JEnlister< DirectoryStream_Filter> DirectoryStream_Filter::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::DirectoryStream_Filter>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::file::DirectoryStream_Filter( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::DirectoryStream_Filter>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::file::DirectoryStream_Filter>& proxy ) : 
    ::jace::proxy::java::nio::file::DirectoryStream_Filter( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::DirectoryStream_Filter>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::file::DirectoryStream_Filter( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::DirectoryStream_Filter>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::file::DirectoryStream_Filter( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::DirectoryStream_Filter>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::file::DirectoryStream_Filter>& object ) : 
    ::jace::proxy::java::nio::file::DirectoryStream_Filter( object.getJavaJniValue() ), Object( NO_OP ) {

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

