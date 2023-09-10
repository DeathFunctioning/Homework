/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_clone3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:22:39 by tbaker            #+#    #+#             */
/*   Updated: 2023/09/10 18:38:13 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = NULL;
	char		*line;
	int			bytes;

	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer != NULL)
	{
		if (ft_new_line(buffer) > 0)



	}
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			break;
		buffer[bytes] = '\0';
		if (ft_new_line(buffer) > 0)
			buffer = ft_split_buffer(buffer);
		else

			



	return (line);
}

{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Why want this file open");
		return (1);
	}
	printf("test1 = %s", get_next_line(fd));
	printf("test2 = %s", get_next_line(fd));
	printf("test3 = %s", get_next_line(fd));
	printf("test4 = %s", get_next_line(fd));
	close(fd);
	return (0);
}
