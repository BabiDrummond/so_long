/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:54:18 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/29 20:03:09 by bmoreira         ###   ########.fr       */
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

void	parser(t_game *game, char *buffer)
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
	game->map = split;
}

void	map_print(char **matrix)
{
	while (*matrix)
		ft_printf("%s\n", *matrix++);
}

void	init_map(t_game *game)
{
	game->collectible = 0;
	game->exit = 0;
	game->player = 0;
	game->wall = 0;
	game->floor = 0;
	game->init.x = 0;
	game->init.y = 0;
	game->end.x = 0;
	game->end.y = 0;
	game->size.x = 0;
	game->size.y = 0;
}

int	main(void)
{
	t_game	game;
	char	*buffer;
	char	*filename;

	filename = "maps/map01.ber";
	validate_filename(filename, ".ber");
	read_file(&buffer, filename);
	ft_printf("%s\n", buffer);
	parser(&game, buffer);
	init_map(&game);
	validate_map(&game);
	ft_printf("x: %d, y: %d\n", game.size.x, game.size.y);
	map_print(game.map);
	ft_split_free(game.map);
}
