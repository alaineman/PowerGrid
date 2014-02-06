#include "mappingunavailableexception.h"

MappingUnavailableException::MappingUnavailableException(const char* msg) throw() :
    JNIException (msg) {
}

MappingUnavailableException::MappingUnavailableException(const std::string& msg) throw() :
    JNIException (msg) {
}

MappingUnavailableException::MappingUnavailableException(const QString &str) throw() :
    JNIException (str) {
}

MappingUnavailableException::MappingUnavailableException(const MappingUnavailableException &rhs) throw ():
    JNIException (rhs) {
}


MappingUnavailableException& MappingUnavailableException::operator =(const MappingUnavailableException& rhs) throw() {
    if (&rhs == this) {
        return *this;
    }
    ( ( JNIException& ) *this ) = ( JNIException& ) rhs;

    return *this;
}
