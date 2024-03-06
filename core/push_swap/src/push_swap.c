/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:48:51 by tbaker            #+#    #+#             */
/*   Updated: 2024/03/06 16:32:21 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	main_loop(t_list **stack_a, char **argv)
{
	int			i;
	long long	nb;

	i = 1;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == -1)
			error (stack_a);
		nb = ft_atoi(argv[i]);
		if (nb < -2147483648 || nb > 2147483647)
			error (stack_a);
		if (i == 1)
			*stack_a = ft_lstnew(stack_a, (int)nb);
		else
		{
			ft_lstadd_back(stack_a, ft_lstnew(stack_a, (int)nb));
			if (check_double((int)nb, stack_a) == -1)
				error (stack_a);
		}
		i++;
	}
}

//if (i == 1)//this was changed from i = 1 may need to change back 
//		ft_print_list(stack_a, stack_b);
int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		main_loop(&stack_a, argv);
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
	return (1);
}
