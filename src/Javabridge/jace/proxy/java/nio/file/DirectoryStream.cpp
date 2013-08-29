
#ifndef JACE_PROXY_JAVA_NIO_FILE_DIRECTORYSTREAM_H
#include "jace/proxy/java/nio/file/DirectoryStream.h"
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
#ifndef JACE_PROXY_JAVA_UTIL_ITERATOR_H
#include "jace/proxy/java/util/Iterator.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )

/**
 * The Jace C++ proxy class source for java/nio/file/DirectoryStream.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define DirectoryStream_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define DirectoryStream_INITIALIZER
#endif

::jace::proxy::java::util::Iterator DirectoryStream::iterator() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Iterator >( "iterator" ).invoke( *this, arguments );
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
DirectoryStream::DirectoryStream() : Object( NO_OP ) { 
}

DirectoryStream::DirectoryStream( jvalue value ) DirectoryStream_INITIALIZER {
  setJavaJniValue( value );
}

DirectoryStream::DirectoryStream( jobject object ) DirectoryStream_INITIALIZER {
  setJavaJniObject( object );
}

DirectoryStream::DirectoryStream( const DirectoryStream& object ) DirectoryStream_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

DirectoryStream::DirectoryStream( const NoOp& noOp ) DirectoryStream_INITIALIZER {
}

const JClass* DirectoryStream::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/file/DirectoryStream" );
  return &javaClass;
}

const JClass* DirectoryStream::getJavaJniClass() const throw ( JNIException ) {
  return DirectoryStream::staticGetJavaJniClass();
}

JEnlister< DirectoryStream> DirectoryStream::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::DirectoryStream>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::file::DirectoryStream( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::DirectoryStream>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::file::DirectoryStream>& proxy ) : 
    ::jace::proxy::java::nio::file::DirectoryStream( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::DirectoryStream>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::file::DirectoryStream( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::DirectoryStream>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::file::DirectoryStream( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::DirectoryStream>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::file::DirectoryStream>& object ) : 
    ::jace::proxy::java::nio::file::DirectoryStream( object.getJavaJniValue() ), Object( NO_OP ) {

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

