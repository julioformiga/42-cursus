/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:21:28 by julio.formiga     #+#    #+#             */
/*   Updated: 2025/05/16 15:21:28 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
private:
  std::string _type;

public:
  Weapon(std::string type);
  ~Weapon(void);
  const std::string &getType(void) const;
  void setType(std::string type);
};

#endif
