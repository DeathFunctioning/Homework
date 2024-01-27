#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	char	c;

	i = 0;
	if (argc == 2)
	{
		while(argv[1][i])
		{
			c = argv[1][i];
			if (c >= 64 && c <= 90)
			{
				if (c == 90)
					c -= 25;
				else
					c += 1;
			}
			if (c >= 97 && c <= 122)
			{
				if (c == 122)
					c -= 25;
				else
					c += 1;
			}
			write(1, &c, 1);
			i++;
		}

	}
	write(1, "\n", 1);
	return (0);
}
