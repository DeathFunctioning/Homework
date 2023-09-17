/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_get_next_line.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:55:30 by tbaker            #+#    #+#             */
/*   Updated: 2023/09/17 15:56:06 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMP_GET_NEXT_LINE_H
# define TEMP_GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
int		ft_find_nl(char *buffer);

#endif
