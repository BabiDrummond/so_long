/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:19:30 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/29 21:19:44 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_elements(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->size.y)
	{
		j = -1;
		while (++j < g->size.x)
		{
			if (g->map[i][j] == 'C')
				g->collectible++;
			else if (g->map[i][j] == 'E' && ++g->exit)
			{
				g->end.x = j;
				g->end.y = i;
			}
			else if (g->map[i][j] == 'P' && ++g->player)
			{
				g->init.x = j;
				g->init.y = i;
			}
		}
	}
	if (g->collectible < 1 || g->player != 1 || g->exit != 1)
		error_handler(g->map, "Invalid elements in map.", EXIT_FAILURE);
}
