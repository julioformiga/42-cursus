/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:35:52 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/02/27 10:35:52 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack_a)
{
	while (stack_a)
	{
		ft_printf("%d ", stack_a->val);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
	// ft_printf("__\n");
	// ft_printf(" a\n");
}

void	ft_print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a)
	{
		if (stack_b)
		{
			ft_printf("% 13d %d\n", stack_a->val, stack_b->val);
			stack_b = stack_b->next;
		}
		else
		{
			ft_printf("% 13d\n", stack_a->val);
		}
		stack_a = stack_a->next;
	}
	ft_printf("           __ __\n");
	ft_printf("            a b\n");
}
