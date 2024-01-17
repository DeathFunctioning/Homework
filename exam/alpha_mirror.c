#include <unistd.h>

int	main(int argc, char ** argv)
{
	int	i;
	int	j;
	char	c;

	i = 0;
	j = 0;
	if (argc == 2)
	{
		while(argv[1][i])
		{
			c = argv[1][i];
			if (c >= 65 && c <= 90)
			{
				if(c < 78)
				{
					j = c - 65;
					c = 90 - j;
				}
				else
				{
					j = 90 - c;
					c = j + 65;
				}
			}
			if (c >= 97 && c <= 122)
			{
				if(c < 110)
				{
					j = c - 97;
					c = 122 - j;
				}
				else
				{
					j = 122 - c;
					c = j + 97;
				}
			}
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
