/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_monsters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 22:49:33 by bmoreira          #+#    #+#             */
/*   Updated: 2025/12/04 19:07:34 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_direction(t_monster *monster)
{
	if (monster->direction == 0)
		monster->direction = 1;
	else
		monster->direction = 0;
}

void	check_new_pos(t_game *game, t_monster *monster, t_pos *new, int mov)
{
	if (monster->direction == 0 && mov == 0)
		*new = (t_pos){monster->pos.x - 1, monster->pos.y + 0};
	if (monster->direction == 1 && mov == 0)
		*new = (t_pos){monster->pos.x + 1, monster->pos.y + 0};
	if (monster->direction == 0 && mov == 1)
		*new = (t_pos){monster->pos.x + 0, monster->pos.y - 1};
	if (monster->direction == 1 && mov == 1)
		*new = (t_pos){monster->pos.x + 0, monster->pos.y + 1};
	if (ft_strchr("1EMXYZ", game->map.grid[new->y][new->x]))
		change_direction(monster);
}

void	set_new_pos(t_game *game, t_monster *monster, t_pos *new_pos)
{
	char	tile;

	tile = game->map.grid[new_pos->y][new_pos->x];
	if (ft_strchr("1EMXYZ", tile))
		return ;
	if (tile == 'P' && ft_printf("##### GAME OVER! #####\n"))
		game_destroy(game);
	game->map.grid[monster->pos.y][monster->pos.x] = '0';
	game->map.grid[new_pos->y][new_pos->x] = 'M';
	monster->pos = *new_pos;
}

void	move_monster(t_game *game, t_monster *monster, t_pos *new_pos, int mov)
{
	check_new_pos(game, monster, new_pos, mov);
	set_new_pos(game, monster, new_pos);
}

void	move_monsters(t_game *game)
{
	static int	velocity = 0;
	t_pos		new_pos;
	int			i;

	i = -1;
	if (velocity++ < 50)
		return ;
	velocity = 0;
	while (++i < game->map.monsters)
	{
		if (i % 2 == 0)
			move_monster(game, &game->map.monster[i], &new_pos, 0);
		else
			move_monster(game, &game->map.monster[i], &new_pos, 1);
	}
}
