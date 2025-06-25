#include "Point.hpp"
#include <ostream>
#include <sstream>

Point::Point() : _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(Point &copy) {
  *this = copy;
}

Point::Point(Fixed const &x, Fixed const &y) : _x(x), _y(y) {}

Point &Point::operator=(Point const &copy) {
  if (this != &copy) {
    this->~Point();
    new (this) Point(copy._x, copy._y);
  }
  return *this;
}

std::string Point::show_points(void) const {
  std::stringstream ss;
  ss << "(" << _x.toFloat() << ", " << _y.toFloat() << ")";
  return ss.str();
}

Point::~Point() {}

std::ostream &operator<<(std::ostream &os, Point const &point) {
  os << point.show_points();
  return (os);
}

float sign(Point const &p, Point const &a, Point const &b) {
  float v1x = p.getX() - b.getX();
  float v1y = p.getY() - b.getY();
  float v2x = a.getX() - b.getX();
  float v2y = a.getY() - b.getY();

  return (v1x * v2y - v2x * v1y);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  float d1, d2, d3;
  bool has_neg, has_pos;

  d1 = sign(point, a, b);
  d2 = sign(point, b, c);
  d3 = sign(point, c, a);
  has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
  has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
  return !(has_neg && has_pos);
}
