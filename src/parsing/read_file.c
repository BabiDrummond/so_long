/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:34:17 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/30 19:34:40 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_file(char **buffer, char *file_name)
{
	char	*line;
	int		fd;

	*buffer = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error_handler(buffer, "Error reading file.", EXIT_FAILURE);
	line = get_next_line(fd);
	while (line)
	{
		*buffer = ft_strjoin_free(*buffer, line);
		if (!*buffer)
			error_handler(buffer, "Error joining line.", EXIT_FAILURE);
		line = get_next_line(fd);
	}
}
