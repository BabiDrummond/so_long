/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:54:18 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/23 16:28:39 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_chars(char *str, const char *set)
{
	int i;
	int j;
	int valid;
  
	i = -1;
	valid = 0;
  	while (str[++i])
  	{
    	j = -1;
    	valid = 0;
    	while (set[++j])
    		if (str[i] == set[j] && ++valid)
        		break;
    	if (!valid)
    		return (valid);
  	}
  	return (valid);
}

void	read_file(char **buffer, char *file_name)
{
	char	*line;
	int		fd;

	*buffer = ft_strdup("");
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		*buffer = ft_strjoin_free(*buffer, line);
		if (!*buffer)
			return ;
		line = get_next_line(fd);
	}
}

void	parse(t_map *map, char *buffer)
{
	char **split;
	int	i;
	int j;

	i = 0;
	j = 0;
	split = ft_split(buffer, '\n');
	free(buffer);
	while (split[i])
		if (!check_chars(split[i++], "01CEP"))
			error_handler(split, "Invalid chars in map.", EXIT_FAILURE);
	map->map = split;
	while(j < i)
		ft_printf("%s\n", map->map[j++]);
}

int main(void)
{
	t_map map;
	char *buffer;
	
	read_file(&buffer, "maps/map01.ber");
	ft_printf("%s\n", buffer);
	parse(&map, buffer);
	ft_split_free(map.map);
}