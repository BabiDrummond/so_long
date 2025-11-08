/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:06:15 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/07 19:37:24 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_environment_sprites(t_game *game, int width, int height)
{
	game->img[FRID1] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/xpm/frid.xpm", &width, &height);
	game->img[FRID2] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/xpm/frid2.xpm", &width, &height);
	game->img[WALL] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/xpm/wall.xpm", &width, &height);
	game->img[WALL2] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/xpm/wall42.xpm", &width, &height);
	game->img[FLOOR] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/xpm/floor.xpm", &width, &height);
}

static void	load_collectible_sprites(t_game *game, int width, int height)
{
	game->img[MILK] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/xpm/milk.xpm", &width, &height);
	game->img[BUTTER] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/xpm/butter.xpm", &width, &height);
	game->img[BREAD] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/xpm/bread.xpm", &width, &height);
}

static void	load_player_sprites(t_game *game, int width, int height)
{
	game->img[PLAY1] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/xpm/play1.xpm", &width, &height);
	game->img[PLAY2] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/xpm/play2.xpm", &width, &height);
	game->img[PLAY3] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/xpm/play3.xpm", &width, &height);
	game->img[PLAY4] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/xpm/play4.xpm", &width, &height);
	game->img[PLAY5] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/xpm/play5.xpm", &width, &height);
	game->img[PLAY6] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/xpm/play6.xpm", &width, &height);
	game->img[PLAY7] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/xpm/play7.xpm", &width, &height);
	game->img[PLAY8] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/xpm/play8.xpm", &width, &height);
}

static void	load_monster_sprites(t_game *game, int width, int height)
{
	game->img[CAM1] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/xpm/cam1.xpm", &width, &height);
	game->img[CAM2] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/xpm/cam2.xpm", &width, &height);
}

void	load_sprites(t_game *game)
{
	int	width;
	int	height;
	int	i;

	i = -1;
	width = TILE;
	height = TILE;
	load_environment_sprites(game, width, height);
	load_collectible_sprites(game, width, height);
	load_player_sprites(game, width, height);
	load_monster_sprites(game, width, height);
	while (++i < SPRITES)
		if (!game->img[i])
			destroy_game(game);
}
