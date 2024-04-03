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
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (NULL);
}

void	ft_error(char *msg, int signal)
{
	char	*error;

	error = ft_strjoin("pipex: ", msg);
	if (signal == EXIT_SUCCESS)
		ft_printf("%s\n", error);
	else
		perror(error);
	free(error);
	exit(signal);
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
		ft_error("Command not found", 127);
	}
	if (execve(path, cmd, envp) != 0)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		free(path);
		ft_error("Command error", EXIT_FAILURE);
	}
}

int	gnl(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	buffer = (char *)malloc(10000 * sizeof(char));
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

int	open_file(char *file, int i)
{
	int	fd;

	fd = 0;
	if (i == 0)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (i == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (i == 2)
		fd = open(file, O_RDONLY);
	if (fd == EXIT_FAILURE)
		ft_error("Error open file", EXIT_FAILURE);
	return (fd);
}
