/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:35:24 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/22 11:45:06 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_parse(t_map *map, char *buffer)
{
	char	**split;

	if (!buffer)
		error_handler(NULL, "Empty map.", EXIT_FAILURE);
	split = ft_split(buffer, '\n');
	free(buffer);
	if (!split)
		error_handler(NULL, "Error spliting buffer.", EXIT_FAILURE);
	map->grid = split;
}
