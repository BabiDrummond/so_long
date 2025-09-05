/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:54:18 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/05 20:35:45 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int validate_line(char *str, const char *set)
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
	t_list	*lst_lines;
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		line = trim(line, '\n');
		ft_lstadd_back(&lst_lines, ft_lstnew(line));
		line = get_next_line(fd);
	}
	while (lst_lines)
	{
		ft_printf("%s", lst_lines->content);
		lst_lines = lst_lines->next;
	}
}


// int check_char(char *set, char c)
// {
//   while(*set)
//   {
//     if (*set++ == c)
//       return (1);
//   }
//   return (0);
// }

// int validate_line(char *str, const char *set)
// {
//   int valid;
  
//   valid = 0;
//   while (*str)
//   {
//     if (check_char(set, *str++))
//       valid = 1;
//     else
//       return (0);
//   }
//   return (valid);
// }

// void	read_file(char *file_name)
// {
// 	char	*map;
// 	char	*line;
// 	int		fd;

// 	map = ft_strdup("");
// 	fd = open(file_name, O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		line = trim(line, '\n');
// 		ft_printf("line: %s\n", line);
// 		ft_printf("Valid? %d\n", validate_line(line, "01CEP"));
// 		map = ft_strjoin(map, line);
// 		line = get_next_line(fd);
// 	}
// 	ft_printf("%s", map);
// }

int main(void)
{
	read_file("maps/map01.ber");
}