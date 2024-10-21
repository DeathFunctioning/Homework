/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:58:05 by tbaker            #+#    #+#             */
/*   Updated: 2024/10/17 15:59:20 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_one_philo(t_philo *philo, t_data *data)
{
	if (data->philo_number == 1)
	{
		ft_usleep(data->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

void	ft_eat(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->r_fork);
	if ((ft_get_current_time() - philo->last_meal) > data->time_to_die
		|| data->sim_end != 0)
		return ;
	ft_print_action(philo, "has taken right fork");
	if (ft_one_philo(philo, data) == 0)
		return ;
	pthread_mutex_lock(philo->l_fork);
	if ((ft_get_current_time() - philo->last_meal) > data->time_to_die
		|| data->sim_end != 0)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	ft_print_action(philo, "has taken left fork");
	philo->last_meal = ft_get_current_time();
	philo->meals_eaten++;
	if (data->meals_to_eat > 0 && philo->meals_eaten == data->meals_to_eat)
		philo->data->philo_eaten++;
	ft_print_action(philo, "is eating");
	ft_usleep(data->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	ft_sleep(t_philo *philo, t_data *data)
{
	if ((ft_get_current_time() - philo->last_meal) > data->time_to_die
		|| data->sim_end != 0)
		return ;
	ft_print_action(philo, "is sleeping");
	ft_usleep(data->time_to_sleep);
}

void	ft_think(t_philo *philo, t_data *data)
{
	if ((ft_get_current_time() - philo->last_meal) > data->time_to_die
		|| data->sim_end != 0)
		return ;
	ft_print_action(philo, "is thinking");
}
