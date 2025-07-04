#include "ClapTrap.hpp"
#include "Utils.hpp"

#include <iostream>

ClapTrap::ClapTrap()
    : _name("Clone"), _hitpoints(10), _energy(10), _attackdamage(0),
      _debug(false) {
  banner("Clap Constructor [" + _name + "]");
  this->showData();
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
  if (this != &copy)
    *this = copy;
  this->showData();
}

ClapTrap::ClapTrap(std::string name)
    : _hitpoints(10), _energy(10), _attackdamage(0), _debug(false) {
  _name = name;
  banner("Clap Constructor [" + name + "]");
  this->showData();
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
  if (this != &copy) {
    _name = copy._name;
    _hitpoints = copy._hitpoints;
    _energy = copy._energy;
    _attackdamage = copy._attackdamage;
  }
  return (*this);
}

void ClapTrap::debug(bool debug) {
  _debug = debug;
}

void ClapTrap::showData(void) {
  std::cout << DARKGREEN << " [" << _name << "] " << std::ends;
  std::cout << ": " << _hitpoints << " | " << std::ends;
  std::cout << ": " << _energy << " | " << std::ends;
  std::cout << "󱢾: " << _attackdamage << RESET << std::endl;
}

void ClapTrap::attack(std::string const &target) {
  if (_hitpoints > 0 && _energy > 0) {
    std::cout << GREEN << "󰓥 " << _name << " attacks " << CYAN << target
              << GREEN << ", causing " << CYAN << _attackdamage << GREEN
              << " points of damage!" << RESET << std::endl;
    _energy--;
  } else {
    std::cout << RED << std::ends;
    if (_hitpoints <= 0)
      std::cout << " Points is empty, you cannot attack " << std::ends;
    else if (_energy <= 0)
      std::cout << " Energy is empty, you cannot attack " << std::ends;
    std::cout << BLUE << target << RESET << std::endl;
  }
  if (_debug)
    ClapTrap::showData();
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (amount > 0) {
    if (amount >= _hitpoints)
      _hitpoints = 0;
    else
      _hitpoints -= amount;
    std::cout << RED << "   󱢾 " << _name << " take " << YELLOW << amount
              << RED << " of damage" << RESET << std::endl;
  } else
    std::cout << RED << "You cannot take negative damage." << RESET
              << std::endl;
  if (_debug)
    ClapTrap::showData();
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_energy > 0) {
    _hitpoints += amount;
    _energy--;
    std::cout << CYAN << "    " << _name << " repair " << BLUE << amount
              << CYAN << " hit points" << RESET << std::endl;
  } else
    std::cout << RED << "    Energy is empty, you cannot repair." << RESET
              << std::endl;
  if (_debug)
    ClapTrap::showData();
}

ClapTrap::~ClapTrap() {
  banner("Clap Destructor [" + _name + "]", RED);
}
