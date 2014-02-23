#ifndef JACE_TYPES_JBYTE_H
#define JACE_TYPES_JBYTE_H

#include "jace/os_dep.h"
#include "jace/JNIHelper.h"
#include "jace/JClass.h"
#include "jace/proxy/JValue.h"
#include "jace/JNIException.h"

namespace jace {
namespace proxy {
namespace types {


/** 
 * A representation of the java primitive byte.
 *
 * @author Toby Reyelts
 *
 */
class JACE_API JByte : public ::jace::proxy::JValue {


public:


/**
 * Creates a new JByte with the given value.
 *
 */
JByte( jvalue value );


/**
 * Creates a new JByte with the given value.
 *
 */
JByte( jbyte byte );


/**
 * Destroys the existing java object.
 *
 */
virtual ~JByte();


/**
 * Returns the byte value of this java byte.
 *
 */
operator jbyte() const;


/**
 * Returns the byte value of this java byte.
 *
 */
jbyte getByte() const;


/**
 * Compares this JByte to another.
 *
 */
bool operator==( const JByte& byte_ ) const;


/**
 * Compares this JByte to another.
 *
 */
bool operator!=( const JByte& byte_ ) const;


/**
 * Compares this JByte to a jbyte.
 *
 */
bool operator==( jbyte val ) const;


/**
 * Compares this JByte to a jbyte.
 *
 */
bool operator!=( jbyte val ) const;


/**
 * Returns the JClass for this class.
 *
 */
static const ::jace::JClass* staticGetJavaJniClass() throw ( ::jace::JNIException );


/**
 * Returns the JClass for this instance.
 *
 */
virtual const ::jace::JClass* getJavaJniClass() const throw ( ::jace::JNIException );

};


}
}
}

#endif // #ifndef JACE_TYPES_JBYTE_H


