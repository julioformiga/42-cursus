/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 05:26:49 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/03/03 05:26:49 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_3_sort(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (ft_lstsize((void *)tmp) == 2)
	{
		if (tmp->val > tmp->next->val)
			sa(tmp);
	}
	else if (ft_lstsize((void *)tmp) == 3)
	{
		if ((tmp->val > tmp->next->val && tmp->next->val > tmp->next->next->val)
			|| (tmp->next->next->val > tmp->val && tmp->val > tmp->next->val)
			|| (tmp->next->val > tmp->next->next->val
				&& tmp->val < tmp->next->next->val))
			sa(tmp);
		if (tmp->val > tmp->next->next->val
			&& tmp->next->next->val > tmp->next->val)
			ra(&tmp);
		if (tmp->next->val > tmp->val && tmp->val > tmp->next->next->val)
			rra(&tmp);
	}
	*stack = tmp;
}

void	ft_stack_5_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stackdata	data;

	data = ft_stack_get_data(stack_a);
	while ((*stack_a)->val != data.min && (*stack_a)->val != data.max)
		ra(stack_a);
	pb(stack_a, stack_b);
	if (data.len == 5)
	{
		while ((*stack_a)->val != data.min && (*stack_a)->val != data.max)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	ft_stack_3_sort(stack_a);
	pa(stack_a, stack_b);
	if ((*stack_a)->val > (*stack_a)->next->val)
		ra(stack_a);
	if (data.len == 5)
	{
		pa(stack_a, stack_b);
		while ((*stack_a)->val != data.min)
			ra(stack_a);
	}
}

void	ft_stack_6_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stackdata	data;

	data = ft_stack_get_data(stack_a);
	while ((*stack_a)->val != data.min && (*stack_a)->val != data.max)
		ra(stack_a);
	pb(stack_a, stack_b);
	ft_stack_5_sort(stack_a, stack_b);
	pa(stack_a, stack_b);
	while ((*stack_a)->val != data.min)
		ra(stack_a);
}

void	ft_stack_radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int			i;
	int			j;
	int			n_negative;
	t_stackdata	data;

	i = -1;
	data = ft_stack_get_data(stack_a);
	n_negative = 0;
	if (data.min < 0)
		n_negative = -data.min;
	while (i++, !ft_stack_is_sorted(stack_a))
	{
		j = 0;
		while (j++, j <= data.len)
		{
			if (ft_stack_is_sorted(stack_a))
				break ;
			if (((((*stack_a)->val + n_negative) >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize((void *)*stack_b) != 0)
			pa(stack_a, stack_b);
	}
}
