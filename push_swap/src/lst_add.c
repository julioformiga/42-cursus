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

static t_stack	*lst_new(int i)
{
	t_stack	*list;

	list = (t_stack *)malloc(sizeof(t_stack));
	if (list == NULL)
		return (NULL);
	list->val = i;
	list->next = NULL;
	return (list);
}

t_stack	*lst_add(t_stack *lst, int value)
{
	t_stack	*current;

	if (!lst)
	{
		current = lst_new(value);
		return (current);
	}
	current = lst;
	if (current->val == value)
		return (NULL);
	while (current->next)
	{
		current = current->next;
		if (current->val == value)
			return (NULL);
	}
	current->next = (t_stack *)malloc(sizeof(t_stack));
	current->next->val = value;
	current->next->next = NULL;
	current = lst;
	return (current);
}

void	lst_print(t_stack *lst)
{
	while (lst)
	{
		ft_printf("% 13d\n", lst->val);
		lst = lst->next;
	}
	ft_printf("           __\n");
	ft_printf("            a\n");
}

static t_stack	*ft_lst_add_check(t_stack *stack, char **numbers)
{
	int		i;

	if (numbers)
	{
		i = -1;
		while (i++, numbers[i])
		{
			if (ft_check_int_out_of_range(numbers[i]))
				return (NULL);
			stack = lst_add(stack, ft_atoi(numbers[i]));
			if (!stack)
				return (NULL);
		}
	}
	return (stack);
}

t_stack	*ft_lst_add_argc(t_stack *stack, int argc, char **argv)
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
			stack = ft_lst_add_check(stack, args_space);
			if (!stack)
				return (NULL);
		}
		else
			stack = lst_add(stack, ft_atoi(argv[i]));
	}
	return (stack);
}
