/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:34:30 by tbaker            #+#    #+#             */
/*   Updated: 2023/08/04 20:19:11 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_output(va_list mod, char c)
{
	int		count;
	char 	test;
	char	*s1;

	count = 0;
	if (c == 'c')
	{
		test = va_arg(mod, int);
		write(1, &test, 1);
		count++;
	}
	else if (c == 's')
	{
		s1 = va_arg(mod, char*);
		count = strlen(s1);
		write(1, s1, count);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	mod;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(mod, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			len = len + ft_format_output(mod, format[i]);
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(mod);
	return(len);
}

int	main(void)
{
	char			c = '$';
	char			*s = "We make plans to kiss the sun at nigth";
//	int				n = 42;
//	int				neg = -42;
//	unsigned int	un = 4242;
//	int				*ptr = &n;
//	float			fn = 42.42424242;


//		1st test 	
	printf("C's printf = %c\n", c);
	ft_printf("My ft_printf = %c\n", c);

//		Mandatory
	printf("%i\n", printf("C's printf = %s\n", s));
	printf("%i\n",ft_printf("My ft_printf = %s\n", s) - 2);
/*	printf("C's printf = %p\n", (void*) ptr);
	ft_printf("My ft_printf = %p\n", (void*) ptr);
	printf("C's printf = %i\n", n);
	ft_printf("My ft_printf = %i\n", n);
	printf("C's printf = %u\n",nb);
	ft_printf("My ft_printf = %u\n",nb);
	printf("C's printf = %x\n", n);
	ft_printf("My ft_printf = %x\n", n);
	printf("C's printf = %X\n", n);
	ft_printf("My ft_printf = %X\n", n);
	printf("C's printf = %%\n",);
	ft_printf("My ft_printf = %%\n",);
*/
//		Bonus	
/*	printf("C's printf = %-5i\n",n);
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
	return (0);
}

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
