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

bool	PhoneBook::isWhiteSpace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}

bool	PhoneBook::checkIndexValue(std::string& indexValue)
{
	size_t	i;

	i = 0;
	while (isWhiteSpace(indexValue.at(i)) && i < indexValue.length()) 
	{
		i++;
		if (i == indexValue.length())
			return (false);
	}
	while (i < indexValue.length()) 
	{
		if (indexValue.at(i) == '+' || indexValue.at(i) == '-')
		{
			if (indexValue.at(i) == '+')
				i++;
			else
				return (false);	
		}
		if (indexValue.at(i) >= '0' && indexValue.at(i) <= '9')
			i++;
		else
			return (false);
		i++;
	}
		return (true);
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
		while (indexValue.empty())
		{
			std::cout << "Empty string entered. ";
			std::cout << "Enter index to view contact information: ";
			std::getline(std::cin, indexValue);
		}
		if (checkIndexValue(indexValue))
		{
			nbr = atoi(indexValue.c_str()); 
			if (nbr >= 0 && nbr < numberOfContacts)
       		 {
	       		 std::cout << "First name: " << contacts[nbr].firstName << std::endl;
	       		 std::cout << "Last name: " << contacts[nbr].lastName << std::endl;
	       		 std::cout << "Nickname: " << contacts[nbr].nickname << std::endl;
				 std::cout << "Phone Number: " << contacts[nbr].phoneNumber << std::endl;
				 std::cout << "Darkest secret: " << contacts[nbr].darkestSecret << std::endl;
				 return ;
			 }
			else
				std::cout << "Index out of range. ";
		}
		else
			std::cout << "Incorrect input. Please enter positve number. ";
	}
}

void	PhoneBook::displayContacts(void)
{

	for (int i = 0; i < numberOfContacts; i++)
	{
		std::cout << "Index: [" << i << "] " << "|";
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
