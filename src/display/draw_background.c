/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:50:23 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/04 21:50:39 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_background(t_map *map, t_mlx *mlx)
{
	int	row;
	int	col;

	row = -1;
	while (++row < map->rows)
	{
		col = -1;
		while (++col < map->cols)
		{
			if (map->grid[row][col] == '0')
				draw_rect(mlx, col, row, get_rgb(70, 200, 200));
			if (map->grid[row][col] == '1')
				draw_rect(mlx, col, row, get_rgb(122, 122, 122));
			if (map->grid[row][col] == 'C')
				draw_rect(mlx, col, row, get_rgb(255, 150, 0));
			if (map->grid[row][col] == 'E')
				draw_rect(mlx, col, row, get_rgb(0, 190, 0));
			if (map->grid[row][col] == 'M')
				draw_rect(mlx, col, row, get_rgb(255, 0, 100));
			if (map->grid[row][col] == 'P')
				draw_rect(mlx, col, row, get_rgb(255, 128, 255));
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img, 0, 0);
}
