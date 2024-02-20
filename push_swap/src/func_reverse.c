/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:31:08 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/02/19 15:31:08 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (stack_a && (*stack_a)->next)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		last = *stack_a;
		while (last->next)
			last = last->next;
		*stack_a = last;
		(*stack_a) = tmp->next;
		ft_printf("rra\n");
	}
}

void	rrb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (stack_b && (*stack_b)->next)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		last = *stack_b;
		while (last->next)
			last = last->next;
		tmp->next = tmp;
		tmp->next = NULL;
		ft_printf("rrb\n");
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
