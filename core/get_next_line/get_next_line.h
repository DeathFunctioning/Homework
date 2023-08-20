
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <stddef.h>

typedef struct s_list
{
	char			*buff;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	*ft_new_line(char *buffer);
#endif
