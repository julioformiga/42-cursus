#include "Fixed.hpp"
#include <iostream>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fp_number(0) {
  std::cout << BLUE << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int fixedp_number) {
  std::cout << BLUE << "Int constructor called" << RESET << std::endl;
  _fp_number = fixedp_number << _fractionalBits;
}

Fixed::Fixed(const float floatp_number) {
  std::cout << BLUE << "Float constructor called" << RESET << std::endl;
  _fp_number = floatp_number * (1 << _fractionalBits);
}

Fixed::Fixed(const Fixed &copy) {
  std::cout << CYAN << "Copy constructor called" << RESET << std::endl;
  *this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy) {
  std::cout << MAGENTA << "Copy assignment operator called" << RESET
            << std::endl;
  if (this != &copy) {
    _fp_number = copy.getRawBits();
  }
  return *this;
}

int Fixed::getRawBits(void) const { return _fp_number; }

void Fixed::setRawBits(const int fp_number) { _fp_number = fp_number; }

float Fixed::toFloat(void) const {
  if (_fp_number == 0)
    return 0.0f;
  return (float)((float)_fp_number / (1 << _fractionalBits));
}

int Fixed::toInt(void) const { return (int)(_fp_number >> _fractionalBits); }

Fixed::~Fixed() {
  std::cout << RED << "Destructor called" << RESET << std::endl;
}
std::ostream &operator<<(std::ostream &os, Fixed const &fixed) {
  os << fixed.toFloat();
  return (os);
}
