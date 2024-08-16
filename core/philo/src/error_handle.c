# include "philo.h"

int	ft_data_check(char *argv[])
{
	int	i;
	int	j;

	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] < 48 || argv[j][i] > 58)
			{
				printf("fail c other than digits");//remove 
				return (0);
			}
			i++;
		}
		j++;
	}
	printf("pass all digits");//remove 
	return (1);
}
