#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h> //remove test

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

//	init

t_list	*ft_lstnew(int data);
void	ft_lstadd_back(t_list **list, t_list *new);
void	ft_print_list(t_list *list); //remove test

// utils

int	ft_atoi(const char *s);

// rotate stack

void		rotate_list(t_list **list);
void		ra(t_list **list);
void		rb(t_list **list);
void		rr(t_list **list_a, t_list **list_b);

// reverse rotate stack


#endif

