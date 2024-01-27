#include <unistd.h>

int	main(int argc, char **argv)
{
	int	len;
	int	i;
	char	c;

	len = 0;
	i = 0;
	if(argc == 2)
	{
		while(argv[1][len])
			len++;
		len--;
		while(argv[1][len] == 32 || argv[1][len] == '\t')
			len--;
		while(argv[1][i] == 32 || argv[1][i] == '\t')
			i++;
		while(i <= len)
		{
			c = argv[1][i];
			if(c == 32 || c == '\t')
			{
				write(1, "   ", 3);
				while(argv[1][i] == 32 || argv[1][i] == '\t')
					i++;
			}
			else
			{
				write(1, &c, 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
