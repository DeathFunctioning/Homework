#include <iostream>
#include <string>

int	main(void)
{
	std::string userInput;

	std::cout << "Enter ADD to add contacted" << std::endl;
	std::cout << "Enter SEARCH to search for contacted" << std::endl;
	std::cout << "Enter EXIT to exit program" << std::endl;
	while (1)
	{
		std::cin  >> userInput;
		if (userInput == "ADD")
			std::cout << "Add fuction selected" << std::endl;
		else if (userInput == "SEARCH")
			std::cout << "Searh function selected" << std::endl;
		else if (userInput == "EXIT")
			break ;
		else
			std::cout << "Incorrected input, please try again" << std::endl;
	}
	return (0);
}

