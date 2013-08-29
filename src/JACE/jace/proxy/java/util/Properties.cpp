
#ifndef JACE_PROXY_JAVA_UTIL_PROPERTIES_H
#include "jace/proxy/java/util/Properties.h"
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
#ifndef JACE_PROXY_JAVA_LANG_OBJECT_H
#include "jace/proxy/java/lang/Object.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_READER_H
#include "jace/proxy/java/io/Reader.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_IOEXCEPTION_H
#include "jace/proxy/java/io/IOException.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_INPUTSTREAM_H
#include "jace/proxy/java/io/InputStream.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_OUTPUTSTREAM_H
#include "jace/proxy/java/io/OutputStream.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_WRITER_H
#include "jace/proxy/java/io/Writer.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_INVALIDPROPERTIESFORMATEXCEPTION_H
#include "jace/proxy/java/util/InvalidPropertiesFormatException.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_ENUMERATION_H
#include "jace/proxy/java/util/Enumeration.h"
#endif
#ifndef JACE_PROXY_JAVA_UTIL_SET_H
#include "jace/proxy/java/util/Set.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_PRINTSTREAM_H
#include "jace/proxy/java/io/PrintStream.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_PRINTWRITER_H
#include "jace/proxy/java/io/PrintWriter.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, util )

/**
 * The Jace C++ proxy class source for java/util/Properties.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define Properties_INITIALIZER : ::jace::proxy::java::util::Hashtable( NO_OP ), ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define Properties_INITIALIZER : ::jace::proxy::java::util::Hashtable( NO_OP )
#endif

Properties::Properties() Properties_INITIALIZER {
  ::jace::JArguments arguments;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

Properties::Properties( ::jace::proxy::java::util::Properties p0, CopyConstructorSpecifier ccs ) Properties_INITIALIZER {
  ::jace::JArguments arguments;
  arguments << p0;
  jobject localRef = newObject( arguments );
  setJavaJniObject( localRef );
  JNIEnv* env = ::jace::helper::attach();
  ::jace::helper::deleteLocalRef( env, localRef );
}

::jace::proxy::java::lang::Object Properties::setProperty( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "setProperty" ).invoke( *this, arguments );
}

void Properties::load( ::jace::proxy::java::io::Reader p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "load" ).invoke( *this, arguments );
}

void Properties::load( ::jace::proxy::java::io::InputStream p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "load" ).invoke( *this, arguments );
}

void Properties::save( ::jace::proxy::java::io::OutputStream p0, ::jace::proxy::java::lang::String p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "save" ).invoke( *this, arguments );
}

void Properties::store( ::jace::proxy::java::io::Writer p0, ::jace::proxy::java::lang::String p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "store" ).invoke( *this, arguments );
}

void Properties::store( ::jace::proxy::java::io::OutputStream p0, ::jace::proxy::java::lang::String p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "store" ).invoke( *this, arguments );
}

void Properties::loadFromXML( ::jace::proxy::java::io::InputStream p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "loadFromXML" ).invoke( *this, arguments );
}

void Properties::storeToXML( ::jace::proxy::java::io::OutputStream p0, ::jace::proxy::java::lang::String p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "storeToXML" ).invoke( *this, arguments );
}

void Properties::storeToXML( ::jace::proxy::java::io::OutputStream p0, ::jace::proxy::java::lang::String p1, ::jace::proxy::java::lang::String p2 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1 << p2;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "storeToXML" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Properties::getProperty( ::jace::proxy::java::lang::String p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getProperty" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::String Properties::getProperty( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::java::lang::String >( "getProperty" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Enumeration Properties::propertyNames() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Enumeration >( "propertyNames" ).invoke( *this, arguments );
}

::jace::proxy::java::util::Set Properties::stringPropertyNames() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::util::Set >( "stringPropertyNames" ).invoke( *this, arguments );
}

void Properties::list( ::jace::proxy::java::io::PrintStream p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "list" ).invoke( *this, arguments );
}

void Properties::list( ::jace::proxy::java::io::PrintWriter p0 ) {
  ::jace::JArguments arguments;
  arguments << p0;
  ::jace::JMethod< ::jace::proxy::types::JVoid >( "list" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
Properties::Properties( jvalue value ) Properties_INITIALIZER {
  setJavaJniValue( value );
}

Properties::Properties( jobject object ) Properties_INITIALIZER {
  setJavaJniObject( object );
}

Properties::Properties( const Properties& object ) Properties_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

Properties::Properties( const NoOp& noOp ) Properties_INITIALIZER {
}

const JClass* Properties::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/util/Properties" );
  return &javaClass;
}

const JClass* Properties::getJavaJniClass() const throw ( JNIException ) {
  return Properties::staticGetJavaJniClass();
}

JEnlister< Properties> Properties::enlister;

END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::util::Properties>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::util::Properties( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::util::Properties>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::util::Properties>& proxy ) : 
    ::jace::proxy::java::util::Properties( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::util::Properties>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::util::Properties( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Properties>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::util::Properties( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::util::Properties>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::util::Properties>& object ) : 
    ::jace::proxy::java::util::Properties( object.getJavaJniValue() ), Object( NO_OP ) {

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

