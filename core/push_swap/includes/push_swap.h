#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h> //remove test

//data = arg int value
//ind_p = position in the list from head to tail 
//ind_v = relative value of int value

typedef struct s_list
{
	int				data;
	int				idx_p;
	int				idx_v;
	struct s_list	*next;
}	t_list;

//	init.c

t_list		*ft_lstnew(int data);
void		ft_lstadd_back(t_list **list, t_list *new);
int			lst_size_index(t_list **list);
void		ft_print_list(t_list *stack_a, t_list *stack_b); //remove test

// utils.c

long long	ft_atoi(const char *s);

// rotate_stack.c

void		rotate_list(t_list **list);
void		ra(t_list **list);
void		rb(t_list **list);
void		rr(t_list **list_a, t_list **list_b);

// reverse_rotate_stack.c

void		reverse_rotate_list(t_list **list);
void		rra(t_list **list);
void		rrb(t_list **list);
void		rrr(t_list **list_a, t_list **list_b);

// swap_stack.c

void		swap_node(t_list **list);
void		sa(t_list **list);
void		sb(t_list **list);
void		ss(t_list **list_a, t_list **list_b);

// push_stack.c

void		push_node(t_list **list_a, t_list **list_b);
void		pa(t_list **list_a, t_list **list_b);
void		pb(t_list **list_a, t_list **list_b);

// error.c

void		error(t_list **list);
int			ft_isdigit(char *s);
int			check_double(int nb, t_list **list);
int			check_sort(t_list **list);

// sort_10.c

void		sort_10(t_list **list_a, t_list **list_b);

// sort.c

void		sort_3(t_list **list);
void		sort_5(t_list **list_a, t_list **list_b);
void		pb_min_values(t_list **list_a, t_list **list_b);
void		index_value(t_list **list, int len);

#endif
