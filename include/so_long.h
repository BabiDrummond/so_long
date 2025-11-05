/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:59:16 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/04 21:55:40 by bmoreira         ###   ########.fr       */
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
	int		rows;
	int		cols;
	t_pos	player;
	t_pos	exit;
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

// Display
int		close_window(t_game *game);
void	draw_background(t_map *map, t_mlx *mlx);
void	draw_rect(t_mlx *mlx, int col, int row, int color);
int		get_rgb(int r, int g, int b);
void	put_pixel(t_mlx *mlx, int x, int y, int color);
int		render(t_game *game);

// Gameplay
int		check_exit(t_game *game);
int		key_press(int key, t_game *game);
void	move_player(t_game *game, int x, int y);

// Parsing
void	map_init(t_map *map);
void	map_load(t_map *map, char *filename);
void	map_parse(t_map *map, char *buffer);
void	map_read(char **buffer, char *file_name);

// Validation
void	validate_chars(t_map *map, const char *set);
void	validate_elements(t_map *map);
void	validate_filename(char *filename, char *extension);
void 	validate_path(t_map *map);
void	validate_size(t_map *map);
void	validate_walls(t_map *map);

// Utils
void	error_handler(char **args, const char *error_msg, int exit_code);

#endif