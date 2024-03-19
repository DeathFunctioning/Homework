/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:08:52 by tbaker            #+#    #+#             */
/*   Updated: 2024/03/19 20:58:11 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//void	signal_handler(int sig, siginfo_t *info, void *context)
void	signal_handler(int sig, siginfo_t *info, void *context)
{
	context = NULL;
	if (sig == SIGUSR2)
		ft_printf("signal recevied from %d\n", info->si_pid);
	exit (0);
}

void	send_signal(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (c & (1 << bit))
			kill (pid, SIGUSR2);
		else
			kill (pid, SIGUSR1);
		bit--;
		usleep(100);
	}
}

static void	send_message(int pid, char *message)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(message);
	while (i <= len)
	{
		send_signal(pid, message[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char				*message;
	int					pid;
	struct sigaction	sa;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
		send_message(pid, message);
		sa.sa_sigaction = &signal_handler;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			pause();
	}
	ft_printf("Error! \n Enter [PID] [Message] next time ;-}\n");
	return (1);
}
