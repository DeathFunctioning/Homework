#include "philo.h"

//need to build real programme
void	*ft_watcher(void *p)
{
	t_data	*data;

	data = (t_data *)p;
	while (1)
	{
		if (data->sim_end != 0)
			write (2, "game over man\n", 14);
	}
	return (NULL);
}

// could add thread for mointoring before first loop 
void	*ft_simulation(void *p)
{
	t_data	*data;

	data = (t_data *)p;
	if (data->philos->id % 2 == 0)
		usleep(1);
	while (data->sim_end == 0)
	{
	//	ft_eat(data);// need to be built 
	//	ft_sleep(data);// need to be built 
	//	ft_think(data);// need to be built
	}
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
		if (pthread_create(&data->philos[i].thread, NULL, &ft_simulation, &data) == -1)
			return (ft_free_return_failure(data, "Pthread create philo error"));
		i++;
	}
	i = 0;
	while (i < data->philo_number)
	{
		if (pthread_join(data->philos[i].thread, NULL) == -1)
			return (ft_free_return_failure(data, "Pthread join philo error"));
		i++;
	}
	return (0);
}
