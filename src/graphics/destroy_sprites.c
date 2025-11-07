/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:55:41 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/07 17:55:58 by bmoreira         ###   ########.fr       */
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
