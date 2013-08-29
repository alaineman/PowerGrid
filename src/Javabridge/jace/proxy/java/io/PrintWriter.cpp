
#ifndef JACE_PROXY_JAVA_IO_PRINTWRITER_H
#include "jace/proxy/java/io/PrintWriter.h"
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
#ifndef JACE_PROXY_JAVA_IO_OUTPUTSTREAM_H
#include "jace/proxy/java/io/OutputStream.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_FILENOTFOUNDEXCEPTION_H
#include "jace/proxy/java/io/FileNotFoundException.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_UNSUPPORTEDENCODINGEXCEPTION_H
#include "jace/proxy/java/io/UnsupportedEncodingException.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_FILE_H
#include "jace/proxy/java/io/File.h"
#endif
#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif
#ifndef JACE_TYPES_JCHAR_H
#include "jace/proxy/types/JChar.h"
#endif
#ifndef JACE_TYPES_JLONG_H
#include "jace/proxy/types/JLong.h"
#endif
#ifndef JACE_TYPES_JFLOAT_H
#include "jace/proxy/types/JFloat.h"
#endif
#ifndef JACE_TYPES_JDOUBLE_H
#include "jace/proxy/types/JDouble.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_OBJECT_H
#include "jace/proxy/java/lang/Object.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_LOCALE_H
#include "jace/proxy/java/util/Locale.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_CHARSEQUENCE_H
#include "jace/proxy/java/lang/CharSequence.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, io )

