/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:03:29 by tbaker            #+#    #+#             */
/*   Updated: 2024/08/31 14:40:12 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include "macros.h"

//	Do i need a pointer for the mutexs?ZZ
typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	size_t			last_meal;//use this as start time 
	int				id;
	int				meals_eaten;

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
	int				sim_end;
}	t_data;

//	error_handle.c
int		ft_data_check(char *argv[]);

//	create_threads
void	*ft_watcher(void *p);
void	*ft_simulation(void *p);
int		ft_create_philos_threads(t_data *data);

//	init.c
int		ft_init_forks(t_data *data);
void	ft_init_philos(t_data *data);
int		ft_init_data(t_data *data, int argc, char *argv[]);
int		ft_free_return_failure(t_data *data, char *error_msg);

//	utils.c
int		ft_strlen(char *s);
//int		ft_usleep(size_t ms);
size_t	ft_get_current_time(void);
int		ft_atoi(char *s);

#endif
