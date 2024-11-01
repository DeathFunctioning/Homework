/* ************************************************************************** */
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

//I can save three lines of code changing my loop condition
//to != "EXIT", but i dont like the flow i like the == "EXIT"
//condition with the break fuck it decide later once i have 
//finished this exercise
//last thing i need to do is prompt use to enter index
//after displaying contacts them std::c++_outing them 
//line by line and it should all be done 
//and need to leak and error test and maybe write some comments 
int	main(void)
{
	std::string userInput;
	PhoneBook phoneBook;

	std::cout << "Enter ADD to add contacted" << std::endl;
	std::cout << "Enter SEARCH to search for contacted" << std::endl;
	std::cout << "Enter EXIT to exit program" << std::endl;
	//while (true)
	while (userInput != "EXIT")
	{
		std::cout << "Enter option: ";
		std::getline(std::cin, userInput);
		if (userInput == "ADD")
			phoneBook.addContacts();
		else if (userInput == "SEARCH")
			phoneBook.displayContacts();
//		else if (userInput == "EXIT")
//			break ;
		else if (userInput != "EXIT")
//		else
			std::cout << "Incorrected input, please try again" << std::endl;
	}
	return (0);
}

