#include "ClapTrap.hpp"
#include "Utils.hpp"

#include <iostream>

ClapTrap::ClapTrap() {
  _name = "Clone";
  _points = 10;
  _energy = 10;
  _damage = 0;
  _debug = false;
  std::cout << BLUE << "======== Constructor [" << _name
            << "] ========" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _points(10), _energy(10), _damage(0) {
  _name = name;
  _debug = false;
  std::cout << BLUE << "======== Constructor [" << _name
            << "] ========" << RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
  if (this != &copy) {
    _name = copy._name;
    _points = copy._points;
    _energy = copy._energy;
    _damage = copy._damage;
  }
  return (*this);
}

void ClapTrap::debug(bool debug) {
  _debug = debug;
}

void ClapTrap::showData(void) {
  std::cout << DARKGREEN << "󰋼 ClapTrap: " << _name << " | " << std::ends;
  std::cout << "P: " << _points << " | " << std::ends;
  std::cout << "E: " << _energy << " | " << std::ends;
  std::cout << "D: " << _damage << RESET << std::endl;
  std::cout << std::endl;
}

void ClapTrap::attack(std::string const &target) {
  // if (_points > 0 && _energy > 0 && _damage > 0) {
  if (_points > 0 && _energy > 0) {
    std::cout << GREEN << "󰓥 " << _name << " attacks " << CYAN << target
              << GREEN << ", causing " << CYAN << _damage << GREEN
              << " points of damage!" << RESET << std::endl;
    _energy--;
  } else {
    std::cout << RED << " " << std::ends;
    if (_points <= 0)
      std::cout << "Points is empty, you cannot attack " << std::ends;
    else if (_energy <= 0)
      std::cout << "Energy is empty, you cannot attack " << std::ends;
    // else if (_damage <= 0)
    //   std::cout << "Damage is empty, you cannot attack " << std::ends;
    std::cout << BLUE << target << RESET << std::endl;
  }
  if (_debug)
    ClapTrap::showData();
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (amount > 0) {
    _damage += amount;
    std::cout << YELLOW << "\t[[[[[   " << _name << " take " << RED << amount
              << YELLOW << " of damage   ]]]]]" << RESET << std::endl;
  } else
    std::cout << RED << "You cannot take negative damage." << RESET
              << std::endl;
  if (_debug)
    ClapTrap::showData();
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_energy > 0) {
    _points += amount;
    _energy--;
    std::cout << CYAN << "\t[[[[[   " << _name << " repair " << BLUE << amount
              << CYAN << " points   ]]]]]" << RESET << std::endl;
  } else
    std::cout << RED << "Energy is empty, you cannot repair." << RESET
              << std::endl;
  if (_debug)
    ClapTrap::showData();
}

ClapTrap::~ClapTrap() {
  std::cout << RED << "========= Destructor [" << _name << "] ========" << RESET
            << std::endl;
}
