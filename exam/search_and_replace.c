#include <unistd.h>

int	main(int argc, char **argv)
{
	char	r;
	char	c;
	char	rw;
	int	i;

	i = 0;
	if(argc == 4 && !argv[2][i + 1] && !argv[3][i + 1])
	{
		r = argv[2][i];
		rw = argv[3][i];	
		while(argv[1][i])
		{
			c = argv[1][i];
			if (c == r)
				c = rw;
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);		
}
