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

// need to add destroy mutexs for forks and whatever other mutex i create
// need to build the watcher thread to check meals eaten and for philos death :
// need to free allocate memery?? for forks and philos if sucessful 
int main(int argc, char *argv[])
{
	t_data  data;
	int		i;//remove

	i = 0;
	if (argc == 5 || argc == 6)
	{
		if (ft_data_check(argv) == -1)
			return (EXIT_FAILURE);
		if (ft_init_data(&data, argc, argv) == -1)
			return (EXIT_FAILURE);
		//remove test for leaks make its own function for destroying mutex
		while (i < data.philo_number)
		{
			pthread_mutex_destroy(&data.forks[i]);
			i++;
		}
		return (EXIT_SUCCESS);
	}
	//need to write better error msg
	write (2, "Not enough args\n", 17);
	return (EXIT_FAILURE);
}
