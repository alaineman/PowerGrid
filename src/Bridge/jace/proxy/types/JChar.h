
#ifndef JACE_TYPES_JCHAR_H
#define JACE_TYPES_JCHAR_H

#include "jace/os_dep.h"
#include "jace/JNIHelper.h"
#include "jace/JClass.h"
#include "jace/proxy/JValue.h"
#include "jace/JNIException.h"

#include <iostream>

namespace jace {
namespace proxy {
namespace types {

/** 
 * A representation of the java primitive char.
 *
 * @author Toby Reyelts
 *
 */
class JACE_API JChar : public JValue {


public:


/**
 * Creates a new JChar with the given value.
 *
 */
JChar( jvalue value );


/**
 * Creates a new JChar with the given value.
 *
 */
JChar( jchar char_ );


/**
 * Destroys the existing java object.
 *
 */
virtual ~JChar();


/**
 * Returns the char value of this java char.
 *
 */
operator jchar() const;

/**
 * Returns the char value of this java char.
 *
 */
jchar getChar() const;


/**
 * Compares this instance to another.
 *
 */
bool operator==( const JChar& char_ ) const;


/**
 * Compares this instance to another.
 *
 */
bool operator!=( const JChar& char_ ) const;


/**
 * Compares this instance to another.
 *
 */
bool operator==( jchar val ) const;


/**
 * Compares this instance to another.
 *
 */
bool operator!=( jchar val ) const;


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

/**
 * Support printing of characters.
 *
 */
friend std::ostream& operator<<( std::ostream& stream, const JChar& val );


};

} // namespace types
} // namespace proxy
} // namespace jace

#endif // #ifndef JACE_TYPES_JCHAR_H


