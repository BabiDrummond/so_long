/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:41:49 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/07 19:01:39 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init_values(t_map *map)
{
	map->collectibles = 0;
	map->players = 0;
	map->exits = 0;
	map->monsters = 0;
	map->rows = 0;
	map->cols = 0;
	map->player.x = 0;
	map->player.y = 0;
	map->exit.x = 0;
	map->exit.y = 0;
	map->monsters = 0;
}
