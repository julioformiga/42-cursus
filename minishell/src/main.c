/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:34:41 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/08/30 13:34:41 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signal = 0;

void	prompt(int signal, char *dir)
{
	char	*prompt;

	prompt = "[minishell@42]";
	if (dir == NULL)
		dir = "~";
	if (signal == 0)
		ft_printf("\033[1;32m%s %s $>\033[0m ", prompt, dir);
	else if (signal == 1)
		ft_printf("\033[1;31m%s %s $>\033[0m ", prompt, dir);
	else
		ft_printf("\033[1;33m%s %s $>\033[0m ", prompt, dir);
}

int	ft_check_exit(char *str)
{
	if (str == NULL)
		return (1);
	if (ft_strncmp(str, "exit", 4) == 0)
		return (0);
	if (ft_strncmp(str, "e", 1) == 0)
		return (0);
	return (1);
}

void	ft_getenv(char **env)
{
	while (*env)
	{
		ft_printf("%s\n", *env);
		env++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*rl;

	(void)argc;
	(void)argv;
	ft_getenv(envp);
	rl = NULL;
	while (1)
	{
		prompt(g_signal, NULL);
		rl = readline("");
		if (!ft_check_exit(rl))
			break ;
		ft_printf("%s\n", rl);
	}
	free(rl);
	return (0);
}
