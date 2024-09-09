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

#include "libft.h"
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

void	ft_getenv(char **env)
{
	while (*env)
	{
		// ft_printf("%s\n", *env);
		env++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*rl;
	char	*prompt_out;

	(void)argc;
	(void)argv;
	ft_getenv(envp);
	rl = NULL;
	while (1)
	{
		prompt_out = prompt(g_signal, "src/");
		rl = readline(prompt_out);
		free(prompt_out);
		if (!ft_check_exit(rl))
			break ;
		ft_printf("%s\n", rl);
		free(rl);
	}
	return (0);
}
