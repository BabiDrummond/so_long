/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:18:49 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/30 18:34:24 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_size(t_map *map)
{
	size_t	row;
	size_t	col;

	row = 0;
	col = ft_strlen(map->grid[row]);
	while (map->grid[row])
		if (ft_strlen(map->grid[row++]) != col)
			error_handler(map->grid, "Irregular map.", EXIT_FAILURE);
	if (row < 4 || col < 4)
		error_handler(map->grid, "Map too small.", EXIT_FAILURE);
	map->size.x = col;
	map->size.y = row;
}
