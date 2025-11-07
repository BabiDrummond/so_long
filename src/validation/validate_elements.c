/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:17:13 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/07 17:51:39 by bmoreira         ###   ########.fr       */
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
			else if (map->grid[i][j] == 'P')
				map->players++;
			else if (map->grid[i][j] == 'E')
				map->exits++;
			else if (map->grid[i][j] == 'M')
				map->monsters++;
		}
	}
	if (map->collectibles < 1 || map->monsters < 1
		 || map->players != 1 || map->exits != 1)
		error_handler(map->grid, "Invalid elements in map.", EXIT_FAILURE);
}
