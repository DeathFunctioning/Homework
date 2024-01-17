#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*s1;
	char	*s2;
	int	i;
	int	j;
	int	stop;

	i = 0;
	j = 0;
	stop = 0;
	s1 = argv[1];
	s2 = argv[2];
	if (argc == 3)
	{
		while(s1[i])
		{
			j = 0;
			stop = 0;
			while(j < i)
			{
				if (s1[j] == s1[i]) 
					stop = 1;
				j++;
			}
			if (stop == 0)
				write(1, &s1[i], 1);
			i++;
		}
		i = 0;
		while(s2[i])
		{
			j = 0;
			stop = 0;
			while(j < i)
			{
				if (s1[j] == s2[i]) 
				{
					stop = 1;
					break;
				}
				j++;
			}
			j = 0;
			while(stop == 0 && j < i)
			{
				if (s2[j] == s2[i])
				{	
					stop = 1;
					break;
				}
				j++;
			}
			if (stop == 0)
				write(1, &s2[i], 1);

			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
