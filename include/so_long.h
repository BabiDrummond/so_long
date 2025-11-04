/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:59:16 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/03 21:21:19 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/include/libft.h"

# define SQUARE 32

typedef enum e_keys
{
	ESC = 65307,
	W = 119,
	A = 97,
	S = 115,
	D = 100,
}	t_keys;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	char	**grid;
	int		collectibles;
	int		players;
	int		exits;
	int		height;
	int		width;
	t_pos	init;
	t_pos	end;
}	t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
	void	*img;
	void	*addr;
	int		bpp;
	int		line_size;
	int		endian;
	int		height;
	int		width;
}	t_mlx;

typedef struct s_game
{
	t_map	map;
	t_mlx	mlx;
}	t_game;

// Parsing
void	init_map(t_map *map);
void	map_loader(t_map *map, char *filename);
void	parse_map(t_map *map, char *buffer);
void	read_file(char **buffer, char *file_name);

// Validation
void	error_handler(char **args, const char *error_msg, int exit_code);
void	map_validator(t_map *map);
void	validate_chars(t_map *map, const char *set);
void	validate_elements(t_map *map);
void	validate_filename(char *filename, char *extension);
void 	validate_path(t_map *map);
void	validate_size(t_map *map);
void	validate_walls(t_map *map);

#endif