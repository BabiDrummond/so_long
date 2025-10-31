/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:20:30 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/31 20:40:21 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_walls(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->grid[++i])
	{
		j = -1;
		while (map->grid[i][++j])
		{
			if ((i == 0 || i == map->height - 1) && map->grid[i][j] != '1')
				error_handler(map->grid, "Map missing walls.", EXIT_FAILURE);
			else if ((j == 0 || j == map->width - 1) && map->grid[i][j] != '1')
				error_handler(map->grid, "Map missing walls.", EXIT_FAILURE);
		}
	}
}
