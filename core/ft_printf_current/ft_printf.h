#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_format_sort(va_list mod, const char c, int len);
int	ft_string(char *s);
int	ft_integer(int nbr);
int	ft_unsigned(unsigned int nbr);
//int	ft_hexadecimal(unsigned int nbr, const char c, int len);
//int	ft_pointer(size_t nbr, int len);

#endif
