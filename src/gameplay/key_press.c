/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:53:40 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/07 22:01:04 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int key, t_game *game)
{
	if (key == ESC)
		destroy_game(game);
	if (key == UP)
		move_player(game, game->map.player.x + 0, game->map.player.y - 1);
	if (key == LEFT)
	{
		move_player(game, game->map.player.x - 1, game->map.player.y + 0);
		game->direction = 0;
	}
	if (key == DOWN)
		move_player(game, game->map.player.x + 0, game->map.player.y + 1);
	if (key == RIGHT)
	{
		move_player(game, game->map.player.x + 1, game->map.player.y + 0);
		game->direction = 1;
	}
	return (0);
}
