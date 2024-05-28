/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:22:05 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/05/28 17:22:05 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_map_init(t_map *map, int n)
{
	map->width = 0;
	map->height = 0;
	map->min = 0;
	map->max = 0;
	map->data = (int **)malloc(n * sizeof(int *));
	ft_memset(map->data, 0, n * sizeof(int *));
}
