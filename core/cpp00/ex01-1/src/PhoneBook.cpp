#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	displayContacts(Contact& Contacts)
{

	
	for (i = 0; i < numberOfContacts; i++;)
	{
		std::cout << "["i +1"]" << " |";
		std::cout << Contacts[i].firstName << " |";
		std::cout << Contacts[i].lastName << " |";
		std::cout << Contacts[i].nickname << " |";
		std::cout << Contacts[i].phoneNumber << " |";
		std::cout << Contacts[i].darkestSecret << " |";
	}
	return ;
}

void	addContacts(Contact& Contacts)
{


}
