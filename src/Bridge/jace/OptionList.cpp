
#include "jace/OptionList.h"
using ::jace::OptionList;
using ::jace::Option;
using ::jace::SystemProperty;
using ::jace::CustomOption;

#include <string>
using std::string;

#include <cstring>

#include <vector>
using std::vector;
typedef std::vector<OptionList::OptionPtr> OptionPtr;

#ifdef JACE_BROKEN_USING_DECLARATION
  using std::vector<OptionList::OptionPtr>;
  using std::vector<std::string>;
#endif

#include <algorithm>
using std::copy;

#include <iterator>
using std::back_inserter;

namespace jace {

OptionList::OptionList() : options() {
}

void OptionList::push_back( const Option& option ) {
  OptionPtr ptr( option.clone() );
  options.push_back( ptr );
}

size_t OptionList::size() const {
  return options.size();
}

OptionList::iterator OptionList::begin() const {
  return iterator( options.begin() );
}
 
OptionList::iterator OptionList::end() const {
  return iterator( options.end() );
}

namespace {
  char* stringDup( const char* str ) {
    size_t length = strlen( str );
    char* newStr = new char[ length + 1 ];
    strcpy( newStr, str );
    return newStr;
  }
}

OptionList::iterator::iterator( vector<OptionPtr>::iterator it_ ) { it = it_; }
OptionList::iterator OptionList::iterator::operator++() { return it++; }
OptionList::iterator OptionList::iterator::operator++(int) { return ++it; }
OptionList::iterator OptionList::iterator::operator--() { return it--; }
OptionList::iterator OptionList::iterator::operator--(int) { return --it; }
OptionList::OptionPtr OptionList::iterator::operator*() { return *it; }
bool OptionList::iterator::operator!=( const OptionList::iterator& it_ ) { return it_.it != it; }

JavaVMOption* OptionList::createJniOptions() const {

  JavaVMOption* jniOptions = new JavaVMOption[ size() ];
  
  iterator it = begin();
  iterator end_it = end();

  for ( int i = 0; it != end_it; ++it, ++i ) {
    jniOptions[ i ].optionString = stringDup( (*it)->stringValue().c_str() );
    jniOptions[ i ].extraInfo = (*it)->extraInfo();
  }

  return jniOptions;
}


void OptionList::destroyJniOptions( JavaVMOption* jniOptions ) const {

  for ( unsigned int i = 0; i < size(); ++i ) {
    delete[] (jniOptions[ i ].optionString);
  }

  delete[] jniOptions;
}

SystemProperty::SystemProperty( const std::string& name_, const std::string& value_ ) :
  mName( name_ ), mValue( value_ ) {
}
  
std::string SystemProperty::name() {
  return mName;
}
  
std::string SystemProperty::value() {
  return mValue;
}

std::string SystemProperty::stringValue() {
  return "-D" + mName + "=" + mValue;
}

void* SystemProperty::extraInfo() {
  return 0;
}

Option* SystemProperty::clone() const {
  return new SystemProperty( mName, mValue ); 
}

CustomOption::CustomOption( const std::string& value_ ) : value( value_ ) {
}

std::string CustomOption::stringValue() {
  return value;
}

void* CustomOption::extraInfo() {
  return 0;
}

jace::Option* CustomOption::clone() const {
  return new CustomOption( value );
}

}
