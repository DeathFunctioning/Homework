/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:34:30 by tbaker            #+#    #+#             */
/*   Updated: 2023/08/02 22:58:38 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{

}

int	main(void)
{
	char			c = '$'
	char			*s = "We make plans to kiss the sun at nigth";
	int				n = 42;
	int				neg = -42;
	unsigned int	un = 4242;
	int				*ptr = &n;
	float			fn = 42.42424242;


//		1st test 	
	printf("C's printf = %c\n", c);
	ft_printf("My ft_printf = % c\n", c);

//		Mandatory
/*	printf("C's printf = %s\n", s);
	ft_printf("My ft_printf = %s\n", s);
	printf("C's printf = %p\n", (void*) ptr);
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
