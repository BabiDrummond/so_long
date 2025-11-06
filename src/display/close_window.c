/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:52:00 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/05 20:20:51 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	ft_matrix_free(game->map.grid);
	mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win);
	mlx_destroy_display(game->mlx.mlx_ptr);
	free(game->mlx.mlx_ptr);
	exit(EXIT_SUCCESS);
}
