/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 08:34:04 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/09/18 08:34:04 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cmd_check(char *path, char *cmd)
{
	char	*full_path;
	char	*full_path_cmd;
	char	**paths;
	int		i;

	paths = ft_split(path, ':');
	i = -1;
	while (paths[++i])
	{
		full_path = ft_strjoin(paths[i], "/");
		full_path_cmd = ft_strjoin(full_path, cmd);
		free(full_path);
		if (access(full_path_cmd, X_OK) == 0)
		{
			free_array(paths);
			return (full_path_cmd);
		}
		free(full_path_cmd);
	}
	printf("%s: command not found\n", cmd);
	free_array(paths);
	return (NULL);
}

int	cmd_setup(char *command, t_env *env, char ***args, char **full_path)
{
	char	*path;

	path = env_get(env, "PATH");
	*full_path = cmd_check(path, command);
	if (!*full_path)
		return (1);
	*args = ft_split(command, ' ');
	return (0);
}
