/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:59:16 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/22 21:23:03 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../libft/include/libft.h"

typedef struct s_map
{
	char	**map;
	int		player;
	int		collectible;
	int		enemy;
	int		walls;
	int		floor;
}	t_map;

char	*read_file(char *file_name);

#endif