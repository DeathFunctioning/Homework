#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	len;
	int	start;
	int	end;
	char	c;

	i = 0;
	len = 0;
	start = 0;
	end = 0;
	c = 0;

	if(argc == 2)
	{
		while(argv[1][len])
			len++;
		len--;
		while((argv[1][len] == 32 || argv[1][len] == '\t' ) && len > 0 )
			len--;
		while((argv[1][i] == 32 || argv[1][i] == '\t' ) && argv[1][i])
			i++;
		while(len >= i)
		{
			while((argv[1][len] != 32 && argv[1][len] != '\t' ) && len >= i)
			{
				if(argv[1][len + 1] == 32 || argv[1][len + 1] == '\t' || argv[1][len + 1] == '\0')
					end = len;
				if(argv[1][len - 1] == 32 || argv[1][len - 1] == '\t' || len == i)
					start = len;
				len--;
			}
			while(start <= end)
			{
				c = argv[1][start];
				write(1, &c, 1);
				start++;
			}
			if((argv[1][len] == 32 || argv[1][len] == '\t') && len >= i)
			{
				write(1, " ", 1);
				while((argv[1][len] == 32 || argv[1][len] == '\t') && len > i)
					len--;
			}
		}

	}
	write(1, "\n", 1);
	return (0);
}
