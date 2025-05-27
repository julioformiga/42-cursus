#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
    : _name(name), _weapon(weapon) {
  std::cout << "\033[1;31m-----============== [ A] =============-----"
            << std::endl;
}

HumanA::~HumanA(void) { std::cout << "\033[0m" << std::ends; }

void HumanA::attack() const {
  std::cout << _name << " attacks with their " << _weapon.getType()
            << std::endl;
}
