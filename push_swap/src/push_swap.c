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
#include <limits.h>

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

t_stackdata	ft_stack_get_data(t_stack **stack)
{
	t_stackdata	data;
	t_stack		*tmp;
	int			i;

	tmp = *stack;
	data.len = ft_lstsize((void *)tmp);
	data.min = tmp->val;
	data.max = tmp->val;
	i = -1;
	while (i++, tmp->next)
	{
		if (data.min > tmp->next->val)
			data.min = tmp->next->val;
		if (data.max < tmp->next->val)
			data.max = tmp->next->val;
		if (i == data.len / 2)
			data.pivot = tmp->val;
		tmp = tmp->next;
	}
	return (data);
}

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
	t_stackdata	data;

	i = -1;
	data = ft_stack_get_data(stack_a);
	while (i++, !ft_stack_is_sorted(stack_a))
	{
		j = 0;
		while (j++, j <= data.len)
		{
			if (ft_stack_is_sorted(stack_a))
				break ;
			if (data.min < 0)
				data.min = -data.min;
			if (((((*stack_a)->val + data.min) >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize((void *)*stack_b) != 0)
			pa(stack_a, stack_b);
	}
}

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
	else
		ft_stack_radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (argc > 1)
	{
		if (valid_args(argv))
			return (1);
		stack_a = NULL;
		stack_b = NULL;
		stack_a = ft_stack_add_argc(stack_a, argc, argv);
		if (!stack_a)
		{
			ft_printf("Error\n");
			return (1);
		}
		if (!ft_stack_is_sorted(&stack_a))
			ft_stack_sort(&stack_a, &stack_b);
		if (!ft_stack_is_sorted(&stack_a))
		{
			ft_printf("KO\n");
			return (1);
		}
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
	}
	return (0);
}
