/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:17:32 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/09/16 16:17:32 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_freeenv(t_env env)
{
	while (env.next != NULL)
	{
		free(env.key);
		free(env.value);
		env = *env.next;
	}
}
