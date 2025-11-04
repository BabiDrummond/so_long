/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:54:18 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/04 19:46:49 by bmoreira         ###   ########.fr       */
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

void	move_player(t_map *map, int x, int y)
{
	t_pos	curr;
	t_pos	next;
	
	curr.y = map->player.y;
	curr.x = map->player.x;
	next.y = curr.y + y;
	next.x = curr.x + x;
	if (map->grid[next.y][next.x] != '1')
	{
		map->grid[curr.y][curr.x] = '0';
		map->grid[next.y][next.x] = 'P';
		map->player.y = next.y;
		map->player.x = next.x;
		if (map->grid[next.y][next.x] == 'C')
			map->collectibles--;
	}
	ft_matrix_print(map->grid);
}

int	keypress(int key, t_game *game)
{
	if (key == ESC)
		close_window(game);
	if (key == W)
		move_player(&game->map, 0, -1);
	if (key == A)
		move_player(&game->map, -1, 0);
	if (key == S)
		move_player(&game->map, 0, 1);
	if (key == D)
		move_player(&game->map, 1, 0);
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
	int	row;
	int	col;

	row = -1;
	while (++row < map->rows)
	{
		col = -1;
		while (++col < map->cols)
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

void	init_mlx(t_mlx *mlx, int width, int height)
{
	mlx->width = width * SQUARE;
	mlx->height = height * SQUARE;
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, mlx->width, mlx->height, "So long");
	mlx->img = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_size, &mlx->endian);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_handler(NULL, "Usage: ./so_long <map_file.ber>", EXIT_FAILURE);
	map_loader(&game.map, argv[1]);
	map_validator(&game.map);
	ft_printf("x: %d, y: %d\n", game.map.rows, game.map.cols);
	ft_matrix_print(game.map.grid);
	init_mlx(&game.mlx, game.map.cols, game.map.rows);
	//render(&game.map, &game.mlx);
	mlx_put_image_to_window(game.mlx.mlx_ptr, game.mlx.win, game.mlx.img, 0, 0);
	mlx_hook(game.mlx.win, 2, 1L << 0, &keypress, &game);
	mlx_loop_hook(game.mlx.mlx_ptr, &render, &game);
	mlx_loop(game.mlx.mlx_ptr);
}
