/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:21:55 by tbaker            #+#    #+#             */
/*   Updated: 2024/10/22 17:42:43 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_check_dead_or_meals_eaten(t_data *data, int i)
{
	while (i < data->philo_number)
	{
		if ((ft_get_current_time() - data->philos[i].last_meal)
			> data->time_to_die)
		{
			data->sim_end++;
			ft_print_action(&data->philos[i], "died");
			return (RETURN_SUCCESS);
		}
		if (data->philo_eaten == data->philo_number)
		{
			data->sim_end++;
			return (RETURN_SUCCESS);
		}
		i++;
	}
	return (RETURN_FAILURE);
}

void	*ft_watcher(void *p)
{
	t_data	*data;

	data = (t_data *)p;
	while (data->sim_end == 0)
	{
		if (ft_check_dead_or_meals_eaten(data, 0) == 0)
			return (NULL);
		ft_usleep(5);
	}
	return (NULL);
}

void	*ft_simulation(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (philo->id % 2)
		ft_usleep(5);
	while (philo->data->sim_end == 0)
	{
		if (philo->data->sim_end != 0)
			return (NULL);
		ft_eat(philo, philo->data);
		if (philo->data->sim_end != 0)
			return (NULL);
		ft_sleep(philo, philo->data);
		if (philo->data->sim_end != 0)
			return (NULL);
		ft_think(philo, philo->data);
		if (philo->data->sim_end != 0)
			return (NULL);
		ft_usleep(5);
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
