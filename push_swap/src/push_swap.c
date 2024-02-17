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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc > 1)
	{
		if (valid_args(argv))
			return (1);
		stack_a = NULL;
		stack_a = ft_lst_add_argc(stack_a, argc, argv);
		if (!stack_a)
			ft_printf("Error\n");
		else
		{
			ft_printf(" --------- Stacks ---------\n");
			lst_print(stack_a);
		}
	}
	return (0);
}
