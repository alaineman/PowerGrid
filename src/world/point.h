#ifndef POINT_H
#define POINT_H

#include "stdafx.h"

namespace world {
  class Point
  {
    private:
      int x, y;
      short z;
    public:
      Point(int x_coordinate, int y_coordinate, short plane);
      Point(const Point& orig);
      Point(int x_coordinate, int y_coordinate);

      int GetX();
      int GetY();
      short GetPlane();

      double GetAngle();
      double GetRadius();

      double GetDistance(Point other);

      Point operator +(Point other);
      Point operator -(Point other);
      Point operator *(double scalar);
      Point operator /(double scalar);

      bool operator==(Point other);
  };
}
#endif // POINT_H
