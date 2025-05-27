#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA {
public:
  HumanA(std::string _name, Weapon &_weapon);
  ~HumanA(void);
  void setWeapon(Weapon &_weapon);
  void attack(void) const;

private:
  std::string _name;
  Weapon &_weapon;
};

#endif
