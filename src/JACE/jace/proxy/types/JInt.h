#ifndef JACE_TYPES_JINT_H
#define JACE_TYPES_JINT_H

#include "jace/os_dep.h"
#include "jace/namespace.h"
#include "jace/JNIHelper.h"
#include "jace/JClass.h"
#include "jace/proxy/JValue.h"
#include "jace/JNIException.h"
#include "jace/proxy/types/JByte.h"

#include <iostream>

namespace jace {
namespace proxy {
namespace types {

/** 
 * A representation of the java primitive int.
 *
 * @author Toby Reyelts
 *
 */
class JACE_API JInt : public JValue {

public:

/**
 * Creates a new instance with the given value.
 *
 */
JInt( jvalue value );


/**
 * Creates a new instance with the given value.
 *
 */
JInt( const jint int_ );


/**
 * Creates a new instance with the given value.
 *
 */
JInt( const ::jace::proxy::types::JByte& byte_ );


/**
 * Destroys the existing java object.
 *
 */
virtual ~JInt();


/**
 * Returns the value of this instance.
 *
 */
operator jint();


/**
 * Returns the value of this instance.
 *
 */
jint getInt() const;


friend std::ostream& operator<<( std::ostream& stream, const JInt& val );

/**
 * Compares this JInt to another.
 *
 */
bool operator==( const JInt& int_ ) const;


/**
 * Compares this JInt to another.
 *
 */
bool operator!=( const JInt& int_ ) const;


/**
 * Compares this JInt to a jint.
 *
 */
bool operator==( jint val ) const;


/**
 * Compares this JInt to a jint.
 *
 */
bool operator!=( jint val ) const;


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

#endif // #ifndef JACE_TYPES_JINT_H


