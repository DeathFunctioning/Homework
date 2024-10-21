/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:22:32 by tbaker            #+#    #+#             */
/*   Updated: 2024/10/17 14:41:55 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ft_free_destroy_mutex(t_data *data)
{
	int		i;

	i = 0;
	if (data->forks)
	{
		while (i < data->philo_number)
		{
			if (&data->forks[i])
				pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		pthread_mutex_destroy(&data->print_lock);
		free(data->forks);
		data->forks = NULL;
	}
	if (data->philos)
	{
		free(data->philos);
		data->philos = NULL;
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
		ft_free_destroy_mutex(&data);
		return (EXIT_SUCCESS);
	}
	write (2, "Not enough args\n", 17);
	return (EXIT_FAILURE);
}
