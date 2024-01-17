#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (argc == 2)
	{
		while(argv[1][len])
			len++;
		len--;
		while((argv[1][len] == 32 || argv[1][len] == '\t') && len > 0)
			len--;
		while(argv[1][i] && i <= len)
		{
			while((argv[1][i] == 32 || argv[1][i] == '\t') && (argv[1][i] && i <= len))
				i++;
			while((argv[1][i] != 32 && argv[1][i] != '\t') && (argv[1][i] && i <= len))
			{
				write(1, &argv[1][i], 1);
				i++;
			}
			if ((argv[1][i] == 32 || argv[1][i] == '\t') && (argv[1][i] && i <= len))
			{
				write(1, "   ", 3);
				while(argv[1][i] == 32 || argv[1][i] == '\t')
					i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
