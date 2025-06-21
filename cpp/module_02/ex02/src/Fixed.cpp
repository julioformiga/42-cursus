#include "Fixed.hpp"
#include <cmath>
#include <iostream>

const int Fixed::_fractional_bits = 8;

Fixed::Fixed() : _fp_number(0) {}

Fixed::Fixed(const int fixedp_number) {
  _fp_number = fixedp_number << _fractional_bits;
}

Fixed::Fixed(const float floatp_number) {
  _fp_number = roundf(floatp_number * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed &copy) {
  *this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy) {
  if (this != &copy)
    _fp_number = copy.getRawBits();
  return *this;
}

Fixed Fixed::operator++() {
  _fp_number++;
  return (*this);
}

Fixed Fixed::operator++(int) {
  Fixed tmp = *this;
  ++_fp_number;
  return tmp;
}

Fixed Fixed::operator--() {
  --_fp_number;
  return (*this);
}

Fixed Fixed::operator--(int) {
  Fixed tmp = *this;
  --_fp_number;
  return tmp;
}

Fixed Fixed::operator*(const Fixed &other) const {
  Fixed result;
  result.setRawBits(
      (this->getRawBits() * (other.getRawBits()) >> _fractional_bits));
  return result;
}

Fixed Fixed::operator+(const Fixed &other) const {
  return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
  return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
  if (other.getRawBits() == 0)
    throw std::invalid_argument("Division by zero");
  return (this->toFloat() / other.toFloat());
}

int Fixed::getRawBits(void) const {
  return _fp_number;
}

void Fixed::setRawBits(const int fp_number) {
  _fp_number = fp_number;
}

float Fixed::toFloat(void) const {
  if (_fp_number == 0)
    return 0.0f;
  return ((float)_fp_number / (float)(1 << _fractional_bits));
}

int Fixed::toInt(void) const {
  return (int)(_fp_number >> _fractional_bits);
}

Fixed &Fixed::min(Fixed &n1, Fixed &n2) {
  if (n1.toFloat() >= n2.toFloat())
    return (n2);
  return (n1);
}

const Fixed &Fixed::min(const Fixed &n1, const Fixed &n2) {
  if (n1.toFloat() >= n2.toFloat())
    return (n2);
  return (n1);
}

Fixed &Fixed::max(Fixed &n1, Fixed &n2) {
  if (n1.toFloat() >= n2.toFloat())
    return (n1);
  return (n2);
}

const Fixed &Fixed::max(const Fixed &n1, const Fixed &n2) {
  if (n1.toFloat() >= n2.toFloat())
    return (n1);
  return (n2);
}

Fixed::~Fixed() {}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed) {
  os << fixed.toFloat();
  return (os);
}
