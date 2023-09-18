/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_clone3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:22:39 by tbaker            #+#    #+#             */
/*   Updated: 2023/09/17 16:16:18 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_copy_line(char *buffer, char *line)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)malloc(sizeof(char) * ft_strlen(buffer) + 1);
	if (!line)
		return (NULL);
	while (*buffer)
	{
		temp[i] = buffer[i];
		i++;
	}
	temp[i] = '\0';
	line = ft_strjoin(line, temp);
	printf("ft_copy_line_test-b = %s\n", buffer);
	printf("ft_copy_line_test-t = %s\n", temp);
	printf("ft_copy_line_test-l = %s\n", line);
	return (line);
}

char	*get_next_line(int fd)
{
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
		line = ft_copy_line(buffer, line);
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
	printf("test1 = %s\n", get_next_line(fd));
	close(fd);
	return (0);
}
