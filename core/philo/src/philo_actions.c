#include "philo.h"

void  ft_eat(t_philo *philo, t_data *data)
{
  printf("%zu %d has taken a fork\n", ft_get_current_time(), philo->id);
  printf("%zu %d has taken a fork\n", ft_get_current_time(), philo->id);
  printf("%zu %d is eating\n", ft_get_current_time(), philo->id);
  ft_usleep(data->time_to_eat);
  philo->meals_eaten++;
}

void  ft_sleep(t_philo *philo, t_data *data)
{
  printf("%zu %d is sleeping\n", ft_get_current_time(), philo->id);
  ft_usleep(data->time_to_sleep);
}

void  ft_think(t_philo *philo)
{
  printf("%zu %d is thinking\n", ft_get_current_time(), philo->id);
}

void  ft_death(t_philo *philo, t_data *data)
{
  data->sim_end++;
  printf("%zu %d died\n", ft_get_current_time(), philo->id);
}

