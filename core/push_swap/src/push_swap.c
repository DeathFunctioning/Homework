#include <push_swap.h>

int	main(int argc, char **argv)
{
	int		j;
	t_list	*stack_a; 

	j = 1;
	if (argc > 1)
	{
		while(argv[j])
		{
			if (j == 1)
				stack_a = ft_lstnew(ft_atoi(argv[j]));
			else
				ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[j])));
			j++;
		}
		//remove testing swap functions

		ft_print_list(stack_a);//remove testing
		ra(&stack_a);
		ft_print_list(stack_a);//remove testing
		rra(&stack_a);
		ft_print_list(stack_a);//remove testing
		return (0);
	}
		write(1, "Error\n", 6);
		return (1);
}

