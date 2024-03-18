/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 05:37:55 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/03/15 05:37:55 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	return (NULL);
}

int	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (path == NULL)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		ft_error("Error");
	}
	if (execve(path, cmd, envp) == -1)
		ft_error("Error");
}

int	gnl(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	buffer = (char *)malloc(10000);
	if (buffer == NULL)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != 0)
	{
		if (c != '\n' && c != 0)
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = 0;
	*line = buffer;
	free(buffer);
	return (r);
}
