/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:21:55 by tbaker            #+#    #+#             */
/*   Updated: 2024/08/31 14:40:01 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

//need to build real programme
void	*ft_watcher(void *p)
{
	t_data	*data;

	data = (t_data *)p;
	while (1)
	{
		if (data->sim_end != 0)
		{
			write (2, "game over man\n", 14);
			break ;
		}
	}
	return (NULL);
}

// could add thread for mointoring before first loop 
// issus with updating values in the curent threads struct 
// need 
void	*ft_simulation(void *p)
{
	//t_data	*data;

	//odata = (t_data *)p;
	t_philo	*philos;

	philos = (t_philo *)p;
	if (philos->id % 2)
	{
		philos->meals_eaten = 1;
		usleep(5);
	}
	philos->meals_eaten++; 
	//printf("This is philo id = %d\n", get_pid);
	//printf("This is philo last_meal = %zu\n", data->philos->last_meal);
/*	while (data->sim_end == 0)
	{
	//	ft_eat(data);// need to be built 
	//	ft_sleep(data);// need to be built 
	//	ft_think(data);// need to be built
	}*/
	return (NULL);
}

// could add thread for mointoring before first loop 
// and join it in after the second join loop
// Would slos need to added it to the data struct to save space
int	ft_create_philos_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_number)
	{
		data->philos[i].last_meal = ft_get_current_time();
		if (pthread_create(&data->philos[i].thread, NULL, &ft_simulation, &data->philos) != 0)
			return (ft_free_return_failure(data, "Pthread create philo error"));
		i++;
	}
	i = 0;
	while (i < data->philo_number)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (ft_free_return_failure(data, "Pthread join philo error"));
		i++;
	}
	return (0);
}
