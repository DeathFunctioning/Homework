
#include "ft_print.h"

int	ft_convert_char(va_list list, char *format, int i)
{
	char c_convert;

	if (format[i] == 'c') 
	{
		c_convert = va_arg(list, int);
		write(1, &c_convert, 1);
		return (1);
	}
	else











	int left;
	int width;

	width = 0;
	left = 0;
	









	while (format[i] != 'c')
	{
		if (format[i] == '-')
		{
			left = 1;
			i++;
			if (format[i] == 48)
				write(1, "error", 5) //ft_error();
		}
		if (format[i] >= 48 && <= 57)
		{	
			if (format[i] == 48)
				write(1, "error", 5) //ft_error();
			width = width + format[i] - 48;

	



	return (len);
}
