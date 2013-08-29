
#ifndef JACE_PROXY_JAVA_NIO_FILE_DIRECTORYSTREAM_H
#define JACE_PROXY_JAVA_NIO_FILE_DIRECTORYSTREAM_H

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
 * The interfaces implemented by this class.
 *
 */
#ifndef JACE_PROXY_JAVA_IO_CLOSEABLE_H
#include "jace/proxy/java/io/Closeable.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_ITERABLE_H
#include "jace/proxy/java/lang/Iterable.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Iterator;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_5( jace, proxy, java, nio, file )

/**
 * The Jace C++ proxy class for java/nio/file/DirectoryStream.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class DirectoryStream : public virtual ::jace::proxy::java::lang::Object, public virtual ::jace::proxy::java::io::Closeable, public virtual ::jace::proxy::java::lang::Iterable {

public: 

/**
 * iterator
 *
 */
::jace::proxy::java::util::Iterator iterator();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
/**
 * Special no arg constructor for interface virtual inheritance
 *
 */
DirectoryStream();
DirectoryStream( jvalue value );
DirectoryStream( jobject object );
DirectoryStream( const DirectoryStream& object );
DirectoryStream( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< DirectoryStream> enlister;
};

END_NAMESPACE_5( jace, proxy, java, nio, file )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::nio::file::DirectoryStream>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::nio::file::DirectoryStream>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::file::DirectoryStream>& proxy );
#else
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
  template <> JFieldProxy< ::jace::proxy::java::nio::file::DirectoryStream>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::file::DirectoryStream>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::file::DirectoryStream>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::file::DirectoryStream>& object );
#else
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

#endif // #ifndef JACE_PROXY_JAVA_NIO_FILE_DIRECTORYSTREAM_H

