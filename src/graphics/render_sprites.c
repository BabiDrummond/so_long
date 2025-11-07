/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:52:29 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/07 17:56:42 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_environment(t_game *game, int col, int row, char tile)
{
	if (tile == '0')
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
			game->img[FLOOR], col * TILE, row * TILE);
	if (tile == '1' && (row == 0 && col == 1))
			mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
				game->img[WALL2], col * TILE, row * TILE);
	if (tile == '1' && (row != 0 || col != 1))
			mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
				game->img[WALL], col * TILE, row * TILE);
	if (tile == 'E')
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
			game->img[FRID2], col * TILE, row * TILE);
}

static void	render_collectible(t_game *game, int col, int row, char tile)
{
	if (tile == 'X')
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
		game->img[BREAD], col * TILE, row * TILE);
	if (tile == 'Y')
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
		game->img[MILK], col * TILE, row * TILE);
	if (tile == 'Z')
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
		game->img[BUTTER], col * TILE, row * TILE);
}

static void	render_player(t_game *game, int col, int row)
{
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
		game->img[PLAY1], col * TILE, row * TILE);
}

static void	render_monster(t_game *game, int col, int row)
{
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
		game->img[CAM1], col * TILE, row * TILE);
}

int	render_sprites(t_game *game)
{
	char	tile;
	int		row;
	int		col;

	row = -1;
	while (++row < game->map.rows)
	{
		col = -1;
		while (++col < game->map.cols)
		{
			tile = game->map.grid[row][col];
			if (tile == '0' || tile == '1' || tile == 'E')
				render_environment(game, col, row, tile);
			if (tile == 'X' || tile == 'Y' || tile == 'Z')
				render_collectible(game, col, row, tile);
			if (tile == 'P')
				render_player(game, col, row);
			if (tile == 'M')
				render_monster(game, col, row);
		}
	}
	return (0);
}
