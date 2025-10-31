/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:54:18 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/30 21:21:13 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	main(void)
// {
// 	t_map	map;
// 	char	*filename;

// 	filename = "maps/invalidchars.ber";
// 	map_loader(&map, filename);
// 	map_validator(&map);
// 	ft_printf("x: %d, y: %d\n", map.size.x, map.size.y);
// 	ft_matrix_print(map.grid);
// 	ft_split_free(map.grid);
// }

void	close_window(t_mlx *m_data)
{
	mlx_destroy_window(m_data->mlx, m_data->win);
	mlx_destroy_image(m_data->mlx, m_data->img);
	mlx_destroy_display(m_data->mlx);
	free(m_data->mlx);
	exit(EXIT_SUCCESS);
}

int	key_handler(int key, t_mlx *m_data)
{
	if (key == ESC)
		close_window(m_data);
	else
		ft_printf("Key pressed: %c\n", key);
	return (FALSE);
}

void	ft_put_pixel(t_mlx *m_data, int x, int y, int color)
{
	char	*dst;

	dst = m_data->addr + (y * m_data->line_lenght + x * (m_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	t_mlx	m_data;

	ft_putstr_fd("oi", 1);
	m_data.mlx = mlx_init();
	m_data.win = mlx_new_window(m_data.mlx, 720, 440, "Hello World");
	m_data.img = mlx_new_image(m_data.mlx, 720, 440);
	m_data.addr = mlx_get_data_addr(m_data.img, &m_data.bits_per_pixel, &m_data.line_lenght, &m_data.endian);
	
	ft_put_pixel(&m_data, 720 / 2, 440 / 2, 0x00FF0000);
	mlx_put_image_to_window(m_data.mlx, m_data.win, m_data.img, 0, 0);
	mlx_key_hook(m_data.win, key_handler, &m_data);
	mlx_loop(m_data.mlx);
}
