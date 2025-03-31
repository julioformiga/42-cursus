/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 06:13:39 by julio.formiga     #+#    #+#             */
/*   Updated: 2025/03/31 06:13:39 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie(std::string name) : _name(name) {}
		~Zombie() {
			std::cout << _name << " is destroyed." << std::endl;
		}
		void announce(void) const {
			std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
		}
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
