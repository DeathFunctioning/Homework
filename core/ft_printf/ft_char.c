
#include "ft_printf.h"

int	ft_char(va_list list, char *format, int i)
{
	int left;
	int width;

	width = 0;
	left = 0;
	if (format[i] == '-')
		left = 1;
	i++;
	while (format[i] >= 48 && <= 57)
	{
		width = width + format[i] -  48;
		i++;
	}










