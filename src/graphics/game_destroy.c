/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 22:42:45 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/22 12:32:26 by bmoreira         ###   ########.fr       */
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

int	game_destroy(t_game *game)
{
	ft_matrix_free(game->map.grid);
	destroy_sprites(game);
	destroy_monsters(game);
	destroy_mlx(&game->mlx);
	ft_printf("Moves: %d\nCollected: %d\n", game->moves, game->collected);
	exit(EXIT_SUCCESS);
}
