#include "ClapTrap.hpp"

int main(void) {
  ClapTrap dev("Julio");
  dev.debug(true);
  dev.attack("C");
  dev.takeDamage(10);
  dev.attack("Python");
  dev.takeDamage(5);
  dev.attack("Java");
  dev.attack("C++");
  dev.beRepaired(2);
  dev.attack("Assembly");

  // ClapTrap clone;
  // clone.debug(false);
  // clone.takeDamage(3);
  // clone.attack("Java");
  return (0);
}
