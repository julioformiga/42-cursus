/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:15:33 by julio.formiga     #+#    #+#             */
/*   Updated: 2025/04/03 18:15:33 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

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
		Contact(void);
		Contact(std::string firstName, std::string lastName,
		  std::string nickName, std::string phoneNumber,
		  std::string darkestSecret);
		~Contact(void);
		std::string truncateString(const std::string &str) const;
		void displayContact(void) const;
		void displayFullContact(void) const;
		bool isActive(void) const;
		void deactivate(void);
};

#endif
