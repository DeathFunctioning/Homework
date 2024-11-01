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

//test for displaying list of current contacts added 
//will update for peroper formating later once this is working 
//also need to add meber function to selcet and diplay contacts once list has been displayed 
//i think i need to remove darkest secret and phone number ?
PhoneBook::PhoneBook() : numberOfContacts(0), indexPosition(0) {}	

bool	PhoneBook::checkIndexValue(std::string indexValue)
{
	if (indexValue.length() == 1)
	{
		if (indexValue.at(0) <= '0' && indexValue.at(0) >= '7')
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

//	std::cout << "Enter index to view contact information: ";
	while (true)
	{
		std::cout << "Enter index to view contact information: ";
		std::getline(std::cin, indexValue);
		// maybe i just cin the or i just check the first char in the string ignoring white space if not between 0 and 7 return false if its in range atoi the string might have check the string.length is only 1 bite first then check if between 0 - 7 and less than number contacts not very modulor but will work in the case
		// i will look at it tommorow need to sleep
		// I NEED TO CHANGE atoi to handle errors and incorrect values 
		if (!checkIndexValue(indexValue))
			nbr = atoi(indexValue.c_str());// need to add error handling 
		else
			std::cout << "Incorrect input.  ";
		//if (need build function that checks the line for valid intergeri and ruturns a bool)
		//{
		if (nbr >= 0 && nbr < numberOfContacts)
			break ;
		else
			std::cout << "Index out of range. ";
		//}
		//else
		//	std::cout << "Incorrect input.  ";
	}
	std::cout << this->contacts[nbr].firstName << std::endl;
	std::cout << this->contacts[nbr].lastName << std::endl;
	std::cout << this->contacts[nbr].nickname << std::endl;
	std::cout << this->contacts[nbr].phoneNumber << std::endl;
	std::cout << this->contacts[nbr].darkestSecret << std::endl;
	return ;
}

void	PhoneBook::displayContacts(void)
{

	for (int i = 0; i < numberOfContacts; i++)
	{
		std::cout << "Index: [" << i << "]" << "|";
		if (this->contacts[i].firstName.length() > 10)
			std::cout << this->contacts[i].firstName.substr(0,9) << "." << "|";
		else if (this->contacts[i].firstName.length() < 10)
			std::cout << this->contacts[i].firstName.append(10 - contacts[i].firstName.length(), ' ') << "|";
		else
			std::cout << this->contacts[i].firstName << "|";
		if (this->contacts[i].lastName.length() > 10)
			std::cout << this->contacts[i].lastName.substr(0,9) << "." << "|";
		else if (this->contacts[i].lastName.length() < 10)
			std::cout << this->contacts[i].lastName.append(10 - contacts[i].lastName.length(), ' ') << "|";
		else
			std::cout << this->contacts[i].lastName << "|";
		if (this->contacts[i].nickname.length() > 10)
			std::cout << this->contacts[i].nickname.substr(0,9) << ".";
		else if (this->contacts[i].nickname.length() < 10)
			std::cout << this->contacts[i].nickname.append(10 - contacts[i].nickname.length(), ' ');
		else
			std::cout << this->contacts[i].nickname;
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
