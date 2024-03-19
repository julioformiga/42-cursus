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

#include "../include/pipex.h"

void	pid_child(char **argv, char **envp, int *fd)
{
	int	input_file;

	input_file = open(argv[1], O_RDONLY);
	if (input_file == -1)
		ft_error("Error: open failed", EXIT_FAILURE);
	dup2(fd[1], STDOUT_FILENO);
	dup2(input_file, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

void	pid_parent(char **argv, char **envp, int *fd)
{
	int	output_file;

	output_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	if (output_file == -1)
		ft_error("Error: open failed", EXIT_FAILURE);
	dup2(fd[0], STDIN_FILENO);
	dup2(output_file, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

int	main(int argc, char *argv[], char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (argc != 5)
		ft_error(ERROR_ARGS, EXIT_SUCCESS);
	if (pipe(fd) == -1)
		ft_error("Error: pipe failed", EXIT_FAILURE);
	pid1 = fork();
	if (pid1 == -1)
		ft_error("Error: fork failed", EXIT_FAILURE);
	if (pid1 == 0)
		pid_child(argv, envp, fd);
	waitpid(pid1, NULL, 0);
	pid_parent(argv, envp, fd);
	return (0);
}
