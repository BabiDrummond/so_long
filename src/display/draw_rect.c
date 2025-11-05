/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:50:03 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/04 21:50:41 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_rect(t_mlx *mlx, int col, int row, int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SQUARE)
	{
		x = -1;
		while (++x < SQUARE)
			put_pixel(mlx, col * SQUARE + x, row * SQUARE + y, color);
	}
}
