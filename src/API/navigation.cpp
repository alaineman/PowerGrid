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
#include "navigation.h"

namespace API {

using component::Position;

Navigation::Navigation(QList<Position*> path) :
    _path(path), _current(-1), _length(-1) {
}

long Navigation::computeLength() const {
    if (_path.length() <= 1) {
        return 0;
    }
    Position* p (_path.at(0));
    long length (0);
    for (int i=1;i<_path.length();i++) {
        Position* next (_path.at(i));
        length += p->distance(next);
        p = next;
    }
    return length;
}

long Navigation::length() const {
    if (_length < 0) {
        _length = computeLength();
    }
    return _length;
}

bool Navigation::hasNext() const {
    return _current+1 < _path.length();
}

Position* Navigation::next() {
    Q_ASSERT_X(hasNext(), "Navigation::next()", "No next element");
    _current++;
    Position* next = _path.at(_current);
    emit progress(next);
    return next;
}

Position* Navigation::current() const {
    if (_current < 0) {
        return NULL;
    } else {
        return _path.at(_current);
    }
}

void Navigation::reset() {
    _current = -1;
}

}
