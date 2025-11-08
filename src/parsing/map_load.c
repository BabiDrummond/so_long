/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:36:33 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/07 19:01:02 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_load(t_map *map, char *filename)
{
	char	*buffer;

	validate_filename(filename, ".ber");
	map_read(&buffer, filename);
	map_parse(map, buffer);
	map_init_values(map);
	validate_size(map);
	validate_chars(map);
	validate_elements(map);
	validate_walls(map);
	map_init_positions(map);
	validate_path(map);
}
