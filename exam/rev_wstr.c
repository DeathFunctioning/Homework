#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int start;
	int	end;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
			i++;
		i--;
		while (i > 0)
		{
			if (argv[1][i] == 32 || argv[1][i] == '\t')
			{
				write(1, " ", 1);
				while (argv[1][i] == 32 || argv[1][i] == '\t')
					i--;
			}	
			end = i;
			while (argv[1][i] != 32 && argv[1][i] != '\t')
			{
				if (argv[1][i] == 32 || argv[1][i] == '\t' || i == 0)
					break ;
				i--;
			}
			start = i + 1; 
			if (i == 0)
				start = 0;
			while (start <= end)
			{
				write(1, &argv[1][start], 1);
				start++;
			}
		}
	}
	write (1, "\n", 1);
	return (0);
}
