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

void	ft_error(char *msg, int signal)
{
	if (signal == EXIT_SUCCESS)
		ft_printf("%s\n", msg);
	else
		perror(msg);
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
		ft_error(path, EXIT_FAILURE);
	}
	if (execve(path, cmd, envp) == -1)
		ft_error(cmd[0], EXIT_FAILURE);
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

int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0644);
	if (file == -1)
		ft_error("Error open file", EXIT_FAILURE);
	return (file);
}
