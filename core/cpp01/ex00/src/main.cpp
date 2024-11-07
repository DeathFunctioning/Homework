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

int	main(void)
{
	Zombie* zombiePtr;
	std::string input;

	std::cout << "enter name of zombie: ";
	std::cin << input;
	zombiePtr = newZombie(input);
	delete zombiePtr;

	return (0);
}

