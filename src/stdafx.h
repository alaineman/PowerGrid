#ifndef STDAFX_H
#define STDAFX_H

// The PowerGrid version, should only be changed on version change.
#define POWERGRID_VERSION "0.1"

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

// Include common C/C++ headers
#include <cstdlib>
#include <iostream>
#include <stdexcept>

// Include common Qt headers
#include <QtGlobal>
#include <QDebug>

#endif // STDAFX_H
