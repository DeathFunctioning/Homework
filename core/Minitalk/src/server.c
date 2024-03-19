/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:09:02 by tbaker            #+#    #+#             */
/*   Updated: 2024/03/19 20:55:31 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	bit = 0;
	static int				bitcount = 0;
	int						i;

	context = NULL;
	i = info->si_pid;
	if (sig == SIGUSR2)
		bit = bit | 1;
	bitcount++;
	if (bitcount == 8)
	{
		if (bit == '\0')
		{
			ft_printf("\n");
			usleep(100);
			kill(i, SIGUSR2);
		}
		ft_printf("%c", bit);
		bitcount = 0;
		bit = 0;
	}
	bit = bit << 1;
}

//while used as an event handler
int	main(void)
{
	struct sigaction	sa;

	ft_printf("Welcome to my server ...; )\n");
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
