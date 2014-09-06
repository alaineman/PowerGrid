#include "jace/proxy/types/JLong.h"
#include "jace/JClassImpl.h"
using jace::JClassImpl;

namespace jace {
namespace proxy {
namespace types {

JLong::JLong( jvalue value ) {
  setJavaJniValue( value );
}


JLong::JLong( jlong long_ ) {
  jvalue value;
  value.j = long_;
  setJavaJniValue( value );
}

JLong::JLong( const JInt& int_ ) {
  jvalue value;
  value.j = int_.getInt();
  setJavaJniValue( value );
}


JLong::~JLong() {}

JLong::operator jlong() const {
  return getJavaJniValue().j;
}

jlong JLong::getLong() const {
  return getJavaJniValue().j;
}

bool JLong::operator==( const JLong& long_ ) const {
  return long_.getLong() == getLong();
}

bool JLong::operator!=( const JLong& long_ ) const {
  return !( *this == long_ );
}

bool JLong::operator==( jlong val ) const {
  return val == getLong();
}

bool JLong::operator!=( jlong val ) const {
  return ! ( *this == val );
}

const JClass* JLong::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "long", "J" );
  return &javaClass;
}

const JClass* JLong::getJavaJniClass() const throw ( JNIException ) {
  return JLong::staticGetJavaJniClass();
}

}
}
}

