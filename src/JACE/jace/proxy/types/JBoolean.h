#ifndef JACE_TYPES_JBOOLEAN_H
#define JACE_TYPES_JBOOLEAN_H

#include "jace/os_dep.h"
#include "jace/JNIHelper.h"
#include "jace/JClass.h"
#include "jace/proxy/JValue.h"
#include "jace/JNIException.h"

namespace jace {
namespace proxy {
namespace types {


/**
 * A representation of the java primitive boolean.
 *
 * @author Toby Reyelts
 *
 */
class JACE_API JBoolean : public jace::proxy::JValue {


public:


/**
 * Creates a new instance with the given value.
 *
 */
JBoolean( jvalue value );


/**
 * Creates a new instance with the given value.
 *
 */
JBoolean( jboolean value );


/**
 * Destroys the existing java object.
 *
 */
virtual ~JBoolean();


/**
 * Returns the value of this instance.
 *
 */
operator jboolean() const;

/**
 * Returns the value of this instance.
 *
 */
jboolean getBoolean() const;


/**
 * Compares this JBoolean to another.
 *
 */
bool operator==( const JBoolean& boolean_ ) const;


/**
 * Compares this JBoolean to another.
 *
 */
bool operator!=( const JBoolean& boolean_ ) const;


/**
 * Compares this JBoolean to a jboolean.
 *
 */
bool operator==( jboolean val ) const;


/**
 * Compares this JBoolean to a jboolean.
 *
 */
bool operator!=( jboolean val ) const;


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

#endif // #ifndef JACE_TYPES_JBOOLEAN_H

