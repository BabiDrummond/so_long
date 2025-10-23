/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 01:14:06 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/23 20:23:16 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_chars(t_map *map, const char *set)
{
	int	i;
	int	j;
	int	k;
	int	valid;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			k = -1;
			valid = 0;
			while (set[++k])
				if (map->map[i][j] == set[k] && ++valid)
					break ;
			if (!valid)
				error_handler(map->map, "Invalid chars in map.", EXIT_FAILURE);
		}
	}
}

void	check_map_size(t_map *map)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(map->map[i]);
	while (map->map[i])
		if (ft_strlen(map->map[i++]) != size)
			error_handler(map->map, "Irregular map.", EXIT_FAILURE);
	if (i < 4 || size < 4)
		error_handler(map->map, "Map too small.", EXIT_FAILURE);
}

void	validate_map(t_map *map)
{
	check_chars(map, "01CEP");
	check_map_size(map);
}

// int main(void)
// {
//     void *mlx = mlx_init();
//     void *win = mlx_new_window(mlx, 100, 100, "oi");
//     (void) win;
//     ft_putstr_fd("oi", 1);
//     mlx_loop(mlx);
// }