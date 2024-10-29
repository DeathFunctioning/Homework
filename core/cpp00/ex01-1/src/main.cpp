#include "main.hpp"

int	main(void)
{
	std::string userInput;
	PhoneBook phoneBook;

	std::cout << "Enter ADD to add contacted" << std::endl;
	std::cout << "Enter SEARCH to search for contacted" << std::endl;
	std::cout << "Enter EXIT to exit program" << std::endl;
	while (true)
	{
		std::cout << "Enter option: ";
		std::cin  >> userInput;
		if (userInput == "ADD")
			phoneBook.addContact(Contact());
		else if (userInput == "SEARCH")
			phoneBook.displayContacts();
		else if (userInput == "EXIT")
			break ;
		else
			std::cout << "Incorrected input, please try again" << std::endl;
	}
	return (0);
}

