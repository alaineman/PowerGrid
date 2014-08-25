#ifndef VEC3D_H
#define VEC3D_H

namespace component {
 class Position;
}

/**
 * @brief Represents a vector in 3D space.
 *
 *
 */
class Vec3D {
private:
    double _x,_y,_z;
public:
    Vec3D(double x = 0.0, double y = 0.0, double z = 0.0);
    Vec3D(int x, int y = 0, int z = 0);

    /**
     * @brief Copies a Position from the RS client to a local
     *        Vec3D instance
     *
     * This constructor allows for inserting Position* values in
     * functions that accept Vec3D instances.
     *
     * @param pos - the Position to take coordinates from
     */
    Vec3D(component::Position* pos);

    double x() const { return _x; }
    double y() const { return _y; }
    double z() const { return _z; }

    double dist(Vec3D other) const;
    double squareDist(Vec3D other) const;
};

#endif // VEC3D_H
