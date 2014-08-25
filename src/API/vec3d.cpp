#include "vec3d.h"
#include <math.h>

#include "component/position.h"

Vec3D::Vec3D(double x, double y, double z) :
    _x(x), _y(y), _z(z) {
}

Vec3D::Vec3D(int x, int y, int z) :
    _x(x), _y(y), _z(z) {
}

Vec3D::Vec3D(component::Position *pos) {
    Q_ASSERT_X(pos, "Vec3D(Position*)", "parameter is NULL");
    _x = pos->getX();
    _y = pos->getY();
    _z = pos->getZ();
}

double Vec3D::dist(Vec3D other) const {
    return sqrt(squareDist(other));
}

double Vec3D::squareDist(Vec3D other) const {
    double dx = other.x() - _x;
    double dy = other.y() - _y;
    double dz = other.z() - _z;
    return dx*dx + dy*dy + dz*dz;
}
