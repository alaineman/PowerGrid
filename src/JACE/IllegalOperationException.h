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
#ifndef ILLEGALOPERATIONEXCEPTION_H
#define ILLEGALOPERATIONEXCEPTION_H

#include "jace/JNIException.h"
using jace::JNIException;

/**
 * An exception which is caused by invoking a call to the
 * java virtual machine that is not allowed by JACE or
 * PowerGrid.
 *
 * This exception is mainly thrown when trying to modify
 * the data in the client directly. Since this may lead to
 * undefined behavior in the Runescape client, such
 * operations are mostly blocked. The exception to this
 * are operations that push input events to the client.
 *
 * @author Patrick Kramer
 */
class IllegalOperationException : public JNIException
{
public:
    /**
     * Creates a new JNIException with the given mesage.
     *
     */
    JACE_API IllegalOperationException(const char* str) throw ();

    /**
     * Creates a new JNIException with the given mesage.
     *
     */
    JACE_API IllegalOperationException( const std::string& value ) throw ();

    /**
     * Creates a new JNIException from an existing JNIException.
     *
     */
    JACE_API IllegalOperationException( const IllegalOperationException& rhs ) throw ();

    /**
     * Creates a new JNIException with the given mesage.
     *
     */
    JACE_API IllegalOperationException( const QString& str) throw();

    /**
     * Creates a new JNIException from an existing JNIException.
     *
     */
    JACE_API IllegalOperationException& operator=( const IllegalOperationException& rhs ) throw ();
};

#endif // ILLEGALOPERATIONEXCEPTION_H
