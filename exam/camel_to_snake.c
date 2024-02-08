#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	c;

	i = 0;
	if (argc == 2)
	{
		while(argv[1][i])
		{
			c = argv[1][i];
			if (c >= 65 && c <= 90)
			{
				write(1, "_", 1);
				c += 32;
			}
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
