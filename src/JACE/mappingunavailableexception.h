#ifndef MAPPINGUNAVAILABLEEXCEPTION_H
#define MAPPINGUNAVAILABLEEXCEPTION_H

#include "jace/JNIException.h"
using jace::JNIException;

#include <string>
using std::string;

/**
 * @brief JNIException subclass for indicating missing bindings.
 *
 * This type of objects may be thrown when a required class mapping
 * is not available. It usually indicates that a class or field mapping
 * used to exist but was removed by a Runescape update. It could also
 * indicate the updater is no longer able to find the binding for the class.
 *
 * It is advised, but not required (for debugging purposes and clarity), that
 * instances of this class are constructed with the name of the missing
 * binding as message.
 *
 * @author Patrick Kramer
 */
class MappingUnavailableException : public JNIException {
public:
    /**
     * @brief Creates a new MappingUnavailableException with the specified message
     * @param msg the message
     */
    JACE_API MappingUnavailableException(const string& msg) throw();
    /**
     * @brief Copy Constructor
     * @param rhs the object to copy from
     */
    JACE_API MappingUnavailableException(const MappingUnavailableException& rhs) throw();

    /**
     * Assignment operator overload
     */
    JACE_API MappingUnavailableException& operator =(const MappingUnavailableException& rhs) throw();
};

#endif // MAPPINGUNAVAILABLEEXCEPTION_H
