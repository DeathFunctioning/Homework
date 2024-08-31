/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:22:09 by tbaker            #+#    #+#             */
/*   Updated: 2024/08/31 12:59:15 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

//check if philos are between 1 - 200
//checks if args from 1 - 5 if the string contains only chars from 
// 0 - 9 
// need to remove printf 
// need to error check if atoi is not equal to 0 for all args except for
// argv 6 number of times a philo must eat 
int	ft_data_check(char *argv[])
{
	int	i;
	int	j;

	j = 1;
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 200)
		return (ft_free_return_failure(NULL, "Number of philos needs to between 1 - 200")); 
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] < 48 || argv[j][i] > 57)
				return (ft_free_return_failure(NULL, "Error invailed argument postive number required")); 
			i++;
		}
		j++;
	}
	return (0);
}
