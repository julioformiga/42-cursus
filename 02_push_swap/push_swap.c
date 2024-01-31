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

char	*ft_replace(char *str, char s, char r)
{
	int	i;

	i = -1;
	while (i++, str[i])
		if (str[i] == s)
			str[i] = r;
	return (str);
}

int	ft_isblank(char c)
{
	if (c == ' ' || c == '\t')
		return (0);
	return (1);
}

int	has_blank(const char *str)
{
	int	i;

	i = -1;
	while (i++, str[i])
		if (ft_isblank(str[i]))
			return (1);
	return (0);
}

int	check_arg(char *str)
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
	int		arg_number;
	char	*arg;
	char	**args_space;

	i = 0;
	arg_number = 1;
	ft_printf("-----------------------\n");
	ft_printf("Validating arguments...\n");
	while (i++, args[i])
	{
		if (has_blank(args[i]))
		{
			args[i] = ft_replace(args[i], '\t', ' ');
			args_space = ft_split(args[i], ' ');
			if (args_space)
			{
				arg_number--;
				while (arg_number++, *args_space)
				{
					ft_printf("%d:\t[%s]", arg_number, *args_space);
					if (check_arg(*args_space))
						ft_printf("\tError: invalid argument\n");
					else
						ft_printf("\tOK\n");
					args_space++;
				}
			}
		}
		else
		{
			arg = args[i];
			ft_printf("  %d:\t[%s]", arg_number, arg);
			if (check_arg(*args_space))
				ft_printf("\tError: invalid argument\n");
			else
				ft_printf("\tOK\n");
			arg_number++;
		}
	}
	ft_printf("-----------------------\n");
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc > 1)
	{
		while (i++, i < argc)
		{
			ft_printf("%d: %s\n", i, argv[i]);
		}
	}
	valid_args(argv);
	return (0);
}
