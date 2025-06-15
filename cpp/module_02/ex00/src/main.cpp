#include "Fixed.hpp"
#include <iostream>

int main(void) {
  Fixed a;
  // a.setRawBits(42);
  Fixed b(a);
  Fixed c;

  c = b;

  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;

  return (0);
}
