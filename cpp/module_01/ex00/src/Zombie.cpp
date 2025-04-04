/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:23:26 by julio.formiga     #+#    #+#             */
/*   Updated: 2025/03/30 14:23:26 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(void) {}

Zombie::Zombie(std::string name) : _name(name) {}

Zombie* Zombie::newZombie(std::string name)
{
	return (new Zombie(name));
}

void Zombie::announce(void) const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}

Zombie::~Zombie() {
	std::cout << _name << " is destroyed." << std::endl;
}
