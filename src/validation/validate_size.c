/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:18:49 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/29 21:24:43 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_size(t_game *g)
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
