/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:18:43 by tbaker            #+#    #+#             */
/*   Updated: 2024/11/01 12:52:01 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}

void Contact::inputContact(void)
{
	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	while (firstName.empty())
	{
		std::cout << "You entered empty string" << std::endl;
		std::cout << "Enter first name: ";
		std::getline(std::cin, firstName);
	}

	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	while (lastName.empty())
	{
		std::cout << "You entered empty string" << std::endl;
		std::cout << "Enter last name: ";
		std::getline(std::cin, lastName);
	}

	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	while (nickname.empty())
	{
		std::cout << "You entered empty string" << std::endl;
		std::cout << "Enter nickname: ";
		std::getline(std::cin, nickname);
	}

	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	while (phoneNumber.empty())
	{
		std::cout << "You entered empty string" << std::endl;
		std::cout << "Enter phone number: ";
		std::getline(std::cin, phoneNumber);
	}

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);
	while (darkestSecret.empty())
	{
		std::cout << "You entered empty string" << std::endl;
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, darkestSecret);
	}

	return ;
}
