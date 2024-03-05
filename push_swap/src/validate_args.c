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

static int	check_string_arg(const char *str)
{
	int	i;

	if ((ft_strlen(str) == 1 && !ft_isdigit(str[0])) || str[0] == 0)
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

static int	check_string_with_space(char *str)
{
	char	**args_space;
	char	*tmp;
	int		i;

	tmp = ft_replace(str, '\t', ' ');
	args_space = ft_split(tmp, ' ');
	if (args_space)
	{
		i = 0;
		while (i++, args_space[i])
			if (check_string_arg(args_space[i]))
				return (1);
		ft_free(args_space);
	}
	return (0);
}

int	valid_args(char **args)
{
	int		i;

	i = 0;
	while (i++, args[i])
	{
		if (ft_has_blank(args[i]))
		{
			if (check_string_with_space(args[i]))
				return (1);
		}
		else
			if (check_string_arg(args[i]))
				return (1);
	}
	return (0);
}
