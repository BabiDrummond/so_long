/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:54:18 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/22 21:35:41 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

char	*read_file(char *file_name)
{
	char	*buffer;
	char	*line;
	int		fd;

	buffer = ft_strdup("");
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		buffer = ft_strjoin_free(buffer, line);
		if (!buffer)
			return (NULL);
		line = get_next_line(fd);
	}
	return (buffer);
}

void	parse(t_map *map, char *buffer)
{
	char **split;
	int	i;
	int j;

	i = 0;
	j = 0;
	split = ft_split(buffer, '\n');
	while (split[i])
		ft_printf("Valid? %d\n", check_chars(split[i++], "01CEP"));
	map->map = split;
	while(j < i)
		ft_printf("%s\n", map->map[j++]);
}

int main(void)
{
	t_map map;
	char *buffer;
	
	buffer = read_file("maps/map01.ber");
	ft_printf("%s\n", buffer);
	parse(&map, buffer);
}