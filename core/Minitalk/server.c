#include "minitalk.h"

void	signal_handler(int sig)
{
	unsigned char	bit;
	static int		bitcount = 0;
	char			c;

	if (sig == SIGUSR2)
		c = c | 1;
	else
		c = 0;
	bitcount++;
	if (bitcount == 8)
	{
		bit = (char) c;
		if (bit == '\0')
		{
			ft_printf("\n");
			return (0);
		}
		ft_printf("%c", bit);
		bitcount = 0;
	}
	c = c << 1;
}

//while used as an event handler
int	main(void)
{
	struct sigaction	sa;

	ft_printf("Welcome to my server ...");
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_handler = &signal_handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		usleep (50);
}
