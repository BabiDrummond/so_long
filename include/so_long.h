/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:59:16 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/07 17:57:51 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/include/libft.h"

# define SET "01CEMP"
# define TILE 64
# define SPRITES 18

typedef enum e_keys
{
	ESC = 65307,
	UP = 119,
	LEFT = 97,
	DOWN = 115,
	RIGHT = 100,
}	t_keys;

typedef enum e_sprites
{
	FLOOR = 0,
	FRID1 = 1,
	FRID2 = 2,
	WALL = 3,
	WALL2 = 4,
	CAM1 = 5,
	CAM2 = 6,
	MILK = 7,
	BUTTER = 8,
	BREAD = 9,
	PLAY1 = 10,
	PLAY2 = 11,
	PLAY3 = 12,
	PLAY4 = 13,
	PLAY5 = 14,
	PLAY6 = 15,
	PLAY7 = 16,
	PLAY8 = 17,
}	t_sprites;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_monster
{
	t_pos	pos;
	int		move;
}	t_monster;

typedef struct s_map
{
	char		**grid;
	int			collectibles;
	int			players;
	int			exits;
	int			monsters;
	int			rows;
	int			cols;
	t_pos		player;
	t_pos		exit;
	t_monster	*monster;
}	t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
	int		height;
	int		width;
}	t_mlx;

typedef struct s_game
{
	t_map	map;
	t_mlx	mlx;
	void	*img[SPRITES];
}	t_game;

// Gameplay
int		check_exit(t_game *game);
int		key_press(int key, t_game *game);
void	move_player(t_game *game, int x, int y);
int		close_game(t_game *game);

// Graphics
int		get_rgb(int r, int g, int b);
void	destroy_sprites(t_game *game);
void	load_sprites(t_game *game);
int		render_sprites(t_game *game);

// Parsing
void	map_init_values(t_map *map);
void	map_init_positions(t_map *map);
void	map_load(t_map *map, char *filename);
void	map_parse(t_map *map, char *buffer);
void	map_read(char **buffer, char *file_name);

// Validation
void	error_handler(char **args, const char *error_msg, int exit_code);
void	validate_chars(t_map *map);
void	validate_elements(t_map *map);
void	validate_filename(char *filename, char *extension);
void 	validate_path(t_map *map);
void	validate_size(t_map *map);
void	validate_walls(t_map *map);

#endif