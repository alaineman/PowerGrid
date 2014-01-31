#include "jace/BaseException.h"

namespace jace {

BaseException::BaseException( const char* value ) throw () :
    mValue( value ) {
}

BaseException::BaseException( const std::string& value ) throw () : 
  mValue( value ) {
}


BaseException::BaseException( const BaseException& rhs ) throw () {
  mValue = rhs.mValue;
}


BaseException& BaseException::operator=( const BaseException& rhs ) throw () {

  if ( &rhs == this ) {
    return *this;
  }

  mValue = rhs.mValue;

  return *this;
}

BaseException::BaseException(const QString &str) throw() {
    mValue = str.toStdString();
}

BaseException::~BaseException() throw () {
}


const char* BaseException::what() const throw () {
  return mValue.c_str();
}


}

