#include "push_swap.h"

void    ft_print_list(t_list *stack_a, t_list *stack_b)
{
        int     i;

        i = 0;
        while (stack_a && stack_b)
        {
                printf("Idx = %i   %i   %i   idx_v_a = %i\n", stack_a->idx_p, stack_a->data, stack_b->data, stack_a->idx_v);
                stack_a = stack_a->next;
                stack_b = stack_b->next;
                i++;
        }
        while (stack_a)
        {
                printf("Idx = %i   %i   X   ind_v_a = %i\n", stack_a->idx_p, stack_a->data, stack_a->idx_v);
                stack_a = stack_a->next;
        }
        while (stack_b)
        {
                printf("B Idx ignore = %i   X   %i\n", i, stack_b->data);
                stack_b = stack_b->next;
        }
        printf("       stack_a  stack_b \n");
}
