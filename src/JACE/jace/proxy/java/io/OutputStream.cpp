
#ifndef JACE_PROXY_JAVA_IO_OUTPUTSTREAM_H
#include "jace/proxy/java/io/OutputStream.h"
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
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, io )

/**
 * The Jace C++ proxy class source for java/io/OutputStream.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define OutputStream_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define OutputStream_INITIALIZER
#endif

OutputStream::OutputStream() OutputStream_INITIALIZER {
  ::jace::JArguments arguments;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

void OutputStream::write( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "write" ).invoke( *this, arguments );
}

void OutputStream::write( ::jace::JArray< ::jace::proxy::types::JByte > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "write" ).invoke( *this, arguments );
}

void OutputStream::write( ::jace::JArray< ::jace::proxy::types::JByte > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "write" ).invoke( *this, arguments );
}

void OutputStream::flush() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "flush" ).invoke( *this, arguments );
}

void OutputStream::close() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "close" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
OutputStream::OutputStream( jvalue value ) OutputStream_INITIALIZER {
  setJavaJniValue( value );
}

OutputStream::OutputStream( jobject object ) OutputStream_INITIALIZER {
  setJavaJniObject( object );
}

OutputStream::OutputStream( const OutputStream& object ) OutputStream_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

OutputStream::OutputStream( const NoOp& noOp ) OutputStream_INITIALIZER {
}

const JClass* OutputStream::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/io/OutputStream" );
  return &javaClass;
}

const JClass* OutputStream::getJavaJniClass() const throw ( JNIException ) {
  return OutputStream::staticGetJavaJniClass();
}

JEnlister< OutputStream> OutputStream::enlister;

END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::io::OutputStream>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::io::OutputStream( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::io::OutputStream>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::io::OutputStream>& proxy ) : 
    ::jace::proxy::java::io::OutputStream( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::io::OutputStream>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::io::OutputStream( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::io::OutputStream>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::io::OutputStream( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::io::OutputStream>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::io::OutputStream>& object ) : 
    ::jace::proxy::java::io::OutputStream( object.getJavaJniValue() ), Object( NO_OP ) {

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

