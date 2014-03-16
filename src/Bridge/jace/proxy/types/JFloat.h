
#ifndef JACE_TYPES_JFLOAT_H
#define JACE_TYPES_JFLOAT_H

#include "jace/os_dep.h"
#include "jace/JNIHelper.h"
#include "jace/JClass.h"
#include "jace/proxy/JValue.h"
#include "jace/JNIException.h"

namespace jace {
namespace proxy {
namespace types {

/** 
 * A representation of the java primitive float.
 *
 * @author Toby Reyelts
 *
 */
class JACE_API JFloat : public JValue {


public:


/**
 * Creates a new instance with the given value.
 *
 */
JFloat( jvalue value );


/**
 * Creates a new instance with the given value.
 *
 */
JFloat( jfloat value );


/**
 * Destroys the existing java object.
 *
 */
virtual ~JFloat();


/**
 * Returns the value of this instance.
 *
 */
operator jfloat() const;

/**
 * Returns the value of this instance.
 *
 */
jfloat getFloat() const;


/**
 * Compares this instance to another.
 *
 */
bool operator==( const JFloat& value ) const;


/**
 * Compares this instance to another.
 *
 */
bool operator!=( const JFloat& value ) const;


/**
 * Compares this instance to another.
 *
 */
bool operator==( jfloat value ) const;


/**
 * Compares this instance to another.
 *
 */
bool operator!=( jfloat value ) const;


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

#endif // #ifndef JACE_TYPES_JFLOAT_H


