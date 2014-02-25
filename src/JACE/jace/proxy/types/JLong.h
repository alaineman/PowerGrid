
#ifndef JACE_TYPES_JLONG_H
#define JACE_TYPES_JLONG_H
#include "jace/os_dep.h"
#include "jace/namespace.h"
#include "jace/JNIHelper.h"
#include "jace/JClass.h"
#include "jace/proxy/JValue.h"
#include "jace/JNIException.h"

#include "jace/proxy/types/JInt.h"

namespace jace {
namespace proxy {
namespace types {

/** 
 * A representation of the java primitive long.
 *
 * @author Toby Reyelts
 *
 */
class JACE_API JLong : public JValue {

public:

/**
 * Creates a new instance with the given value.
 *
 */
JLong( jvalue value );


/**
 * Creates a new instance with the given value.
 *
 */
JLong( jlong long_ );


/**
 * Creates a new instance with the given value.
 *
 */
JLong( const ::jace::proxy::types::JInt& int_ );


/**
 * Destroys the existing java object.
 *
 */
virtual ~JLong();


/**
 * Returns the value of this instance.
 *
 */
operator jlong() const;


/**
 * Returns the value of this instance.
 *
 */
jlong getLong() const;


/**
 * Compares this instance to another.
 *
 */
bool operator==( const JLong& long_ ) const;


/**
 * Compares this instance to another.
 *
 */
bool operator!=( const JLong& long_ ) const;


/**
 * Compares this instance to a primitive.
 *
 */
bool operator==( jlong val ) const;


/**
 * Compares this instance to a primitive.
 *
 */
bool operator!=( jlong val ) const;


/**
 * Returns the JClass for this class.
 *
 */
static const ::jace::JClass* staticGetJavaJniClass() throw ( ::jace::JNIException );

/**
 * Retrieves the JavaClass for this JObject.
 *
 * @throw JNIException if an error occurs while trying to retrieve the class.
 *
 */
virtual const ::jace::JClass* getJavaJniClass() const throw ( ::jace::JNIException );

};

}
}
}

#endif // #ifndef JACE_TYPES_JLONG_H


