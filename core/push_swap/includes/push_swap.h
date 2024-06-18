/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:50:58 by tbaker            #+#    #+#             */
/*   Updated: 2024/06/18 19:29:16 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

//data = arg int value
//ind_p = position in the list from head to tail 
//ind_v = relative value of int value

typedef struct s_list
{
	int				data;//one off update
	int				idx_p;
	int				idx_v;//one off update
	int				max;//do i need
	struct s_list	*next;
}	t_list;

//	main
void		free_array(char **array);
int			parse_string(t_list **list_a, char *s);
void		main_loop(t_list **list_a, char **argv, int i);
void		sort_select(t_list **list_a, t_list **list_b, int argc);

//	init.c

void		index_value(t_list **list, int len, int min);
void		index_assign_value(t_list **list, int i, int min);
t_list		*ft_lstnew(t_list **list, int data);
void		ft_lstadd_back(t_list **list, t_list *new);
int			lst_size_index(t_list **list);

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
void		free_list(t_list **list);
int			ft_isdigit(char *s);
int			check_double(int nb, t_list **list);
int			check_sort(t_list **list);

// sort.c

void		sort_3(t_list **list);
void		sort_5(t_list **list_a, t_list **list_b);
void		pb_min_descending_order(t_list **list_a, t_list **list_b);
void		pa_till_stack_b_empty(t_list **list_a, t_list **list_b);
int			get_idx_p(t_list **list, int i);

// radix_sort.c

void		radix_sort(t_list **list_a, t_list **list_b);

// ft_spilt.c

char		**ft_split(char const *s, char c);
#endif
