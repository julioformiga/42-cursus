#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main(void) {
  Point a(Fixed(3.01f), Fixed(4.0f));
  Point b(Fixed(1.3f), Fixed(2.0f));
  Point c(Fixed(2.0f), Fixed(5.2f));
  Point check1(Fixed(2.2f), Fixed(4.0f));
  Point check2(Fixed(((3.01f + 1.3f) / 2)), Fixed((4.0f + 2.0f) / 2));
  Point check3(Fixed(4.0f), Fixed(2.2f));

  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  std::cout << check1 << "\t" << bsp(a, b, c, check1) << std::endl;
  std::cout << check2 << "\t" << bsp(a, b, c, check2) << std::endl;
  std::cout << check3 << "\t" << bsp(a, b, c, check3) << std::endl;

  return (0);
}
