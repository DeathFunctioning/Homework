# include "philo.h"

int	main(int argc, char *argv[])
{

	if (argc == 5 || argc == 6)
	{
		if (ft_data_check(argv))
			printf("data incorrect\n");
		printf("hit middle code\n");
		return (0);
	}
	printf("the beginning of my new life\n");
	return (1);
}
