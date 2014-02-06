#include "IllegalOperationException.h"
#include "jace/JNIException.h"
using jace::JNIException;

IllegalOperationException::IllegalOperationException(const char* str) throw () :
        JNIException(str) {
}

IllegalOperationException::IllegalOperationException(const IllegalOperationException &rhs) throw() :
        JNIException(rhs) {
}

IllegalOperationException::IllegalOperationException(const QString &str) throw() :
        JNIException(str) {
}

IllegalOperationException::IllegalOperationException(const std::string &value) throw() :
        JNIException(value) {
}

IllegalOperationException& IllegalOperationException::operator=( const IllegalOperationException& rhs ) throw () {
    if ( &rhs == this) {
        return *this;
    }

    ( ( JNIException& ) *this ) = ( JNIException& ) rhs;

    return *this;
}
