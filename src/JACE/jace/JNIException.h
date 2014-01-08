#ifndef JACE_JNI_EXCEPTION_H
#define JACE_JNI_EXCEPTION_H

#include "jace/os_dep.h"
#include "jace/namespace.h"
#include "jace/BaseException.h"
#include "jni.h"
#include <string>

BEGIN_NAMESPACE( jace )


/**
 * An exception which is caused by invoking a call to the
 * java virtual machine through JNI.
 *
 * @author Toby Reyelts
 *
 */
class JNIException : public BaseException {

public:

/**
 * Creates a new JNIException with the given mesage.
 *
 */
JACE_API JNIException( const std::string& value ) throw ();

/**
 * Creates a new JNIException from an existing JNIException.
 *
 */
JACE_API JNIException( const JNIException& rhs ) throw ();

/**
 * Creates a new JNIException from an existing JNIException.
 *
 */
JACE_API JNIException& operator=( const JNIException& rhs ) throw ();

};

std::string JNIError_toString(jint errCode) throw();

END_NAMESPACE( jace )


#endif // #ifndef JACE_JNI_EXCEPTION_H


