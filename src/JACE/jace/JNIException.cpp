
#include "jace/JNIException.h"

#include <string>
using std::string;


BEGIN_NAMESPACE( jace )

JNIException::JNIException( const string& value ) throw () : 
  BaseException( value ) {
}


JNIException::JNIException( const JNIException& rhs ) throw () : 
  BaseException( rhs ) {
}


JNIException& JNIException::operator=( const JNIException& rhs ) throw () {

  if ( &rhs == this ) {
    return *this;
  }

  ( ( BaseException& ) *this ) = ( BaseException& ) rhs;

  return *this;
}

/**
 * @brief converts a JNI error code into a human-readable description
 * Recognized values are all defined JNI Error codes (which includes
 * JNI_OK, and all JNI_E... defines). If the provided value is neither of these,
 * a generic error message including the provided value is returned.
 *
 * @param errCode the JNI error code
 * @return a human-readable description of the error
 */
string JNIError_toString(jint errCode) throw() {
    switch (errCode) {
    case JNI_OK:
        return "Success";
    case JNI_ERR:
        return "General JNI error";
    case JNI_EDETACHED:
        return "Thread detached from the VM";
    case JNI_EVERSION:
        return "JNI version error";
    case JNI_ENOMEM:
        return "Not enough memory";
    case JNI_EEXIST:
        return "VM already created";
    case JNI_EINVAL:
        return "Invalid arguments";
    default:
        // should never happen, but to cover all values:
        return "Unknown error code: " + std::to_string(errCode);
    }
}

END_NAMESPACE( jace )
