/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:22:32 by tbaker            #+#    #+#             */
/*   Updated: 2024/08/31 14:14:33 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

// need to remove printf test statements 
// need to 
void	ft_test(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_number)
	{
		printf("thread id =  %d\n", data->philos[i].id);
		printf("thread last_meal =  %zu\n", data->philos[i].last_meal);
		printf("thread meals_eaten =  %d\n", data->philos[i].meals_eaten);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;	

	if (argc == 5 || argc == 6)
	{
		if (ft_data_check(argv) == -1)
			return (EXIT_FAILURE);
		if (ft_init_data(&data, argc, argv) == -1)
			return (EXIT_FAILURE);
//		ft_test(&data);
		return (EXIT_SUCCESS);
	}
	//need to write better error msg
	write (2, "Not enough args\n", 17);
	return (EXIT_FAILURE);
}
