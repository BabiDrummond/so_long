/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:48:30 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/07 22:34:22 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int next_x, int next_y)
{
	t_pos	curr;
	char	next_tile;

	curr = (t_pos){game->map.player.x, game->map.player.y};
	next_tile = game->map.grid[next_y][next_x];
	if (next_tile == '1')
		return ;
	if (ft_strchr("XYZ", next_tile))
			game->collected++;
	if (next_tile == 'M')
		destroy_game(game);
	if (next_tile == 'E' && game->collected == game->map.collectibles)
		destroy_game(game);
	if (curr.x == game->map.exit.x && curr.y == game->map.exit.y)
		game->map.grid[curr.y][curr.x] = 'E';
	else
		game->map.grid[curr.y][curr.x] = '0';
	game->map.grid[next_y][next_x] = 'P';
	game->map.player = (t_pos){next_x, next_y};
	game->moves++;
	ft_matrix_print(game->map.grid);
	ft_printf("collect: %d, collected: %d\n",
		game->map.collectibles, game->collected);
}
