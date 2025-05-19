/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:09:09 by julio.formiga     #+#    #+#             */
/*   Updated: 2025/05/14 12:09:09 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Memory address of the string variable: "
		<< std::setw(18) << &string << std::endl;
	std::cout << "Memory address held by stringPTR: "
		<< std::setw(23) << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: "
		<< std::setw(23) << &stringREF << std::endl;

	std::cout << "This is the value of variable string: "
		<< std::setw(19) << string << std::endl;
	std::cout << "This is the value of variable stringPTR: "
		<< std::setw(16) << *stringPTR << std::endl;
	std::cout << "This is the value of variable stringREF: "
		<< std::setw(16) << stringREF << std::endl;

	return (0);
}
