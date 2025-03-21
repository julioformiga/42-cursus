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

#include <iostream>
#include <iomanip>
#include <ostream>

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
		bool _active;

	public:

		Contact(void) {
			this->_active = false;
		}

		Contact(std::string firstName, std::string lastName,
		  std::string nickName, std::string phoneNumber,
		  std::string darkestSecret)
		{
			this->_firstName = firstName;
			this->_lastName = lastName;
			this->_nickName = nickName;
			this->_phoneNumber = phoneNumber;
			this->_darkestSecret = darkestSecret;
			this->_active = true;
		}

		~Contact(void) {}

		std::string truncateString(const std::string &str) const
		{
			if (str.length() > 10)
				return str.substr(0, 9) + ".";
			return str;
		}

		void displayContact(void) const {
			if (this->_active)
				std::cout << "│"
						<< std::setw(10) << truncateString(_firstName) << "│"
						<< std::setw(10) << truncateString(_lastName) << "│"
						<< std::setw(10) << truncateString(_nickName) << "│"
					<< std::endl;
		}

		void displayFullContact(void) const {
			if (this->_active) {
				std::cout << "───────────────────────────────────────────" << std::endl;
				std::cout << "            CONTACT DETAILS" << std::endl;
				std::cout << "───────────────────────────────────────────" << std::endl;
				std::cout << "First Name: " << _firstName << std::endl;
				std::cout << "Last Name: " << _lastName << std::endl;
				std::cout << "Nickname: " << _nickName << std::endl;
				std::cout << "Phone Number: " << _phoneNumber << std::endl;
				std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
				std::cout << "───────────────────────────────────────────" << std::endl;
			}
		}

		bool isActive(void) const {
			return this->_active;
		}

		void deactivate(void) {
			this->_active = false;
		}
};

class PhoneBook
{
	private:
		static const int MAX_CONTACTS = 8;
		Contact _contacts[MAX_CONTACTS];
		int _currentIndex;

	public:
		PhoneBook(void) {
			std::cout << "Welcome to PhoneBook!" << std::endl;
			_currentIndex = 0;
		}
		~PhoneBook(void) {
			std::cout << "Goodbye!" << std::endl;
		}

		void addContact(void) {
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

		void listContacts(void) const {
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
};

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
