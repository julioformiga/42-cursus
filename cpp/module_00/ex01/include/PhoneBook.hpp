/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:17:07 by julio.formiga     #+#    #+#             */
/*   Updated: 2025/04/03 18:17:07 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		static const int MAX_CONTACTS = 8;
		Contact _contacts[MAX_CONTACTS];
		int _currentIndex;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void addContact(void);
		void listContacts(void) const;
};

#endif
