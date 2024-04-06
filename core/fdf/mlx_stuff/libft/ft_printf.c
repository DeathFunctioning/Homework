/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:34:30 by tbaker            #+#    #+#             */
/*   Updated: 2024/03/20 15:59:10 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allow write and perform addition on nbr in function in one line of code
int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

// Sorts mod into correct functions
// Handles %c %% and adds "0x" to %P
int	ft_format_sort(va_list mod, const char c, int len)
{
	char	c_return;

	if (c == 'c')
	{
		c_return = va_arg(mod, int);
		len = len + write(1, &c_return, 1);
	}
	else if (c == 's')
		len = len + ft_string(va_arg(mod, char *));
	else if (c == 'i' || c == 'd')
		len = len + ft_integer(va_arg(mod, int));
	else if (c == 'u')
		len = len + ft_unsigned(va_arg(mod, unsigned int));
	else if (c == 'x' || c == 'X')
		len = len + ft_hexadecimal(va_arg(mod, unsigned int), c);
	else if (c == 'p')
	{
		len = len + write(1, "0x", 2);
		len = len + ft_pointer(va_arg(mod, unsigned long));
	}
	else if (c == '%')
		len = len + write(1, "%", 1);
	return (len);
}

// Writes char and finds %
// Counts times writen and returns total printf size
int	ft_printf(const char *format, ...)
{
	va_list	mod;
	int		i;
	int		len;
	char	c;

	i = 0;
	len = 0;
	va_start(mod, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			c = format[i];
			len = ft_format_sort(mod, c, len);
		}
		else
			len = len + write(1, &format[i], 1);
		i++;
	}
	va_end(mod);
	return (len);
}
