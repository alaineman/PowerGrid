
#ifndef JACE_PROXY_JAVA_NIO_FILE_FILESTORE_H
#include "jace/proxy/java/nio/file/FileStore.h"
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
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_TYPES_JLONG_H
#include "jace/proxy/types/JLong.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_CLASS_H
#include "jace/proxy/java/lang/Class.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_FILE_ATTRIBUTE_FILESTOREATTRIBUTEVIEW_H
#include "jace/proxy/java/nio/file/attribute/FileStoreAttributeView.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )

/**
 * The Jace C++ proxy class source for java/nio/file/FileStore.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define FileStore_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define FileStore_INITIALIZER
#endif

::jace::proxy::java::lang::String FileStore::name() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "name" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String FileStore::type() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "type" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean FileStore::isReadOnly() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isReadOnly" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong FileStore::getTotalSpace() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "getTotalSpace" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong FileStore::getUsableSpace() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "getUsableSpace" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong FileStore::getUnallocatedSpace() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "getUnallocatedSpace" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean FileStore::supportsFileAttributeView( ::jace::proxy::java::lang::Class p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "supportsFileAttributeView" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean FileStore::supportsFileAttributeView( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "supportsFileAttributeView" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::attribute::FileStoreAttributeView FileStore::getFileStoreAttributeView( ::jace::proxy::java::lang::Class p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::attribute::FileStoreAttributeView >( "getFileStoreAttributeView" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object FileStore::getAttribute( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "getAttribute" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
FileStore::FileStore( jvalue value ) FileStore_INITIALIZER {
  setJavaJniValue( value );
}

FileStore::FileStore( jobject object ) FileStore_INITIALIZER {
  setJavaJniObject( object );
}

FileStore::FileStore( const FileStore& object ) FileStore_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

FileStore::FileStore( const NoOp& noOp ) FileStore_INITIALIZER {
}

const JClass* FileStore::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/file/FileStore" );
  return &javaClass;
}

const JClass* FileStore::getJavaJniClass() const throw ( JNIException ) {
  return FileStore::staticGetJavaJniClass();
}

JEnlister< FileStore> FileStore::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::FileStore>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::file::FileStore( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::FileStore>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::file::FileStore>& proxy ) : 
    ::jace::proxy::java::nio::file::FileStore( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::FileStore>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::file::FileStore( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::FileStore>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::file::FileStore( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::FileStore>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::file::FileStore>& object ) : 
    ::jace::proxy::java::nio::file::FileStore( object.getJavaJniValue() ), Object( NO_OP ) {

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

