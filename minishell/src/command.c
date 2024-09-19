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

static void	ft_free_array(char **array)
{
	int	i;

	i = -1;
	if (array)
	{
		while (array[++i])
			free(array[i]);
		free(array);
	}
}

char	*ft_cmd_check(char *path, char *cmd)
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
			ft_free_array(paths);
			return (full_path_cmd);
		}
		free(full_path_cmd);
	}
	ft_free_array(paths);
	return (NULL);
}

int	ft_cmd_exec(char *command, t_env *env)
{
	char	*path;
	char	*full_path;

	path = ft_env_get(env, "PATH");
	if (path)
	{
		full_path = ft_cmd_check(path, command);
		if (full_path)
		{
			printf("%s is in PATH\n", full_path);
			free(full_path);
			return (0);
		}
		else
			printf("%s is not in PATH\n", command);
	}
	return (0);
}
