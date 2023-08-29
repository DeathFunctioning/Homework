
#include "ft_printf.h"

int	ft_string(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	write(1, s, i);
//	printf("i = %i\n", i);
	return (i);
}

int	ft_integer(int nbr)
{
	int	len;

	len = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		len = len + write(1, "-", 1);
		nbr = -nbr;
		//len++;
	}
	else
		len = len + ft_unsigned(nbr);
/*	
	{
		if (nbr >= 10)
		{
			len++;
			nbr = nbr / 10;
			ft_interger(nbr);
		}
		nbr = nbr % 10 + 48;
		len++;
		write(1, &nbr, 1);
	}*/
	return (len);
}

int	ft_unsigned(unsigned int nbr)
{
	int	len;

	len = 1;
	if (nbr >= 10)
		len = len + ft_unsigned(nbr / 10);
	nbr = nbr % 10 + 48;
	write(1, &nbr, 1);
	return (len);
}
/*
int	ft_hexadecimal(unsigned int nbr, const char c, int len)
{
	if (nbr > 16)
	{
		len++;
		ft_hexadecimal(nbr / 16, c, len);
		ft_hexadecimal(nbr % 16, c, len);
	}
	len++;
	if (nbr < 10)
		write(1, &nbr + 48, 1);
	else 
	{
		if (c == 'x' || c == 'p')
			write(1, nbr - 10 + 'a', 1);
		if (c == 'X')
			write(1, nbr - 10 + 'A', 1);
	}
	return (len);
}

int	ft_pointer(size_t nbr, int len)
{
	write(1, "0x", 2);
	len = len + 2;
	if (nbr > 16)
	{
		len++;
		ft_pointer(nbr / 16, len);
		ft_pointer(nbr % 16, len);
	}
	len++;
	if (nbr < 10)
		write(1, nbr + 48, 1);
	else
			write(1, nbr - 10 + 'a', 1);
	return (len);
}*/
