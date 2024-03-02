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
		//move this loop
		while (argv[i])
		{
			if (ft_isdigit(argv[i]) == -1)
				error (&stack_a);
			nb = ft_atoi(argv[i]);
			if (nb < -2147483648 || nb > 2147483647)
				error (&stack_a);
			if (!stack_a)//this was changed from i = 1 may need to change back 
				stack_a = ft_lstnew((int)nb);
			else
			{
				ft_lstadd_back(&stack_a, ft_lstnew((int)nb));
				if (check_double((int)nb, &stack_a) == -1)
					error (&stack_a);
			}
			i++;
		}
		if (check_sort(&stack_a)) //is sort retun value changed 
		{
			write(1, "1sorted\n", 8);
			ft_print_list(stack_a, NULL);
			return (0);
		}
		index_value(&stack_a, argc - 1);
		ft_print_list(stack_a, stack_b);//test
		if (argc == 3)
			sa(&stack_a);
		else if (argc == 4)
			sort_3(&stack_a);
		else 
			sort_5(&stack_a, &stack_b);
		ft_print_list(stack_a, stack_b);//test
		return (0);
	}
	else
		error (&stack_a);
}
