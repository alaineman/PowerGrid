#include "point.h"
#include "math.h"

namespace world {
  Point::Point(const Point &orig) {
    x = orig.x;
    y = orig.y;
    z = orig.z;
  }

  Point::Point(int x_coordinate, int y_coordinate, short plane) {
    x = x_coordinate;
    y = y_coordinate;
    z = plane;
  }

  Point::Point(int x_coordinate, int y_coordinate) {
    x = x_coordinate;
    y = y_coordinate;
    z = 0;
  }

  int Point::GetX() {
    return x;
  }

  int Point::GetY() {
    return y;
  }

  short Point::GetPlane() {
    return z;
  }

  double Point::GetAngle() {
    return atan2(y, x);
  }

  double Point::GetRadius() {
    return sqrt(x*x + y*y);
  }

  double Point::GetDistance(Point other) {
    Point base = *this - other;
    return base.GetRadius();
  }

  Point Point::operator + (Point other) {
    return Point(x + other.GetX(), y + other.GetY(), z + other.GetPlane());
  }

  Point Point::operator - (Point other) {
    return Point(x - other.GetX(), y - other.GetY(), z - other.GetPlane());
  }

  Point Point::operator * (double s) {
    return Point ((int)(x * s), (int)(y * s), (int)(z * s));
  }

  Point Point::operator / (double s) {
    return *this * (1/s);
  }

  bool Point::operator == (Point other) {
    return (x == other.GetX() && y == other.GetY() && z == other.GetPlane());
  }
}
