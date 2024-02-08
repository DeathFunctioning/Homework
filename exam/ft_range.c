#include <unistd.h>
#include <stdlib.h>

int	*ft_range(int start, int end)
{

	int	i;
	int	nb;
	int *array;

	i = 0;
	nb = start;
	if (start == end)
	{
		array = malloc(sizeof(array));
		if (!array)
			return (NULL);
		array[i] = nb;
		return (array);
	}
	if (start < end) //going forwards
	{
	
		while(nb <= end)
		{
			i++;
			nb++;
		}
		array = malloc(sizeof(array) * i);
		i = 0;
		nb = start;
		while(nb <= end)
		{
			array[i] = nb;
			nb++;
			i++;
		}
	}
	else
	{
		while(nb >= end)
		{
			i++;
			nb--;
		}
		array = malloc(sizeof(array) * i);
		i = 0;
		nb = start;
		while(nb >= end)
		{
			array[i] = nb;
			nb--;
			i++;
		}
	}
	return (array);
}
/*
int	main(int argc, char **argv)
{
	int	*test;
	int	limit = 1;
	int	i = 0;

	if (argc == 3)
	{
		test = ft_range(atoi(argv[1]), atoi(argv[2]));
		while (i < limit)
		{
			printf("%d", test[i]);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}*/

