#include "navigation.h"

Navigation::Navigation(QList<Vec3D> path) :
    _path(path), _current(-1), _length(-1) {
}

long Navigation::computeLength() const {
    if (_path.length() <= 1) {
        return 0;
    }
    Vec3D p (_path.at(0));
    long length (0);
    for (int i=1;i<_path.length();i++) {
        Vec3D next (_path.at(i));
        length += p.dist(next);
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

Vec3D Navigation::next() {
    Q_ASSERT_X(hasNext(), "Navigation::next()", "No next element");
    _current++;
    Vec3D next (_path.at(_current));
    emit progress(next);
    return next;
}

Vec3D Navigation::current() const {
    if (_current < 0) {
        return Vec3D();
    } else {
        return _path.at(_current);
    }
}

void Navigation::reset() {
    _current = -1;
}
