/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:02:52 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/03/18 19:02:52 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	pid_main(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_error("Pipe error", EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		ft_error("Fork error", EXIT_FAILURE);
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		execute(argv, envp);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
	}
}

static void	here_doc(char *limiter, int argc)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	if (argc < 6)
		ft_error(ERROR_ARGS_BONUS, EXIT_FAILURE);
	if (pipe(fd) == -1)
		ft_error("Pipe error", EXIT_FAILURE);
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (gnl(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		wait(NULL);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	file_input;
	int	file_output;

	if (argc < 5)
		ft_error(ERROR_ARGS_BONUS, EXIT_SUCCESS);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		i = 3;
		file_output = open_file(argv[argc - 1], 0);
		here_doc(argv[2], argc);
	}
	else
	{
		i = 2;
		file_output = open_file(argv[argc - 1], 1);
		file_input = open_file(argv[1], 2);
		dup2(file_input, STDIN_FILENO);
	}
	while (i < argc - 2)
		pid_main(argv[i++], envp);
	dup2(file_output, STDOUT_FILENO);
	close(file_output);
	execute(argv[argc - 2], envp);
	return (0);
}
