/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:19:30 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/04 19:39:37 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_elements(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			if (map->grid[i][j] == 'C')
				map->collectibles++;
			else if (map->grid[i][j] == 'E' && ++map->exits)
			{
				map->exit.x = j;
				map->exit.y = i;
			}
			else if (map->grid[i][j] == 'P' && ++map->players)
			{
				map->player.x = j;
				map->player.y = i;
			}
		}
	}
	if (map->collectibles < 1 || map->players != 1 || map->exits != 1)
		error_handler(map->grid, "Invalid elements in map.", EXIT_FAILURE);
}
