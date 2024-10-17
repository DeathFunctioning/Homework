/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:22:32 by tbaker            #+#    #+#             */
/*   Updated: 2024/10/15 13:57:33 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

// need to add destroy mutexs for forks and whatever other mutex i create
// need to build the watcher thread to check meals eaten and for philos death :
// need to free allocate memery?? for forks and philos if sucessful 
void	ft_free_destroy_mutex(t_data *data)
{
	int		i;

	i = 0;
/*	while (i < data->philo_number)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}*/
	if (data->forks)
	{
		while (i < data->philo_number)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
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
		//if statement to check if philo number == 1 then build function for only one philo 
		//return success no need to free or do any thing else 
		if (ft_init_data(&data, argc, argv) == -1)
			return (EXIT_FAILURE);
		ft_free_destroy_mutex(&data);
		return (EXIT_SUCCESS);
	}
	//need to write better error msg
	write (2, "Not enough args\n", 17);
	return (EXIT_FAILURE);
}
