
#ifndef JACE_PROXY_JAVA_IO_PRINTWRITER_H
#define JACE_PROXY_JAVA_IO_PRINTWRITER_H

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
#ifndef JACE_PROXY_JAVA_IO_WRITER_H
#include "jace/proxy/java/io/Writer.h"
#endif

/**
 * Classes which this class is fully dependent upon.
 *
 */
#ifndef JACE_TYPES_JCHAR_H
#include "jace/proxy/types/JChar.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_OBJECT_H
#include "jace/proxy/java/lang/Object.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class OutputStream;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class FileNotFoundException;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class UnsupportedEncodingException;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class File;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JChar;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JLong;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JFloat;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JDouble;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class Object;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Locale;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class CharSequence;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, io )

/**
 * The Jace C++ proxy class for java/io/PrintWriter.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class PrintWriter : public ::jace::proxy::java::io::Writer {

public: 

/**
 * PrintWriter
 *
 */
PrintWriter( ::jace::proxy::java::io::Writer p0 );

/**
 * PrintWriter
 *
 */
PrintWriter( ::jace::proxy::java::io::Writer p0, ::jace::proxy::types::JBoolean p1 );

/**
 * PrintWriter
 *
 */
PrintWriter( ::jace::proxy::java::io::OutputStream p0 );

/**
 * PrintWriter
 *
 */
PrintWriter( ::jace::proxy::java::io::OutputStream p0, ::jace::proxy::types::JBoolean p1 );

/**
 * PrintWriter
 *
 */
PrintWriter( ::jace::proxy::java::lang::String p0 );

/**
 * PrintWriter
 *
 */
PrintWriter( ::jace::proxy::java::lang::String p0, ::jace::proxy::java::lang::String p1 );

/**
 * PrintWriter
 *
 */
PrintWriter( ::jace::proxy::java::io::File p0 );

/**
 * PrintWriter
 *
 */
PrintWriter( ::jace::proxy::java::io::File p0, ::jace::proxy::java::lang::String p1 );

/**
 * flush
 *
 */
void flush();

/**
 * close
 *
 */
void close();

/**
 * checkError
 *
 */
::jace::proxy::types::JBoolean checkError();

/**
 * write
 *
 */
void write( ::jace::proxy::types::JInt p0 );

/**
 * write
 *
 */
void write( ::jace::JArray< ::jace::proxy::types::JChar > p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * write
 *
 */
void write( ::jace::JArray< ::jace::proxy::types::JChar > p0 );

/**
 * write
 *
 */
void write( ::jace::proxy::java::lang::String p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * write
 *
 */
void write( ::jace::proxy::java::lang::String p0 );

/**
 * print
 *
 */
void print( ::jace::proxy::types::JBoolean p0 );

/**
 * print
 *
 */
void print( ::jace::proxy::types::JChar p0 );

/**
 * print
 *
 */
void print( ::jace::proxy::types::JInt p0 );

/**
 * print
 *
 */
void print( ::jace::proxy::types::JLong p0 );

/**
 * print
 *
 */
void print( ::jace::proxy::types::JFloat p0 );

/**
 * print
 *
 */
void print( ::jace::proxy::types::JDouble p0 );

/**
 * print
 *
 */
void print( ::jace::JArray< ::jace::proxy::types::JChar > p0 );

/**
 * print
 *
 */
void print( ::jace::proxy::java::lang::String p0 );

/**
 * print
 *
 */
void print( ::jace::proxy::java::lang::Object p0 );

/**
 * println
 *
 */
void println();

/**
 * println
 *
 */
void println( ::jace::proxy::types::JBoolean p0 );

/**
 * println
 *
 */
void println( ::jace::proxy::types::JChar p0 );

/**
 * println
 *
 */
void println( ::jace::proxy::types::JInt p0 );

/**
 * println
 *
 */
void println( ::jace::proxy::types::JLong p0 );

/**
 * println
 *
 */
void println( ::jace::proxy::types::JFloat p0 );

/**
 * println
 *
 */
void println( ::jace::proxy::types::JDouble p0 );

/**
 * println
 *
 */
void println( ::jace::JArray< ::jace::proxy::types::JChar > p0 );

/**
 * println
 *
 */
void println( ::jace::proxy::java::lang::String p0 );

/**
 * println
 *
 */
void println( ::jace::proxy::java::lang::Object p0 );

/**
 * printf
 *
 */
::jace::proxy::java::io::PrintWriter printf( ::jace::proxy::java::lang::String p0, ::jace::JArray< ::jace::proxy::java::lang::Object > p1 );

/**
 * printf
 *
 */
::jace::proxy::java::io::PrintWriter printf( ::jace::proxy::java::util::Locale p0, ::jace::proxy::java::lang::String p1, ::jace::JArray< ::jace::proxy::java::lang::Object > p2 );

/**
 * format
 *
 */
::jace::proxy::java::io::PrintWriter format( ::jace::proxy::java::lang::String p0, ::jace::JArray< ::jace::proxy::java::lang::Object > p1 );

/**
 * format
 *
 */
::jace::proxy::java::io::PrintWriter format( ::jace::proxy::java::util::Locale p0, ::jace::proxy::java::lang::String p1, ::jace::JArray< ::jace::proxy::java::lang::Object > p2 );

/**
 * append
 *
 */
::jace::proxy::java::io::PrintWriter append( ::jace::proxy::java::lang::CharSequence p0 );

/**
 * append
 *
 */
::jace::proxy::java::io::PrintWriter append( ::jace::proxy::java::lang::CharSequence p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * append
 *
 */
::jace::proxy::java::io::PrintWriter append( ::jace::proxy::types::JChar p0 );

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
PrintWriter( jvalue value );
PrintWriter( jobject object );
PrintWriter( const PrintWriter& object );
PrintWriter( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< PrintWriter> enlister;
};

END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::io::PrintWriter>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::io::PrintWriter>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::io::PrintWriter>& proxy );
#else
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
  template <> JFieldProxy< ::jace::proxy::java::io::PrintWriter>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::io::PrintWriter>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::io::PrintWriter>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::io::PrintWriter>& object );
#else
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

#endif // #ifndef JACE_PROXY_JAVA_IO_PRINTWRITER_H

