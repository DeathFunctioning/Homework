#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

float	ft_celsius(char *temp_value)
{
	int		temp;
	float	fahrenheit;

	temp = atoi(temp_value);
	fahrenheit = ((float)temp - 32) * 5.0 / 9.0;
	return (fahrenheit);
}

float	ft_fahr(char *temp_value)
{
	int		temp;
	float	celsius;

	temp = atoi(temp_value);
	celsius = ((float)temp * 9.0 / 5.0) + 32;
	return (celsius);
}

int	main(int argc, char *argv[])
{
	float temp;

	temp = 0.00;
	if (argc > 1 && argc < 4)
	{
		if (argv[1][0] == 'c')
		{
			temp = ft_celsius(argv[2]);
			printf("temperature converted to Celsius = %f\n", temp);
			return (EXIT_SUCCESS);
		}
		else if (argv[1][0] == 'f')
		{
			temp = ft_fahr(argv[2]);
			printf("temperature converted to Fahrenheit = %f\n", temp);
			return (EXIT_SUCCESS);
		}
		else
		{
			printf("Incorrect temperature unit please only enter [c] or [f]");
			return (EXIT_FAILURE);
		}
	}
	printf("Need tempture unit [c] or [f] and tempture value?");
	return (EXIT_FAILURE);
}

