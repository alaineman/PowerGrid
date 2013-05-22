#ifndef STDAFX_H
#define STDAFX_H

// The PowerGrid version, should only be changed on version change.
#define POWERGRID_VERSION "0.1"

// Include common C/C++ headers
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <memory>
#include <string>
#include <sstream>

// Include common Qt headers
#include <qcompilerdetection.h>
#ifdef Q_COMPILER_INITIALIZER_LISTS
 // It appears Qt decides that Clang can use initializer lists, but these cannot be found in some cases.
 // As such we don't use them to make sure the Clang compiler does not fail to compile the Qt headers.
 #undef Q_COMPILER_INITIALIZER_LISTS
#endif
#include <QDebug>

// The below options may be customized at will to provide a combination of safety checks
// and functionality that benefits your needs. In most cases, however, simply
// enabling / disabling the DEBUG macro will do the trick.

// Define DEBUG here to enable various safety-checks and debug features automatically
// throughout PowerGrid. This enables / disables a variety of the belowmentioned macros.
#define DEBUG


// Various options to enable or disable certain checks.
// The exact way classes and functions use these macros is dependant on the implementation.
// No assertions can be given as to how far safety is guaranteed.
// Note: when editing, please ensure that each option is left in alphabetical order.

// Show Debug messages depending on DEBUG macro, allows for verbosity control with test runs.
// Debug messages reported using this macro will be ignored when the DEBUG macro is not set.
#ifdef DEBUG
 #define DEBUG_MSG(msg) qDebug(msg)
#else
 #define DEBUG_MSG(msg) (msg)
#endif

// Checks input from users and other arguments for validity. Checks basic properties of strings (such as length),
// but does not look into the semantic meaning of the string to see if it's valid.
#define PG_INPUT_CHECK


// Checks for NULL values in arguments and return values. Recommended to alert the user when
// something goes wrong in the JNI. NULL checks are usually fast, so they should be enabled
// even in a release version.
#define PG_NULL_CHECK


#ifdef DEBUG
 // Deeply checks validity of strings, should be disabled in a release version to enhance speed.
 // Costs significantly more time, but may throw exceptions where otherwise invalid data would
 // be passed along.
 #define PG_STRING_CHECK
#endif

// to_string used to convert anything to its string value.
#define TO_STRING(num) static_cast<std::stringstream*>( &(std::stringstream() << num) )->str()

// Define convenience macro's
#ifdef PG_NULL_CHECK
 #define VERIFY_NON_NULL(pointer) if(pointer == NULL) { throw std::runtime_error(std::string("pointer is NULL (").append(__FILE__).append(":").append(TO_STRING(__LINE__)).append(")")); }
#else
 #define VERIFY_NON_NULL(pointer)
#endif

// Convenience macro for condition checking
#ifdef PG_INPUT_CHECK
 #define VERIFY_THAT(condition) if (!(condition)) { throw std::runtime_error(std::string("Condition failed (").append(__FILE__).append(":").append(TO_STRING(__LINE__)).append(")")); }
#else
 #define VERIFY_THAT(condition)
#endif

// define a const c-type string as a cstring
typedef const char* cstring;

// define a byte-type since it's used a lot as such.
typedef unsigned char byte;

/**
 * @brief enum indicating a value type in the Java environment
 */
enum jvalue_type {
  JVOID, JBOOLEAN, JBYTE, JCHAR, JSHORT, JINT, JLONG, JFLOAT, JDOUBLE, JOBJECT
};


#endif // STDAFX_H
