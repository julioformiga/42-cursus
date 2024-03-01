/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:31:16 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/02/19 15:31:16 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack_a && (*stack_a)->next)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		last = *stack_a;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack_b && (*stack_b)->next)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		last = *stack_b;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
