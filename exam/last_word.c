#include <unistd.h>

int main(int argc, char **argv)
{
	int	len;
	char	c;

	len = 0;
	if(argc == 2)
	{
		while(argv[1][len])
			len++;
		len--;
		while((argv[1][len] == 32 || argv[1][len] == '\t') && len > 0)
			len--;
		while((argv[1][len] != 32 && argv[1][len] != '\t') && len > 0)
			len--;
		len++;
		while(argv[1][len] &&  (argv[1][len] != 32 && argv[1][len] != '\t'))
		{
			c = argv[1][len];
			write(1, &c, 1);
			len++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
