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

char	*prompt(int signal, char *dir)
{
	char	*prompt;
	char	*prompt_ini;

	if (dir == NULL)
		dir = "~";
	if (signal == 0)
		prompt_ini = ft_strjoin("\033[1;32m[minishell@42] ", dir);
	else if (signal == 1)
		prompt_ini = ft_strjoin("\033[1;31m[minishell@42] ", dir);
	else
		prompt_ini = ft_strjoin("\033[1;33m[minishell@42] ", dir);
	prompt = ft_strjoin(prompt_ini, " $>\033[0m ");
	free(prompt_ini);
	return (prompt);
}

int	ft_check_exit(char *str)
{
	if (str == NULL)
		return (1);
	if (ft_strncmp(str, "exit", 4) == 0 && ft_strlen(str) == 4)
		return (0);
	if (ft_strncmp(str, "e", 1) == 0 && ft_strlen(str) == 1)
		return (0);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_env	env;
	char	*rl;
	char	*prompt_out;
	char	*dir;
	char	*dir_home;

	(void)argc;
	(void)argv;
	env = ft_initenv(envp);
	ft_printenv(env);
	rl = NULL;
	while (1)
	{
		dir = ft_getenv(env, "PWD");
		dir_home = ft_getenv(env, "HOME");
		if (ft_strncmp(dir, dir_home, ft_strlen(dir_home)) == 0)
			prompt_out = prompt(g_signal,
					ft_strjoin("~", dir + ft_strlen(dir_home)));
		else
			prompt_out = prompt(g_signal, dir);
		rl = readline(prompt_out);
		free(prompt_out);
		if (!ft_check_exit(rl))
			break ;
		ft_printf("%s\n", rl);
		free(rl);
	}
	ft_freeenv(env);
	return (0);
}
