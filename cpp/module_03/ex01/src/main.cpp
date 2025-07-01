#include "ClapTrap.hpp"
#include "Utils.hpp"

#include <iostream>

class ScavTrap : public ClapTrap {
public:
  ScavTrap() {
    std::cout << BLUE << "======== Constructor [" << _name
              << "] ========" << RESET << std::endl;
  };

  ScavTrap(std::string name) {
    _name = name;
    std::cout << BLUE << "======== Constructor [" << _name
              << "] ========" << RESET << std::endl;
  };

  void guardGate() {}

  ~ScavTrap() {
    std::cout << RED << "========= Destructor [" << _name
              << "] ========" << RESET << std::endl;
  };
};

int main(void) {
  ClapTrap dev("Jedi");
  ScavTrap scav("Scavenger");
  scav.attack("asd");
  // {
  // }
  dev.debug(true);
  dev.attack("C");
  dev.attack("Python");
  dev.takeDamage(5);
  dev.attack("Java");
  dev.attack("C++");
  dev.beRepaired(2);
  dev.attack("Assembly");
  dev.attack("Assembly");
  dev.takeDamage(5);
  dev.beRepaired(2);

  // ClapTrap clone;
  // clone.debug(true);
  // clone = dev;
  // clone.attack("Java");
  // clone.takeDamage(3);
  return (0);
}
