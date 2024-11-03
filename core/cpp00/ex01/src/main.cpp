/* ************************************************************************** */
o
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:32:22 by tbaker            #+#    #+#             */
/*   Updated: 2024/11/01 16:58:31 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		std::getline(std::cin, userInput);

		if (userInput == "ADD")
			phoneBook.addContacts();
		else if (userInput == "SEARCH")
			phoneBook.displayContacts();
		else if (userInput == "EXIT")
			break ;
		else
			std::cout << "Incorrected input, please try again" << std::endl;
	}
	return (0);
}

