/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:54:18 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/06 18:48:37 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_load(t_mlx *mlx, int width, int height)
{
	mlx->width = width * TILE;
	mlx->height = height * TILE;
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, mlx->width, mlx->height, "SoLong");
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_handler(NULL, "Usage: ./so_long <map_file.ber>", EXIT_FAILURE);
	map_load(&game.map, argv[1]);
	ft_printf("x: %d, y: %d\n", game.map.cols, game.map.rows);
	ft_matrix_print(game.map.grid);
	mlx_load(&game.mlx, game.map.cols, game.map.rows);
	game.sprites.img = mlx_xpm_file_to_image(game.mlx.mlx_ptr, "assets/xpm/07_bread.xpm", &game.sprites.width, &game.sprites.height);
	mlx_hook(game.mlx.win, 2, 1L << 0, &key_press, &game);
	mlx_hook(game.mlx.win, 17, 1L << 17, &close_window, &game);
	mlx_loop_hook(game.mlx.mlx_ptr, &render, &game);
	mlx_loop(game.mlx.mlx_ptr);
}
