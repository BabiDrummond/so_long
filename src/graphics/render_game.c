/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:52:29 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/06 21:38:37 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_environment(t_game *game)
{
	int	row;
	int	col;

	row = -1;
	while (++row < game->map.rows)
	{
		col = -1;
		while (++col < game->map.cols)
		{
			if (game->map.grid[row][col] == '0')
				mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
					game->img[FLOOR], col * TILE, row * TILE);
			if ((game->map.grid[row][col] == '1') && (row == 0 && col == 1))
					mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
						game->img[WALL2], col * TILE, row * TILE);
			if ((game->map.grid[row][col] == '1') && (row != 0 || col != 1))
					mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
						game->img[WALL], col * TILE, row * TILE);
			if (game->map.grid[row][col] == 'E')
				mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
					game->img[FRID2], col * TILE, row * TILE);
		}
	}
}

static void	render_collectible(t_game *game)
{
	int	row;
	int	col;
	int	count;

	row = -1;
	count = 0;
	while (++row < game->map.rows)
	{
		col = -1;
		while (++col < game->map.cols)
		{
			if (game->map.grid[row][col] == 'C' && count++ % 3 == 0)
				mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
					game->img[BREAD], col * TILE, row * TILE);
			if (game->map.grid[row][col] == 'C' && count++ % 3 == 1)
				mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
					game->img[BUTTER], col * TILE, row * TILE);
			if (game->map.grid[row][col] == 'C' && count++ % 3 == 2)
				mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
					game->img[MILK], col * TILE, row * TILE);
			if (count == 2)
				count = 0;
		}
	}
}

static void	render_player(t_game *game)
{
	int	row;
	int	col;

	row = -1;
	while (++row < game->map.rows)
	{
		col = -1;
		while (++col < game->map.cols)
			if (game->map.grid[row][col] == 'P')
				mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
					game->img[PLAY1], col * TILE, row * TILE);
	}
}

static void	render_enemy(t_game *game)
{
	int	row;
	int	col;

	row = -1;
	while (++row < game->map.rows)
	{
		col = -1;
		while (++col < game->map.cols)
			if (game->map.grid[row][col] == 'M')
				mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
					game->img[CAM1], col * TILE, row * TILE);
	}
}

int	render_game(t_game *game)
{
	render_environment(game);
	render_collectible(game);
	render_player(game);
	render_enemy(game);
	return (0);
}
