/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:53:30 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/07 17:41:20 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(t_map *map, int row, int col)
{
	if (!map->exits && !map->collectibles)
		return (TRUE);
	if (map->grid[row][col] == 'E')
		map->exits--;
	if (map->grid[row][col] == 'X'
		|| map->grid[row][col] == 'Y'
		|| map->grid[row][col] == 'Z')
		map->collectibles--;
	if (map->grid[row][col] == '1')
		return (FALSE);
	map->grid[row][col] = '1';
	if (flood_fill(map, row - 1, col)
		|| flood_fill(map, row, col + 1)
		|| flood_fill(map, row + 1, col)
		|| flood_fill(map, row, col - 1))
		return (TRUE);
	return (FALSE);
}

void	validate_path(t_map *map)
{
	t_map	map_dup;

	map_dup.grid = ft_matrix_dup(map->grid);
	map_dup.collectibles = map->collectibles;
	map_dup.exits = map->exits;
	if (!flood_fill(&map_dup, map->player.y, map->player.x)
		&& !ft_matrix_free(map_dup.grid))
		error_handler(map->grid, "No valid path.", EXIT_FAILURE);
	ft_matrix_free(map_dup.grid);
}
