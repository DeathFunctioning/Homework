/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:48:51 by tbaker            #+#    #+#             */
/*   Updated: 2024/06/18 15:49:31 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		parse_string(t_list **stack_a, char *s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == 32)
			i++;
		if (ft_isdigit(argv[i]) == -1)
			error (stack_a);

		


	return (count);
}

int	main_loop(t_list **stack_a, char **argv)
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
	return (i);
}

void	sort_select(t_list **stack_a, t_list **stack_b, int len)
{
	if (len == 2)
		sa(stack_a);
	else if (len == 3)
		sort_3(stack_a);
	else if (len == 4 || len == 5)
		sort_5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

//if (i == 1)//this was changed from i = 1 may need to change back 
//		ft_print_list(stack_a, stack_b);
int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	int			len;

	stack_a = NULL;
	stack_b = NULL;
	//new addition
//	if (argc == 2)
//		len = parse_string(&stack_a, argv[1]);
//	else
	len = argc - 1;
	if (agrc > 2)
	{
	//	if (argc == 2)
	//		len = parse_string(&stack_a, argv[1]);
	//	else
	//		len = main_loop(&stack_a, argv);
		main_loop(&stack_a, argv);
		if (check_sort(&stack_a))
			return (0);
		index_value(&stack_a, len, stack_a->data);
		sort_select(&stack_a, &stack_b, len);
/*		if (argc == 3)
			sa(&stack_a);
		else if (argc == 4)
			sort_3(&stack_a);
		else if (argc == 5 || argc == 6)
			sort_5(&stack_a, &stack_b);
		else
			radix_sort(&stack_a, &stack_b);*/
		free_list(&stack_a);
		free_list(&stack_b);
		return (0);
	}
//	if (argc == 2)
//	{
//		write(2, "Error\n", 6);
//		return (-1);
//	}
	return (0);
}
