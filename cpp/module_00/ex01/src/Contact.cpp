/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:50:02 by julio.formiga     #+#    #+#             */
/*   Updated: 2025/04/03 18:50:02 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#include <iostream>
#include <iomanip>

Contact::Contact(void) {
	this->_active = false;
}

Contact::Contact(std::string firstName, std::string lastName,
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

Contact::~Contact(void) {}

std::string Contact::truncateString(const std::string &str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void Contact::displayContact(void) const {
	if (this->_active)
		std::cout << "│"
				<< std::setw(10) << truncateString(_firstName) << "│"
				<< std::setw(10) << truncateString(_lastName) << "│"
				<< std::setw(10) << truncateString(_nickName) << "│"
			<< std::endl;
}

void Contact::displayFullContact(void) const {
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

bool Contact::isActive(void) const {
	return this->_active;
}

void Contact::deactivate(void) {
	this->_active = false;
}
