#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

int main(void) {
  ClapTrap jedi("Jedi");
  jedi.debug(true);
  jedi.attack("Sith");
  jedi.attack("Clone Trooper");
  jedi.takeDamage(2);
  jedi.attack("Clone Trooper");
  jedi.beRepaired(2);
  jedi.takeDamage(5);
  jedi.attack("Darth Vader");
  jedi.takeDamage(5);
  jedi.attack("Darth Vader");

  std::cout << std::endl;

  ScavTrap *sith = new ScavTrap("Sith");
  sith->debug(true);
  sith->guardGate();
  sith->attack("Clone Trooper");
  sith->takeDamage(2);
  sith->attack("R2D2");
  sith->beRepaired(2);
  sith->attack("Skywalker");
  sith->takeDamage(5);
  sith->attack("Yoda");
  sith->takeDamage(15);
  sith->attack("Yoda");
  sith->guardGate();
  sith->guardGate();
  delete sith;

  std::cout << std::endl;

  ClapTrap *clone = new ScavTrap("Clone Trooper");
  clone->attack("test");
  delete clone;

  std::cout << std::endl;
  return (0);
}
