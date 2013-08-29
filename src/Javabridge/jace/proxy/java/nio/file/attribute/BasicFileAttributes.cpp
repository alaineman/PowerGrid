
#ifndef JACE_PROXY_JAVA_NIO_FILE_ATTRIBUTE_BASICFILEATTRIBUTES_H
#include "jace/proxy/java/nio/file/attribute/BasicFileAttributes.h"
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
#ifndef JACE_PROXY_JAVA_NIO_FILE_ATTRIBUTE_FILETIME_H
#include "jace/proxy/java/nio/file/attribute/FileTime.h"
#endif
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_TYPES_JLONG_H
#include "jace/proxy/types/JLong.h"
#endif

BEGIN_NAMESPACE_6( jace, proxy, java, nio, file, attribute )

/**
 * The Jace C++ proxy class source for java/nio/file/attribute/BasicFileAttributes.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define BasicFileAttributes_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define BasicFileAttributes_INITIALIZER
#endif

::jace::proxy::java::nio::file::attribute::FileTime BasicFileAttributes::lastModifiedTime() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::attribute::FileTime >( "lastModifiedTime" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::attribute::FileTime BasicFileAttributes::lastAccessTime() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::attribute::FileTime >( "lastAccessTime" ).invoke( *this, arguments );
}

::jace::proxy::java::nio::file::attribute::FileTime BasicFileAttributes::creationTime() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::nio::file::attribute::FileTime >( "creationTime" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean BasicFileAttributes::isRegularFile() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isRegularFile" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean BasicFileAttributes::isDirectory() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isDirectory" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean BasicFileAttributes::isSymbolicLink() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isSymbolicLink" ).invoke( *this, arguments );
}

::jace::proxy::types::JBoolean BasicFileAttributes::isOther() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "isOther" ).invoke( *this, arguments );
}

::jace::proxy::types::JLong BasicFileAttributes::size() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::types::JLong >( "size" ).invoke( *this, arguments );
}

::jace::proxy::java::lang::Object BasicFileAttributes::fileKey() {
  ::jace::JArguments arguments;
  return ::jace::JMethod< ::jace::proxy::java::lang::Object >( "fileKey" ).invoke( *this, arguments );
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
BasicFileAttributes::BasicFileAttributes() : Object( NO_OP ) { 
}

BasicFileAttributes::BasicFileAttributes( jvalue value ) BasicFileAttributes_INITIALIZER {
  setJavaJniValue( value );
}

BasicFileAttributes::BasicFileAttributes( jobject object ) BasicFileAttributes_INITIALIZER {
  setJavaJniObject( object );
}

BasicFileAttributes::BasicFileAttributes( const BasicFileAttributes& object ) BasicFileAttributes_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

BasicFileAttributes::BasicFileAttributes( const NoOp& noOp ) BasicFileAttributes_INITIALIZER {
}

const JClass* BasicFileAttributes::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/nio/file/attribute/BasicFileAttributes" );
  return &javaClass;
}

const JClass* BasicFileAttributes::getJavaJniClass() const throw ( JNIException ) {
  return BasicFileAttributes::staticGetJavaJniClass();
}

JEnlister< BasicFileAttributes> BasicFileAttributes::enlister;

END_NAMESPACE_6( jace, proxy, java, nio, file, attribute )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::attribute::BasicFileAttributes>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::file::attribute::BasicFileAttributes( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::file::attribute::BasicFileAttributes>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::file::attribute::BasicFileAttributes>& proxy ) : 
    ::jace::proxy::java::nio::file::attribute::BasicFileAttributes( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::attribute::BasicFileAttributes>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::file::attribute::BasicFileAttributes( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::attribute::BasicFileAttributes>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::file::attribute::BasicFileAttributes( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::file::attribute::BasicFileAttributes>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::file::attribute::BasicFileAttributes>& object ) : 
    ::jace::proxy::java::nio::file::attribute::BasicFileAttributes( object.getJavaJniValue() ), Object( NO_OP ) {

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

