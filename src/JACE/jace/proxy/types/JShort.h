#ifndef JACE_TYPES_JSHORT_H
#define JACE_TYPES_JSHORT_H

#include "jace/os_dep.h"
#include "jace/namespace.h"
#include "jace/JNIHelper.h"
#include "jace/JClass.h"
#include "jace/proxy/JValue.h"
#include "jace/JNIException.h"

namespace jace {
namespace proxy {
namespace types {

/** 
 * A representation of the java primitive short.
 *
 * @author Toby Reyelts
 *
 */
class JACE_API JShort : public JValue {


public:


/**
 * Creates a new instance with the given value.
 *
 */
JShort( jvalue value );


/**
 * Creates a new instance with the given value.
 *
 */
JShort( jshort value );


/**
 * Destroys the existing java object.
 *
 */
virtual ~JShort();


/**
 * Returns the value of this instance.
 *
 */
operator jshort() const;


/**
 * Returns the value of this instance.
 *
 */
jshort getShort() const;


/**
 * Compares this instance to another.
 *
 */
bool operator==( const JShort& value ) const;


/**
 * Compares this instance to another.
 *
 */
bool operator!=( const JShort& value ) const;


/**
 * Compares this instance to another.
 *
 */
bool operator==( jshort value ) const;


/**
 * Compares this instance to another.
 *
 */
bool operator!=( jshort value ) const;


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

#endif // #ifndef JACE_TYPES_JSHORT_H


