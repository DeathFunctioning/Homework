#include <push_swap.h>

int	main(int argc, char **argv)
{
	int		i;
	char	c;

	i = 0;
	if (argc == 3)
	{
		while(argv[1][i])
		{
			c = argv[2][i];
			if (c >= 97 && c <= 122)
				c -= 32;
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

