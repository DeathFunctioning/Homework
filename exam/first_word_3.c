#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	char	c;

	i = 0;
	if (argc == 2)
	{
		while(argv[1][i] && (argv[1][i] == '\t' || argv[1][i] == 32))
			i++;
		while(argv[1][i] && argv[1][i] != '\t' && argv[1][i] != 32)
		{
			c = argv[1][i];
			write(1, &c, 1);
			i++;
		}

	}
	write(1, "\n", 1);
	return (0);
}
