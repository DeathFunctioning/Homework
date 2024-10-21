/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:22:09 by tbaker            #+#    #+#             */
/*   Updated: 2024/10/17 15:55:44 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_data_check(char *argv[])
{
	int	i;
	int	j;

	j = 1;
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 200)
		return (ft_free_return_failure(NULL,
				"Number of philos needs to between 1 - 200"));
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] < 48 || argv[j][i] > 57)
				return (ft_free_return_failure(NULL,
						"Error invailed argument postive number required"));
			i++;
		}
		j++;
	}
	return (RETURN_SUCCESS);
}
