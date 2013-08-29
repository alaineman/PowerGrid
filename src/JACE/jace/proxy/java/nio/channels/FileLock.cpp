
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_FILELOCK_H
#include "jace/proxy/java/nio/channels/FileLock.h"
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
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_FILECHANNEL_H
#include "jace/proxy/java/nio/channels/FileChannel.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_CHANNEL_H
#include "jace/proxy/java/nio/channels/Channel.h"
#endif
#ifndef JACE_TYPES_JLONG_H
#include "jace/proxy/types/JLong.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_TYPES_JVOID_H
#include "jace/proxy/types/JVoid.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif

BEGIN_NAMESPACE_5( jace, proxy, java, nio, channels )

/**
 * The Jace C++ proxy class source for java/nio/channels/FileLock.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define FileLock_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define FileLock_INITIALIZER
#endif

::jace::proxy::java::nio::channels::FileChannel FileLock::channel() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::channels::FileChannel >( "channel" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::channels::Channel FileLock::acquiredBy() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::channels::Channel >( "acquiredBy" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong FileLock::position() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "position" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong FileLock::size() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "size" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean FileLock::isShared() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isShared" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean FileLock::overlaps( ::jace::proxy::types::JLong p0, ::jace::proxy::types::JLong p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "overlaps" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean FileLock::isValid() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isValid" ).invoke( *this, arguments );
}

void FileLock::release() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "release" ).invoke( *this, arguments );
}

void FileLock::close() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "close" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String FileLock::toString() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "toString" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
FileLock::FileLock( jvalue value ) FileLock_INITIALIZER {
  setJavaJniValue( value );
}

FileLock::FileLock( jobject object ) FileLock_INITIALIZER {
  setJavaJniObject( object );
}

FileLock::FileLock( const FileLock& object ) FileLock_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

FileLock::FileLock( const NoOp& noOp ) FileLock_INITIALIZER {
}

const JClass* FileLock::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/channels/FileLock" );
  return &javaClass;
}

const JClass* FileLock::getJavaJniClass() const throw ( JNIException ) {
  return FileLock::staticGetJavaJniClass();
}

JEnlister< FileLock> FileLock::enlister;

END_NAMESPACE_5( jace, proxy, java, nio, channels )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::FileLock>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::channels::FileLock( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::FileLock>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::channels::FileLock>& proxy ) : 
    ::jace::proxy::java::nio::channels::FileLock( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::FileLock>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::channels::FileLock( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::FileLock>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::channels::FileLock( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::FileLock>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::channels::FileLock>& object ) : 
    ::jace::proxy::java::nio::channels::FileLock( object.getJavaJniValue() ), Object( NO_OP ) {

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

