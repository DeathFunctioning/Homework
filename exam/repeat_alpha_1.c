#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	int		limit;
	char	c;

	i = 0;
	limit = 0;
	if (argc == 2)
	{
		while(argv[1][i])
		{
			c = argv[1][i];
			limit = 1;
			if (c >= 65 && c <= 90)
				limit = argv[1][i] - 64;
			if (c >= 97 && c <= 122)
				limit = argv[1][i] - 96;
			while(limit--)
				write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
