/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_clone3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:22:39 by tbaker            #+#    #+#             */
/*   Updated: 2023/10/07 17:56:30 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_line_return(char **left, int nl)
{
	char	*line;
	char	*temp;

	line = NULL;
	if (!*left)
		return (NULL);
	line = strndup(*left, nl);
	if (!line)
		return (NULL);
	temp = ft_strndup(*left + nl + 1, (ft_strlen(*left) - (nl + 1)));
	free(*left);
	*left = temp;
	return (temp);
}

int	ft_read(int fd, char *buffer[])
{
	int bytes;

	bytes = read(fd, *buffer, BUFFER_SIZE);
	*buffer[bytes] = '\0';
	if (bytes == 0)
		return (-1);
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char	*left = NULL;
	char		buffer[BUFFER_SIZE + 1];
	int			nl;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nl = ft_find_nl(left);
	if (nl > 0)
		return (ft_line_return(&left, nl));
	while (ft_read(fd, &buffer) > 0)
	{
		if (!left)
			left = ft_strndup("", 1);
		left = ft_strjoin(left, buffer);
		if (ft_find_nl(left) > 0)
			return (ft_line_return(&left, nl));
	}
	if (left)
	{
		line = ft_strndup(left, ft_strlen(left));
		free (left);
		left = NULL;
	}
	return (line);
}

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
}
