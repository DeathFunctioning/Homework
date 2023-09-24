/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_clone3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:22:39 by tbaker            #+#    #+#             */
/*   Updated: 2023/09/24 18:55:52 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
char	*ft_copy_line(char *buffer, char *line)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)malloc(sizeof(char) * ft_strlen(buffer) + 1);
	if (!line)
		return (NULL);
	while (buffer[i])
	{
		temp[i] = buffer[i];
		i++;
	}
	temp[i] = '\0';
//	printf("ft_copy_line_test-t = %s\n", temp);
//	printf("ft_copy_line_test-l = %s\n", line);
//	printf("ft_copy_line_test-b = %s\n", buffer);
	line = ft_strjoin(line, temp);
	free (temp);
	return (line);
}*/

char	*ft_end_line(char *line, char *buffer)
{


	return (temp);
}

char	*ft_buffer_next(char *buffer)
{
	char	*temp;
	int		start;

	start = ft_find_nl(buffer + 1);
	temp = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - start + 1));
	if (!temp)
		return (NULL);
	while (buffer[start] != '\0')
	{
		temp[i] = buffer[start];
		i++;
		start++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*left = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		if (left)
			ft_strjoin(left, buffer);
		if (ft_find_nl(buffer) > 0);
		{
			line = ft_end_line(line, buffer);
			left = ft_buffer_next(buffer);
			break;
		}
		if (!line)
			line = strdup(buffer);
		else
			line = ft_strjoin(line, buffer);
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
	printf("test1 = \n%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
