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
}

void	ft_print_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stackdata	data_a;
	t_stackdata	data_b;
	int			size;

	data_a.len = 0;
	if (*stack_a)
		data_a = ft_stack_get_data(stack_a);
	data_b.len = 0;
	if (*stack_b)
		data_b = ft_stack_get_data(stack_b);
	size = data_a.len;
	if (data_b.len > data_a.len)
		size = data_b.len;
	ft_printf("stacks:\n");
	while (size--, size > -1)
	{
		if (*stack_a)
		{
			ft_printf("% 13d", (*stack_a)->val);
			stack_a = &(*stack_a)->next;
		}
		else
			ft_printf("% 13s", "[]");
		if (*stack_b)
		{
			ft_printf(" %d\n", (*stack_b)->val);
			stack_b = &(*stack_b)->next;
		}
		else
			ft_printf(" %s\n", "[]");
	}
	ft_printf("           __ __\n");
	ft_printf("            a b\n");
}
