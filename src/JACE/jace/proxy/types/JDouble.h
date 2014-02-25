
#ifndef JACE_TYPES_JDOUBLE_H
#define JACE_TYPES_JDOUBLE_H

#include "jace/os_dep.h"
#include "jace/JNIHelper.h"
#include "jace/JClass.h"
#include "jace/proxy/JValue.h"
#include "jace/JNIException.h"

namespace jace {
namespace proxy {
namespace types {

/** 
 * A representation of the java primitive double.
 *
 * @author Toby Reyelts
 *
 */
class JACE_API JDouble : public JValue {


public:


/**
 * Creates a new JDouble with the given value.
 *
 */
JDouble( jvalue value );


/**
 * Creates a new JDouble with the given value.
 *
 */
JDouble( jdouble value );


/**
 * Destroys the existing java object.
 *
 */
virtual ~JDouble();

/**
 * Returns the value of this instance.
 *
 */
operator jdouble() const;


/**
 * Returns the value of this instance.
 *
 */
jdouble getDouble() const;


/**
 * Compares this instance to another.
 *
 */
bool operator==( const JDouble& value ) const;


/**
 * Compares this instance to another.
 *
 */
bool operator!=( const JDouble& value ) const;


/**
 * Compares this instance to another.
 *
 */
bool operator==( jdouble value ) const;


/**
 * Compares this instance to another.
 *
 */
bool operator!=( jdouble value ) const;


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

#endif // #ifndef JACE_TYPES_JDOUBLE_H


