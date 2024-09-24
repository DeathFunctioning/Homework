#include "philo.h"
/* i have a major is with segfault i am not sure where the fault is 
 * mutex, othread create, thread issue, i need to got through my code line by line a trace it all tomorrow 
 * need to run ptsantise to find if its a thread issue 
 * fuck io dont know where to start*/
void  ft_eat(t_philo *philo, t_data *data)
{
  pthread_mutex_lock(philo->r_fork);
  printf("%zu %d has taken a fork\n", ft_get_current_time(), philo->id);
  pthread_mutex_lock(philo->l_fork);
  printf("%zu %d has taken a fork\n", ft_get_current_time(), philo->id);
  if ((size_t) (ft_get_current_time() - philo->last_meal) < (size_t)data->time_to_die)
  {
    philo->last_meal = ft_get_current_time();
    philo->meals_eaten++;
    printf("%zu %d is eating\n", ft_get_current_time(), philo->id);
    ft_usleep(data->time_to_eat);
    //ignores if argv[6] = 0
    //do i need to add a conditon for argv[6] = 0
    if (data->meals_to_eat > 0 && philo->meals_eaten >= data->meals_to_eat)
      philo->required_meals_eaten++;
  }
  //remove just test 
  else
    ft_death(philo, data);
  pthread_mutex_unlock(philo->r_fork);
  pthread_mutex_unlock(philo->l_fork);
  pthread_mutex_destroy(philo->r_fork);
  pthread_mutex_destroy(philo->l_fork);
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

