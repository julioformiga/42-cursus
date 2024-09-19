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

char	*prompt(int signal, t_env *env)
{
	char	*prompt;
	char	*prompt_ini;
	char	*dir;
	char	*dir_home;
	char	*rl;

	dir = ft_env_get(env, "PWD");
	dir_home = ft_env_get(env, "HOME");
	if (ft_strncmp(dir, dir_home, ft_strlen(dir_home)) == 0)
		dir = ft_strjoin("~", dir + ft_strlen(dir_home));
	if (signal == 0)
		prompt_ini = ft_strjoin("\033[1;32m[minishell@42] ", dir);
	else if (signal == 1)
		prompt_ini = ft_strjoin("\033[1;31m[minishell@42] ", dir);
	else
		prompt_ini = ft_strjoin("\033[1;33m[minishell@42] ", dir);
	prompt = ft_strjoin(prompt_ini, " $>\033[0m ");
	free(prompt_ini);
	free(dir);
	rl = readline(prompt);
	free(prompt);
	return (rl);
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
	t_env	*env;
	char	*rl;
	char	*command;

	(void)argc;
	(void)argv;
	env = ft_env_init(envp);
	rl = NULL;
	while (1)
	{
		rl = prompt(g_signal, env);
		if (!ft_check_exit(rl))
			break ;
		if (rl && *rl)
		{
			command = ft_strtrim(rl, " \t\n\r");
			if (command)
			{
				ft_cmd_exec(command, env);
				free(command);
			}
		}
		free(rl);
	}
	ft_env_free(env);
	return (0);
}
