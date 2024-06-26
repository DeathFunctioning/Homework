/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:52:29 by tbaker            #+#    #+#             */
/*   Updated: 2023/10/07 17:56:41 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUFFER_SIZE 100

char	*get_next_line(int fd);
char	*gnl_strjoin(const char *s1, const char *s2, int i, int j);
char	*gnl_strndup(const char *src, int n);
int		gnl_strlen(const char *s);
void	gnl_free(char **s);
char	*gnl_strchr(const char *src, int c);

#endif
