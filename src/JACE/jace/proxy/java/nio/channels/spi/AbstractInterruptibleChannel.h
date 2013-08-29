
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_SPI_ABSTRACTINTERRUPTIBLECHANNEL_H
#define JACE_PROXY_JAVA_NIO_CHANNELS_SPI_ABSTRACTINTERRUPTIBLECHANNEL_H

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
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_CHANNEL_H
#include "jace/proxy/java/nio/channels/Channel.h"
#endif
#ifndef JACE_PROXY_JAVA_NIO_CHANNELS_INTERRUPTIBLECHANNEL_H
#include "jace/proxy/java/nio/channels/InterruptibleChannel.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, io )
class IOException;
END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_6( jace, proxy, java, nio, channels, spi )

/**
 * The Jace C++ proxy class for java/nio/channels/spi/AbstractInterruptibleChannel.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class AbstractInterruptibleChannel : public virtual ::jace::proxy::java::lang::Object, public virtual ::jace::proxy::java::nio::channels::Channel, public virtual ::jace::proxy::java::nio::channels::InterruptibleChannel {

public: 

/**
 * close
 *
 */
void close();

/**
 * isOpen
 *
 */
::jace::proxy::types::JBoolean isOpen();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
AbstractInterruptibleChannel( jvalue value );
AbstractInterruptibleChannel( jobject object );
AbstractInterruptibleChannel( const AbstractInterruptibleChannel& object );
AbstractInterruptibleChannel( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< AbstractInterruptibleChannel> enlister;
};

END_NAMESPACE_6( jace, proxy, java, nio, channels, spi )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel>& proxy ) : 
    ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel>& object ) : 
    ::jace::proxy::java::nio::channels::spi::AbstractInterruptibleChannel( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_NIO_CHANNELS_SPI_ABSTRACTINTERRUPTIBLECHANNEL_H

