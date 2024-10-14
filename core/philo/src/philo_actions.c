#include "philo.h"
/* i have a major is with segfault i am not sure where the fault is 
 * mutex, othread create, thread issue, i need to got through my code line by line a trace it all tomorrow 
 * need to run ptsantise to find if its a thread issue 
 * fuck io dont know where to start*/
void  ft_eat(t_philo *philo, t_data *data)
{
  pthread_mutex_t temp_lock;//remove and replace in t_data

  pthread_mutex_init(&temp_lock, NULL);
  pthread_mutex_lock(philo->r_fork);
  printf("%zu %d has taken a left fork\n", ft_get_current_time(), philo->id);
  pthread_mutex_lock(philo->l_fork);
  printf("%zu %d has taken a right fork\n", ft_get_current_time(), philo->id);
  philo->last_meal = ft_get_current_time();
  pthread_mutex_lock(&temp_lock);
  philo->meals_eaten++;
  printf("%zu %d is eating\n", ft_get_current_time(), philo->id);
  pthread_mutex_unlock(&temp_lock);
  ft_usleep(data->time_to_eat);
  pthread_mutex_destroy(&temp_lock);
  pthread_mutex_unlock(philo->l_fork);
  pthread_mutex_unlock(philo->r_fork);
}

void  ft_sleep(t_philo *philo, t_data *data)
{
  pthread_mutex_t temp_lock_2;//remove and replace in t_data

  pthread_mutex_init(&temp_lock_2, NULL);
  pthread_mutex_lock(&temp_lock_2);
  printf("%zu %d is sleeping\n", ft_get_current_time(), philo->id);
  pthread_mutex_unlock(&temp_lock_2);
  pthread_mutex_destroy(&temp_lock_2);
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

