#include "philo.h"

// need to remove printf test statements 
// need to 
int	main(int argc, char *argv[])
{
	t_data	data;	

	if (argc == 5 || argc == 6)
	{
		if (ft_data_check(argv) == -1)
			return (EXIT_FAILURE);
		if (ft_init_data(&data, argc, argv) == -1)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	//need to write better error msg
	write (2, "not enough args\n", 17);
	return (EXIT_FAILURE);
}
