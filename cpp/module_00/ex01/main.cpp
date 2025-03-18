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
	PhoneBook 	PhoneBook;
	bool		run = true;
	std::string	command;

	PhoneBook.show_instruction();
	std::cout << "\033[33m$>\033[0m";
	while (run && std::getline(std::cin, command))
	{
		if (std::cin.eof() == true)
		{
			std::cout << "You Pressed ^D. Exiting phonebook now." << std::endl;
			exit(0);
		}
		else if (command.compare("ADD") == 0)
			PhoneBook.set_information();
		else if (command.compare("SEARCH") == 0)
			PhoneBook.get_information();
		else if (command.compare("EXIT") == 0)
		{
			std::cout << "\033[34mHope i served you well. Good Bye.\033[0m"
						<< std::endl;
			run = false;
			continue ;
		}
		command.clear();
		PhoneBook.show_instruction();
		std::cout << "\033[33m$> \033[0m";
	}
	if (run)
	{
		std::cout << "You pressed ^D, exiting now." << command << std::endl
		<< "\033[34mHope i served you well. Good Bye.\033[0m" << std::endl;
	}
	return (0);
}
