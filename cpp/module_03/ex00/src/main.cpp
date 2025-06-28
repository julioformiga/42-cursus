#include "ClapTrap.hpp"

int main(void) {
  ClapTrap dev("Julio");
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
  dev.attack("Assembly");
  dev.attack("Assembly");
  dev.attack("Assembly");
  dev.beRepaired(2);
  dev.attack("Assembly");
  dev.attack("Assembly");
  dev.attack("Assembly");

  // ClapTrap clone;
  // clone.debug(true);
  // clone = dev;
  // clone.attack("Java");
  // clone.takeDamage(3);
  return (0);
}
