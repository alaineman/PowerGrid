
#ifndef JACE_PROXY_JAVA_IO_CONSOLE_H
#include "jace/proxy/java/io/Console.h"
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
#ifndef JACE_PROXY_JAVA_IO_PRINTWRITER_H
#include "jace/proxy/java/io/PrintWriter.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_READER_H
#include "jace/proxy/java/io/Reader.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_TYPES_JVOID_H
#include "jace/proxy/types/JVoid.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, io )

/**
 * The Jace C++ proxy class source for java/io/Console.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Console_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Console_INITIALIZER
#endif

::jace::proxy::java::io::PrintWriter Console::writer() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::io::PrintWriter >( "writer" ).invoke( *this, arguments );
}

::jace::proxy::java::io::Reader Console::reader() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::io::Reader >( "reader" ).invoke( *this, arguments );
}

::jace::proxy::java::io::Console Console::format( ::jace::proxy::java::lang::String p0, ::jace::JArray< ::jace::proxy::java::lang::Object > p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::io::Console >( "format" ).invoke( *this, arguments );
}

::jace::proxy::java::io::Console Console::printf( ::jace::proxy::java::lang::String p0, ::jace::JArray< ::jace::proxy::java::lang::Object > p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::io::Console >( "printf" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Console::readLine( ::jace::proxy::java::lang::String p0, ::jace::JArray< ::jace::proxy::java::lang::Object > p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "readLine" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Console::readLine() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "readLine" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::types::JChar > Console::readPassword( ::jace::proxy::java::lang::String p0, ::jace::JArray< ::jace::proxy::java::lang::Object > p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::types::JChar > >( "readPassword" ).invoke( *this, arguments );
}

::jace::JArray< ::jace::proxy::types::JChar > Console::readPassword() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::JArray< ::jace::proxy::types::JChar > >( "readPassword" ).invoke( *this, arguments );
}

void Console::flush() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "flush" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Console::Console( jvalue value ) Console_INITIALIZER {
  setJavaJniValue( value );
}

Console::Console( jobject object ) Console_INITIALIZER {
  setJavaJniObject( object );
}

Console::Console( const Console& object ) Console_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Console::Console( const NoOp& noOp ) Console_INITIALIZER {
}

const JClass* Console::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/io/Console" );
  return &javaClass;
}

const JClass* Console::getJavaJniClass() const throw ( JNIException ) {
  return Console::staticGetJavaJniClass();
}

JEnlister< Console> Console::enlister;

END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::io::Console>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::io::Console( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::io::Console>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::io::Console>& proxy ) : 
    ::jace::proxy::java::io::Console( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::io::Console>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::io::Console( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::io::Console>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::io::Console( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::io::Console>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::io::Console>& object ) : 
    ::jace::proxy::java::io::Console( object.getJavaJniValue() ), Object( NO_OP ) {

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

