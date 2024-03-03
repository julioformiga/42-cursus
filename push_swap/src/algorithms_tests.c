/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_tests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:37:10 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/03/03 13:37:10 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_bubblesort(t_stack **stack)
{
	int		i;
	int		size;
	t_stack	*tmp;

	size = ft_lstsize((void *)*stack) + 1;
	i = size;
	tmp = *stack;
	while (size--, size > 0 && (*stack)->next)
	{
		while (i--, i > 0 && tmp->next)
		{
			if (tmp->val > tmp->next->val)
				sa(tmp);
			tmp = tmp->next;
		}
		tmp = *stack;
		i = size - 1;
	}
}
/*
static void	ft_check_tops(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a)
		if ((*stack_a)->val > (*stack_a)->next->val)
			sa(*stack_a);
	if (*stack_b)
		if ((*stack_b)->val < (*stack_b)->next->val)
			sb(*stack_b);
}

void	ft_stack_insertion_sort(t_stack **stack_a, t_stack **stack_b)
{
	// int			j = 0;
	// t_stackdata	data;
	t_stackdata	a;

	// data = ft_stack_get_data(stack_a);
	// ft_printf("\npivot: %d\n\n", data.pivot);
	// ft_print_stacks(stack_a, stack_b);
	// while (j++, j < 18)
	while (!ft_stack_is_sorted(stack_a))
	{
		while (*stack_a)
		{
			if (*stack_b)
			{
				a = ft_stack_get_data(stack_a);
				if ((*stack_a)->val < (*stack_b)->val
					|| (*stack_a)->val > a.max)
					pb(stack_a, stack_b);
				else if ((*stack_b)->val > a.min)
					ra(stack_a);
				else
					pb(stack_a, stack_b);
			}
			else
				pb(stack_a, stack_b);
		}
		// ft_print_stacks(stack_a, stack_b);
		ft_check_tops(stack_a, stack_b);
		while (*stack_b)
		{
			if (*stack_a)
			{
				a = ft_stack_get_data(stack_b);
				if ((*stack_b)->val < (*stack_a)->val
					|| (*stack_b)->val > a.max)
					pa(stack_a, stack_b);
				else if ((*stack_a)->val > a.min)
					rb(stack_b);
				else
					pa(stack_a, stack_b);
			}
			else
				pa(stack_a, stack_b);
		}
		ft_check_tops(stack_a, stack_b);
		// ft_print_stacks(stack_a, stack_b);
		*stack_a = (*stack_a)->next;
	}
}
*/
