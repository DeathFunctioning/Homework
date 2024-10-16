/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:21:55 by tbaker            #+#    #+#             */
/*   Updated: 2024/10/15 16:19:03 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_check_dead_or_meals_eaten(t_data *data, int i)
{
	while (i < data->philo_number)
	{
		if ((ft_get_current_time() - data->philos[i].last_meal) > data->time_to_die)
		{
			data->sim_end++;
			printf("test philo %d died\n", data->philos[i].id);
			return (RETURN_SUCCESS);
		}
		if (data->philo_eaten == data->philo_number)
		{
			data->sim_end++;
			return (RETURN_SUCCESS);
		}
/*		if (data->philos[i].required_meals_eaten > 0)
		{
			j++;
			if (j >= data->philo_number)
			{
				data->sim_end++;
				return (RETURN_SUCCESS);
			}
		}*/
	/*	if (data->philos_eaten == data->philo_number)
		{
			data->sim_end++;
			return (RETURN_SUCCESS);
		}*/
		i++;
	}
	return (RETURN_FAILURE);
}

//need to check philo 
void	*ft_watcher(void *p)
{
	t_data	*data;

	data = (t_data *)p;
	while (data->sim_end == 0)
	{
		if (ft_check_dead_or_meals_eaten(data, 0) == 0)
			return (NULL);
	}
	return (NULL);
}

// if added can remove help prevent unwant actions i could add condition in the eat function 
void	*ft_simulation(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (philo->id % 2)
		ft_usleep(10);
	while (philo->data->sim_end == 0)
	{
		if (philo->data->sim_end == 0)
			ft_eat(philo, philo->data);
		if (philo->data->sim_end == 0)
			ft_sleep(philo, philo->data);
		if (philo->data->sim_end == 0)
			ft_think(philo);
	}
	return (NULL);
}

int	ft_create_philos_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_number)
	{
		data->philos[i].last_meal = ft_get_current_time();
		if (pthread_create(&data->philos[i].thread, NULL,
				ft_simulation, &data->philos[i]) != 0)
			return (ft_free_return_failure(data, "Pthread create philo error"));
		i++;
	}
	if (pthread_create(&data->watcher_thread, NULL, ft_watcher, data) != 0)
		return (ft_free_return_failure(data, "Pthread create philo error"));
	i = 0;
	while (i < data->philo_number)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (ft_free_return_failure(data, "Pthread join philo error"));
		i++;
	}
	pthread_join(data->watcher_thread, NULL);
	return (RETURN_SUCCESS);
}
