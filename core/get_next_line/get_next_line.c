/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_clone3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:22:39 by tbaker            #+#    #+#             */
/*   Updated: 2023/10/04 19:52:33 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*ft_line(char *left, char *line)
{
	int		nl;
	int		i;
	char	*temp;

	i = 0;
	nl = ft_find_nl(left);
	temp = malloc((nl + 1) * sizeof(*temp));
	if (!temp)
		return (NULL);
	while (i < nl)
	{
		temp[i] = left[i];
		i++;
	}
	temp[i] = '\0';
	if (!line)
		line = strdup("");
	line = ft_strjoin(line, temp);
	temp = NULL;
	free (temp);
	return (line);
}

static char	*ft_left(char *left)
{
	int		nl;
	int		i;
	char	*temp;

	nl = ft_find_nl(left);
	i = 0;
	temp = malloc((ft_strlen(left) - nl + 1) * sizeof(*temp));
	if (!temp)
		return (NULL);
	while (left[i])
	{
		temp[i] = left[nl + 1 + i];
		i++;
	}
	temp[i] = '\0';
	left = ft_strjoin("", temp);
	temp = NULL;
	free (temp);
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*left = NULL;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes;

	line = NULL;
	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_find_nl(left) > 0)
	{
		line = ft_line(left, line);
		left = ft_left(left);
		return (line);
	}
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		if (bytes == 0)
			return (NULL);
		if (!left) 
			left = strdup("");
		left = ft_strjoin(left, buffer);
		if (ft_find_nl(left) > 0)
		{
			line = ft_line(left, line);
			left = ft_left(left);
			return (line);
		}
	}
	return (left);
}
/*
int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Why want this file open");
		return (1);
	}
	printf("test 1 = %s\n", get_next_line(fd));
	printf("test 2 = %s\n", get_next_line(fd));
	printf("test 3 = %s\n", get_next_line(fd));
	printf("test 4 = %s\n", get_next_line(fd));
	printf("test 5 = %s\n", get_next_line(fd));
	printf("test 6 = %s\n", get_next_line(fd));
	printf("test 7 = %s\n", get_next_line(fd));
	printf("test 8 = %s\n", get_next_line(fd));
	printf("test 9 = %s\n", get_next_line(fd));
	printf("test 10 = %s\n", get_next_line(fd));
	close(fd);
	return (0);
}*/
