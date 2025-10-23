/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 01:14:06 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/23 19:36:49 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_chars(char *str, const char *set)
{
	int	i;
	int	j;
	int	valid;

	i = -1;
	valid = 0;
	while (str[++i])
	{
		j = -1;
		valid = 0;
		while (set[++j])
			if (str[i] == set[j] && ++valid)
				break ;
		if (!valid)
			return (valid);
	}
	return (valid);
}

void	validate_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
		if (!check_chars(map->map[i++], "01CEP"))
			error_handler(map->map, "Invalid chars in map.", EXIT_FAILURE);
}

// int main(void)
// {
//     void *mlx = mlx_init();
//     void *win = mlx_new_window(mlx, 100, 100, "oi");
//     (void) win;
//     ft_putstr_fd("oi", 1);
//     mlx_loop(mlx);
// }