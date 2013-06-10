#ifndef POINT_H
#define POINT_H

#include <cmath>

namespace world {
  /**
   * @brief a 3D Point representation
   *
   * The Point class can be used as unique identifier for a tile in the Runescape environment.
   * This class supports various arithmetic operations, and can be used as a 3D vector using the provided operator overloads.
   */
  class Point {
    private:
      int x, y;
      short z;
    public:
      /**
       * @brief Constructs a Point at the given coordinates
       * @param x_coord the x coordinate
       * @param y_coord the y coordinate
       * @param plane the z coordinate, also the plane in the runescape environment.
       */
      explicit Point(int x_coord = 0, int y_coord = 0, short plane = 0) {
        x = x_coord;
        y = y_coord;
        z = plane;
      }

      /**
       * @brief Returns the x coordinate of this Point
       * @return the x coordinate of this Point
       */
      int GetX() { return x; }
      /**
       * @brief Returns the y coordinate of this Point
       * @return the y coordinate of this Point
       */
      int GetY() { return y; }
      /**
       * @brief Returns the z coordinate (aka the plane) of this Point
       * @return the z coordinate of this Point
       */
      short GetPlane() { return z; }

      /// performs a basic vector addition between the two Points
      Point operator +(Point other) { return Point(x + other.GetX(), y + other.GetY(), z + other.GetPlane()); }
      /// performs a besic vector subtraction between the two Points
      Point operator -(Point other) { return Point(x - other.GetX(), y - other.GetY(), z - other.GetPlane()); }
      /// performs a multiplication with a scalar like a vector
      Point operator *(double scalar) { return Point(x * scalar, y * scalar, z * scalar); }
      /// performs a division by a scalar like a vector
      Point operator /(double scalar) { return Point(x / scalar, y / scalar, z / scalar); }

      /// Returns true if and only if the two Points represent the same position
      bool operator==(Point other) { return x == other.GetX() && y == other.GetY() && z == other.GetPlane(); }

      /// Returns the angle of this Point as a vector in the (x,y) plane
      double GetAngle() { return atan2(y, x); }
      /// Returns the length of this Point as a vector in the (x,y) plane
      double GetRadius() { return sqrt(x*x + y*y); }

      /**
       * @brief Returns the distance between this Point and the given Point
       * @param other the other Point
       *
       * Note that this is the same as computing the difference between this and the other Point and then
       * taking the Radius of the resulting Point.
       * @return the distance between this Point and the given Point
       */
      double GetDistance(Point other) { Point diff = (*this - other); return diff.GetRadius(); }
  };
}
#endif // POINT_H
