#include "philo.h"

//check if philos are between 1 - 200
//checks if args from 1 - 5 if the string contains only chars from 
// 0 - 9 
// need to remove printf 
// need to error check if atoi is not equal to 0 for all args except for
// argv 6 number of times a philo must eat 
int	ft_data_check(char *argv[])
{
	int	i;
	int	j;

	j = 1;
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 200)
	{
		write(2, "Number of philos needs to between 1 - 200\n", 42);
		return (-1);
	}
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] < 48 || argv[j][i] > 58)
			{
				write(2, "Please enter postive number only\n", 33); 
				return (-1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
