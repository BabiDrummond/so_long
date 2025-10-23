/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:15:50 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/23 16:26:56 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_handler(char **args, const char *error_msg, int exit_code)
{
	if (args)
		ft_split_free(args);
	if (exit_code == EXIT_FAILURE)
		ft_printf("Error: %s\n", error_msg);
	exit (exit_code);
}
