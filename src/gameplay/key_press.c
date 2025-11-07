/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:53:40 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/06 19:13:11 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int key, t_game *game)
{
	if (key == ESC)
		close_window(game);
	if (key == UP)
		move_player(game, 0, -1);
	if (key == LEFT)
		move_player(game, -1, 0);
	if (key == DOWN)
		move_player(game, 0, 1);
	if (key == RIGHT)
		move_player(game, 1, 0);
	return (0);
}
