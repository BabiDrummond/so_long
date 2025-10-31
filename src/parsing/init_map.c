/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:41:49 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/30 19:41:58 by bmoreira         ###   ########.fr       */
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
	map->size.x = 0;
	map->size.y = 0;
}
