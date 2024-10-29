#include "PhoneBook.hpp"

//test for displaying list of current contacts added 
//will update for peroper formating later once this is working 
//also need to add meber function to selcet and diplay contacts once list has been displayed 
//i think i need to remove darkest secret and phone number ?
PhoneBook::PhoneBook() : numberOfContacts(0), indexPosition(0) {

}	

void	PhoneBook::displayContacts(void)
{
	int	i;

	for (i = 0; i < numberOfContacts; i++)
	{
		std::cout << "[" << i << "]" << " |";
		std::cout << this->contacts[i].firstName << " |";
		std::cout << this->contacts[i].lastName << " |";
		std::cout << this->contacts[i].nickname << " |";
		std::cout << this->contacts[i].phoneNumber << " |";
		std::cout << this->contacts[i].darkestSecret << " |" << std::endl;
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
