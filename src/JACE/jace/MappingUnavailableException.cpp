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

#include "MappingUnavailableException.h"

namespace jace {

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

}
