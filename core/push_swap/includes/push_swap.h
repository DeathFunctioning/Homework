#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

//	init

t_stack	*create_stack(int data);

// utils

int	ft_atoi(const char *s);

#endif

