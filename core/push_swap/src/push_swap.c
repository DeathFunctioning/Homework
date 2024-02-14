#include <push_swap.h>

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
				stack_a = ft_lstnew((int)nb);
			else
			{
				ft_lstadd_back(&stack_a, ft_lstnew((int)nb));
				if (check_double((int)nb, &stack_a) == -1)
					error (&stack_a);
			}
			i++;
		}
		ft_print_list(stack_a);
		if (check_sort(&stack_a) == -1)
			write(1, "not sorted\n", 11);
		else
			write(1, "sorted\n", 7);
		ft_print_list(stack_a);
		ra(&stack_a);
		ft_print_list(stack_a);
		rra(&stack_a);
		ft_print_list(stack_a);
		sa(&stack_a);
		ft_print_list(stack_a);
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		pa(&stack_a, &stack_b);
		ft_print_list(stack_a);
		ft_print_list(stack_b);
		return (0);
	}
	else
		error (&stack_a);
}
