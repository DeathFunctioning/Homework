# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_write_string(char *s)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while(s[i])
	{
		len += write(1, &s[i], 1);
		i++;
	}
	return (len);
}

int	ft_write_int(int nbr)
{
	int		len;
	char	c;

	len = 0;
	if (nbr < 0)
	{
		len += write (1, "-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
		len += ft_write_int(nbr / 10);
	c = 48 + nbr % 10;
	len += write(1, &c, 1);
	return (len);
}

int	ft_write_hex(unsigned int nbr)
{
	int		len;
	char	c;

	len = 0;
	if (nbr > 15)
		len += ft_write_hex(nbr / 16);
	nbr = nbr % 16;
	if (nbr > 9)
		c = 87 + nbr;
	else
		c = 48 + nbr;
	len += write(1, &c, 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	mod;

	len = 0;
	i = 0;
	va_start(mod, format);
	while (format[i])
	{
		if(format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				len += ft_write_string(va_arg(mod, char *));
			else if (format[i] == 'd' || format[i] == 'i')
				len += ft_write_int(va_arg(mod, int));
			else if (format[i] == 'x' || format[i] == 'X')
				len += ft_write_hex(va_arg(mod, int));
			else if (format[i] == '%')
				len += write(1, "%", 1);
			else
				 write (1, "error\n", 6);
			i++;
		}
		len += write(1, &format[i], 1);
		i++;
	}
	va_end(mod);
	return (len);
}
/*
int	main(void)
{

	int		nbr = 42;
	int		ft_return = 0;
	int		printf_return = 0;
	char	*s = "working";

	ft_return =  ft_printf("printf string %s\n", s);  
	printf_return = printf("printf string %s\n", s);  
	ft_printf("ft_printf int %i\n", nbr);  
	printf("printf int %i\n", nbr);
	printf("ft_print_return = %i printf_return = %i\n", ft_return, printf_return);
	ft_printf("ft_printf = Hexadecimal for %d is %x\n", nbr, nbr);  
	printf("printf = Hexadecimal for %d is %x\n", nbr, nbr);  

}*/
