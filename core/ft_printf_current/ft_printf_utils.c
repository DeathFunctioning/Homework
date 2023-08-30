/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:47:31 by tbaker            #+#    #+#             */
/*   Updated: 2023/08/30 15:38:44 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string(char *s)
{
	int		i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
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
	if (nbr > 15)
	{
		len = len + ft_hexadecimal(nbr / 16, c);
		len = len + ft_hexadecimal(nbr % 16, c);
	}
	else
	{
		if (nbr < 10)
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

int	ft_pointer(unsigned long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (ft_putchar('0'));
	if (nbr > 15)
	{
		len = len + ft_pointer(nbr / 16);
		len = len + ft_pointer(nbr % 16);
	}
	else
	{
		if (nbr < 10)
			len = len + ft_putchar(nbr + 48);
		else 
			len = len + ft_putchar(nbr + 87);
	}
	return (len);
}
