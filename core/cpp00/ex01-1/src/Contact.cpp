/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:18:43 by tbaker            #+#    #+#             */
/*   Updated: 2024/10/28 18:17:30 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}

void Contact::inputContact(void)
{
//	std::getline(std::cin, "need to clear buffer");

//	std::cin.sync();

	std::cout << "Enter first name: ";
	std::getline(std::cin, this->firstName);
	//std::getline(std::cin >> std::ws, this->firstName);

	std::cout << "Enter last name: ";
	std::getline(std::cin, this->lastName);

	//std::cin >> this->lastName;
	std::cout << "Enter nickname: ";
	std::getline(std::cin, this->nickname);

	//std::cin >> this->nickname;
	std::cout << "Enter phone number: ";
	std::getline(std::cin, this->phoneNumber);

	//std::cin >> this->phoneNumber;
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, this->darkestSecret);
	//std::cin >> this->darkestSecret;

	return ;
}
