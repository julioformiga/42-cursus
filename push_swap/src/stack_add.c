/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:42:23 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/02/17 12:42:23 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_stack_new(int i)
{
	t_stack	*list;

	list = (t_stack *)malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	list->val = i;
	list->next = NULL;
	return (list);
}

t_stack	*ft_stack_add(t_stack *lst, int value)
{
	t_stack	*current;

	if (!lst)
	{
		current = ft_stack_new(value);
		return (current);
	}
	current = lst;
	if (current->val == value)
		return (ft_free_stack(lst));
	while (current->next)
	{
		current = current->next;
		if (current->val == value)
			return (ft_free_stack(lst));
	}
	current->next = (t_stack *)malloc(sizeof(t_stack));
	current->next->val = value;
	current->next->next = NULL;
	current = lst;
	return (current);
}

void	ft_print_stack(t_stack *stack_a)
{
	while (stack_a)
	{
		ft_printf("%d\n", stack_a->val);
		stack_a = stack_a->next;
	}
	ft_printf("__\n");
	ft_printf(" a\n");
}

void	ft_print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a)
	{
		if (stack_b)
		{
			ft_printf("% 13d %d\n", stack_a->val, stack_b->val);
			stack_b = stack_b->next;
		}
		else
		{
			ft_printf("% 13d\n", stack_a->val);
		}
		stack_a = stack_a->next;
	}
	ft_printf("           __ __\n");
	ft_printf("            a b\n");
}

static t_stack	*ft_stack_add_check(t_stack *stack, char **numbers)
{
	int		i;

	if (numbers)
	{
		i = -1;
		while (i++, numbers[i])
		{
			if (ft_check_int_out_of_range(numbers[i]))
			{
				ft_free_stack(stack);
				return (NULL);
			}
			stack = ft_stack_add(stack, ft_atoi(numbers[i]));
			if (!stack)
				return (NULL);
		}
	}
	return (stack);
}

t_stack	*ft_stack_add_argc(t_stack *stack, int argc, char **argv)
{
	int		i;
	char	**args_space;

	i = 0;
	while (i++, i < argc)
	{
		if (ft_has_blank(argv[i]))
		{
			argv[i] = ft_replace(argv[i], '\t', ' ');
			args_space = ft_split(argv[i], ' ');
			stack = ft_stack_add_check(stack, args_space);
			ft_free(args_space);
			if (!stack)
				return (NULL);
		}
		else
			stack = ft_stack_add(stack, ft_atoi(argv[i]));
	}
	return (stack);
}
