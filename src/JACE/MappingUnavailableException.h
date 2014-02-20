/*
 * Copyright 2014 Patrick Kramer, Vincent Wassenaar
 *
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MAPPINGUNAVAILABLEEXCEPTION_H
#define MAPPINGUNAVAILABLEEXCEPTION_H

#include "jace/JNIException.h"
using jace::JNIException;

#include <string>
using std::string;

/**
 * @brief JNIException subclass for indicating missing bindings.
 *
 * This type of exception may be thrown when a required class mapping
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
    JACE_API MappingUnavailableException(const char* msg) throw();

    /**
     * @brief Creates a new MappingUnavailableException with the specified message
     * @param msg the message
     */
    JACE_API MappingUnavailableException(const string& msg) throw();

    /**
     * @brief Creates a new MappingUnavailableException with the specified message
     * @param str the message
     */
    JACE_API MappingUnavailableException(const QString& str) throw();

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
