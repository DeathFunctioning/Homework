/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:22:39 by tbaker            #+#    #+#             */
/*   Updated: 2023/10/07 17:56:30 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//frees memory and nulls the pointer 
void	gnl_free(char **s)
{
	free(*s);
	*s = NULL;
}

//first if handles left == NULL and returns NULL
//while finds new line position
//if found newline increment past newline 
//then copies the string up to including newline to temp = ...
//the return in get_new_line.
//new left strnduped the remainder of left past the newline. 
// left is freed and the new left assigned to the left for the next call.
//its EOF and no newline what remains in the left is duped to temp and ...
//returned as the last new line.
//left is freed

char	*gnl_split_left(char **left)
{
	char	*temp;
	int		i;
	char	*new_left;

	if (!*left)
		return (NULL);
	i = 0;
	while ((*left)[i] != '\0' && (*left)[i] != '\n')
		i++;
	if ((*left)[i] == '\n')
	{
		i++;
		temp = gnl_strndup(*left, i);
		new_left = gnl_strndup(&(*left)[i], gnl_strlen(&(*left)[i]));
		gnl_free(left);
		*left = new_left;
	}
	else
	{
		temp = gnl_strndup(*left, i);
		gnl_free(left);
	}
	return (temp);
}

//Reads file and writes to buffer returns read size/buffer size as bytes.
//If bytes == -1 empty file need to free left if bytes == 0 EOF.
//rest s just joining left to buffer through temp to contain memory leaks 
//ft_join was over 25 lines so sent it i j at 0 and 0
int	gnl_buffer_join(int fd, char *buffer, char **left)
{
	int		bytes;
	char	*temp;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
	{
		if (bytes == -1)
			gnl_free(left);
		return (bytes);
	}
	buffer[bytes] = '\0';
	temp = *left;
	*left = gnl_strjoin(temp, buffer, 0, 0);
	gnl_free(&temp);
	return (bytes);
}

//Malloc buffer due to stackoverflow with buffer[BUFFER_SIZE + 1].
//buffer_join = sends buffer to get read and left becomes the joined buffer.
//While state checks bytes to see if file still contains data && checks ...
//that no new line has been found. 
//While keeps checking till a new line is found or file empty.
//free the buffer no more to read.
// if left contains data, return new line and store remainder in left. 
//free left EOF return NULL.
char	*gnl_read(char **left, int fd)
{
	int		bytes;
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = gnl_buffer_join(fd, buffer, left);
	while (bytes > 0 && !gnl_strchr(*left, '\n'))
		bytes = gnl_buffer_join(fd, buffer, left);
	gnl_free(&buffer);
	if (*left && **left)
		return (gnl_split_left(left));
	gnl_free(left);
	return (NULL);
}

//Left holds the remainder of the buffer after new line it left holds its ..
//value between calls
//If statements checks for valid fd and buffer that contains some chars.
//returns the next line
char	*get_next_line(int fd)
{
	static char	*left = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (gnl_read(&left, fd));
}
