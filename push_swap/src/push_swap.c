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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
	{
		argc = 7;
		argv[1] = "2";
		argv[2] = "1";
		argv[3] = "3";
		argv[4] = "6";
		argv[5] = "5";
		argv[6] = "8";
	}
	if (argc > 1)
	{
		if (valid_args(argv))
			return (1);
		stack_a = NULL;
		stack_b = NULL;
		stack_a = ft_lst_add_argc(stack_a, argc, argv);
		if (!stack_a)
		{
			ft_printf("Error\n");
			return (1);
		}
		ft_printf(" --------------------------\n");
		lst_print(stack_a, stack_b);
		sa(stack_a);
		ft_printf(" --------------------------\n");
		lst_print(stack_a, stack_b);
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		ft_printf(" --------------------------\n");
		lst_print(stack_a, stack_b);
		rr(&stack_a, &stack_b);
		ft_printf(" --------------------------\n");
		lst_print(stack_a, stack_b);
		rrr(&stack_a, &stack_b);
		ft_printf(" ---------- RRR -----------\n");
		lst_print(stack_a, stack_b);
		sa(stack_a);
		ft_printf(" --------------------------\n");
		lst_print(stack_a, stack_b);
		pa(&stack_a, &stack_b);
		pa(&stack_a, &stack_b);
		pa(&stack_a, &stack_b);
		ft_printf(" --------------------------\n");
		lst_print(stack_a, stack_b);
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
	}
	return (0);
}
