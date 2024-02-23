/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:53:41 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/12/13 14:53:41 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

int	ft_stack_is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_stack_sort_short(t_stack *stack)
{
	int		i;
	int		size;
	t_stack	*tmp;

	size = ft_lstsize((void *)stack) + 1;
	i = size;
	tmp = stack;
	while (size--, size > 0 && stack->next)
	{
		while (i--, i > 0 && tmp->next)
		{
			if (tmp->val > tmp->next->val)
				sa(tmp);
			tmp = tmp->next;
		}
		tmp = stack;
		i = size - 1;
	}
}

void	sort_test(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf(" --------------------------\n");
	ft_print_stacks(stack_a, stack_b);
	sa(stack_a);
	ft_printf(" --------------------------\n");
	ft_print_stacks(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	ft_printf(" --------------------------\n");
	ft_print_stacks(stack_a, stack_b);
	rr(&stack_a, &stack_b);
	ft_printf(" --------------------------\n");
	ft_print_stacks(stack_a, stack_b);
	rrr(&stack_a, &stack_b);
	ft_printf(" --------------------------\n");
	ft_print_stacks(stack_a, stack_b);
	sa(stack_a);
	ft_printf(" --------------------------\n");
	ft_print_stacks(stack_a, stack_b);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	ft_printf(" --------------------------\n");
	ft_print_stacks(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
	{
		argc = 6;
		argv[1] = "2";
		argv[2] = "1";
		argv[3] = "3";
		argv[4] = "0";
		argv[5] = "-5";
	}
	if (argc > 1)
	{
		if (valid_args(argv))
			return (1);
		stack_a = NULL;
		stack_b = NULL;
		stack_a = ft_stack_add_argc(stack_a, argc, argv);
		if (!stack_a)
		{
			ft_printf("Error\n");
			return (1);
		}
		ft_stack_sort_short(stack_a);
		ft_printf("--------------\n");
		ft_print_stack(stack_a);
		if (ft_stack_is_sorted(stack_a))
			ft_printf("OK\n");
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
	}
	return (0);
}
