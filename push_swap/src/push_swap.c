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

int	ft_stack_is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
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

	tmp = *stack;
	data.size = ft_lstsize((void *)tmp);
	data.min = tmp->val;
	data.max = tmp->val;
	while (tmp->next)
	{
		if (data.min > tmp->next->val)
			data.min = tmp->next->val;
		if (data.max < tmp->next->val)
			data.max = tmp->next->val;
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
	if (data.size == 5)
	{
		while ((*stack_a)->val != data.min && (*stack_a)->val != data.max)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	ft_stack_3_sort(stack_a);
	pa(stack_a, stack_b);
	if ((*stack_a)->val > (*stack_a)->next->val)
		ra(stack_a);
	if (data.size == 5)
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
	pb(stack_a, stack_b);
	ft_stack_5_sort(stack_a, stack_b);
	pa(stack_a, stack_b);
	while ((*stack_a)->val != data.min)
		ra(stack_a);
}

void	ft_stack_bubblesort(t_stack *stack)
{
	int		i;
	int		size;
	t_stack	*tmp;

	size = ft_lstsize((void *)stack) + 1;
	i = size;
	tmp = stack;
	while (size--, size > 0 && stack->next)
	{
		while (i--, i > 0 && tmp->next)
		{
			if (tmp->val > tmp->next->val)
				sa(tmp);
			tmp = tmp->next;
		}
		tmp = stack;
		i = size - 1;
	}
}

void	ft_stack_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize((void *)*stack_a);
	if (size == 2 && (*stack_a)->val > (*stack_a)->next->val)
		sa(*stack_a);
	else if (size == 3)
		ft_stack_3_sort(stack_a);
	else if (size == 4 || size == 5)
		ft_stack_5_sort(stack_a, stack_b);
	else if (size == 6)
		ft_stack_6_sort(stack_a, stack_b);
	else
		ft_stack_bubblesort(*stack_a);
	if (!ft_stack_is_sorted(*stack_a))
	{
		ft_print_stack(*stack_a);
		ft_printf("\t\t\t\033[1;31m[KO]\033[0m\n");
	}
	else
		ft_printf("\n\t\t\t\033[1;32m[OK]\033[0m\n");
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (argc == 1)
	{
		argc = 7;
		argv[1] = "2";
		argv[2] = "4";
		argv[3] = "3";
		argv[4] = "1";
		argv[5] = "5";
		argv[6] = "8";
	}
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
		if (!ft_stack_is_sorted(stack_a))
			ft_stack_sort(&stack_a, &stack_b);
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
	}
	return (0);
}
