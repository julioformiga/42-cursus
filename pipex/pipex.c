/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:52:40 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/03/06 13:52:40 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	ft_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (1);
}

int	ft_fork_error(char *msg)
{
	perror(msg);
	exit (EXIT_FAILURE);
}

void	pipex(char *file1, char *file2, char *cmd1, char *cmd2)
{
	int		fd[2];
	pid_t	pid;

	fd[0] = open(file1, O_RDONLY);
	fd[1] = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipe(fd) == -1)
		ft_error("Error: pipe failed\n");
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	// close(fd[0]);
	// close(fd[1]);
	pid = fork();
	if (pid == -1)
		ft_fork_error("Error: fork failed\n");
	if (pid == 0)
	{
		ft_printf("This is the child process  (pid: %d)\n", getpid());
	}
	else
	{
		wait(NULL);
		ft_printf("This is the parent process (pid: %d)\n", getpid());
	}
	waitpid(pid, NULL, 0);
	(void)cmd1;
	(void)cmd2;
}

int	main(int argc, char *argv[])
{
	// argc = 5;
	// argv[0] = "pipex";
	// argv[1] = "input.txt";
	// argv[2] = "cat";
	// argv[3] = "wc";
	// argv[4] = "output.txt";
	if (argc != 5)
		return (ft_error("Error: wrong number of arguments\n"));
	ft_printf("input: %s\n", argv[1]);
	ft_printf("cmd1: %s\n", argv[2]);
	ft_printf("cmd2: %s\n", argv[3]);
	ft_printf("output: %s\n", argv[4]);
	pipex(argv[1], argv[4], argv[2], argv[3]);
	return (0);
}
