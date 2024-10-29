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
	std::cout << "Enter fist name: ";
	std::cin >> this->firstName;
	std::cout << "Enter last name: ";
	std::cin >> this->lastName;
	std::cout << "Enter nickname: ";
	std::cin >> this->nickname;
	std::cout << "Enter phone number: ";
	std::cin >> this->phoneNumber;
	std::cout << "Enter darkest secret: ";
	std::cin >> this->darkestSecret;

	return ;
}
