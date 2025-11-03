/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:36:33 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/03 19:14:01 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_loader(t_map *map, char *filename)
{
	char	*buffer;

	validate_filename(filename, ".ber");
	read_file(&buffer, filename);
	//ft_printf("%s\n", buffer);
	map_parser(map, buffer);
	map_init(map);
}
