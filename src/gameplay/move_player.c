/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:48:30 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/07 18:02:35 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int x, int y)
{
	t_pos	curr;
	t_pos	next;

	curr.y = game->map.player.y;
	curr.x = game->map.player.x;
	next.y = curr.y + y;
	next.x = curr.x + x;
	if (game->map.grid[next.y][next.x] == 'X'
		|| game->map.grid[next.y][next.x] == 'Y'
		|| game->map.grid[next.y][next.x] == 'Z')
			game->map.collectibles--;
	if (game->map.grid[next.y][next.x] != '1')
	{
		if (curr.y == game->map.exit.y && curr.x == game->map.exit.x
			&& !check_exit(game))
			game->map.grid[curr.y][curr.x] = 'E';
		else
			game->map.grid[curr.y][curr.x] = '0';
		game->map.grid[next.y][next.x] = 'P';
		game->map.player.y = next.y;
		game->map.player.x = next.x;
	}
	ft_matrix_print(game->map.grid);
	ft_printf("collect: %d\n", game->map.collectibles);
}
