#include "Fixed.hpp"
#include <bitset>
#include <iostream>

// int main(void) {
//   float float_number = 5.05f;
//   Fixed a;
//   Fixed const b(Fixed(float_number) * Fixed(2));
//   Fixed const c(Fixed(float_number) / Fixed(2));
//   Fixed const d(Fixed(float_number) - Fixed(2));
//   Fixed const e(Fixed(float_number) + Fixed(2));
//
//   std::cout << "a   = " << a << std::endl;
//   std::cout << "++a = " << ++a << std::endl;
//   std::cout << "a   = " << a << std::endl;
//   std::cout << "a++ = " << a++ << std::endl;
//   std::cout << "a   = " << a << std::endl;
//
//   std::cout << std::endl;
//   std::cout << float_number << " * 2 = b(*) = " << b << std::endl;
//   std::cout << float_number << " / 2 = c(/) = " << c << std::endl;
//   std::cout << float_number << " - 2 = d(-) = " << d << std::endl;
//   std::cout << float_number << " + 2 = e(+) = " << e << std::endl;
//   std::cout << "Float number: " << float_number << " - bit("
//             << std::bitset<8>(float_number) << ")" << std::endl;
//   std::cout << "Max - " << Fixed::max(a, b) << std::endl;
//   std::cout << "Min - " << Fixed::min(a, b) << std::endl;
//   return (0);
// }

#include "Fixed.hpp"
#include <iostream>

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;

  std::cout << b << std::endl;

  std::cout << Fixed::max(a, b) << std::endl;

  return 0;
}
