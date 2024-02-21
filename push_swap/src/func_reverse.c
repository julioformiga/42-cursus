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
	t_stack	*prev;
	t_stack	*current;

	if (*stack_a && (*stack_a)->next)
	{
		current = *stack_a;
		while (current->next != NULL)
		{
			prev = current;
			current = current->next;
		}
		prev->next = NULL;
		current->next = *stack_a;
		*stack_a = current;
		printf("rra\n");
	}
}

void	rrb(t_stack **stack_b)
{
	t_stack	*prev;
	t_stack	*current;

	if (*stack_b && (*stack_b)->next)
	{
		current = *stack_b;
		while (current->next != NULL)
		{
			prev = current;
			current = current->next;
		}
		prev->next = NULL;
		current->next = *stack_b;
		*stack_b = current;
		printf("rra\n");
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
