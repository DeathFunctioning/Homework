#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	c;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			c = argv[1][i];
			if ((c >= 65 && c <= 77) || (c >= 97 && c <= 109))
				c += 13;
			else if ((c >= 78  && c <= 90) || (c >= 110 && c <= 122)) 
				c -= 13;
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
