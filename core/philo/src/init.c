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
	return (0);
}

// need to check if this write statemen works
int	ft_free_return_failure(t_data *data, char *error_msg)
{
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
	write (2, error_msg, ft_strlen(error_msg));
	write(2, "\n", 1);
	return (-1);
}

void	ft_init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_number)
	{
		data->philos[i].id = i + 1;
		data->philos[i].l_fork = &data->forks[i];
		if (i == 0)
			data->philos[i].r_fork = &data->forks[data->philo_number - 1];
		else
			data->philos[i].r_fork = &data->forks[i - 1];
		data->philos[i].meals_eaten = 0;
		//add any other variable needed
		//will get time at thread creation
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
	if (argc == 6)
		data->meals_to_eat = ft_atoi(argv[5]);
	else
		data->meals_to_eat = -1;
	data->forks = (pthread_mutex_t *)malloc(data->philo_number * sizeof(pthread_mutex_t));
	data->philos = (t_philo *)malloc(data->philo_number * sizeof(t_philo));
	if (!data->forks || !data->philos)
		return (ft_free_return_failure(data, "Malloc fail"));
	if (ft_create_forks(data) == -1)
		return (-1);
	ft_init_philos(data);
	if (ft_create_philos_threads(data) == -1)
		return (-1);
	return (0);
}
