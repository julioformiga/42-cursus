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

t_env	*ft_envinit(char **envp)
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
		if (!tmp->key || !tmp->value)
		{
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			return (NULL);
		}
		tmp->next = env;
		env = tmp;
		i++;
	}
	return (env);
}

int	ft_envset(t_env *env, char *key, char *value)
{
	while (env != NULL)
	{
		if (ft_strncmp(env->key, key, ft_strlen(key)) == 0)
		{
			free(env->value);
			env->value = ft_strdup(value);
			return (0);
		}
		env = env->next;
	}
	return (1);
}

char	*ft_envget(t_env *env, char *key)
{
	while (env != NULL)
	{
		if (ft_strncmp(env->key, key, ft_strlen(key)) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

void	ft_envprint(t_env *env)
{
	while (env != NULL)
	{
		ft_printf("%042s = %s\n", env->key, env->value);
		env = env->next;
	}
}
