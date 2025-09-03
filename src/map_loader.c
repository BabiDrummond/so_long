/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:54:18 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/02 22:14:44 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// void	read_file(char *file_name)
// {
// 	t_list	*lst_lines;
// 	char	*line;
// 	int		fd;

// 	fd = open(file_name, O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		ft_lstadd_back(&lst_lines, ft_lstnew(line));
// 		line = get_next_line(fd);
// 	}
// 	while (lst_lines)
// 	{
// 		ft_printf("%s", lst_lines->content);
// 		lst_lines = lst_lines->next;
// 	}
// }

int validate_chars(char *str, const char *set)
{
	int	i;
	int	j;
	int	valid;
	
	i = 0;
	while (str[i])
	{
		j = 0;
		valid = 1;
		while (set[j])
		{
			if (str[i] == set[j])
				valid = 0;
			j++;
		}
		i++;
	}
	return (valid);
}

char	*trim(char *str, char set)
{
	char	*new;
	int		i;

	if (!str || !*str)
		return (ft_strdup(""));
	i = 0;
	new = ft_calloc(ft_strlen(str), sizeof(char));
	if (!new)
		return (NULL);
	while (str[i] && str[i] != set)
	{
		new[i] = str[i];
		i++;
	}
	free(str);
	return (new);
}

void	read_file(char *file_name)
{
	char	*map;
	char	*line;
	int		fd;

	map = ft_strdup("");
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		line = trim(line, '\n');
		ft_printf("Valid? %d\n", validate_chars(line, "01CEP"));
		map = ft_strjoin(map, line);
		line = get_next_line(fd);
	}
	ft_printf("%s", map);
}

int main(void)
{
	read_file("maps/map01.ber");
}