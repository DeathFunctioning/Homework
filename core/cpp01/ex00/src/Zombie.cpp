/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:06:40 by tbaker            #+#    #+#             */
/*   Updated: 2024/11/01 17:04:56 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) _name("defaultZombie")
{

	return ;
}

void	Zombie::announce(void)
{
	std::out << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::out << _name << " Has died" << std::endl;
	return ;
}
