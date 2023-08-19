
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	buffer[10];
	ssize_t	bytes_read;
	int		i;
	int		len;
	static int count;

	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
	{
		if (bytes_read == -1)
			return (NULL);
		printf("bytes read = %li\n", bytes_read);
	}
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	len = i;
	line = (char *)malloc(sizeof(char) * len + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	count++;
	printf("count = %i\n", i);
	line[i] = '\0';
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Why want this file open");
		return (1);
	}
	printf("test1 = %s", get_next_line(fd));
	printf("test new line\n");
	printf("test1 = %s", get_next_line(fd));
	printf("test new line\n");
	close(fd);
	return(0);
}
