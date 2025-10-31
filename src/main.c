/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:54:18 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/31 20:47:27 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_map	map;
	char	*filename;

	filename = "maps/map02.ber";
	map_loader(&map, filename);
	map_validator(&map);
	ft_printf("x: %d, y: %d\n", map.width, map.height);
	ft_matrix_print(map.grid);
	ft_split_free(map.grid);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	close_window(t_mlx *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}

int	keypress(int key, t_mlx *data)
{
	if (key == ESC)
		close_window(data);
	else
		ft_printf("Key pressed: %c\n", key);
	return (FALSE);
}

void	ft_put_pixel(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	render(t_mlx *data)
{
	(void) data;
	return (0);
}

// int	main(void)
// {
// 	t_mlx	data;
	
// 	ft_putstr_fd("oi", 1);
// 	data.mlx = mlx_init();
// 	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Hello World");
// 	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
// 	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_lenght, &data.endian);
	
// 	ft_put_pixel(&data, WIDTH / 2, HEIGHT / 2, 0x00FF0000);
// 	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	
// 	mlx_loop_hook(data.mlx, &render, &data);
// 	mlx_hook(data.win, 2, 1L<<0, &keypress, &data);
// 	mlx_loop(data.mlx);
// }
