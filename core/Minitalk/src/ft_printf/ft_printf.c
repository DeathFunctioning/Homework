/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:34:30 by tbaker            #+#    #+#             */
/*   Updated: 2023/09/05 14:37:52 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
/*
int	main(void)
{
	char	c = '$';
	char			*s = "We make plans to kiss the sun at nigth";
	int				n = 424242;
//	int				neg = -42;
	unsigned int	un = 4242424242;
//	float			fn = 42.42424242;


	printf("C's printf = %c\n", c);
	printf("%i\n", printf("C'sss printf = %s", s));
	printf("\n");
	printf("%i\n",ft_printf("My ft_printf = %s", s));
	printf("\n");
	printf("%i\n", printf("C'sss printf = %u", un));
	printf("\n");
	printf("%i\n",ft_printf("My ft_printf = %u", un));
	printf("\n");
	printf("%i\n", printf("C'sss printf = %i, = %s\n", n, s));
	ft_printf("%i\n", ft_printf("My ft_printf = %i, = %s\n", n, s));
	printf("%i\n", printf("C'sss printf = %x\n", un));
	printf("\n");
	printf("%i\n",ft_printf("My ft_printf = %x\n", un));
	printf("\n");
	printf("%i\n", printf("C'sss printf = %X\n", un));
	printf("\n");
	printf("%i\n",ft_printf("My ft_printf = %X\n", un));
	printf("\n");
	printf("%i\n", printf("C'sss printf = %p\n", &s));
	printf("\n");
	printf("%i\n",ft_printf("My ft_printf = %p\n", &s));
	printf("\n");

	return (0);
}*/
/*		Mandatory
	printf("%i\n", printf("C's printf = %s\n", s));
	printf("%i\n",ft_printf("My ft_printf = %s\n", s) - 2);
	printf("C's printf = %p\n", (void*) ptr);
	ft_printf("My ft_printf = %p\n", (void*) ptr);
	printf("C's printf = %i\n", n);
	ft_printf("My ft_printf = %i\n", n);
	printf("C's printf = %u\n",nb);
	ft_printf("My ft_printf = %u\n",un);
	printf("C's printf = %x\n", n);
	ft_printf("My ft_printf = %x\n", un);
	printf("C's printf = %X\n", n);
	ft_printf("My ft_printf = %X\n", n);
	printf("C's printf = %%\n");
	ft_printf("My ft_printf = %%\n");
	return (0);
}

//		Bonus	
	printf("C's printf = %-5i\n",n);
	ft_printf("My ft_printf = %-5i\n",n);
	printf("C's printf = %05i\n",n);
	ft_printf("My ft_printf = %05i\n",n);
	printf("C's printf = %2.f\n",fn);
	ft_printf("My ft_printf = %2.f\n",fn);
	printf("C's printf = %+i\n, %i+\n",n, neg);
	ft_printf("My ft_printf = %+i\n, %+i\n",n, neg);
	printf("C's printf =  % i\n, % i\n",n, neg);
	ft_printf("My ft_printf = % i\n, % i\n",n, neg);
	printf("C's printf = %#x\n",n);
	ft_printf("My ft_printf = %#x\n",n);
*/
//			Conversions
// %c = char
// %s = string
// %p = merroy location address?
// %i = int base 10
// %u = unsisgned int base 10
// x% = hexadecimal/lowercase format base 16
// X% = hexadecimal/upperrcase format base 
// %% = print the % char
//
//			Flags
// - = left alignment for width
// 0 = is this a flag for paddind width with '0'
// . = precision with float points limiting the diplayed lenth of the
// decimal
// # = 
// space char ascii 32 = is used for formatting when return an int sign
// if it is + number it will not be the '+' it will display ' ', the 
// - number will display thr sign.
// + = displays int sign '+' '-'
