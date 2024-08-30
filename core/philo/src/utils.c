#include "philo.h"

// need to replace with philo id instead of sending data
// Could add a mutex lock for writing to terminal 
void	ft_print_action(char *s, t_data data)
{
	printf("%zu %d %s\n", get_current_time(), data->philo[i].id, s)
}

int	ft_atoi(char *s)
{
	int	nbr;
	int	sign;
	
	sign = 1;
	nbr = 0;
	while ((*s == 32) || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= 48 && *s <= 57)
	{
		nbr = nbr * 10 + (*s - 48);
		s++;
	}
	return (nbr * sign);
}
/*
 * 
int	ft_usleep(size_t ms)
{
	size_t	start;

	start = ft_get_current_time();
	while((ft_get_current_time() - start) < ms)
		usleep(500);
	return (0);
}*/

// returns the amount of seconds * 1000 = ms since the epoch + 
// the microseconds between seconds / 1000 = ms
// returning total micro second since the epoch
size_t	ft_get_current_time(void)
{
	struct timeval	time;

	if(gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
