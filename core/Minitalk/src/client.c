#include "minitalk.h"

void	send_signal(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		usleep(100000);
		if (c & (1 << bit))
			kill (pid, SIGUSR2);
		else
			kill (pid, SIGUSR1);
		bit--;
	}
}

void	send_message(int pid, char *message)
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
	char	*message;
	int		pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
		send_message(pid, message);
		return (0);
	}
	ft_printf("Error! \n Enter [PID] [Message] next time ;-}\n");
	return (1);
}
