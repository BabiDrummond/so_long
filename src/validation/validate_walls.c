/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:17:13 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/07 17:47:36 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_walls(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			if ((i == 0 || i == map->rows - 1)
				&& map->grid[i][j] != '1')
				error_handler(map->grid, "Map missing walls.", EXIT_FAILURE);
			else if ((j == 0 || j == map->cols - 1)
				&& map->grid[i][j] != '1')
				error_handler(map->grid, "Map missing walls.", EXIT_FAILURE);
		}
	}
}
