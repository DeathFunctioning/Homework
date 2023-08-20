
#include "get_next_line.h"
//get to new line
//if failed due to return type not char and returning NULL
void	*ft_new_line(char *buffer)
{
	//instead of buffer[i] != '\0'
	while(!(*buffer))
	{
		if (*buffer == '\n')
			return (buffer);
		buffer++;
	}
}
