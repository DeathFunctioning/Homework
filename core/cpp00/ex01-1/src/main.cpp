#include "main.hpp"

int	main(void)
{
	std::string userInput;

	std::cout << "Enter ADD to add contacted" << std::endl;
	std::cout << "Enter SEARCH to search for contacted" << std::endl;
	std::cout << "Enter EXIT to exit program" << std::endl;
	while (true)
	{
		std::cout << "Enter option: ";
		std::cin  >> userInput;
		if (userInput == "ADD")
			Contact testContact;
		else if (userInput == "SEARCH")
			std::cout << "SEARCH function selected" << std::endl;
		else if (userInput == "EXIT")
			break ;
		else
			std::cout << "Incorrected input, please try again" << std::endl;
	}
	return (0);
}

