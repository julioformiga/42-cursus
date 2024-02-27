/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:25:12 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/02/19 14:25:12 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	int	tmp;

	if (stack_a && stack_a->next)
	{
		tmp = stack_a->val;
		stack_a->val = stack_a->next->val;
		stack_a->next->val = tmp;
	}
	write(1, "sa ", 3);
}

void	sb(t_stack *stack_b)
{
	int	tmp;

	if (stack_b && stack_b->next)
	{
		tmp = stack_b->val;
		stack_b->val = stack_b->next->val;
		stack_b->next->val = tmp;
	}
	write(1, "sb ", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