/**
 * The Jace C++ proxy class source for java/io/PrintWriter.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define PrintWriter_INITIALIZER : ::jace::proxy::java::io::Writer( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define PrintWriter_INITIALIZER : ::jace::proxy::java::io::Writer( NO_OP )
#endif

PrintWriter::PrintWriter( ::jace::proxy::java::io::Writer p0 ) PrintWriter_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

PrintWriter::PrintWriter( ::jace::proxy::java::io::Writer p0, ::jace::proxy::types::JBoolean p1 ) PrintWriter_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

PrintWriter::PrintWriter( ::jace::proxy::java::io::OutputStream p0 ) PrintWriter_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

PrintWriter::PrintWriter( ::jace::proxy::java::io::OutputStream p0, ::jace::proxy::types::JBoolean p1 ) PrintWriter_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

PrintWriter::PrintWriter( ::jace::proxy::java::lang::String p0 ) PrintWriter_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

PrintWriter::PrintWriter( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 ) PrintWriter_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

PrintWriter::PrintWriter( ::jace::proxy::java::io::File p0 ) PrintWriter_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

PrintWriter::PrintWriter( ::jace::proxy::java::io::File p0, ::jace::proxy::java::lang::String p1 ) PrintWriter_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

void PrintWriter::flush() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "flush" ).invoke( *this, arguments );
}

void PrintWriter::close() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "close" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean PrintWriter::checkError() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "checkError" ).invoke( *this, arguments );
}

void PrintWriter::write( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "write" ).invoke( *this, arguments );
}

void PrintWriter::write( ::jace::JArray< ::jace::proxy::types::JChar > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "write" ).invoke( *this, arguments );
}

void PrintWriter::write( ::jace::JArray< ::jace::proxy::types::JChar > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "write" ).invoke( *this, arguments );
}

void PrintWriter::write( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "write" ).invoke( *this, arguments );
}

void PrintWriter::write( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "write" ).invoke( *this, arguments );
}

void PrintWriter::print( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "print" ).invoke( *this, arguments );
}

void PrintWriter::print( ::jace::proxy::types::JChar p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "print" ).invoke( *this, arguments );
}

void PrintWriter::print( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "print" ).invoke( *this, arguments );
}

void PrintWriter::print( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "print" ).invoke( *this, arguments );
}

void PrintWriter::print( ::jace::proxy::types::JFloat p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "print" ).invoke( *this, arguments );
}

void PrintWriter::print( ::jace::proxy::types::JDouble p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "print" ).invoke( *this, arguments );
}

void PrintWriter::print( ::jace::JArray< ::jace::proxy::types::JChar > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "print" ).invoke( *this, arguments );
}

void PrintWriter::print( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "print" ).invoke( *this, arguments );
}

void PrintWriter::print( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "print" ).invoke( *this, arguments );
}

void PrintWriter::println() {
  ::jace::JArguments arguments;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "println" ).invoke( *this, arguments );
}

void PrintWriter::println( ::jace::proxy::types::JBoolean p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "println" ).invoke( *this, arguments );
}

void PrintWriter::println( ::jace::proxy::types::JChar p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "println" ).invoke( *this, arguments );
}

void PrintWriter::println( ::jace::proxy::types::JInt p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "println" ).invoke( *this, arguments );
}

void PrintWriter::println( ::jace::proxy::types::JLong p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "println" ).invoke( *this, arguments );
}

void PrintWriter::println( ::jace::proxy::types::JFloat p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "println" ).invoke( *this, arguments );
}

void PrintWriter::println( ::jace::proxy::types::JDouble p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "println" ).invoke( *this, arguments );
}

void PrintWriter::println( ::jace::JArray< ::jace::proxy::types::JChar > p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "println" ).invoke( *this, arguments );
}

void PrintWriter::println( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "println" ).invoke( *this, arguments );
}

void PrintWriter::println( ::jace::proxy::java::lang::Object p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "println" ).invoke( *this, arguments );
}

::jace::proxy::java::io::PrintWriter PrintWriter::printf( ::jace::proxy::java::lang::String p0, ::jace::JArray< ::jace::proxy::java::lang::Object > p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::io::PrintWriter >( "printf" ).invoke( *this, arguments );
}

::jace::proxy::java::io::PrintWriter PrintWriter::printf( ::jace::proxy::java::util::Locale p0, ::jace::proxy::java::lang::String p1, ::jace::JArray< ::jace::proxy::java::lang::Object > p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::io::PrintWriter >( "printf" ).invoke( *this, arguments );
}

::jace::proxy::java::io::PrintWriter PrintWriter::format( ::jace::proxy::java::lang::String p0, ::jace::JArray< ::jace::proxy::java::lang::Object > p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::io::PrintWriter >( "format" ).invoke( *this, arguments );
}

::jace::proxy::java::io::PrintWriter PrintWriter::format( ::jace::proxy::java::util::Locale p0, ::jace::proxy::java::lang::String p1, ::jace::JArray< ::jace::proxy::java::lang::Object > p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::io::PrintWriter >( "format" ).invoke( *this, arguments );
}

::jace::proxy::java::io::PrintWriter PrintWriter::append( ::jace::proxy::java::lang::CharSequence p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::io::PrintWriter >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::io::PrintWriter PrintWriter::append( ::jace::proxy::java::lang::CharSequence p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  return ::jace::JMethod< ::jace::proxy::java::io::PrintWriter >( "append" ).invoke( *this, arguments );
}

::jace::proxy::java::io::PrintWriter PrintWriter::append( ::jace::proxy::types::JChar p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::io::PrintWriter >( "append" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
PrintWriter::PrintWriter( jvalue value ) PrintWriter_INITIALIZER {
  setJavaJniValue( value );
}

PrintWriter::PrintWriter( jobject object ) PrintWriter_INITIALIZER {
  setJavaJniObject( object );
}

PrintWriter::PrintWriter( const PrintWriter& object ) PrintWriter_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

PrintWriter::PrintWriter( const NoOp& noOp ) PrintWriter_INITIALIZER {
}

const JClass* PrintWriter::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/io/PrintWriter" );
  return &javaClass;
}

const JClass* PrintWriter::getJavaJniClass() const throw ( JNIException ) {
  return PrintWriter::staticGetJavaJniClass();
}

JEnlister< PrintWriter> PrintWriter::enlister;

END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::io::PrintWriter>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::io::PrintWriter( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::io::PrintWriter>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::io::PrintWriter>& proxy ) : 
    ::jace::proxy::java::io::PrintWriter( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::io::PrintWriter>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::io::PrintWriter( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::io::PrintWriter>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::io::PrintWriter( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::io::PrintWriter>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::io::PrintWriter>& object ) : 
    ::jace::proxy::java::io::PrintWriter( object.getJavaJniValue() ), Object( NO_OP ) {

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

