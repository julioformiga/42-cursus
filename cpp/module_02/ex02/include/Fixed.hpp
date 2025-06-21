#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"

class Fixed {
public:
  Fixed();
  Fixed(const int fixedp_number);
  Fixed(const float floatp_number);
  Fixed(const Fixed &copy);
  Fixed &operator=(const Fixed &copy);
  Fixed operator++();
  Fixed operator++(int);
  Fixed operator--();
  Fixed operator--(int);
  Fixed operator+(const Fixed &other) const;
  Fixed operator-(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;
  static Fixed &min(Fixed &n1, Fixed &n2);
  static const Fixed &min(const Fixed &n1, const Fixed &n2);
  static Fixed &max(Fixed &n1, Fixed &n2);
  static const Fixed &max(const Fixed &n1, const Fixed &n2);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const fp_number);
  float toFloat(void) const;
  int toInt(void) const;

private:
  int _fp_number;
  static const int _fractional_bits;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif
