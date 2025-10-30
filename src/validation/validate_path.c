/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:53:30 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/30 18:33:49 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(char **map, int row, int col, int *collectibles)
{
	if (map[row][col] == 'E' && !*collectibles)
		return (TRUE);
	if (map[row][col] == 'C')
		(*collectibles)--;
	if (map[row][col] == '1')
		return (FALSE);
	if (map[row][col] != 'E')
		map[row][col] = '1';
	if (flood_fill(map, row - 1, col, collectibles)
		|| flood_fill(map, row, col + 1, collectibles)
		|| flood_fill(map, row + 1, col, collectibles)
		|| flood_fill(map, row, col - 1, collectibles))
		return (TRUE);
	return (FALSE);
}

void	validate_path(t_map *map)
{
	char	**map_dup;
	int		collectibles;

	collectibles = map->collectibles;
	map_dup = ft_matrix_dup(map->grid);
	if (!flood_fill(map_dup, map->init.y, map->init.x, &collectibles)
		&& !ft_split_free(map_dup))
		error_handler(map->grid, "No valid path.", EXIT_FAILURE);
	ft_split_free(map_dup);
}
