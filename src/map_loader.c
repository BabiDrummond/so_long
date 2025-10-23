/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:54:18 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/23 20:36:28 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_file(char **buffer, char *file_name)
{
	char	*line;
	int		fd;

	*buffer = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error_handler(buffer, "Error reading file.", EXIT_FAILURE);
	line = get_next_line(fd);
	while (line)
	{
		*buffer = ft_strjoin_free(*buffer, line);
		if (!*buffer)
			error_handler(buffer, "Error joining line.", EXIT_FAILURE);
		line = get_next_line(fd);
	}
}

void	parser(t_map *map, char *buffer)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(buffer, '\n');
	free(buffer);
	if (!split)
		error_handler(NULL, "Error spliting buffer.", EXIT_FAILURE);
	map->map = split;
}

void	map_print(char **matrix)
{
	while (*matrix)
		ft_printf("%s\n", *matrix++);
}

int	main(void)
{
	t_map	map;
	char	*buffer;
	char	*filename;

	filename = "maps/invalidmap.ber";
	validate_name(filename, ".ber");
	read_file(&buffer, filename);
	ft_printf("%s\n", buffer);
	parser(&map, buffer);
	validate_map(&map);
	map_print(map.map);
	ft_split_free(map.map);
}
