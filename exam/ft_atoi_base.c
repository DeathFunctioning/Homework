#include <unistd.h>
#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int	nb;
	int	i;
	int	sign;

	nb = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str_base <= 10)
	{	
		while (str[i])
		{
			nb = nb * str_base + str[i] - 48;
			i++;
		}
	}
	else
		while (str[i])
		{
			if (str[i] >= 65 && str[i] <= 70)  
				nb = nb * str_base + str[i] - 55;
			else if (str[i] >= 97 && str[i] <= 102)
				nb = nb * str_base + str[i] - 87;
			else
				nb = nb * str_base + str[i] - 48;
			i++;
		}
	return (nb * sign);
}
/*
int	main(int argc, char **argv)
{

	if (argc == 2)
		printf("Result = %i\n", ft_atoi_base(argv[1], 10));
	write(1, "done\n", 5);
	return (0);
}*/
