#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
  ScavTrap();
  ScavTrap(const std::string &name);
  ScavTrap(const ScavTrap &copy);
  ScavTrap &operator=(const ScavTrap &copy);
  void attack(std::string const &target);
  void guardGate();
  ~ScavTrap();

private:
  bool _guard_gate;
};

#endif
