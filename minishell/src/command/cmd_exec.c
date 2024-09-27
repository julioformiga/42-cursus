/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 01:42:07 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/09/23 01:42:07 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cmd_create_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}
	return (0);
}

static int	cmd_fork(char *full_path, char **args, int pipefd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		execve(full_path, args, NULL);
		perror("execve");
		exit(1);
	}
	return (pid);
}

static void	cmd_parent_process(int pipefd[2])
{
	char	buffer[4096];
	ssize_t	bytes_read;

	close(pipefd[1]);
	bytes_read = read(pipefd[0], buffer, sizeof(buffer) - 1);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		printf("%s", buffer);
		bytes_read = read(pipefd[0], buffer, sizeof(buffer) - 1);
	}
	close(pipefd[0]);
}

void	cmd_exec_inline(int argc, char **argv, t_env **env, t_cmd *cmd)
{
	extern int	g_signal;

	if (argc == 3 && argv[1] && ft_strncmp(argv[1], "-c", 3) == 0)
	{
		cmd_init(cmd, argv[2]);
		g_signal = cmd_exec(argv[2], *env);
		free(cmd);
		env_free(*env);
		free(*env);
		exit(g_signal);
	}
	else if (argc > 1)
	{
		printf("Usage:\n./minishell\nOR\n./minishell -c \"command\"\n");
		free(cmd);
		g_signal = 2;
	}
}

int	cmd_exec(char *command, t_env *env)
{
	char	*full_path;
	char	**args;
	int		status;
	int		pipefd[2];
	pid_t	pid;

	if (cmd_setup(command, env, &args, &full_path) != 0)
		return (1);
	if (cmd_create_pipe(pipefd) != 0)
	{
		free_array(args);
		free(full_path);
		return (1);
	}
	pid = cmd_fork(full_path, args, pipefd);
	if (pid > 0)
	{
		cmd_parent_process(pipefd);
		waitpid(pid, &status, 0);
	}
	free_array(args);
	free(full_path);
	if (pid == -1)
		return (1);
	return (WEXITSTATUS(status));
}