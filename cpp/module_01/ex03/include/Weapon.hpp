#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
public:
  Weapon(std::string _type);
  ~Weapon(void);
  const std::string &getType(void) const;
  void setType(std::string _type);

private:
  std::string _type;
};

#endif
