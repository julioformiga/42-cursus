#include "Fixed.hpp"
#include <iostream>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fp_number(0) {
  std::cout << BLUE << "Default constructor called" << RESET << std::endl;
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

Fixed::~Fixed() {
  std::cout << RED << "Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits(void) const {
  std::cout << WHITE << "getRawBits member function called" << RESET
            << std::endl;
  return _fp_number;
}

void Fixed::setRawBits(const int fp_number) {
  std::cout << WHITE << "setRawBits member function called" << RESET
            << std::endl;
  _fp_number = fp_number;
}
