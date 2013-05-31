#ifndef POINT_H
#define POINT_H

#include <cmath>

namespace world {
  class Point {
    private:
      int x, y;
      short z;
    public:
      Point(int x_coord, int y_coord, short plane = 0) {
        x = x_coord;
        y = y_coord;
        z = plane;
      }

      int GetX() { return x; }
      int GetY() { return y; }
      short GetPlane() { return z; }

      Point operator +(Point other) { return Point(x + other.GetX(), y + other.GetY(), z + other.GetPlane()); }
      Point operator -(Point other) { return Point(x - other.GetX(), y - other.GetY(), z - other.GetPlane()); }
      Point operator *(double scalar) { return Point(x * scalar, y * scalar, z * scalar); }
      Point operator /(double scalar) { return Point(x / scalar, y / scalar, z / scalar); }

      bool operator==(Point other) { return x == other.GetX() && y == other.GetY() && z == other.GetPlane(); }

      double GetAngle() { return atan2(y, x); }
      double GetRadius() { return sqrt(x*x + y*y); }

      double GetDistance(Point other) { Point diff = (*this - other); return diff.GetRadius(); }
  };
}
#endif // POINT_H
