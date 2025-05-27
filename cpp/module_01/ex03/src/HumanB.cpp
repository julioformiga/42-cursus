#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
  std::cout << "\033[1;34m-----============== [ B] =============-----"
            << std::endl;
}

HumanB::~HumanB(void) { std::cout << "\033[0m" << std::ends; }

void HumanB::setWeapon(Weapon &weapon) { _weapon = &weapon; }

void HumanB::attack() const {
  if (!_weapon) {
    std::cout << _name << " has no weapon to attack" << std::endl;
    return;
  }
  std::cout << _name << " attacks with their " << _weapon->getType()
            << std::endl;
}
