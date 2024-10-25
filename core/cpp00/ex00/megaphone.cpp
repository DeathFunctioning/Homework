/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:19:11 by tbaker            #+#    #+#             */
/*   Updated: 2024/10/23 14:28:57 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	if (argc > 1)
	{
		i++;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				c = toupper(argv[i][j]);
				std::cout << c;
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
