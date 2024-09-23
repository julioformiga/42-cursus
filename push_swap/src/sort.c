/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:33:35 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/03/03 13:33:35 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_is_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_stack_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stackdata	data;

	data = ft_stack_get_data(stack_a);
	if (data.len == 2 && (*stack_a)->val > (*stack_a)->next->val)
		sa(*stack_a);
	else if (data.len == 3)
		ft_stack_3_sort(stack_a);
	else if (data.len <= 5)
		ft_stack_5_sort(stack_a, stack_b);
	else if (data.len == 6)
		ft_stack_6_sort(stack_a, stack_b);
	else if (data.len <= 100)
		ft_stack_radix_sort(stack_a, stack_b);
	else
		ft_stack_radix_sort(stack_a, stack_b);
}
