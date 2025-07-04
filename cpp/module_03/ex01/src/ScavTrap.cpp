#include "ScavTrap.hpp"
#include "Utils.hpp"

#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
  _name = "Scav";
  _hitpoints = 100;
  _energy = 50;
  _attackdamage = 20;
  _guard_gate = false;
  banner("Scav Constructor [" + _name + "]");
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
  _hitpoints = 100;
  _energy = 50;
  _attackdamage = 20;
  _guard_gate = false;
  banner("Scav Constructor [" + _name + "]");
  this->showData();
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
  if (this != &copy)
    *this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy) {
  if (this != &copy) {
    _name = copy._name + " (copy operator)";
    _hitpoints = copy._hitpoints;
    _attackdamage = copy._attackdamage;
    _energy = copy._energy;
    _debug = copy._debug;
  }
  return (*this);
}

void ScavTrap::attack(std::string const &target) {
  if (_hitpoints > 0 && _energy > 0) {
    std::cout << GREEN << "󰓥 SCAV-ATTACK " << _name << " attacks " << CYAN
              << target << GREEN << ", causing " << CYAN << _attackdamage
              << GREEN << " points of damage!" << RESET << std::endl;
    _energy--;
  } else {
    std::cout << RED << std::ends;
    if (_hitpoints <= 0)
      std::cout << " Hit Points is empty, you cannot attack " << std::ends;
    else if (_energy <= 0)
      std::cout << " Energy is empty, you cannot attack " << std::ends;
    std::cout << BLUE << target << RESET << std::endl;
  }
  if (_debug)
    ScavTrap::showData();
}

void ScavTrap::guardGate() {
  if (_guard_gate) {
    _guard_gate = false;
    msg("󰊙 " + _name + " is already in Gate Keeper mode.", YELLOW);
  } else {
    _guard_gate = true;
    msg("󰊙 " + _name + " is now in Gate Keeper mode.", CYAN);
  }
}

ScavTrap::~ScavTrap() {
  banner("Scav Destructor [" + _name + "]", RED);
}
