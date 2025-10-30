/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:59:16 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/30 18:38:27 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/include/libft.h"

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define TRUE 1
# define FALSE 0

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
	t_pos	init;
	t_pos	end;
	t_pos	size;
}	t_map;

void	read_file(char **buffer, char *file_name);
void	error_handler(char **args, const char *error_msg, int exit_code);

// Validation
void	validate_chars(t_map *map, const char *set);
void	validate_elements(t_map *map);
void	validate_filename(char *filename, char *extension);
void 	validate_path(t_map *map);
void	validate_size(t_map *map);
void	validate_walls(t_map *map);

// Map
void	map_validator(t_map *map);

#endif