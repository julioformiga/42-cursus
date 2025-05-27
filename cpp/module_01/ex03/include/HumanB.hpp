#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB {
public:
  HumanB(std::string _name);
  ~HumanB(void);
  void setWeapon(Weapon &_weapon);
  void attack(void) const;

private:
  std::string _name;
  Weapon *_weapon;
};

#endif
