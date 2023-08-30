/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:48:22 by tbaker            #+#    #+#             */
/*   Updated: 2023/08/30 15:31:54 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_putchar(int c);
int	ft_printf(const char *format, ...);
int	ft_format_sort(va_list mod, const char c, int len);
int	ft_string(char *s);
int	ft_integer(int nbr);
int	ft_unsigned(unsigned int nbr);
int	ft_hexadecimal(unsigned int nbr, const char c);
int	ft_pointer(unsigned long nbr);

#endif
