/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:33:28 by julio.formiga     #+#    #+#             */
/*   Updated: 2025/04/03 19:33:28 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(void) {
	std::cout << "Welcome to PhoneBook!" << std::endl;
	_currentIndex = 0;
}
PhoneBook::~PhoneBook(void) {
	std::cout << "Goodbye!" << std::endl;
}

void PhoneBook::addContact(void) {
	std::string firstName, lastName, nickName;
	std::string phoneNumber, darkestSecret;

	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickName);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter darkestSecret: ";
	std::getline(std::cin, darkestSecret);

	_contacts[_currentIndex % MAX_CONTACTS] = Contact(
		firstName,
		lastName,
		nickName,
		phoneNumber,
		darkestSecret
	);
	_currentIndex++;
	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::listContacts(void) const {
	if (_currentIndex == 0) {
		std::cout << "No contacts found." << std::endl;
		return;
	}

	std::cout << "╭───────────────────────────────────────────╮" << std::endl;
	std::cout << "│               CONTACT LIST                │" << std::endl;
	std::cout << "├──────────┬──────────┬──────────┬──────────┤" << std::endl;
	std::cout << "│   Index  │First Name│ Last Name│ Nickname │" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;

	for (int i = 0; i < MAX_CONTACTS; i++) {
		if (_contacts[i].isActive())
		{
			std::cout << "│" << std::setw(10) << i;
			_contacts[i].displayContact();
		}
	}
	std::cout << "╰──────────┴──────────┴──────────┴──────────╯" << std::endl;

	std::string input;
	std::cout << "\nEnter index to view full contact details (or press Enter to return): ";
	std::getline(std::cin, input);

	if (!input.empty()) {
		bool isValid = true;
		for (size_t i = 0; i < input.length(); i++) {
			if (input[i] < '0' || input[i] > '9') {
				isValid = false;
				break;
			}
		}

		if (isValid) {
			int index = 0;
			for (size_t i = 0; i < input.length(); i++) {
				index = index * 10 + (input[i] - '0');
			}

			if (index >= 0 && index < MAX_CONTACTS && _contacts[index].isActive())
				_contacts[index].displayFullContact();
			else
				std::cout << "Invalid index!" << std::endl;
		} else {
			std::cout << "Invalid input! Please enter a number." << std::endl;
		}
	}
}
