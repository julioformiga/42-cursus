/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:07:58 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/03/04 15:07:58 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/push_swap.h"

static int	checker(int check)
{
	if (check)
		ft_printf("OK\n");
	else
	{
		ft_printf("KO\n");
		return (1);
	}
	return (0);
}

static void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(2);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (argc > 1)
	{
		if (valid_args(argv))
			ft_error();
		stack_a = NULL;
		stack_b = NULL;
		stack_a = ft_stack_add_argc(stack_a, argc, argv);
		if (!stack_a)
			ft_error();
		if (!ft_stack_is_sorted(&stack_a))
			ft_stack_sort(&stack_a, &stack_b);
		checker(ft_stack_is_sorted(&stack_a));
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
	}
	return (0);
}
