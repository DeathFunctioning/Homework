/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:18:43 by tbaker            #+#    #+#             */
/*   Updated: 2024/11/11 18:08:37 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}

bool Contact::_stringIsEmpty(std::string& input)
{
	if (input.empty())
		return (true);
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!std::isspace(input.at(i)))
			return (false);
	}
	return (true);
}

void	Contact::_assignInput(std::string& var, const char* txt)
{
	while (true)
	{
		std::cout << txt;
		std::getline(std::cin, var);
		if (_stringIsEmpty(var))
			std::cout << "Empty string entered. ";
		else
			break ;
	}
}

void Contact::inputContact(void)
{
	_assignInput(firstName, "Enter first name: ");
	_assignInput(lastName, "Enter last name: ");
	_assignInput(phoneNumber, "Enter phone number: ");
	_assignInput(nickname, "Enter nickname: ");
	_assignInput(darkestSecret, "Enter darkest secret: ");
	return ;
}
