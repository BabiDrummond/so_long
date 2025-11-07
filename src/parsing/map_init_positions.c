/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_positions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:15:11 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/07 17:35:52 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:17:13 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/07 16:42:02 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
			if (map->grid[i][j] == 'P')
				map->player = (t_pos){j, i};
	}
}

void	init_exit(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
			if (map->grid[i][j] == 'E')				
				map->exit = (t_pos){j, i};
	}
}

void	init_collectibles(t_map *map)
{
	int	i;
	int	j;
	int	item;

	i = -1;
	item = 0;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			if (map->grid[i][j] == 'C' && ++item)
	        {
		        if (item == 4)
			        item = 0;
		        if (item % 3 == 0)
			        map->grid[i][j] = 'X';
		        if (item % 3 == 1)
			        map->grid[i][j] = 'Y';
		        if (item % 3 == 2)
			        map->grid[i][j] = 'Z';
	        }
		}
	}
}

void	init_monsters(t_map *map)
{
	int	i;
	int	j;
	int k;
	
	i = -1;
	k = 0;
	map->monster = ft_calloc(sizeof(t_monster), map->monsters + 1);
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
			if (map->grid[i][j] == 'M')
				map->monster[k++] = (t_monster){(t_pos) {j, i}, 0};
	}
}

void	map_init_positions(t_map *map)
{
	init_player(map);
	init_exit(map);
	init_collectibles(map);
	init_monsters(map);
}
