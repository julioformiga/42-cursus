#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
public:
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap &operator=(const ClapTrap &copy);
  void attack(std::string const &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void showData(void);
  void debug(bool debug);
  ~ClapTrap();

private:
  std::string _name;
  unsigned int _hitpoints;
  unsigned int _energy;
  unsigned int _attackdamage;
  bool _debug;
};

#endif
