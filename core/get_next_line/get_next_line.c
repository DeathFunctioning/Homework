
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	buffer[BUFF_MAX]	
	
	
	return(line);
}

int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Why want this file open");
		return (1);
	}
	printf("test1 = %s", get_next_line(fd));
	close(fd);
	return(0);
}

