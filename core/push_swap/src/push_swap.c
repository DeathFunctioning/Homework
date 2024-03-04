/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:48:51 by tbaker            #+#    #+#             */
/*   Updated: 2024/03/02 18:23:51 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//if (i == 1)//this was changed from i = 1 may need to change back 
//		ft_print_list(stack_a, stack_b);
int	main(int argc, char **argv)
{
	int			i;
	long long	nb;
	t_list		*stack_a;
	t_list		*stack_b;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		while (argv[i])
		{
			if (ft_isdigit(argv[i]) == -1)
				error (&stack_a);
			nb = ft_atoi(argv[i]);
			if (nb < -2147483648 || nb > 2147483647)
				error (&stack_a);
			if (i == 1)
				stack_a = ft_lstnew(list, (int)nb);
			else
			{
				ft_lstadd_back(&stack_a, ft_lstnew(list, (int)nb));
				if (check_double((int)nb, &stack_a) == -1)
					error (&stack_a);
			}
			i++;
		}
		if (check_sort(&stack_a))
			return (0);
		index_value(&stack_a, argc - 1, stack_a->data);
		if (argc == 3)
			sa(&stack_a);
		else if (argc == 4)
			sort_3(&stack_a);
		else
			sort(&stack_a, &stack_b);
		return (0);
	}
	else
		error (&stack_a);
}
