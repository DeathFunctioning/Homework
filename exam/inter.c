#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;
	int	flag;

	i = 0;
	j = 0;
	if (argc == 3)
	{
		 while(argv[1][i])
		 {
			 j = 0;
			 while(argv[2][j])
			 {
				 if(argv[1][i] == argv[2][j])
				 {
					 flag = 0;
					 k = 0;
					 while(k < i)
					 {
						 if(argv[1][k] == argv[1][i])
						 {
							 flag = 1;
							 break ;
						 }
						 k++;
					 }
					 if(flag == 0) 
					 {
						write(1, &argv[1][i], 1);
					 	j++;
					 	break ;
					 }
				 }
				 j++;
			 }
			 i++;
		 }
	}
	write(1, "\n" , 1);
	return (0);
}
