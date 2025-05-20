#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB {
private:
  std::string _name;
  Weapon *_weapon;

public:
  HumanB(std::string _name);
  ~HumanB(void);
  void setWeapon(Weapon &_weapon);
  void attack(void) const;
};

#endif
