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
void  *ft_watcher(void *p)
{
	t_data  *data;

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

//need to build loop for philo rotuine
//need to do time to eat / time to die comparsion before 
//philo eats 
//somethin like if philo is going to die 
//ft_death
//increment end simulation to 1 loop stops for all 
//need to build meals eat function can do after i have built the death function 
void  *ft_simulation(void *p)
{
	t_philo *philo;

	philo = (t_philo *)p;

    //remove test 
    if (!philo || !philo->data)
    {
        fprintf(stderr, "philo or data pointing to NULL\n");
        return (NULL);
    }
	if (philo->id % 2)
    {
		ft_usleep(10);
	//while (philo->data->sim_end == 0)
    }
    printf("philo %d is starting simulation\n", philo->id);//remove
	while (1)
	{
        printf("test time t0 eat = %d\n", philo->data->time_to_eat);// remove test
		ft_eat(philo, philo->data);// need to be built 
		ft_sleep(philo, philo->data);// need to be built 
		ft_think(philo);// need to be built
	}
	return (NULL);
}

// could add thread for mointoring before first loop 
int	ft_create_philos_threads(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_number)
	{
		data->philos[i].last_meal = ft_get_current_time();
		if (pthread_create(&data->philos[i].thread, NULL, ft_simulation, &data->philos[i]) != 0)
			return (ft_free_return_failure(data, "Pthread create philo error"));
		i++;
	}
//    if (pthread_create(&data->watcher_thread, NULL, ft_watcher, data) != 0)
//		return (ft_free_return_failure(data, "Pthread create philo error"));
	i = 0;
	while (i < data->philo_number)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (ft_free_return_failure(data, "Pthread join philo error"));
		i++;
	}
  //  pthread_join(data->watcher_thread, NULL);
	return (RETURN_SUCCESS);
}
