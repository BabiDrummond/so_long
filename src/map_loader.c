/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:54:18 by bmoreira          #+#    #+#             */
/*   Updated: 2025/08/30 18:47:58 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

int check_chars(char *str)
{
    int     i;
    char    *set;
    
    i = 0;
    set = "01CEP";
    while (*str)
    {
        while (*set)
        {
            if (*str != *set)
                return (0);
            set++;
        }
        str++;
    }
    return (1);
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
		map = ft_strjoin(map, line);
		line = get_next_line(fd);
	}
	ft_printf("%s", map);
}

int main(void)
{
	read_file("maps/map01.ber");
}