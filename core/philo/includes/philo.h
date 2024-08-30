#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include "macros.h"

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*l_forks;
	pthread_mutex_t	*r_forks;
	size_t			last_meal;//use this as start time 
	int				id;

}	t_philo;

typedef struct s_data
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	int				philo_number;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_to_eat;
}	t_data;

//	error_handle.c
int		ft_data_check(char *argv[]);

//	init.c
int		ft_init_forks(t_data data);
int		ft_init_philos(t_data data);
int		ft_create_philos_threads(t_data data);
int		ft_init_data(t_data data, int argc, char **argv);

//	utils.c
int		ft_strlen(char *s);
int		ft_usleep(size_t ms);
size_t	ft_get_current_time(void);
int		ft_atoi(char *s);

#endif
