#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
private:
  std::string _type;

public:
  Weapon(std::string _type);
  ~Weapon(void);
  const std::string &getType(void) const;
  void setType(std::string _type);
};

#endif
