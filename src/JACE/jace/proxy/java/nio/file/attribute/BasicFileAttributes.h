
#ifndef JACE_PROXY_JAVA_NIO_FILE_ATTRIBUTE_BASICFILEATTRIBUTES_H
#define JACE_PROXY_JAVA_NIO_FILE_ATTRIBUTE_BASICFILEATTRIBUTES_H

#ifndef JACE_OS_DEP_H
#include "jace/os_dep.h"
#endif

#ifndef JACE_NAMESPACE_H
#include "jace/namespace.h"
#endif

#ifndef JACE_JOBJECT_H
#include "jace/proxy/JObject.h"
#endif

#ifndef JACE_JENLISTER_H
#include "jace/JEnlister.h"
#endif

#ifndef JACE_JARRAY_H
#include "jace/JArray.h"
#endif

#ifndef JACE_JFIELD_PROXY_H
#include "jace/JFieldProxy.h"
#endif

/**
 * The super class for this class.
 *
 */
#ifndef JACE_PROXY_JAVA_LANG_OBJECT_H
#include "jace/proxy/java/lang/Object.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_6( jace, proxy, java, nio, file, attribute )
class FileTime;
END_NAMESPACE_6( jace, proxy, java, nio, file, attribute )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JLong;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_6( jace, proxy, java, nio, file, attribute )

/**
 * The Jace C++ proxy class for java/nio/file/attribute/BasicFileAttributes.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class BasicFileAttributes : public virtual ::jace::proxy::java::lang::Object {

public: 

/**
 * lastModifiedTime
 *
 */
::jace::proxy::java::nio::file::attribute::FileTime lastModifiedTime();

/**
 * lastAccessTime
 *
 */
::jace::proxy::java::nio::file::attribute::FileTime lastAccessTime();

/**
 * creationTime
 *
 */
::jace::proxy::java::nio::file::attribute::FileTime creationTime();

/**
 * isRegularFile
 *
 */
::jace::proxy::types::JBoolean isRegularFile();

/**
 * isDirectory
 *
 */
::jace::proxy::types::JBoolean isDirectory();

/**
 * isSymbolicLink
 *
 */
::jace::proxy::types::JBoolean isSymbolicLink();

/**
 * isOther
 *
 */
::jace::proxy::types::JBoolean isOther();

/**
 * size
 *
 */
::jace::proxy::types::JLong size();

/**
 * fileKey
 *
 */
::jace::proxy::java::lang::Object fileKey();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
/**
 * Special no arg constructor for interface virtual inheritance
 *
 */
BasicFileAttributes();
BasicFileAttributes( jvalue value );
BasicFileAttributes( jobject object );
BasicFileAttributes( const BasicFileAttributes& object );
BasicFileAttributes( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< BasicFileAttributes> enlister;
};

END_NAMESPACE_6( jace, proxy, java, nio, file, attribute )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::nio::file::attribute::BasicFileAttributes>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::nio::file::attribute::BasicFileAttributes>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::file::attribute::BasicFileAttributes>& proxy );
#else
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
  template <> JFieldProxy< ::jace::proxy::java::nio::file::attribute::BasicFileAttributes>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::file::attribute::BasicFileAttributes>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::file::attribute::BasicFileAttributes>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::file::attribute::BasicFileAttributes>& object );
#else
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

#endif // #ifndef JACE_PROXY_JAVA_NIO_FILE_ATTRIBUTE_BASICFILEATTRIBUTES_H

