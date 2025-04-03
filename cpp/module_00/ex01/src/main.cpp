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

#include "PhoneBook.hpp"

#include <iostream>

int main(void)
{
	PhoneBook phoneBook;
	std::string command;

	while (true) {
		std::cout << "\nEnter command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, command);

		if (command == "a" || command == "ADD")
			phoneBook.addContact();
		else if (command == "s" || command == "SEARCH")
			phoneBook.listContacts();
		else if (command == "e" || command == "EXIT")
			break;
		else
			std::cout << "Invalid command. Try again." << std::endl;
	}

	return (0);
}
