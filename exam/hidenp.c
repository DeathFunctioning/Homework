#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if(argc == 3)
	{
		while(argv[2][i])
		{
			if(argv[2][i] == argv[1][j])
				j++;
			if(!argv[1][j])
			{
				write(1, "1", 1);
				break ;

			}
			i++;
			if(!argv[2][i])
			{
				write(1, "0", 1);
				break ;
			}
		}
	}
	write(1, "\n", 1);
	return (0);





}
