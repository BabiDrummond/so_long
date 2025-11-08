/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:52:00 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/07 19:14:58 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_sprites(t_game *game)
{
	int	i;

	i = -1;
	while (++i < SPRITES)
		if (game->img[i])
			mlx_destroy_image(game->mlx.mlx_ptr, game->img[i]);
}

static void	destroy_monsters(t_game *game)
{
	if (game->map.monsters > 0 && game->map.monster)
		free(game->map.monster);
}

static void	destroy_mlx(t_mlx *mlx)
{
	if (mlx->mlx_ptr && mlx->win)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
}

int	destroy_game(t_game *game)
{
	ft_matrix_free(game->map.grid);
	destroy_sprites(game);
	destroy_monsters(game);
	destroy_mlx(&game->mlx);
	exit(EXIT_SUCCESS);
}
