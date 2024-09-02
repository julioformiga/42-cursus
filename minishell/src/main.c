/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:34:41 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/08/30 13:34:41 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	size_t	len;
	ssize_t	read;

	line = NULL;
	len = 0;
	(void)argc;
	(void)argv;
	(void)envp;
	while (1)
	{
		ft_printf("\033[1;32m[🟢 42-minishell] $>\033[0m ");
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (feof(stdin))
				break ;
			perror("getline");
			break ;
		}
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		if (ft_strncmp(line, "exit", 4) == 0
			&& (line[4] == '\0' || line[4] == ' '))
			break ;
		if (system(line) == -1)
			perror("system");
	}
	free(line);
	return (0);
}
