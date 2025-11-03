/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:41:49 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/03 19:43:40 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *map)
{
	map->collectibles = 0;
	map->players = 0;
	map->exits = 0;
	map->init.x = 0;
	map->init.y = 0;
	map->end.x = 0;
	map->end.y = 0;
	map->height = 0;
	map->width = 0;
}
