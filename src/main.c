/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:54:18 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/03 19:13:26 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
int	main(int argc, char **argv)
{
	t_game	game;
	
	if (argc <= 1)
		error_handler(NULL, "Command: ./so_long FILE_PATH\n", EXIT_FAILURE);
	map_loader(&game.map, argv[1]);
	map_validator(&game.map);
	ft_printf("x: %d, y: %d\n", game.map.width, game.map.height);
	ft_matrix_print(game.map.grid);
	//ft_split_free(game.map.grid);

	ft_putstr_fd("oi", 1);
	game.data.mlx = mlx_init();
	game.data.win = mlx_new_window(game.data.mlx, WIDTH, HEIGHT, "Hello World");
	game.data.img = mlx_new_image(game.data.mlx, WIDTH, HEIGHT);
	game.data.addr = mlx_get_data_addr(game.data.img, &game.data.bits_per_pixel, 
										&game.data.line_lenght, &game.data.endian);
	
	ft_put_pixel(&game.data, WIDTH / 2, HEIGHT / 2, 0x00FF0000);
	mlx_put_image_to_window(game.data.mlx, game.data.win, game.data.img, 0, 0);
	
	mlx_loop_hook(game.data.mlx, &render, &game.data);
	mlx_hook(game.data.win, 2, 1L<<0, &keypress, &game.data);
	mlx_loop(game.data.mlx);
}
