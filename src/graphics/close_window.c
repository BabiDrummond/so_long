/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:52:00 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/06 21:18:57 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_sprites(t_game *game)
{
	int	i;

	i = -1;
	while (++i < SPRITES)
		if (game->img[i])
			mlx_destroy_image(game->mlx.mlx_ptr, game->img[i]);
}

int	close_window(t_game *game)
{
	ft_matrix_free(game->map.grid);
	destroy_sprites(game);
	mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win);
	mlx_destroy_display(game->mlx.mlx_ptr);
	free(game->mlx.mlx_ptr);
	exit(EXIT_SUCCESS);
}
