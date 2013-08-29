
#ifndef JACE_PROXY_JAVA_IO_FILEDESCRIPTOR_H
#include "jace/proxy/java/io/FileDescriptor.h"
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
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_SYNCFAILEDEXCEPTION_H
#include "jace/proxy/java/io/SyncFailedException.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, io )

/**
 * The Jace C++ proxy class source for java/io/FileDescriptor.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define FileDescriptor_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define FileDescriptor_INITIALIZER
#endif

FileDescriptor::FileDescriptor() FileDescriptor_INITIALIZER {
  ::jace::JArguments arguments;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::types::JBoolean FileDescriptor::valid() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "valid" ).invoke( *this, arguments );
}

void FileDescriptor::sync() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "sync" ).invoke( *this, arguments );
}

/**
 * public static final in
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::io::FileDescriptor > FileDescriptor::in() {
  return ::jace::JField< ::jace::proxy::java::io::FileDescriptor >( "in" ).get( staticGetJavaJniClass() );
}

/**
 * public static final out
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::io::FileDescriptor > FileDescriptor::out() {
  return ::jace::JField< ::jace::proxy::java::io::FileDescriptor >( "out" ).get( staticGetJavaJniClass() );
}

/**
 * public static final err
 *
 */
::jace::JFieldProxy< ::jace::proxy::java::io::FileDescriptor > FileDescriptor::err() {
  return ::jace::JField< ::jace::proxy::java::io::FileDescriptor >( "err" ).get( staticGetJavaJniClass() );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
FileDescriptor::FileDescriptor( jvalue value ) FileDescriptor_INITIALIZER {
  setJavaJniValue( value );
}

FileDescriptor::FileDescriptor( jobject object ) FileDescriptor_INITIALIZER {
  setJavaJniObject( object );
}

FileDescriptor::FileDescriptor( const FileDescriptor& object ) FileDescriptor_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

FileDescriptor::FileDescriptor( const NoOp& noOp ) FileDescriptor_INITIALIZER {
}

const JClass* FileDescriptor::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/io/FileDescriptor" );
  return &javaClass;
}

const JClass* FileDescriptor::getJavaJniClass() const throw ( JNIException ) {
  return FileDescriptor::staticGetJavaJniClass();
}

JEnlister< FileDescriptor> FileDescriptor::enlister;

END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::io::FileDescriptor>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::io::FileDescriptor( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::io::FileDescriptor>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::io::FileDescriptor>& proxy ) : 
    ::jace::proxy::java::io::FileDescriptor( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::io::FileDescriptor>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::io::FileDescriptor( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::io::FileDescriptor>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::io::FileDescriptor( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::io::FileDescriptor>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::io::FileDescriptor>& object ) : 
    ::jace::proxy::java::io::FileDescriptor( object.getJavaJniValue() ), Object( NO_OP ) {

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

