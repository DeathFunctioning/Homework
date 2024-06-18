/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:48:51 by tbaker            #+#    #+#             */
/*   Updated: 2024/06/18 19:27:52 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

//i use 0 here for main_loop to strt at the beging of the array
int	parse_string(t_list **stack_a, char *s)
{
	char	**s_argv;
	int		count;

	count = 0;
	s_argv = ft_split(s, 32);
	while (s_argv[count])
		count++;
	if (count < 2)
	{
		free_array(s_argv);
		write(2, "Error\n", 6);
		exit (-1);
	}
	main_loop(stack_a, s_argv, 0);
	free_array(s_argv);
	return (count);
}

void	main_loop(t_list **stack_a, char **argv, int i)
{
	long long	nb;

	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == -1)
			error (stack_a);
		nb = ft_atoi(argv[i]);
		if (nb < -2147483648 || nb > 2147483647)
			error (stack_a);
		if (!stack_a)
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
//		when i can main_loop here i define i as 1 to skip pass the porgram name
int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		if (argc == 2)
			argc = parse_string(&stack_a, argv[1]) + 1;
		else
			main_loop(&stack_a, argv, 1);
		if (check_sort(&stack_a))
		{
			free_list(&stack_a);
			return (0);
		}
		index_value(&stack_a, argc - 1, stack_a->data);
		sort_select(&stack_a, &stack_b, argc - 1);
		free_list(&stack_a);
		free_list(&stack_b);
		return (0);
	}
	return (0);
}
