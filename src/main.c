/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:54:18 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/07 22:25:29 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_load(t_game *game)
{
	game->mlx.width = game->map.cols * TILE;
	game->mlx.height = game->map.rows * TILE;
	game->mlx.mlx_ptr = mlx_init();
	if (!game->mlx.mlx_ptr)
		destroy_game(game);
	game->mlx.win = mlx_new_window(game->mlx.mlx_ptr,
			game->mlx.width, game->mlx.height, "SoLong");
	if (!game->mlx.win)
		destroy_game(game);
}

void	game_init_values(t_game *game)
{
	game->render = 0;
	game->frames = 0;
	game->moves = 0;
	game->direction = 0;
	game->collected = 0;
	game->game_over = 0;
}

int	game_loop(t_game *game)
{
	render_game(game);
	game_sleep(10000);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_handler(NULL, "Usage: ./so_long <map_file.ber>", EXIT_FAILURE);
	map_load(&game.map, argv[1]);
	ft_printf("x: %d, y: %d\n", game.map.cols, game.map.rows);
	ft_matrix_print(game.map.grid);
	game_init_values(&game);
	mlx_load(&game);
	load_sprites(&game);
	mlx_hook(game.mlx.win, 2, 1L << 0, &key_press, &game);
	mlx_hook(game.mlx.win, 17, 1L << 17, &destroy_game, &game);
	mlx_loop_hook(game.mlx.mlx_ptr, &game_loop, &game);
	mlx_loop(game.mlx.mlx_ptr);
}
