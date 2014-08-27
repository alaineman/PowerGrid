#include "navigation.h"

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
