/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 22:36:50 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/07 22:41:21 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init_values(t_game *game)
{
	game->render = 0;
	game->frames = 0;
	game->moves = 0;
	game->direction = 0;
	game->collected = 0;
	game->game_destroy = 0;
}
