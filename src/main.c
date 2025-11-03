/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:54:18 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/03 19:41:00 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	close_window(t_game *game)
{
	ft_split_free(game->map.grid);
	mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win);
	mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img);
	mlx_destroy_display(game->mlx.mlx_ptr);
	free(game->mlx.mlx_ptr);
	exit(EXIT_SUCCESS);
}

int	keypress(int key, t_game *game)
{
	if (key == ESC)
		close_window(game);
	else
		ft_printf("Key pressed: %c\n", key);
	return (FALSE);
}

void	ft_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_size + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
}

int	render(t_mlx *mlx)
{
	(void) mlx;
	return (0);
}

void	draw_rect()
{
	
}

int	main(int argc, char **argv)
{
	t_game	game;
	
	if (argc != 2)
		error_handler(NULL, "Usage: ./so_long <map_file.ber>", EXIT_FAILURE);
	map_loader(&game.map, argv[1]);
	map_validator(&game.map);
	ft_printf("x: %d, y: %d\n", game.map.width, game.map.height);
	ft_matrix_print(game.map.grid);

	ft_putstr_fd("oi", 1);
	game.mlx.mlx_ptr = mlx_init();
	game.mlx.win = mlx_new_window(game.mlx.mlx_ptr, WIDTH, HEIGHT, "Hello World");
	game.mlx.img = mlx_new_image(game.mlx.mlx_ptr, WIDTH, HEIGHT);
	game.mlx.addr = mlx_get_data_addr(game.mlx.img, &game.mlx.bpp, 
										&game.mlx.line_size, &game.mlx.endian);
	
	ft_put_pixel(&game.mlx, WIDTH / 2, HEIGHT / 2, 0x00FF0000);
	mlx_put_image_to_window(game.mlx.mlx_ptr, game.mlx.win, game.mlx.img, 0, 0);
	
	mlx_loop_hook(game.mlx.mlx_ptr, &render, &game.mlx);
	mlx_hook(game.mlx.win, 2, 1L<<0, &keypress, &game);
	mlx_loop(game.mlx.mlx_ptr);
}
