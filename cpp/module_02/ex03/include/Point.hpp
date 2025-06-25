#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"
#include <ostream>

class Point {
public:
  Point();
  Point(Point &copy);
  Point(Fixed const &x, Fixed const &y);
  Point &operator=(Point const &copy);
  std::string show_points(void) const;

  float getX(void) const {
    return _x.toFloat();
  };

  float getY(void) const {
    return _y.toFloat();
  };

  ~Point();

private:
  Fixed const _x;
  Fixed const _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

float sign(Point const &check, Point const &a, Point const &b);

std::ostream &operator<<(std::ostream &os, Point const &point);

#endif
