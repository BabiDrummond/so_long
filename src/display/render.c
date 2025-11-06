/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:52:29 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/06 18:55:06 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_game *game)
{
	int	row;
	int	col;

	row = -1;
	while (++row < game->map.rows)
	{
		col = -1;
		while (++col < game->map.cols)
		{
			mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win, game->sprites.img, col * TILE, row * TILE);
			// 	mlx->img = 
			// if (map->grid[row][col] == '1')
			// 	draw_rect(mlx, col, row, get_rgb(122, 122, 122));
			// if (map->grid[row][col] == 'C')
			// 	draw_rect(mlx, col, row, get_rgb(255, 150, 0));
			// if (map->grid[row][col] == 'E')
			// 	draw_rect(mlx, col, row, get_rgb(0, 190, 0));
			// if (map->grid[row][col] == 'M')
			// 	draw_rect(mlx, col, row, get_rgb(255, 0, 100));
			// if (map->grid[row][col] == 'P')
			// 	draw_rect(mlx, col, row, get_rgb(255, 128, 255));
		}
	}
	return (0);
}
