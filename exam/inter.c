#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		flag;
	char	*s1;
	char	*s2;

	i = 0;
	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];
		while (s1[i])
		{
			j = 0;
			flag = 0;
			while(j < i)
			{
				if (s1[j] == s1[i])
					flag = 1;
				j++;
			}
			j = 0;
			while (s2[j] && flag == 0)  
			{


				if(s1[i] == s2[j])
				{
					write(1, &s1[i], 1);
					break ;
				}
				j++;

			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
