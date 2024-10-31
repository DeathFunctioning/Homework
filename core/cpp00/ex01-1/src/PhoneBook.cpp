#include "PhoneBook.hpp"

//test for displaying list of current contacts added 
//will update for peroper formating later once this is working 
//also need to add meber function to selcet and diplay contacts once list has been displayed 
//i think i need to remove darkest secret and phone number ?
PhoneBook::PhoneBook() : numberOfContacts(0), indexPosition(0) {}	

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
