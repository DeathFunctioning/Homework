#include "philo.h"

// define exit suc3ess and failure define marocs enums 
// could also create my own printe error function 
// the i could something like return (ft_error("Forks mallos error));
// one lining the the if statement would need to create string length
// if not i have to go and check all my writes and make sure the right length
int	ft_create_forks(t_data data)
{
	int	i;

	i = 0;
	data->forks = (pthread_mutex_t *)malloc(data->philo_number * sizeof(pthread_mutex_t));
	if (!data->forks)
	{
		write (2, "Forks malloc error\n", 19);
		return (-1);
	}
	while (i < data->philo_number)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) == -1)
		{
			write(2, "Mutex fork error\n", 17);
			return (-1);
		}
		i++;
	}
	return (0);
}

// Need to move this to the thread create function this is for in
// build seperate join anmd free function same for forks destiry and free
int	ft_create_philos_threads(t_data data)
{
	int	i;

	i = 0;
	data->philos = (pthread_mutex_t *)malloc(data->philo_number * sizeof(pthread_mutex_t));
	if (!data->philos)
	{
		write (2, "philos malloc error\n", 20);
		return (-1);
	}
	while (i < data->philo_number)
	{
		if (pthread_mutex_init(&data->philos[i], NULL) == -1)
		{
			write(2, "Pthread philo error\n", 20);
			return (-1);
		}
		else
			if(ft_init_philos(t_data data) == EXIT_FAILURE)
			{

			}
		i++;
	}
	return (0);
}

// need to check if this write statemen works
// need to add strlen
// need to clean all my code and start adding exit failure exit success
// need to create return_failure instead of exit_failure or -1
int	ft_free_return_failure(t_data data, char *error_msg)
{
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
	write (2, &s, ft_strlen(s));
	write(2, "\n", 1);
	return (EXIT_FAILURE);
}

int	ft_init_data(t_data data,int argc, char **argv)
{

	data->forks = (pthread_mutex_t *)malloc(data->philo_number * sizeof(pthread_mutex_t));
	data->philos = (pthread_t *)malloc(data->philo_number * sizeof(pthread_t));
	if (!forks || !philos)
	{

	}
	data->philo_number = argv[1];
	data->time_to_die = argv[2];
	data->time_to_eat = argv[3];
	data->time_to_sleep = argv[4];
	if (argc == 6)
		data->meals_to_eat = argv[5];
	else
		data->meals_to_eat = -1;
	if (ft_init_forks(data) == -1)
		return (-1);
	if (ft_create_philos_threads(data) == -1)
		return (-1);
	return (0);
}
