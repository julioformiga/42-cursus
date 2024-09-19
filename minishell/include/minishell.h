/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:35:35 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/08/30 14:35:35 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <stdbool.h>
# include <string.h>
# include <termios.h>
# include <curses.h>
# include <dirent.h>

extern int	g_signal;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

char	*ft_strndup(const char *s1, size_t n);

t_env	*ft_envinit(char **envp);
char	*ft_envget(t_env *env, char *key);
void	ft_envprint(t_env *env);
void	ft_envfree(t_env *env);

char	*ft_cmd_check(char *path, char *cmd);
int		ft_cmd_exec(char *command, t_env *env);

#endif
