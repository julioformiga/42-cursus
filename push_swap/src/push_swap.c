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
	int		i;

	if (argc > 1)
	{
		if (valid_args(argv))
			ft_printf("Error\n");
		else
		{
			i = 0;
			while (i++, i < argc)
			{
				ft_printf("%d: %s\n", i, argv[i]);
			}
		}
	}
	return (0);
}
