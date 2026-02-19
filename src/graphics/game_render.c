/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:52:29 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/19 17:56:11 by bmoreira         ###   ########.fr       */
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
	if (tile == 'E' && game->collected != game->map.collectibles)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
			game->img[FRID1], col * TILE, row * TILE);
	if (tile == 'E' && game->collected == game->map.collectibles)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
			game->img[FRID2], col * TILE, row * TILE);
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
	if (game->frames <= 15 && game->direction == 0)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
			game->img[PLAY1], col * TILE, row * TILE);
	if (game->frames > 15 && game->frames <= 30 && game->direction == 0)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
			game->img[PLAY2], col * TILE, row * TILE);
	if (game->frames > 30 && game->frames <= 45 && game->direction == 0)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
			game->img[PLAY3], col * TILE, row * TILE);
	if (game->frames > 45 && game->frames <= 60 && game->direction == 0)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
			game->img[PLAY4], col * TILE, row * TILE);
	if (game->frames <= 15 && game->direction == 1)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
			game->img[PLAY5], col * TILE, row * TILE);
	if (game->frames > 15 && game->frames <= 30 && game->direction == 1)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
			game->img[PLAY6], col * TILE, row * TILE);
	if (game->frames > 30 && game->frames <= 45 && game->direction == 1)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
			game->img[PLAY7], col * TILE, row * TILE);
	if (game->frames > 45 && game->frames <= 60 && game->direction == 1)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
			game->img[PLAY8], col * TILE, row * TILE);
}

static void	render_monster(t_game *game, int col, int row)
{
	if (game->map.monster->direction == 0)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
			game->img[CAM1], col * TILE, row * TILE);
	if (game->map.monster->direction == 1)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
			game->img[CAM2], col * TILE, row * TILE);
}

static void	render_interface(t_game *game, int col, int row)
{
	char	*text;

	text = ft_strjoin_free(ft_strdup("Moves: "),
			ft_itoa(game->moves), TRUE, TRUE);
	text = ft_strjoin_free(text, ft_strdup("   Collected: "), TRUE, TRUE);
	text = ft_strjoin_free(text, ft_itoa(game->collected), TRUE, TRUE);
	mlx_string_put(game->mlx.mlx_ptr, game->mlx.win, col, row, 0xFFFFFF, text);
	free(text);
}

void	game_render(t_game *game)
{
	char	tile;
	int		row;
	int		col;

	game->frames++;
	if (game->frames > FRAME_MAX)
		game->frames = 0;
	row = -1;
	while (++row < game->map.rows)
	{
		col = -1;
		while (++col < game->map.cols)
		{
			tile = game->map.grid[row][col];
			if (ft_strchr("01EXYZ", tile))
				render_environment(game, col, row, tile);
			if (tile == 'P')
				render_player(game, col, row);
			if (tile == 'M')
				render_monster(game, col, row);
			render_interface(game, (game->map.cols / 2) * TILE, (1 * TILE) / 2);
		}
	}
}
