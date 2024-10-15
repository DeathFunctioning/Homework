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

//need to check philo 
void    *ft_watcher(void *p)
{
    t_data  *data;
    int     i;
    int     j;

	data = (t_data *)p;
	while (data->sim_end == 0)
	{
        i = 0;
        j = 0;
        while (i < data->philo_number)
        {
            if (data->philos[i].required_meals_eaten > 0)
            {
                j++;
                if (j >= data->philo_number)
                {
                    data->sim_end++;
                    break ;
                }
            }
            i++;
        }
	}
	return (NULL);
}

void  *ft_simulation(void *p)
{
	t_philo *philo;

	philo = (t_philo *)p;
	if (philo->id % 2)
		ft_usleep(2);
	while (philo->data->sim_end == 0)
	{
		ft_eat(philo, philo->data);
		ft_sleep(philo, philo->data);
		ft_think(philo);
	}
	return (NULL);
}

int	ft_create_philos_threads(t_data *data)
{
	int i;

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
