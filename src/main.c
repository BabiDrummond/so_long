/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:54:18 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/03 20:34:24 by bmoreira         ###   ########.fr       */
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

void	draw_rect(t_mlx *mlx, int col, int row, int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SQUARE)
	{
		x = -1;
		while (++x < SQUARE)
			ft_put_pixel(mlx, col * SQUARE + x, row * SQUARE + y, color);
	}
}

int	render(t_map *map, t_mlx *mlx)
{
	int	col;
	int	row;

	row = -1;
	while (++row < map->height)
	{
		col = -1;
		while (++col < map->width)
		{
			if (map->grid[row][col] == '0')
				draw_rect(mlx, col, row, create_rgb(70, 200, 200));
			if (map->grid[row][col] == '1')
				draw_rect(mlx, col, row, create_rgb(122, 122, 122));
			if (map->grid[row][col] == 'C')
				draw_rect(mlx, col, row, create_rgb(255, 150, 0));
			if (map->grid[row][col] == 'E')
				draw_rect(mlx, col, row, create_rgb(0, 190, 0));
			if (map->grid[row][col] == 'M')
				draw_rect(mlx, col, row, create_rgb(255, 0, 100));
			if (map->grid[row][col] == 'P')
				draw_rect(mlx, col, row, create_rgb(255, 128, 255));
		}
	}
	return (0);
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
	game.mlx.width = game.map.width * SQUARE;
	game.mlx.height = game.map.height * SQUARE;
	game.mlx.mlx_ptr = mlx_init();
	game.mlx.win = mlx_new_window(game.mlx.mlx_ptr, game.mlx.width,
			game.mlx.height, "Hello World");
	game.mlx.img = mlx_new_image(game.mlx.mlx_ptr, game.mlx.width,
			game.mlx.height);
	game.mlx.addr = mlx_get_data_addr(game.mlx.img, &game.mlx.bpp,
			&game.mlx.line_size, &game.mlx.endian);
	render(&game.map, &game.mlx);
	mlx_put_image_to_window(game.mlx.mlx_ptr, game.mlx.win, game.mlx.img, 0, 0);
	mlx_loop_hook(game.mlx.mlx_ptr, &render, &game.mlx);
	mlx_hook(game.mlx.win, 2, 1L << 0, &keypress, &game);
	mlx_loop(game.mlx.mlx_ptr);
}
