/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:43:36 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/03/06 13:43:36 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define ERROR_ARGS "Error: Invalid arguments\n\
Usage: ./pipex <file1> <cmd1> <cmd2> <file2>\n"
# define ERROR_ARGS_BONUS "Error: Invalid arguments\n\
Usage:\t./pipex <file1> <cmd1> <cmd2> <...> <file2>\n\
\t\t./pipex here_doc <limiter> <cmd> <cmd2> <...> <file2>\n"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../lib/ft_printf/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

void	pipex(char *file1, char *file2, char *cmd1, char *cmd2);
void	ft_error(char *msg, int signal);
char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);
int		gnl(char **line);
int		open_file(char *argv, int i);

#endif
