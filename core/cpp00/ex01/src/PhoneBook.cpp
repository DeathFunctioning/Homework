/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:06:40 by tbaker            #+#    #+#             */
/*   Updated: 2024/11/01 17:04:56 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : numberOfContacts(0), indexPosition(0) {}	

bool	PhoneBook::checkIndexValue(std::string indexValue)
{
	if (indexValue.length() == 1)
	{
		if (indexValue.at(0) >= '0' && indexValue.at(0) <= '7')
			return (true);
		else
		   return (false);	
	}
	else
		return (false);
}

void	PhoneBook::selectContact(void)
{
	std::string indexValue;
	int			nbr;

    nbr = -1;
	while (true)
	{
		std::cout << "Enter index to view contact information: ";
		std::getline(std::cin, indexValue);
		if (checkIndexValue(indexValue))
		{
			nbr = atoi(indexValue.c_str()); 
			if (nbr >= 0 && nbr < numberOfContacts)
       		 {
	       		 std::cout << contacts[nbr].firstName << std::endl;
	       		 std::cout << contacts[nbr].lastName << std::endl;
	       		 std::cout << contacts[nbr].nickname << std::endl;
				 std::cout << contacts[nbr].phoneNumber << std::endl;
				 std::cout << contacts[nbr].darkestSecret << std::endl;
				 return ;
			 }
			else
				std::cout << "Index out of range. ";
		}
		else
			std::cout << "Incorrect input.  ";
	}
}

void	PhoneBook::displayContacts(void)
{

	for (int i = 0; i < numberOfContacts; i++)
	{
		std::cout << "Index: [" << i << "]" << "|";
		if (contacts[i].firstName.length() > 10)
			std::cout << contacts[i].firstName.substr(0,9) << "." << "|";
		else if (contacts[i].firstName.length() < 10)
			std::cout << contacts[i].firstName.append(10 - contacts[i].firstName.length(), ' ') << "|";
		else
			std::cout << contacts[i].firstName << "|";
		if (contacts[i].lastName.length() > 10)
			std::cout << contacts[i].lastName.substr(0,9) << "." << "|";
		else if (contacts[i].lastName.length() < 10)
			std::cout << contacts[i].lastName.append(10 - contacts[i].lastName.length(), ' ') << "|";
		else
			std::cout << contacts[i].lastName << "|";
		if (contacts[i].nickname.length() > 10)
			std::cout << contacts[i].nickname.substr(0,9) << ".";
		else if (contacts[i].nickname.length() < 10)
			std::cout << contacts[i].nickname.append(10 - contacts[i].nickname.length(), ' ');
		else
			std::cout << contacts[i].nickname;
		std::cout << std::endl;
	}
	selectContact();
	return ;
}

void	PhoneBook::addContacts(void)
{
	if (indexPosition < MAX_CONTACTS)
	{
		contacts[indexPosition].inputContact();
		indexPosition++;
		if(numberOfContacts < MAX_CONTACTS)
			numberOfContacts++;
	}
	else
	{
		indexPosition = 0;
		contacts[indexPosition].inputContact();
		indexPosition++;
	}
	return ;
}
