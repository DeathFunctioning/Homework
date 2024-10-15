#include "philo.h"

// when dose the count as been eaten is once the time to eat has elapsed or is it when it eats
// will need to update if statement 
// dose the philo need to stop eating once they have eaten required meals 
// if so i can add if statement in the simulation loop checking meals eaten
void  ft_eat(t_philo *philo, t_data *data)
{
  pthread_mutex_lock(philo->r_fork);
  printf("%zu %d has taken a left fork\n", ft_get_current_time(), philo->id);
  pthread_mutex_lock(philo->l_fork);
  printf("%zu %d has taken a right fork\n", ft_get_current_time(), philo->id);
  philo->last_meal = ft_get_current_time();
  philo->meals_eaten++;
  printf("%zu %d is eating\n", ft_get_current_time(), philo->id);
  ft_usleep(data->time_to_eat);
  if (data->meals_to_eat > 0 && philo->meals_eaten >= data->meals_to_eat)
      philo->required_meals_eaten++;
  pthread_mutex_unlock(philo->l_fork);
  pthread_mutex_unlock(philo->r_fork);
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
