#include "PhoneBook.hpp"

void	ftAddContact(PhoneBook *newPhoneBook)
{
	int			i;
	Contact		test2;

	
	std::cout << "Add function selected" << std::endl;



}

int	main(void)
{
	PhoneBook	newPhoneBook;
	std::string userInput;

	std::cout << "ADD to add contacted" << std::endl;
	std::cout << "SEARCH to search for contacted" << std::endl;
	std::cout << "EXIT to exit program" << std::endl;
	while (1)
	{
		std::cout << "Enter option: ";
		std::cin  >> userInput;
		if (userInput == "ADD")
			ftAddContact(newPhoneBook);
		else if (userInput == "SEARCH")
			std::cout << "Searh function selected" << std::endl;
		else if (userInput == "EXIT")
			break ;
		else
			std::cout << "Incorrected input, please try again" << std::endl;
	}
	return (0);
}

