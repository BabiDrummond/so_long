/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:53:30 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/29 20:02:54 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(char **map, int row, int col, int *collectibles)
{
	if (map[row][col] == 'E' && !*collectibles)
		return (TRUE);
	if (map[row][col] == 'C')
		(*collectibles)--;
	if (map[row][col] == '1')
		return (FALSE);
	if (map[row][col] != 'E')
		map[row][col] = '1';
	if (flood_fill(map, row - 1, col, collectibles)
		|| flood_fill(map, row, col + 1, collectibles)
		|| flood_fill(map, row + 1, col, collectibles)
		|| flood_fill(map, row, col - 1, collectibles))
		return (TRUE);
	return (FALSE);
}

int	ft_matrix_len(char **matrix)
{
	int	len;

	len = 0;
	while (matrix[len])
		len++;
	return (len);
}

char	**ft_matrix_dup(char **src)
{
	char	**new;
	int		row;
	int		col;

	row = -1;
	new = ft_calloc(ft_matrix_len(src) + 1, sizeof(char *));
	if (!new)
		return (NULL);
	while (src[++row])
	{
		col = -1;
		new[row] = ft_calloc(ft_strlen(src[row]) + 1, sizeof(char));
		if (!new[row])
			return (NULL);
		while (src[row][++col])
			new[row][col] = src[row][col];
	}
	return (new);
}

void	check_valid_path(t_game *g)
{
	char	**map_dup;
	int		collectibles;

	collectibles = g->collectible;
	map_dup = ft_matrix_dup(g->map);
	if (!flood_fill(map_dup, g->init.y, g->init.x, &collectibles)
		&& !ft_split_free(map_dup))
		error_handler(g->map, "No valid path.", EXIT_FAILURE);
	ft_split_free(map_dup);
}
