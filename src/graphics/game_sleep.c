/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_sleep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:25:40 by bmoreira          #+#    #+#             */
/*   Updated: 2025/11/07 22:34:17 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_sleep(long usec)
{
	struct timeval	start;
	struct timeval	now;
	long			time_passed;

	time_passed = 0;
	gettimeofday(&start, NULL);
	while (time_passed < usec)
	{
		gettimeofday(&now, NULL);
		time_passed = (now.tv_sec - start.tv_sec) * 1000000
			+ now.tv_usec - start.tv_usec;
	}
}
