#include <unistd.h>

void	print_bits(unsigned char octect)
{
	unsigned char	bits;
	int				i;

	i = 8;
	while (i--)
	{
		bits = (octect >> i & 1) + 48;
		write(1, &bits, 1);
	}
}
