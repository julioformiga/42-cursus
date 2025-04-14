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
	int	N = 5;

	Zombie zombie1 = Zombie("Zombie #1");
	zombie1.announce();

	Zombie* zombie2 = new Zombie("Zombie #2");
	zombie2->announce();
	delete zombie2;

	Zombie* horde = zombieHorde(N, "Horde Zombie");
	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}
