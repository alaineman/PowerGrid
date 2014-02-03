
#include "jace/JNIException.h"

#include <string>
using std::string;


namespace jace {

JNIException::JNIException(const char *str) throw() :
    BaseException(str) {

}

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

JNIException::JNIException(const QString &str) throw () :
    BaseException(str) {
}


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

}
