#ifndef JACE_JNI_EXCEPTION_H
#define JACE_JNI_EXCEPTION_H

#include "jace/os_dep.h"
#include "jace/BaseException.h"
#include "jni.h"
#include <string>

namespace jace {


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
    JACE_API JNIException(const char* str) throw ();

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
     * Creates a new JNIException with the given mesage.
     *
     */
    JACE_API JNIException( const QString& str) throw();

    /**
     * Creates a new JNIException from an existing JNIException.
     *
     */
    JACE_API JNIException& operator=( const JNIException& rhs ) throw ();

};

/**
 * @brief converts a JNI error code into a human-readable description
 * Recognized values are all defined JNI Error codes (which includes
 * JNI_OK, and all JNI_E... defines). If the provided value is neither of these,
 * a generic error message including the provided value is returned.
 *
 * @param errCode the JNI error code
 * @return a human-readable description of the error
 */
std::string JNIError_toString(jint errCode) throw();

}


#endif // #ifndef JACE_JNI_EXCEPTION_H


