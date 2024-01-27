#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	char	c;

	i = 0;
	j = 1;
	if (argc > 1)
	{
		while(j < argc)
		{
			i = 0;
			while(argv[j][i])
			{
				if(argv[j][i + 1] == 32 || argv[j][i + 1] == '\t' || argv[j][i + 1] == '\0')
				{
					if(argv[j][i] >= 97 && argv[j][i] <= 122)
					{
						c =  argv[j][i];
						c = c - 32;
						write(1, &c, 1);
					}
					else
						write(1, &argv[j][i], 1);
				}
				else
					if(argv[j][i] >= 64 && argv[j][i] <= 90)
					{	
						c =  32 + argv[j][i]; 
						write(1, &c, 1);
					}
					else
						write(1, &argv[j][i], 1);
				i++;
			}
			j++;
			write(1, "\n", 1);
		}
		return(0);
	}
	write(1, "\n", 1);
	return (0);
}
