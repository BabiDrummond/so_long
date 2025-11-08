/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 22:43:27 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/07 22:43:53 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_mlx(t_game *game)
{
	game->mlx.width = game->map.cols * TILE;
	game->mlx.height = game->map.rows * TILE;
	game->mlx.mlx_ptr = mlx_init();
	if (!game->mlx.mlx_ptr)
		game_destroy(game);
	game->mlx.win = mlx_new_window(game->mlx.mlx_ptr,
			game->mlx.width, game->mlx.height, "SoLong");
	if (!game->mlx.win)
		game_destroy(game);
}
