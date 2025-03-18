/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:10:45 by julio.formiga     #+#    #+#             */
/*   Updated: 2025/03/18 03:10:45 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <cstdlib>

class Contact{
	private:
		static std::string	_fields_name[5];
		std::string			_informations[11];

		enum Field {
		FirstName = 0,
			LastName,
			NickName,
			PhoneNumber,
			DarkestSecret
		};
	public:
		Contact(void);
		~Contact(void);

		bool	set_contact();
		void	get_contact(int index)const;
};

#endif
