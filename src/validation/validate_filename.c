/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:37:06 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/29 18:52:41 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_filename(char *filename, char *extension)
{
	int	f_len;
	int	e_len;

	f_len = ft_strlen(filename);
	e_len = ft_strlen(extension);
	if (f_len < 5 || !ft_strnstr(filename + (f_len - e_len), extension, e_len))
		error_handler(NULL,
			"Invalid file. Please provide a .ber file.", EXIT_FAILURE);
}
