/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:54:18 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/30 18:40:14 by bmoreira         ###   ########.fr       */
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
	if (!buffer)
		error_handler(NULL, "Empty map.", EXIT_FAILURE);
	split = ft_split(buffer, '\n');
	free(buffer);
	if (!split)
		error_handler(NULL, "Error spliting buffer.", EXIT_FAILURE);
	map->grid = split;
}

void	init_map(t_map *map)
{
	map->collectibles = 0;
	map->players = 0;
	map->exits = 0;
	map->init.x = 0;
	map->init.y = 0;
	map->end.x = 0;
	map->end.y = 0;
	map->size.x = 0;
	map->size.y = 0;
}

// int	main(void)
// {
// 	t_map	map;
// 	char	*buffer;
// 	char	*filename;

// 	filename = "maps/map02.ber";
// 	validate_filename(filename, ".ber");
// 	read_file(&buffer, filename);
// 	ft_printf("%s\n", buffer);
// 	parser(&map, buffer);
// 	init_map(&map);
// 	map_validator(&map);
// 	ft_printf("x: %d, y: %d\n", map.size.x, map.size.y);
// 	ft_matrix_print(map.grid);
// 	ft_split_free(map.grid);
// }

int main(void)
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 100, 100, "oi");
    (void) win;
    ft_putstr_fd("oi", 1);
    mlx_loop(mlx);
}