/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:20:30 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/29 21:20:43 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_walls(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if ((i == 0 || i == g->size.y - 1) && g->map[i][j] != '1')
				error_handler(g->map, "Map missing walls.", EXIT_FAILURE);
			else if ((j == 0 || j == g->size.x - 1) && g->map[i][j] != '1')
				error_handler(g->map, "Map missing walls.", EXIT_FAILURE);
		}
	}
}
