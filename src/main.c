/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:54:18 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/08 00:04:50 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_handler(NULL, "Usage: ./so_long <map_file.ber>", EXIT_FAILURE);
	map_load(&game.map, argv[1]);
	game_init_values(&game);
	load_mlx(&game);
	load_sprites(&game);
	mlx_hook(game.mlx.win, 2, 1L << 0, &key_press, &game);
	mlx_hook(game.mlx.win, 17, 1L << 17, &game_destroy, &game);
	mlx_loop_hook(game.mlx.mlx_ptr, &game_loop, &game);
	mlx_loop(game.mlx.mlx_ptr);
}
