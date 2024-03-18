#include "minitalk.h"

void	signal_handler(int sig)
{
	static unsigned char	bit = 0;
	static int				bitcount = 0;

	if (sig == SIGUSR2)
		bit = bit | 1;
	bitcount++;
	if (bitcount == 8)
	{
		if (bit == '\0')
		{
			ft_printf("\n");
			bitcount = 0;
			bit = 0;
			return ;
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

	ft_printf("Welcome to my server ...; )");
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_handler = &signal_handler;
	sa.sa_flags = 0;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
}
