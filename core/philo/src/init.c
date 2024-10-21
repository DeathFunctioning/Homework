/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:22:20 by tbaker            #+#    #+#             */
/*   Updated: 2024/10/17 15:57:51 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_create_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_number)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) == -1)
			return (ft_free_return_failure(data, "Mutex fork error"));
		i++;
	}
	if (pthread_mutex_init(&data->print_lock, NULL) == -1)
	{
		ft_destroy_mutex(data);
		return (ft_free_return_failure(data, "Mutex fork error"));
	}
	return (RETURN_SUCCESS);
}

int	ft_free_return_failure(t_data *data, char *error_msg)
{
	if (data)
		ft_free(data);
	write (2, error_msg, ft_strlen(error_msg));
	write(2, "\n", 1);
	return (RETURN_FAILURE);
}

void	ft_init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_number)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].l_fork = &data->forks[i];
		if (i == 0)
			data->philos[i].r_fork = &data->forks[data->philo_number - 1];
		else
			data->philos[i].r_fork = &data->forks[i - 1];
		data->philos[i].meals_eaten = 0;
		data->philos[i].required_meals_eaten = 0;
		i++;
	}
}

int	ft_init_data(t_data *data, int argc, char *argv[])
{
	data->philo_number = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->sim_end = 0;
	data->philo_eaten = 0;
	data->base_time = ft_get_current_time();
	if (argc == 6)
		data->meals_to_eat = ft_atoi(argv[5]);
	else
		data->meals_to_eat = -1;
	data->forks = (pthread_mutex_t *)malloc(data->philo_number
			* sizeof(pthread_mutex_t));
	data->philos = (t_philo *)malloc(data->philo_number * sizeof(t_philo));
	if (!data->forks || !data->philos)
		return (ft_free_return_failure(data, "Malloc fail"));
	if (ft_create_forks(data) == -1)
		return (RETURN_FAILURE);
	ft_init_philos(data);
	if (ft_create_philos_threads(data) == -1)
		return (RETURN_FAILURE);
	return (RETURN_SUCCESS);
}
