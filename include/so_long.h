/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:59:16 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/23 20:10:01 by bmoreira         ###   ########.fr       */
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

typedef struct s_map
{
	char	**map;
	int		player;
	int		collectible;
	int		enemy;
	int		walls;
	int		floor;
}	t_map;

void	read_file(char **buffer, char *file_name);
void	error_handler(char **args, const char *error_msg, int exit_code);

// Validation
void	check_chars(t_map *map, const char *set);
void	validate_map(t_map *map);
void	validate_name(char *filename, char *extension);

#endif