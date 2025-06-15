#ifndef FIXED_HPP
#define FIXED_HPP

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

class Fixed {
public:
  Fixed();
  Fixed(const Fixed &copy);
  Fixed &operator=(const Fixed &copy);
  ~Fixed();
  int getRawBits(void) const;
  void setRawBits(int const fp_number);

private:
  int _fp_number;
  static const int _fractionalBits;
};

#endif
