/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:29:45 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/09/16 15:29:45 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	ft_initenv(char **envp)
{
	t_env	*env;
	t_env	*tmp;
	int		i;

	env = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		tmp = malloc(sizeof(t_env));
		tmp->key = ft_strndup(envp[i], ft_strchr(envp[i], '=') - envp[i]);
		tmp->value = ft_strdup(ft_strchr(envp[i], '=') + 1);
		tmp->next = env;
		env = tmp;
		i++;
	}
	return (*env);
}

int	ft_setenv(t_env env, char *key, char *value)
{
	while (env.next != NULL)
	{
		if (ft_strncmp(env.key, key, ft_strlen(key)) == 0)
		{
			free(env.value);
			env.value = ft_strdup(value);
			return (0);
		}
		env = *env.next;
	}
	return (1);
}

char	*ft_getenv(t_env env, char *key)
{
	while (env.next != NULL)
	{
		if (ft_strncmp(env.key, key, ft_strlen(key)) == 0)
			return (env.value);
		env = *env.next;
	}
	return (NULL);
}

void ft_printenv(t_env env)
{
	while (env.next != NULL)
	{
		ft_printf("%042s = %s\n", env.key, env.value);
		env = *env.next;
	}
}
