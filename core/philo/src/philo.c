/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:22:32 by tbaker            #+#    #+#             */
/*   Updated: 2024/08/31 14:14:33 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

// need to add destroy mutexs for forks and whatever other mutex i create
// need to build the watcher thread to check meals eaten and for philos death :
int main(int argc, char *argv[])
{
	t_data  data;	

	if (argc == 5 || argc == 6)
	{
		if (ft_data_check(argv) == -1)
			return (EXIT_FAILURE);
		if (ft_init_data(&data, argc, argv) == -1)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	//need to write better error msg
	write (2, "Not enough args\n", 17);
	return (EXIT_FAILURE);
}
