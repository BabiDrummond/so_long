/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 01:14:06 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/30 18:30:43 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_validator(t_map *map)
{
	validate_chars(map, "01CEPM");
	validate_size(map);
	validate_elements(map);
	validate_walls(map);
	validate_path(map);
}
