/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:09:45 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/02/02 15:09:45 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_string_arg(char *str)
{
	int	i;

	if (ft_strlen(str) == 1 && !ft_isdigit(str[0]))
		return (1);
	if (ft_strlen(str) > 1)
	{
		if (!ft_strchr(VALID_CHARS, str[0]))
			return (1);
		i = 0;
		while (i++, str[i])
			if (!ft_isdigit(str[i]))
				return (1);
	}
	return (0);
}

int	valid_args(char **args)
{
	int		i;
	char	**args_space;

	i = 0;
	while (i++, args[i])
	{
		if (has_blank(args[i]))
		{
			args[i] = ft_replace(args[i], '\t', ' ');
			args_space = ft_split(args[i], ' ');
			if (args_space)
			{
				while (*args_space)
				{
					if (check_string_arg(*args_space))
						return (1);
					args_space++;
				}
			}
		}
		else
			if (check_string_arg(*args_space))
				return (1);
	}
	return (0);
}
