# include "philo.h"

// need to remove printf test statements 
// need to 
int	main(int argc, char *argv[])
{
	t_data	data;	

	if (argc == 5 || argc == 6)
	{
		if (ft_data_check(argv) == -1)
			return (1);
		return (0);
	}
	write (2, "not enough args\n", 17);
	return (1);
}
