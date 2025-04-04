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

#include <string>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie(void);
		Zombie(std::string name);
		Zombie* newZombie(std::string name);
		void announce(void) const;
		void randomChump(std::string name);
		~Zombie(void);
};

#endif
