
#include "jace/proxy/types/JByte.h"
#include "jace/JClassImpl.h"
using jace::JClassImpl;

namespace jace {
namespace proxy {
namespace types {

JByte::JByte( jvalue value ) {
  setJavaJniValue( value );
}


JByte::JByte( jbyte byte ) {
  jvalue value;
  value.b = byte;
  setJavaJniValue( value );
}

JByte::~JByte() {}

JByte::operator jbyte() const { 
  return getJavaJniValue().b;
}

jbyte JByte::getByte() const {
  return getJavaJniValue().b;
}

bool JByte::operator==( const JByte& byte_ ) const {
  return byte_.getByte() == getByte();
}

bool JByte::operator!=( const JByte& byte_ ) const {
  return !( *this == byte_ );
}

bool JByte::operator==( jbyte val ) const {
  return val == getByte();
}

bool JByte::operator!=( jbyte val ) const {
  return ! ( *this == val );
}

const JClass* JByte::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "byte", "B" );
  return &javaClass;
}

const JClass* JByte::getJavaJniClass() const throw ( JNIException ) {
  return JByte::staticGetJavaJniClass();
}

}
}
}
