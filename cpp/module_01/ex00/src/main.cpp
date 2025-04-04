/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:11:09 by julio.formiga     #+#    #+#             */
/*   Updated: 2025/03/18 03:11:09 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie zombie1 = Zombie("Zombie #1");
	zombie1.announce();

	Zombie* zombie2 = new Zombie("Zombie #2");
	zombie2->announce();
	delete zombie2;

	Zombie *zombies[2] = {};
	zombies[0]->randomChump("Zombie #3");

	zombies[1] = zombies[0]->newZombie("Zombie #4");

	zombies[1]->announce();
	delete zombies[1];

	return (0);
}
