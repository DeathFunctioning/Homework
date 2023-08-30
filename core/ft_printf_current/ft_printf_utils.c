
#include "ft_printf.h"

int	ft_string(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	write(1, s, i);
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
	}
	else
		len = len + ft_unsigned(nbr);
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

int	ft_hexadecimal(unsigned int nbr, const char c)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (ft_putchar('0'));
	if (nbr >= 16)
	{
		len = len + ft_hexadecimal(nbr / 16, c);
		len = len + ft_hexadecimal(nbr % 16, c);
	}
	else
	{
		if (nbr <= 9)
			len = len + ft_putchar(nbr + 48);
		else 
		{
			if (c == 'x')
				len = len + ft_putchar(nbr + 87);
			if (c == 'X')
				len = len + ft_putchar(nbr + 55);
		}
	}
	return (len);
}
/*
int	ft_hexadecimal(unsigned int nbr, const char c)
{
	int	len;

	len = 0;
	if (nbr == 0)
	{
		len = len + write(1, "0", 1);
		return (len);
	}
	if (nbr >= 16)
	{
		ft_hexadecimal(nbr / 16, c);
		ft_hexadecimal(nbr % 16, c);
	}
	len++;
	if (nbr < 10)
		len = len + ft_putchar(nbr + '0');
	else 
	{
		if (c == 'x')
			len = len + ft_putchar(nbr - 10 + 'a');
		if (c == 'X')
			len = len + ft_putchar(nbr - 10 + 'A');
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
