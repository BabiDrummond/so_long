/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:59:16 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/28 18:54:12 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../libft/include/libft.h"

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_game
{
	char	**map;
	int		collectible;
	int		exit;
	int		player;
	int		wall;
	int		floor;
	t_pos	init;
	t_pos	end;
	t_pos	size;
}	t_game;

void	read_file(char **buffer, char *file_name);
void	error_handler(char **args, const char *error_msg, int exit_code);

// Validation
void	validate_map(t_game *game);
void	validate_name(char *filename, char *extension);

#endif