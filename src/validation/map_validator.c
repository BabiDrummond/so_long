/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 01:14:06 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/24 22:15:19 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_chars(char **map, const char *set)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (!ft_strchr(set, map[i][j]))
				error_handler(map, "Invalid chars in map.", EXIT_FAILURE);
	}
}

void	check_map_size(t_game *g)
{
	size_t	row;
	size_t	col;

	row = 0;
	col = ft_strlen(g->map[row]);
	while (g->map[row])
		if (ft_strlen(g->map[row++]) != col)
			error_handler(g->map, "Irregular map.", EXIT_FAILURE);
	if (row < 4 || col < 4)
		error_handler(g->map, "Map too small.", EXIT_FAILURE);
	g->size.x = col;
	g->size.y = row;
}

void	check_valid_elements(t_game *g)
{
	int	i;
	int j;

	i = -1;
	while (++i < g->size.y)
	{
		j = -1;
		while (++j < g->size.x)
		{
			if (g->map[i][j] == 'C')
				g->collectible++;
			else if (g->map[i][j] == 'E' && g->exit++)
			{
				g->end.x = j;
				g->end.y = i;
			}
			else if (g->map[i][j] == 'P' && g->player++)
			{
				g->init.x = j;
				g->init.y = i;
			}
		}
	}
	ft_printf("c: %d, e: %d, p: %d", g->collectible, g->exit, g->player);
	if (g->collectible < 1 || g->player != 1 || g->exit != 1)
		error_handler(g->map, "Invalid elements in map.", EXIT_FAILURE);
}

void	validate_map(t_game *game)
{
	check_chars(game->map, "01CEP");
	check_map_size(game);
	check_valid_elements(game);
}
