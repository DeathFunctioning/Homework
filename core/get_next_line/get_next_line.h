/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:52:29 by tbaker            #+#    #+#             */
/*   Updated: 2023/10/07 13:22:12 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(char const *s);
int		ft_find_nl(char *buffer);
int		ft_strndup(char char *src, unsigned int n);

#endif
